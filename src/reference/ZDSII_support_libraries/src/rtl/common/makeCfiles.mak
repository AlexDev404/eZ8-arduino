#
#   build C files from template files
#
#     Evoke from a bash shell

F= f_ far
N= n_ near
R= r_ rom
E= e_ pageE
X= 

.PHONY : atof atoi atol  \
      bsearch qsort  \
      frexp gets  \
      calloc free itod malloc realloc  \
      memchr memcmp memcpy memmove memset  \
      modf puts putsNOnl  \
      printf vprintf sprintf vsprintf  \
      scanf sscanf  \
      strcat strchr strcmp strcpy strcspn  strlen strncat strncmp strncpy  \
      strpbrk strrchr strspn strstr strtok   \
      strtod strtol strtoul   \
      _uprint upscan uscan uscan2 usscan 

all : atof atoi atol  \
      bsearch qsort  \
      frexp gets  \
      calloc free itod malloc realloc  \
      memchr memcmp memcpy memmove memset  \
      modf puts putsNOnl  \
      printf vprintf sprintf vsprintf  \
      scanf sscanf  \
      strcat strchr strcmp strcpy strcspn  strlen strncat strncmp strncpy  \
      strpbrk strrchr strspn strstr strtok   \
      strtod strtol strtoul   \
      _uprint upscan uscan uscan2 usscan 

atof : ATOF.C EATOF.C FATOF.C NATOF.C
atoi : ATOI.C EATOI.C FATOI.C NATOI.C
atol : ATOL.C EATOL.C FATOL.C NATOL.C


bsearch : BSEARCH.C EEBSEARCH.C EFBSEARCH.C ENBSEARCH.C ERBSEARCH.C FEBSEARCH.C FFBSEARCH.C FNBSEARCH.C \
          FRBSEARCH.C NEBSEARCH.C NFBSEARCH.C NNBSEARCH.C NRBSEARCH.C RRBSEARCH.C

calloc : CALLOC.C ECALLOC.C FCALLOC.C NCALLOC.C

free : EFREE.C FFREE.C  NFREE.C
frexp : EFREXP.C FFREXP.C FREXP.C NFREXP.C
gets : EGETS.C FGETS.C GETS.C NGETS.C
itod : ITOD.C NITOD.C FITOD.C EITOD.C
malloc: EMALLOC.C FMALLOC.C NMALLOC.C

memchr : EMEMCHR.C FMEMCHR.C MEMCHR.C NMEMCHR.C RMEMCHR.C

memcmp : EEMEMCMP.C EFMEMCMP.C ENMEMCMP.C ERMEMCMP.C FEMEMCMP.C FFMEMCMP.C \
        FNMEMCMP.C FRMEMCMP.C MEMCMP.C NEMEMCMP.C NFMEMCMP.C NNMEMCMP.C \
        NRMEMCMP.C REMEMCMP.C RFMEMCMP.C RNMEMCMP.C RRMEMCMP.C

memcpy: EEMEMCPY.C EFMEMCPY.C ENMEMCPY.C ERMEMCPY.C FEMEMCPY.C FFMEMCPY.C FNMEMCPY.C FRMEMCPY.C MEMCPY.C \
        NEMEMCPY.C NFMEMCPY.C NNMEMCPY.C NRMEMCPY.C REMEMCPY.C RFMEMCPY.C RNMEMCPY.C RRMEMCPY.C

memmove : EEMEMMOVE.C EFMEMMOVE.C ENMEMMOVE.C ERMEMMOVE.C FEMEMMOVE.C FFMEMMOVE.C FNMEMMOVE.C FRMEMMOVE.C MEMMOVE.C \
          NEMEMMOVE.C NFMEMMOVE.C NNMEMMOVE.C NRMEMMOVE.C REMEMMOVE.C RFMEMMOVE.C RNMEMMOVE.C RRMEMMOVE.C

memset : EMEMSET.C FMEMSET.C MEMSET.C NMEMSET.C

modf : EMODF.C FMODF.C MODF.C NMODF.C

printf : EPRINTF.C FPRINTF.C NPRINTF.C PRINTF.C RPRINTF.C

puts : EPUTS.C FPUTS.C NPUTS.C PUTS.C RPUTS.C

putsNOnl : EPUTSNONL.C FPUTSNONL.C NPUTSNONL.C PUTSNONL.C RPUTSNONL.C

qsort : EQSORT.C FQSORT.C NQSORT.C QSORT.C

realloc : EREALLOC.C FREALLOC.C NREALLOC.C REALLOC.C

vprintf :EVPRINTF.C FVPRINTF.C NVPRINTF.C RVPRINTF.C VPRINTF.C

scanf : NSCANF.C FSCANF.C ESCANF.C RSCANF.C SCANF.C

sscanf : EESSCANF.C EFSSCANF.C ENSSCANF.C ERSSCANF.C FESSCANF.C FFSSCANF.C FNSSCANF.C FRSSCANF.C \
         NESSCANF.C NFSSCANF.C NNSSCANF.C NRSSCANF.C SSCANF.C

