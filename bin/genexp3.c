/*
							(C) elfin(安藤 寿茂)

	genexp3: GNU ld format to DOS Extender .exp format converter

							1991-03-02 by elfin

	オフセットやリアルメモリの確保等の run386の機能を使う P3形式を出力
	可能とした。また，シンボル･テーブルの変換も行い, 386debugでシンボリック
	デバッグを可能とした。
*/

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define	CODE_SEG	0x0c
#define	SYM_SIZE	12
#define	MAGIC		0x107	/* .bin file magic */
#define	M_386		0x64	/* .bin file CPU code */

/* flags */
int	symbol = 0;
int	p3type = 0;

struct exec
{
  unsigned long a_info;		/* Use macros N_MAGIC, etc for access */
  unsigned long a_text;		/* length of text, in bytes */
  unsigned long a_data;		/* length of data, in bytes */
  unsigned long a_bss;		/* length of uninitialized data area for file, 
								in bytes */
  unsigned long a_syms;		/* length of symbol table data in file, 
								in bytes */
  unsigned long a_entry;		/* start address */
  unsigned long a_trsize;		/* length of relocation info for text, 
								in bytes */
  unsigned long a_drsize;		/* length of relocation info for data, 
								in bytes */
} bin;

struct expmp
{
  char	magic[2];		/* "MP" */
  short	modlen;			/* file length % 512 */
  short npages;			/* (file length + 511 / 512 */
  short	nreloc;			/* no of relocation items = 0 */
  short hdrlen;			/* header length in 16B unit */
  short	mindata;		/* minimum required memory in 4KB unit */
  short maxdata;		/* maximum required memory in 4KB unit */
  short	esp[2];			/* initial stack pointer */
  unsigned short checksum;	/* check sum */
  short	eip[2];			/* entry point instruction pointer */
  short	relocoff;		/* reloc table offset = 0x1e */
  short noverlay;		/* overlay number = 0 */
  short flag;			/* flag = 1 ?? */
#if 1
  char	dummy[226];
#else
  char	dummy[482];
#endif
} mp;

struct expp3
{
  char	magic[2];		/* "P3" */
  short	type;			/* type = 1 */
  short p3size;			/* P3 header size = 0x180 */
  short	expsize[2];		/* exp file size */
  unsigned short checksum;	/* check sum = ~word sum */
  long	p3lsize;		/* P3 header size = 0x180 */
  long	dxlsize;		/* DX header size = 0x80 */
  long	hdrlsize;		/* total header size = 0x200 */
  char	dummy1[14];
  short lhdrsize[2];		/* total header size */
  short	progsize[2];		/* program size (expsize - toal header size) */
  short symoff[2];		/* symbol table offset */
  short symsize[2];		/* symbol table size */
  short dummy2[16];
  short	mindata[2];		/* minimum data area in byte unit */
  short	maxdata[2];		/* maximum data area in byte unit */
  short	offset[2];		/* program offset, multiple of page size */
  short	esp[2];			/* initial stack pointer */
  short	dummy3;
  short	eip[2];			/* entry point instruction pointer */
  short	dummy4[4];
  long	progsize2;		/* program size */
  char	dummy5[0x108];
} p3;   

struct expdx
{
  char	dx[2];			/* "DX" */
  short	minreal;		/* mimimum real memory in 16B unit */
  short	maxreal;		/* maximum real memory in 16B unit */
  short	minibuf;		/* system call data buffer min in KB unit */
  short	maxibuf;		/* system call data buffer max in KB unit */
  short nistack;		/* number of istacks */
  short istksize;		/* mode switch stack(istack) size in KB unit */
  short	realbreak[2];		/* real mode program size in byte unit */
  short	callbufs;		/* inter mode data buffer size in KB unit */
  char	dummy[0x6c];
} dx; 

