#  This makefile builds the lists of files that go into the crt libraries:
#
#
#       fp_common_src  -  files that go into fp library

#  Get the list of files to go into the crt libs
#
# List of unadorned source files
U_SRC= abort.c abs.c atos.c \
       clr_print_fmt.c \
       errno.c \
       flt_data.c format.c fprint_send.c \
       getchar.c \
       isalnum.c isalpha.c iscntrl.c isdigit.c isgraph.c islower.c isprint.c \
       ispunct.c isspace.c isupper.c isxdigit.c \
       labs.c \
       maptab.c modf.c \
       print_ctrl.c print_globals.c print_putch.c print_putnearstring.c \
       print_putfarstring.c  print_putromstring.c print_putromstring0.c \
       print_putstring.c print_send.c putchar.c \
       rand.c \
       sabs.c satan.c scan_globals.c srand.c \
       tolower.c toupper.c \
       ultoa.c ureverse.c uscan_state.c uscan_put.c ustoa.c uultoa.c uustoa.c

# CRT functions that get pageE/far/near versions, one e, f, or n prefix
EFN_SRC= atof.c atoi.c atol.c \
	calloc.c \
	free.c \
	gets.c \
	itod.c \
	malloc.c memset.c \
	qsort.c \
	realloc.c \
	strtod.c strtol.c strtoul.c

# CRT functions that get pageE/far/near/rom versions, one e, f, n, or r prefix
EFNR_SRC= memchr.c \
	 printf.c puts.c putsNOnl.c \
	 scanf.c strchr.c strrchr.c strlen.c \
	 uprint.c upscan.c uscan2.c usscan.c \
	 vprintf.c

# CRT functions that get pageE/far/near/rom versions, one e, f, or n then one e, f, n, or r prefix
EFN_EFNR_SRC= bsearch.c \
	    sprintf.c sscanf.c strcat.c strcpy.c strncat.c strncpy.c strtok.c \
	    uscan.c \
	    vsprintf.c

# CRT functions that get pageE/far/near/rom versions, two e, f, n, or r prefixes
EFNR_EFNR_SRC= memcmp.c memcpy.c memmove.c \
	     strcmp.c strcspn.c strncmp.c strpbrk.c strspn.c strstr.c

#  List of files to go into the fp libs
FP_SRC= acos.c asin.c atan.c atan2.c \
	ceil.c cos.c cosh.c \
	exp.c \
	fabs.c fatof.c floor.c fmod.c \
	modf.c fmodf.c fpdata.c frexp.c ffrexp.c \
	ldexp.c log.c log10.c \
	nmodf.c \
	nfrexp.c \
	pow.c \
	satan.c sin.c sinh.c sinus.c sqrt.c \
	tan.c tanh.c \
	udtof.c udtog.c ufltrnd.c uultoa.c \
	xcoef.c

#  List of files to go into the help libs
HELP_SRC=  flash1.c flash2.c \
	   intrp.c

#  List of files to go into the csio libs
CSIO_SRC= csio.c \
	  getch.c \
	  kbhit.c \
	  putch.c

all : crt_common_src fp_common_src help_common_src csio_common_src

crt_common_src : buildrtl.mak
	rm -f $@
	echo '; C Source Files For CRT library' >> $@
	echo '; This file is "made"; do not edit directly' >> $@
	echo '; Edit buildrtl.mak and run make' >> $@
	for f in $(U_SRC) $(EFN_SRC) $(EFNR_SRC) $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo $$f ; done >> $@
	for f in $(EFN_SRC) $(EFNR_SRC) ; do echo e$$f; done >> $@
	for f in $(EFN_SRC) $(EFNR_SRC) ; do echo f$$f; done >> $@
	for f in $(EFN_SRC) $(EFNR_SRC) ; do echo n$$f; done >> $@
	for f in $(EFNR_SRC) ; do echo r$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo ee$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo ef$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo en$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo er$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo fe$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo ff$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo fn$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo fr$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo ne$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo nf$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo nn$$f; done >> $@
	for f in $(EFN_EFNR_SRC) $(EFNR_EFNR_SRC) ; do echo nr$$f; done >> $@
	for f in $(EFNR_EFNR_SRC) ; do echo re$$f; done >> $@
	for f in $(EFNR_EFNR_SRC) ; do echo rf$$f; done >> $@
	for f in $(EFNR_EFNR_SRC) ; do echo rn$$f; done >> $@
	for f in $(EFNR_EFNR_SRC) ; do echo rr$$f; done >> $@

fp_common_src : buildrtl.mak
	rm -f $@
	echo '; Floating point library C Source Files' >> $@
	echo '; This file is "made"; do not edit directly' >> $@
	echo '; Edit buildrtl.mak and run make' >> $@
	for f in $(FP_SRC) ; do echo $$f ; done >> $@


help_common_src : buildrtl.mak
	rm -f $@
	echo '; Floating point library C Source Files' >> $@
	echo '; This file is "made"; do not edit directly' >> $@
	echo '; Edit buildrtl.mak and run make' >> $@
	for f in $(HELP_SRC) ; do echo $$f ; done >> $@


csio_common_src : buildrtl.mak
	rm -f $@
	echo '; Floating point library C Source Files' >> $@
	echo '; This file is "made"; do not edit directly' >> $@
	echo '; Edit buildrtl.mak and run make' >> $@
	for f in $(CSIO_SRC) ; do echo $$f ; done >> $@