sprintf: EESPRINTF.C EFSPRINTF.C ENSPRINTF.C ERSPRINTF.C FESPRINTF.C FFSPRINTF.C FNSPRINTF.C FRSPRINTF.C \
         NESPRINTF.C  NFSPRINTF.C  NNSPRINTF.C NRSPRINTF.C SPRINTF.C 

vsprintf: EEVSPRINTF.C EFVSPRINTF.C ENVSPRINTF.C ERVSPRINTF.C FEVSPRINTF.C FFVSPRINTF.C FNVSPRINTF.C FRVSPRINTF.C \
          NEVSPRINTF.C NFVSPRINTF.C NNVSPRINTF.C NRVSPRINTF.C VSPRINTF.C

strcat : EESTRCAT.C EFSTRCAT.C ENSTRCAT.C ERSTRCAT.C FESTRCAT.C FFSTRCAT.C FNSTRCAT.C FRSTRCAT.C \
         NESTRCAT.C NFSTRCAT.C NNSTRCAT.C NRSTRCAT.C RESTRCAT.C RFSTRCAT.C RNSTRCAT.C STRCAT.C

strchr : ESTRCHR.C FSTRCHR.C NSTRCHR.C RSTRCHR.C STRCHR.C

strcmp: EESTRCMP.C EFSTRCMP.C ENSTRCMP.C ERSTRCMP.C FESTRCMP.C FFSTRCMP.C FNSTRCMP.C FRSTRCMP.C STRCMP.C \
        NESTRCMP.C NFSTRCMP.C NNSTRCMP.C NRSTRCMP.C RESTRCMP.C RFSTRCMP.C RNSTRCMP.C RRSTRCMP.C

strcpy : EESTRCPY.C EFSTRCPY.C ENSTRCPY.C ERSTRCPY.C FESTRCPY.C FFSTRCPY.C FNSTRCPY.C FRSTRCPY.C \
         NESTRCPY.C NFSTRCPY.C NNSTRCPY.C NRSTRCPY.C RESTRCPY.C RFSTRCPY.C RNSTRCPY.C STRCPY.C

strcspn: EESTRCSPN.C EFSTRCSPN.C ENSTRCSPN.C ERSTRCSPN.C FESTRCSPN.C FFSTRCSPN.C FNSTRCSPN.C FRSTRCSPN.C STRCSPN.C \
         NESTRCSPN.C NFSTRCSPN.C NNSTRCSPN.C NRSTRCSPN.C RESTRCSPN.C RFSTRCSPN.C RNSTRCSPN.C RRSTRCSPN.C

strlen : ESTRLEN.C FSTRLEN.C NSTRLEN.C RSTRLEN.C STRLEN.C

strncat : EESTRNCAT.C EFSTRNCAT.C ENSTRNCAT.C ERSTRNCAT.C FESTRNCAT.C FFSTRNCAT.C FNSTRNCAT.C FRSTRNCAT.C \
          NESTRNCAT.C NFSTRNCAT.C NNSTRNCAT.C NRSTRNCAT.C RESTRNCAT.C RFSTRNCAT.C RNSTRNCAT.C STRNCAT.C

strncmp: EESTRNCMP.C EFSTRNCMP.C ENSTRNCMP.C ERSTRNCMP.C FESTRNCMP.C FFSTRNCMP.C FNSTRNCMP.C FRSTRNCMP.C STRNCMP.C \
         NESTRNCMP.C NFSTRNCMP.C NNSTRNCMP.C NRSTRNCMP.C RESTRNCMP.C RFSTRNCMP.C RNSTRNCMP.C RRSTRNCMP.C

strncpy : EESTRNCPY.C EFSTRNCPY.C ENSTRNCPY.C ERSTRNCPY.C FESTRNCPY.C FFSTRNCPY.C FNSTRNCPY.C FRSTRNCPY.C \
          NESTRNCPY.C NFSTRNCPY.C NNSTRNCPY.C NRSTRNCPY.C RESTRNCPY.C RFSTRNCPY.C RNSTRNCPY.C STRNCPY.C

strpbrk: EESTRPBRK.C EFSTRPBRK.C ENSTRPBRK.C ERSTRPBRK.C FESTRPBRK.C FFSTRPBRK.C FNSTRPBRK.C FRSTRPBRK.C STRPBRK.C \
         NESTRPBRK.C NFSTRPBRK.C NNSTRPBRK.C NRSTRPBRK.C RESTRPBRK.C RFSTRPBRK.C RNSTRPBRK.C RRSTRPBRK.C

strrchr : ESTRRCHR.C FSTRRCHR.C NSTRRCHR.C RSTRRCHR.C STRRCHR.C

strspn: EESTRSPN.C EFSTRSPN.C ENSTRSPN.C ERSTRSPN.C FESTRSPN.C FFSTRSPN.C FNSTRSPN.C FRSTRSPN.C STRSPN.C \
        NESTRSPN.C NFSTRSPN.C NNSTRSPN.C NRSTRSPN.C RESTRSPN.C RFSTRSPN.C RNSTRSPN.C RRSTRSPN.C