struct exp_symtbl {
  char  hdr[4];			/* "SYM1" */
  short len1;			/* SYM1 length = 0xe */
  short len2;			/* PROGRAM length = 0x14 */
  short	dummy1;
  short	symsize[2];		/* symbol table size */
  char  plen;			/* string length = 7 */
  char  prgm[7];		/* "PROGRAM" */
  char  dummy2[4];
  unsigned char esp[8];		/* stack pointer seg:offset */
} sym;

char	buf[1024];

void error_msg(char *s);
void error_msg1(char *s, char *p);
void init_hdr(void);
char *fname(char *name, char *ext, int force);
long gen_symbol(FILE *bin_file, FILE *exp_file);

/* set default sizes in P3 and DX header */
void
init_hdr()
{
    memset((void *)mp.magic, 0, sizeof(mp));
    memset((void *)p3.magic, 0, sizeof(p3));
    memset((void *)dx.dx, 0, sizeof(dx));
    memset((void *)sym.hdr, 0, sizeof(sym));

    mp.magic[0] = 'M'; mp.magic[1] = 'P';
    mp.hdrlen = sizeof(mp)>>4;		/* header length in 16B unit */
    mp.maxdata = 0xffff;	/* maximum required memory = 256MB */
    mp.relocoff = 0x1e;		/* reloc table offset = 0x1e */
    mp.flag = 1;
    
    p3.magic[0] = 'P'; p3.magic[1] = '3';
    p3.type = 1;
    p3.p3size = p3.p3lsize = sizeof(p3);
    p3.dxlsize = sizeof(dx);
    *(long *)p3.lhdrsize =  p3.hdrlsize = p3.p3lsize + p3.dxlsize;
    p3.mindata[0] = 0x2000;
    p3.maxdata[0] = p3.maxdata[1] = 0xffff;

    dx.dx[0] = 'D'; dx.dx[1] = 'X';
    dx.minibuf = 1;
    dx.maxibuf = 0x40;
    dx.nistack = 4;
    dx.istksize = 1;

    strcpy(sym.hdr, "SYM1");
    sym.len1 = 0xe;			/* SYM1 length = 0xe */
    sym.len2 = 0x14;			/* PROGRAM length = 0x14 */
    sym.plen = 7;			/* string length = 7 */
    strcpy(sym.prgm, "PROGRAM");		/* "PROGRAM" */
}

char *usage[] = {"usage: genexp [opts] [-SYM] infile [outfile]\n",
	"  opts =    -optname value\n",
	"  optname = minreal[16B], maxreal[16B], minibuf[1KB], maxibuf[1KB]\n",
	"            realbreak[B], callbufs[1KB], nistack, istksize[KB]\n",
	"	     -SYM for symbol table\n"};