strstr: EESTRSTR.C EFSTRSTR.C ENSTRSTR.C ERSTRSTR.C FESTRSTR.C FFSTRSTR.C FNSTRSTR.C FRSTRSTR.C STRSTR.C \
        NESTRSTR.C NFSTRSTR.C NNSTRSTR.C NRSTRSTR.C RESTRSTR.C RFSTRSTR.C RNSTRSTR.C RRSTRSTR.C

strtod : ESTRTOD.C FSTRTOD.C NSTRTOD.C STRTOD.C

strtok: EESTRTOK.C EFSTRTOK.C ENSTRTOK.C ERSTRTOK.C FESTRTOK.C FFSTRTOK.C FNSTRTOK.C FRSTRTOK.C STRTOK.C \
        NESTRTOK.C NFSTRTOK.C NNSTRTOK.C NRSTRTOK.C

strtol : ESTRTOL.C FSTRTOL.C NSTRTOL.C STRTOL.C

strtoul : ESTRTOUL.C FSTRTOUL.C NSTRTOUL.C STRTOUL.C

_uprint : EUPRINT.C FUPRINT.C NUPRINT.C RUPRINT.C UPRINT.C

upscan : EUPSCAN.C FUPSCAN.C NUPSCAN.C RUPSCAN.C UPSCAN.C

uscan : EEUSCAN.C EFUSCAN.C ENUSCAN.C ERUSCAN.C FEUSCAN.C FFUSCAN.C FNUSCAN.C FRUSCAN.C \
        NEUSCAN.C NFUSCAN.C NNUSCAN.C NRUSCAN.C USCAN.C

uscan2 : EUSCAN2.C FUSCAN2.C NUSCAN2.C RUSCAN2.C USCAN2.C

usscan : EUSSCAN.C FUSSCAN.C NUSSCAN.C USSCAN.C RUSSCAN.C 

ATOF.C : ATOF.TPL  makeCfiles.mak
	./makeCfile.bsh $@ ATOF.TPL  $X
EATOF.C : ATOF.TPL  makeCfiles.mak
	./makeCfile.bsh $@ ATOF.TPL  $E
FATOF.C : ATOF.TPL  makeCfiles.mak
	./makeCfile.bsh $@ ATOF.TPL  $F
NATOF.C : ATOF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ATOF.TPL  $N

ATOI.C : ATOI.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ATOI.TPL  $X
EATOI.C : ATOI.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ATOI.TPL  $E
FATOI.C : ATOI.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ATOI.TPL  $F
NATOI.C : ATOI.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ATOI.TPL  $N


ATOL.C : ATOL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ATOL.TPL  $X
EATOL.C : ATOL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ATOL.TPL  $E
FATOL.C : ATOL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ATOL.TPL  $F
NATOL.C : ATOL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ATOL.TPL  $N

BSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $X
EEBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $E $E
EFBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $E $F
ENBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $E $N
ERBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $E $R
FEBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $F $E
FFBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $F $F
FNBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $F $N
FRBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $F $R
NEBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $N $E
NFBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $N $F
NNBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $N $N
NRBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $N $R
RRBSEARCH.C: BSEARCH.TPL makeCfiles.mak 
	./makeCfile.bsh $@ BSEARCH.TPL  $R $R

CALLOC.C : CALLOC.TPL makeCfiles.mak 
	./makeCfile.bsh $@ CALLOC.TPL  $X
ECALLOC.C : CALLOC.TPL makeCfiles.mak 
	./makeCfile.bsh $@ CALLOC.TPL  $E
FCALLOC.C : CALLOC.TPL makeCfiles.mak 
	./makeCfile.bsh $@ CALLOC.TPL  $F
NCALLOC.C : CALLOC.TPL makeCfiles.mak 
	./makeCfile.bsh $@ CALLOC.TPL  $N

EFREE.C : FREE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ FREE.TPL  $E
FFREE.C : FREE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ FREE.TPL  $F
NFREE.C  : FREE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ FREE.TPL  $N

EFREXP.C : FREXP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ FREXP.TPL  $E
FFREXP.C : FREXP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ FREXP.TPL  $F
FREXP.C : FREXP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ FREXP.TPL  $X
NFREXP.C : FREXP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ FREXP.TPL  $N

EGETS.C : GETS.TPL makeCfiles.mak 
	./makeCfile.bsh $@ GETS.TPL  $E
FGETS.C : GETS.TPL makeCfiles.mak 
	./makeCfile.bsh $@ GETS.TPL  $F
GETS.C  : GETS.TPL makeCfiles.mak 
	./makeCfile.bsh $@ GETS.TPL  $X
NGETS.C : GETS.TPL makeCfiles.mak 
	./makeCfile.bsh $@ GETS.TPL  $N

ITOD.C : ITOD.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ITOD.TPL  $X
NITOD.C : ITOD.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ITOD.TPL  $N
FITOD.C : ITOD.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ITOD.TPL  $F
EITOD.C : ITOD.TPL makeCfiles.mak 
	./makeCfile.bsh $@ ITOD.TPL  $E