main(int argc, char **argv)
{
    FILE	*bin_file = NULL, *exp_file = NULL;
    int		i, nb, zero = 0;
    long	len, symsize = 0;
    unsigned short checksum = 0;
    char	*bname = NULL, *ename = NULL;

    if(argc < 2) {
	for(i = 0; i < sizeof(usage)/sizeof(usage[0]); i++)
 	    fputs(usage[i], stderr);
	exit(1);
    }

    init_hdr();

    while(--argc) {
	++argv;
	if(**argv == '-') {		/* options */
	    int  val;
	    char *p = *argv + 1;

	    if(!stricmp(p, "SYM")) {
		symbol = 1;
		continue;
	    }

	    argv++; argc--;
	    val = atoi(*argv);
	
	         if(!stricmp(p, "minr")) dx.minreal = val;
	    else if(!stricmp(p, "maxr")) dx.maxreal = val;
	    else if(!stricmp(p, "mini")) dx.minibuf = val;
	    else if(!stricmp(p, "maxi")) dx.maxibuf = val;
	    else if(!stricmp(p, "realb")) *(long *)dx.realbreak = val;
	    else if(!stricmp(p, "callb")) dx.callbufs = val;
	    else if(!stricmp(p, "ni")) dx.nistack = val;
	    else if(!stricmp(p, "istk")) dx.istksize = val;
	    else error_msg1("undefined option: %s", *argv);

	    p3type = 1;			/* P3 option specified */
	} else if(bin_file == NULL) {
	    bname = fname(*argv, "bin", 0);
	    bin_file = fopen(bname, "rb");
	    if(bin_file == NULL) error_msg1("input file: %s not found", *argv);
	} else if(exp_file == NULL) {
	    ename = fname(*argv, "exp", 0);

	    exp_file = fopen(ename, "wb");
	    if(exp_file == NULL) 
		error_msg1("output file: %s can not be made", *argv);
	} else error_msg1("too many file names: %s", *argv);
    }

    if(bin_file == NULL) error_msg("no input file specified");
    if(exp_file == NULL) {
	ename = fname(bname, "exp", 1);

	exp_file = fopen(ename, "wb");
	if(exp_file == NULL) 
	    error_msg1("output file: %s can not be made", *argv);
    }

    if(bname) free(bname);
    if(ename) free(ename);

    nb = fread((void *)&bin.a_info, 1, sizeof(bin), bin_file);

    printf("bin.a_info = %x MAGIC=%x M_386=%x\n", bin.a_info, MAGIC, M_386);
    if(((bin.a_info & 0xffff) != MAGIC) && ((bin.a_info>>16& 0xff) != M_386))
	error_msg("incorrect binary file format, use -N option for ld.");

    if(bin.a_entry) p3type = 1;			/* P3 (offset != 0) */
    if(!p3type) {				 /* MP type output file */
	mp.modlen = (bin.a_text + bin.a_data + (mp.hdrlen<<4)) % 512;
						/* file length % 512 */
	mp.npages = (bin.a_text + bin.a_data + (mp.hdrlen<<4) + 511) >> 9;
						/* (file length + 511) / 512 */
  	mp.mindata = (bin.a_bss + 4095) >> 12;
	*(long *)mp.eip = bin.a_entry;
	*(long *)mp.esp = bin.a_entry + bin.a_text + bin.a_data + bin.a_bss + 1024;

	fwrite((void *)mp.magic, sizeof(mp), 1, exp_file);
	for(i = 0; i < sizeof(mp); i++) 
	    checksum += *((unsigned short *)mp.magic + i);

    } /*else if(bin.a_entry & (getpagesize() - 1)) {
	error_msg("illegal offset, not a multiple of page size");

    } */else {					/* P3 type output file */
	*(long *)p3.expsize = p3.hdrlsize + bin.a_text + bin.a_data;
	*(long *)p3.progsize = p3.progsize2 = bin.a_text + bin.a_data;
	*(long *)p3.offset = *(long *)p3.eip = bin.a_entry;
	*(long *)p3.esp = bin.a_entry + bin.a_text + bin.a_data + bin.a_bss + 1024;

	fwrite((void *)p3.magic, sizeof(p3), 1, exp_file);
	for(i = 0; i < sizeof(p3); i++) 
	    checksum += *((unsigned short *)p3.magic + i);
	fwrite((void *)dx.dx, sizeof(dx), 1, exp_file);
	for(i = 0; i < sizeof(p3); i++) 
	    checksum += *((unsigned short *)dx.dx + i);
    }

    for(len = bin.a_text + bin.a_data; len > 0; len -= nb) {
	if(ferror(bin_file)) error_msg("input file read error");
	if(feof(bin_file)) error_msg("input file un-expected end");
	nb = (len > sizeof(buf)) ? sizeof(buf) : len;
	nb = fread(buf, 1, nb, bin_file);
	for(i = 0; i < nb; i++) checksum += buf[i];
	fwrite(buf, nb, 1, exp_file);
	if(feof(exp_file) || ferror(exp_file)) 
	    error_msg("output file write error");
    }

/* generate symbol table in 386LINK format */

    if(bin.a_syms && symbol) symsize = gen_symbol(bin_file, exp_file);

/* write correct check sum */

    fseek(exp_file, 0L, SEEK_SET);
    if(p3type) {			/* P3 file */
	p3.checksum = ~checksum;
	*(long *)p3.symoff = *(long *)p3.progsize + p3.hdrlsize;
	*(long *)p3.symsize = symsize;
	fwrite((void *)p3.magic, sizeof(p3), 1, exp_file);
    } else {				/* MP file */
	mp.checksum = ~checksum;
	fwrite((void *)mp.magic, sizeof(mp), 1, exp_file);
    }
    fclose(exp_file);
    fclose(bin_file);
}