EMALLOC.C : MALLOC.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MALLOC.TPL  $E
FMALLOC.C : MALLOC.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MALLOC.TPL  $F
NMALLOC.C : MALLOC.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MALLOC.TPL  $N

EMEMCHR.C : MEMCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCHR.TPL  $E
FMEMCHR.C : MEMCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCHR.TPL  $F
MEMCHR.C : MEMCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCHR.TPL  $X
NMEMCHR.C : MEMCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCHR.TPL  $N
RMEMCHR.C : MEMCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCHR.TPL  $R

EEMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $E $E
EFMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $E $F
ENMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $E $N
ERMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $E $R
FEMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $F $E
FFMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $F $F
FNMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $F $N
FRMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $F $R
MEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $X
NEMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $N $E
NFMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $N $F
NNMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $N $N
NRMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $N $R
REMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $R $E
RFMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $R $F
RNMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $R $N
RRMEMCMP.C : MEMCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCMP.TPL  $R $R

EEMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $E $E
EFMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $E $F
ENMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $E $N
ERMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $E $R
FEMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $F $E
FFMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $F $F
FNMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $F $N
FRMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $F $R
MEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $X
NEMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $N $E
NFMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $N $F
NNMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $N $N
NRMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $N $R
REMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $R $E
RFMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $R $F
RNMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $R $N
RRMEMCPY.C : MEMCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMCPY.TPL  $R $R

#   MEMMOVE.TPL - TRUE/FALSE parm as to whether the two spaces are the same
EEMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P TRUE  $E $E
EFMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $E $F
ENMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $E $N
ERMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $E $R
FEMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $F $E
FFMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P TRUE  $F $F
FNMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $F $N
FRMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $F $R
MEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P TRUE  $X
NEMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $N $E
NFMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $N $F
NNMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P TRUE  $N $N
NRMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $N $R
REMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $R $E
RFMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $R $F
RNMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P FALSE $R $N
RRMEMMOVE.C : MEMMOVE.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMMOVE.TPL  -P TRUE  $R $R

EMEMSET.C : MEMSET.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMSET.TPL  $E
FMEMSET.C : MEMSET.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMSET.TPL  $F
MEMSET.C : MEMSET.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMSET.TPL  $X
NMEMSET.C : MEMSET.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMSET.TPL  $N
RMEMSET.C : MEMSET.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MEMSET.TPL  $R

EMODF.C : MODF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MODF.TPL  $E
FMODF.C : MODF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MODF.TPL  $F
MODF.C : MODF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MODF.TPL  $X
NMODF.C : MODF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ MODF.TPL  $N

EPRINTF.C : PRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PRINTF.TPL  $E
FPRINTF.C : PRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PRINTF.TPL  $F
NPRINTF.C : PRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PRINTF.TPL  $N
PRINTF.C : PRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PRINTF.TPL  $X
RPRINTF.C : PRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PRINTF.TPL  $R

EPUTS.C : PUTS.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PUTS.TPL  $E
FPUTS.C : PUTS.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PUTS.TPL  $F
NPUTS.C : PUTS.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PUTS.TPL  $N
PUTS.C : PUTS.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PUTS.TPL  $X
RPUTS.C : PUTS.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PUTS.TPL  $R

EPUTSNONL.C : PUTSNONL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PUTSNONL.TPL  $E
FPUTSNONL.C : PUTSNONL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PUTSNONL.TPL  $F
NPUTSNONL.C : PUTSNONL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PUTSNONL.TPL  $N
PUTSNONL.C : PUTSNONL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PUTSNONL.TPL  $X
RPUTSNONL.C : PUTSNONL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ PUTSNONL.TPL  $R

EQSORT.C : QSORT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ QSORT.TPL  $E
FQSORT.C : QSORT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ QSORT.TPL  $F
NQSORT.C : QSORT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ QSORT.TPL  $N
QSORT.C : QSORT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ QSORT.TPL  $X

EREALLOC.C : REALLOC.TPL makeCfiles.mak 
	./makeCfile.bsh $@ REALLOC.TPL  $E
FREALLOC.C : REALLOC.TPL makeCfiles.mak 
	./makeCfile.bsh $@ REALLOC.TPL  $F
NREALLOC.C : REALLOC.TPL makeCfiles.mak 
	./makeCfile.bsh $@ REALLOC.TPL  $N
REALLOC.C : REALLOC.TPL makeCfiles.mak 
	./makeCfile.bsh $@ REALLOC.TPL  $X

EVPRINTF.C : VPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VPRINTF.TPL  $E
FVPRINTF.C : VPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VPRINTF.TPL  $F
NVPRINTF.C : VPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VPRINTF.TPL  $N
RVPRINTF.C : VPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VPRINTF.TPL  $R
VPRINTF.C : VPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VPRINTF.TPL  $X

NSCANF.C : SCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SCANF.TPL  $N
FSCANF.C : SCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SCANF.TPL  $F
ESCANF.C : SCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SCANF.TPL  $E
RSCANF.C : SCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SCANF.TPL  $R
SCANF.C : SCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SCANF.TPL  $X

EESSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $E $E
EFSSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $E $F
ENSSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $E $N
ERSSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $E $R
FESSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $F $E
FFSSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $F $F
FNSSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $F $N
FRSSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $F $R
NESSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $N $E
NFSSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $N $F
NNSSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $N $N
NRSSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $N $R
SSCANF.C : SSCANF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SSCANF.TPL  $X

EESPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $E $E
EEVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $E $E
EFSPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $E $F
EFVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $E $F
ENSPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $E $N
ENVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $E $N
ERSPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $E $R
ERVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $E $R
FESPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $F $E
FEVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $F $E
FFSPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $F $F
FFVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $F $F
FNSPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $F $N
FNVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $F $N
FRSPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $F $R
FRVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $F $R
NESPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $N $E
NEVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $N $E
NFSPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $N $F
NFVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $N $F
NNSPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $N $N
NNVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $N $N
NRSPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $N $R
NRVSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $N $R
SPRINTF.C : SPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ SPRINTF.TPL  $X
VSPRINTF.C : VSPRINTF.TPL makeCfiles.mak 
	./makeCfile.bsh $@ VSPRINTF.TPL  $X

EESTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $E $E
EFSTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $E $F
ENSTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $E $N
ERSTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $E $R
FESTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $F $E
FFSTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $F $F
FNSTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $F $N
FRSTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $F $R
NESTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $N $E
NFSTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $N $F
NNSTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $N $N
NRSTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $N $R
RESTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $R $E
RFSTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $R $F
RNSTRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $R $N
STRCAT.C : STRCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCAT.TPL  $X

ESTRCHR.C: STRCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCHR.TPL  $E
FSTRCHR.C: STRCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCHR.TPL  $F
NSTRCHR.C: STRCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCHR.TPL  $N
RSTRCHR.C: STRCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCHR.TPL  $R
STRCHR.C: STRCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCHR.TPL  $X

EESTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $E $E
EFSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $E $F
ENSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $E $N
ERSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $E $R
FESTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $F $E
FFSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $F $F
FNSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $F $N
FRSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $F $R
NESTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $N $E
NFSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $N $F
NNSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $N $N
NRSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $N $R
RESTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $R $E
RFSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $R $F
RNSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $R $N
RRSTRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $R $R
STRCMP.C : STRCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCMP.TPL  $X

EESTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $E $E
EFSTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $E $F
ENSTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $E $N
ERSTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $E $R
FESTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $F $E
FFSTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $F $F
FNSTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $F $N
FRSTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $F $R
NESTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $N $E
NFSTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $N $F
NNSTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $N $N
NRSTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $N $R
RESTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $R $E
RFSTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $R $F
RNSTRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $R $N
STRCPY.C : STRCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCPY.TPL  $X

EESTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $E $E
EFSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $E $F
ENSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $E $N
ERSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $E $R
FESTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $F $E
FFSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $F $F
FNSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $F $N
FRSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $F $R
NESTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $N $E
NFSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $N $F
NNSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $N $N
NRSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $N $R
RESTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $R $E
RFSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $R $F
RNSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $R $N
RRSTRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $R $R
STRCSPN.C : STRCSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRCSPN.TPL  $X

ESTRLEN.C : STRLEN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRLEN.TPL  $E
FSTRLEN.C : STRLEN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRLEN.TPL  $F
NSTRLEN.C : STRLEN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRLEN.TPL  $N
RSTRLEN.C : STRLEN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRLEN.TPL  $R
STRLEN.C : STRLEN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRLEN.TPL  $X

EESTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $E $E
EFSTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $E $F
ENSTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $E $N
ERSTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $E $R
FESTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $F $E
FFSTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $F $F
FNSTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $F $N
FRSTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $F $R
NESTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $N $E
NFSTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $N $F
NNSTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $N $N
NRSTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $N $R
RESTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $R $E
RFSTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $R $F
RNSTRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $R $N
STRNCAT.C : STRNCAT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCAT.TPL  $X

EESTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $E $E
EFSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $E $F
ENSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $E $N
ERSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $E $R
FESTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $F $E
FFSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $F $F
FNSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $F $N
FRSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $F $R
NESTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $N $E
NFSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $N $F
NNSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $N $N
NRSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $N $R
RESTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $R $E
RFSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $R $F
RNSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $R $N
RRSTRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $R $R
STRNCMP.C : STRNCMP.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCMP.TPL  $X

EESTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $E $E
EFSTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $E $F
ENSTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $E $N
ERSTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $E $R
FESTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $F $E
FFSTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $F $F
FNSTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $F $N
FRSTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $F $R
NESTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $N $E
NFSTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $N $F
NNSTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $N $N
NRSTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $N $R
RESTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $R $E
RFSTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $R $F
RNSTRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $R $N
STRNCPY.C : STRNCPY.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRNCPY.TPL  $X

EESTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $E $E
EFSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $E $F
ENSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $E $N
ERSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $E $R
FESTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $F $E
FFSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $F $F
FNSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $F $N
FRSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $F $R
NESTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $N $E
NFSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $N $F
NNSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $N $N
NRSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $N $R
RESTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $R $E
RFSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $R $F
RNSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $R $N
RRSTRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $R $R
STRPBRK.C : STRPBRK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRPBRK.TPL  $X

ESTRRCHR.C : STRRCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRRCHR.TPL  $E
FSTRRCHR.C : STRRCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRRCHR.TPL  $F
NSTRRCHR.C : STRRCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRRCHR.TPL  $N
RSTRRCHR.C : STRRCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRRCHR.TPL  $R
STRRCHR.C : STRRCHR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRRCHR.TPL  $X

EESTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $E $E
EFSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $E $F
ENSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $E $N
ERSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $E $R
FESTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $F $E
FFSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $F $F
FNSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $F $N
FRSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $F $R
NESTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $N $E
NFSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $N $F
NNSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $N $N
NRSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $N $R
RESTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $R $E
RFSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $R $F
RNSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $R $N
RRSTRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $R $R
STRSPN.C : STRSPN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSPN.TPL  $X

EESTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $E $E
EFSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $E $F
ENSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $E $N
ERSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $E $R
FESTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $F $E
FFSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $F $F
FNSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $F $N
FRSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $F $R
NESTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $N $E
NFSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $N $F
NNSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $N $N
NRSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $N $R
RESTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $R $E
RFSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $R $F
RNSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $R $N
RRSTRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $R $R
STRSTR.C : STRSTR.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRSTR.TPL  $X

ESTRTOD.C : STRTOD.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOD.TPL  $E
FSTRTOD.C : STRTOD.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOD.TPL  $F
NSTRTOD.C : STRTOD.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOD.TPL  $N
STRTOD.C : STRTOD.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOD.TPL  $X

EESTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $E $E
EFSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $E $F
ENSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $E $N
ERSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $E $R
FESTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $F $E
FFSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $F $F
FNSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $F $N
FRSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $F $R
NESTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $N $E
NFSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $N $F
NNSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $N $N
NRSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $N $R
RESTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $R $E
RFSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $R $F
RNSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $R $N
RRSTRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $R $R
STRTOK.C : STRTOK.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOK.TPL  $X

ESTRTOL.C : STRTOL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOL.TPL  $E
FSTRTOL.C : STRTOL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOL.TPL  $F
NSTRTOL.C : STRTOL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOL.TPL  $N
STRTOL.C : STRTOL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOL.TPL  $X

ESTRTOUL.C : STRTOUL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOUL.TPL  $E
FSTRTOUL.C : STRTOUL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOUL.TPL  $F
NSTRTOUL.C : STRTOUL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOUL.TPL  $N
STRTOUL.C : STRTOUL.TPL makeCfiles.mak 
	./makeCfile.bsh $@ STRTOUL.TPL  $X

EUPRINT.C : UPRINT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ UPRINT.TPL  $E
FUPRINT.C : UPRINT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ UPRINT.TPL  $F
NUPRINT.C : UPRINT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ UPRINT.TPL  $N
RUPRINT.C : UPRINT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ UPRINT.TPL  $R
UPRINT.C : UPRINT.TPL makeCfiles.mak 
	./makeCfile.bsh $@ UPRINT.TPL  $X

EUPSCAN.C : UPSCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ UPSCAN.TPL  $E
FUPSCAN.C : UPSCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ UPSCAN.TPL  $F
NUPSCAN.C : UPSCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ UPSCAN.TPL  $N
RUPSCAN.C : UPSCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ UPSCAN.TPL  $R
UPSCAN.C : UPSCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ UPSCAN.TPL  $X

EEUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $E $E
EFUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $E $F
ENUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $E $N
ERUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $E $R
FEUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $F $E
FFUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $F $F
FNUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $F $N
FRUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $F $R
NEUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $N $E
NFUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $N $F
NNUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $N $N
NRUSCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $N $R
USCAN.C : USCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN.TPL  $X

EUSCAN2.C : USCAN2.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN2.TPL  $E
FUSCAN2.C : USCAN2.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN2.TPL  $F
RUSCAN2.C : USCAN2.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN2.TPL  $R
NUSCAN2.C : USCAN2.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN2.TPL  $N
USCAN2.C : USCAN2.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USCAN2.TPL  $X

EUSSCAN.C : USSCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USSCAN.TPL  $E
FUSSCAN.C : USSCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USSCAN.TPL  $F
NUSSCAN.C : USSCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USSCAN.TPL  $N
USSCAN.C : USSCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USSCAN.TPL  $X
RUSSCAN.C: USSCAN.TPL makeCfiles.mak 
	./makeCfile.bsh $@ USSCAN.TPL  $R