long
gen_symbol(FILE *bin_file, FILE *exp_file)
{
    int	  i;
    char  *ss_tbl;
    long  lss_tbl, bsymtbl_pos, esymtbl_pos;
    long  size = 0;			/* exp file symbol table size */

    bsymtbl_pos = ftell(bin_file);
    esymtbl_pos = ftell(exp_file);
    
/* skip symbol table for the moment */

    fseek(bin_file, bin.a_syms, SEEK_CUR);

/* read symbol character string table */

    fread(&lss_tbl, 4, 1, bin_file);	/* total size of table */

    if((ss_tbl = malloc(lss_tbl)) == NULL) 
	error_msg("not enough memory for symbol table");

    if(fread(ss_tbl + 4, 1, lss_tbl - 4, bin_file) != lss_tbl - 4)
	error_msg("symbol table read error");

/* back to symbol table */

    fseek(bin_file, bsymtbl_pos, SEEK_SET);

/* write exp_symtable header */

    *(long *)sym.esp = (bin.a_entry) ? *(long *)p3.esp : *(long *)mp.esp;
    *(long *)(sym.esp + 4) = CODE_SEG;

    fwrite((void *)sym.hdr, sizeof(sym), 1, exp_file);
    if(feof(exp_file) || ferror(exp_file)) 
	error_msg("output file write error");

/* translate symbol table and write */

    for(i = 0; i < bin.a_syms; i += SYM_SIZE) {
	long	syment[4], n;
	char	*p;

	fread(syment, SYM_SIZE, 1, bin_file);
	if((char)syment[1] != 4) {	/* other than local text symbol */
	    p = ss_tbl + syment[0];
	    if(*p == '_') p++;		/* remove leading '_' */
	    n = strlen(p);
	    fputc(n, exp_file);
	    fputs(p, exp_file);
	    syment[3] = 1;		/* exp file symbol type ? */
	    fwrite(&syment[2], 6, 1, exp_file);
	    if(feof(exp_file) || ferror(exp_file)) 
		error_msg("output file write error");
	    size += n + 7;
	}
    }

/* write correct symtable size */

    *(long *)sym.symsize = size; 
    fseek(exp_file, esymtbl_pos, SEEK_SET);

    fwrite((void *)sym.hdr, sizeof(sym), 1, exp_file);
    if(feof(exp_file) || ferror(exp_file)) 
	error_msg("output file write error");
    return (sizeof(sym) + size);
}

char *
fname(char *name, char *ext, int force)
{
    char *p = name;
    char *s = strrchr(name, '.');

    while(*p) {			/* convert pathchar */
	if(*p == '/') *p = '\\';
	p++;
    }

    if((s == NULL) || (strchr(s, '\\') != NULL)) {	/* supply ext */
	p = malloc(strlen(name) + 5);
	sprintf(p, "%s.%s", name, ext);
    } else if(force) {					/* change ext */
	p = malloc(s-name+5);
	strncpy(p, name, s-name+1);
	strcpy(p+(s-name)+1, ext);
    } else {
	p = malloc(strlen(name) + 1);
	strcpy(p, name);
    }
    return p;
}

void
error_msg(char *s)
{
    fputs(s, stderr);
    fputc('\n', stderr);
    exit(1);
}

void
error_msg1(char *s, char *p)
{
    fprintf(stderr, s, p);
    fputc('\n', stderr);
    exit(1);
}