clean :
	rm ATOF.C EATOF.C FATOF.C NATOF.C 
	rm ATOI.C EATOI.C FATOI.C NATOI.C 
	rm ATOL.C EATOL.C FATOL.C NATOL.C 
	rm BSEARCH.C EEBSEARCH.C EFBSEARCH.C ENBSEARCH.C ERBSEARCH.C FEBSEARCH.C FFBSEARCH.C FNBSEARCH.C
	rm FRBSEARCH.C NEBSEARCH.C NFBSEARCH.C NNBSEARCH.C NRBSEARCH.C RRBSEARCH.C
	rm CALLOC.C ECALLOC.C FCALLOC.C NCALLOC.C 
	rm EFREE.C FFREE.C NFREE.C  
	rm EFREXP.C FFREXP.C FREXP.C NFREXP.C 
	rm EGETS.C FGETS.C GETS.C  NGETS.C 
	rm ITOD.C NITOD.C FITOD.C EITOD.C
	rm EMALLOC.C FMALLOC.C NMALLOC.C 
	rm EMEMCHR.C FMEMCHR.C MEMCHR.C NMEMCHR.C RMEMCHR.C 
	rm EEMEMCMP.C EFMEMCMP.C ENMEMCMP.C ERMEMCMP.C FEMEMCMP.C FFMEMCMP.C
	rm FNMEMCMP.C FRMEMCMP.C MEMCMP.C NEMEMCMP.C NFMEMCMP.C NNMEMCMP.C
	rm NRMEMCMP.C REMEMCMP.C RFMEMCMP.C RNMEMCMP.C RRMEMCMP.C
	rm EEMEMCPY.C EFMEMCPY.C ENMEMCPY.C ERMEMCPY.C FEMEMCPY.C FFMEMCPY.C FNMEMCPY.C FRMEMCPY.C MEMCPY.C
	rm NEMEMCPY.C NFMEMCPY.C NNMEMCPY.C NRMEMCPY.C REMEMCPY.C RFMEMCPY.C RNMEMCPY.C RRMEMCPY.C
	rm EEMEMMOVE.C EFMEMMOVE.C ENMEMMOVE.C ERMEMMOVE.C FEMEMMOVE.C FFMEMMOVE.C FNMEMMOVE.C FRMEMMOVE.C MEMMOVE.C 
	rm NEMEMMOVE.C NFMEMMOVE.C NNMEMMOVE.C NRMEMMOVE.C REMEMMOVE.C RFMEMMOVE.C RNMEMMOVE.C RRMEMMOVE.C 
	rm EMEMSET.C FMEMSET.C MEMSET.C NMEMSET.C RMEMSET.C
	rm EMODF.C FMODF.C MODF.C NMODF.C 
	rm EPRINTF.C FPRINTF.C NPRINTF.C PRINTF.C RPRINTF.C 
	rm EPUTS.C FPUTS.C NPUTS.C PUTS.C RPUTS.C 
	rm EPUTSNONL.C FPUTSNONL.C NPUTSNONL.C PUTSNONL.C RPUTSNONL.C 
	rm EQSORT.C FQSORT.C NQSORT.C QSORT.C 
	rm EREALLOC.C FREALLOC.C NREALLOC.C REALLOC.C 
	rm EVPRINTF.C FVPRINTF.C NVPRINTF.C RVPRINTF.C VPRINTF.C 
	rm NSCANF.C FSCANF.C ESCANF.C RSCANF.C SCANF.C 
	rm EESSCANF.C EFSSCANF.C ENSSCANF.C ERSSCANF.C FESSCANF.C FFSSCANF.C FNSSCANF.C FRSSCANF.C 
	rm NESSCANF.C NFSSCANF.C NNSSCANF.C NRSSCANF.C SSCANF.C 
	rm EESPRINTF.C EFSPRINTF.C ENSPRINTF.C ERSPRINTF.C FESPRINTF.C FFSPRINTF.C FNSPRINTF.C FRSPRINTF.C 
	rm NESPRINTF.C  NFSPRINTF.C  NNSPRINTF.C NRSPRINTF.C SPRINTF.C 
	rm EEVSPRINTF.C EFVSPRINTF.C ENVSPRINTF.C ERVSPRINTF.C FEVSPRINTF.C FFVSPRINTF.C FNVSPRINTF.C FRVSPRINTF.C 
	rm NEVSPRINTF.C NFVSPRINTF.C NNVSPRINTF.C NRVSPRINTF.C VSPRINTF.C 
	rm EESTRCAT.C EFSTRCAT.C ENSTRCAT.C ERSTRCAT.C FESTRCAT.C FFSTRCAT.C FNSTRCAT.C FRSTRCAT.C 
	rm NESTRCAT.C NFSTRCAT.C NNSTRCAT.C NRSTRCAT.C RESTRCAT.C RFSTRCAT.C RNSTRCAT.C STRCAT.C 
	rm ESTRCHR.C FSTRCHR.C NSTRCHR.C RSTRCHR.C STRCHR.C
	rm EFSTRCMP.C EFSTRCMP.C ENSTRCMP.C ERSTRCMP.C FESTRCMP.C FFSTRCMP.C FNSTRCMP.C FRSTRCMP.C STRCMP.C 
	rm NESTRCMP.C NFSTRCMP.C NNSTRCMP.C NRSTRCMP.C RESTRCMP.C RFSTRCMP.C RNSTRCMP.C RRSTRCMP.C 
	rm EESTRCPY.C EFSTRCPY.C ENSTRCPY.C ERSTRCPY.C FESTRCPY.C FFSTRCPY.C FNSTRCPY.C FRSTRCPY.C 
	rm NESTRCPY.C NFSTRCPY.C NNSTRCPY.C NRSTRCPY.C RESTRCPY.C RFSTRCPY.C RNSTRCPY.C STRCPY.C 
	rm EESTRCSPN.C EFSTRCSPN.C ENSTRCSPN.C ERSTRCSPN.C FESTRCSPN.C FFSTRCSPN.C FNSTRCSPN.C FRSTRCSPN.C STRCSPN.C 
	rm NESTRCSPN.C NFSTRCSPN.C NNSTRCSPN.C NRSTRCSPN.C RESTRCSPN.C RFSTRCSPN.C RNSTRCSPN.C RRSTRCSPN.C 
	rm ESTRLEN.C FSTRLEN.C NSTRLEN.C RSTRLEN.C STRLEN.C 
	rm EESTRNCAT.C EFSTRNCAT.C ENSTRNCAT.C ERSTRNCAT.C FESTRNCAT.C FFSTRNCAT.C FNSTRNCAT.C FRSTRNCAT.C 
	rm NESTRNCAT.C NFSTRNCAT.C NNSTRNCAT.C NRSTRNCAT.C RESTRNCAT.C RFSTRNCAT.C RNSTRNCAT.C STRNCAT.C 
	rm EESTRNCMP.C EFSTRNCMP.C ENSTRNCMP.C ERSTRNCMP.C FESTRNCMP.C FFSTRNCMP.C FNSTRNCMP.C FRSTRNCMP.C STRNCMP.C 
	rm NESTRNCMP.C NFSTRNCMP.C NNSTRNCMP.C NRSTRNCMP.C RESTRNCMP.C RFSTRNCMP.C RNSTRNCMP.C RRSTRNCMP.C 
	rm EESTRNCPY.C EFSTRNCPY.C ENSTRNCPY.C ERSTRNCPY.C FESTRNCPY.C FFSTRNCPY.C FNSTRNCPY.C FRSTRNCPY.C 
	rm NESTRNCPY.C NFSTRNCPY.C NNSTRNCPY.C NRSTRNCPY.C RESTRNCPY.C RFSTRNCPY.C RNSTRNCPY.C STRNCPY.C 
	rm EESTRPBRK.C EFSTRPBRK.C ENSTRPBRK.C ERSTRPBRK.C FESTRPBRK.C FFSTRPBRK.C FNSTRPBRK.C FRSTRPBRK.C STRPBRK.C 
	rm NESTRPBRK.C NFSTRPBRK.C NNSTRPBRK.C NRSTRPBRK.C RESTRPBRK.C RFSTRPBRK.C RNSTRPBRK.C RRSTRPBRK.C 
	rm ESTRRCHR.C FSTRRCHR.C NSTRRCHR.C RSTRRCHR.C STRRCHR.C 
	rm EESTRSPN.C EFSTRSPN.C ENSTRSPN.C ERSTRSPN.C FESTRSPN.C FFSTRSPN.C FNSTRSPN.C FRSTRSPN.C STRSPN.C 
	rm NESTRSPN.C NFSTRSPN.C NNSTRSPN.C NRSTRSPN.C RESTRSPN.C RFSTRSPN.C RNSTRSPN.C RRSTRSPN.C 
	rm EESTRSTR.C EFSTRSTR.C ENSTRSTR.C ERSTRSTR.C FESTRSTR.C FFSTRSTR.C FNSTRSTR.C FRSTRSTR.C STRSTR.C
	rm NESTRSTR.C NFSTRSTR.C NNSTRSTR.C NRSTRSTR.C RESTRSTR.C RFSTRSTR.C RNSTRSTR.C RRSTRSTR.C
	rm ESTRTOD.C FSTRTOD.C NSTRTOD.C STRTOD.C 
	rm EESTRTOK.C EFSTRTOK.C ENSTRTOK.C ERSTRTOK.C FESTRTOK.C FFSTRTOK.C FNSTRTOK.C FRSTRTOK.C 
	rm NESTRTOK.C NFSTRTOK.C NNSTRTOK.C NRSTRTOK.C RESTRTOK.C RFSTRTOK.C RNSTRTOK.C RRSTRTOK.C STRTOK.C 
	rm ESTRTOL.C FSTRTOL.C NSTRTOL.C STRTOL.C 
	rm ESTRTOUL.C FSTRTOUL.C NSTRTOUL.C STRTOUL.C 
	rm FFUPRINT.C FNUPRINT.C FRUPRINT.C NFUPRINT.C NNUPRINT.C NRUPRINT.C UPRINT.C 
	rm EUPRINT.C FUPRINT.C NUPRINT.C RUPRINT.C
	rm EUPSCAN.C FUPSCAN.C NUPSCAN.C RUPSCAN.C UPSCAN.C 
	rm EEUSCAN.C EFUSCAN.C ENUSCAN.C ERUSCAN.C FEUSCAN.C FFUSCAN.C FNUSCAN.C FRUSCAN.C 
	rm NEUSCAN.C NFUSCAN.C NNUSCAN.C NRUSCAN.C USCAN.C 
	rm EUSCAN2.C FUSCAN2.C RUSCAN2.C NUSCAN2.C USCAN2.C 
	rm EUSSCAN.C FUSSCAN.C NUSSCAN.C USSCAN.C RUSSCAN.C 
