REM ------------------------------------------
REM  batch file to build all runtime libraries 
REM 
REM  Zilog, Inc.
REM ------------------------------------------

@SET BIN=..\..\bin
@SET CC=@%BIN%\eZ8cc
@SET ASM=@%BIN%\eZ8asm
@SET LINK=@%BIN%\eZ8link
@SET LIB=%BIN%\eZ8lib

@SET INCSTD=..\..\include\std
@SET INCZLG=..\..\include\zilog

@SET LIBDIR=..\..\lib
@SET SRCPATH=..\..\src

@REM ---make sure dir exists
@mkdir %LIBDIR%
@mkdir %LIBDIR%\std
@mkdir %LIBDIR%\zilog

@REM -- Set to 1 to save temporary files produced by the compiler
SET SAVE_TEMPS=0
@REM -- Set to 1 to save .lst files for startup modules
SET SAVELISTFILES=0
IF "%SAVELISTFILES%" == "1" MKDIR listsave

REM -- build/copy startup64XX --
@%ASM% -quiet -debug -cpu=Z8F6423 -define:_Z8F6423=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startups
REM  startups.obj is now obsolete  COPY startups.obj %LIBDIR%\zilog
MOVE startups.obj %LIBDIR%\zilog\StartupF64XXS.obj
IF "%SAVELISTFILES%" == "1" COPY Startups.lst listsave\startups.lst
IF "%SAVELISTFILES%" == "1" MOVE Startups.lst listsave\startupsF64XXS.lst

@%ASM% -quiet -debug -cpu=Z8F6423 -define:_Z8F6423=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startupl
REM  startupl.obj is now obsolete  COPY startupl.obj %LIBDIR%\zilog
MOVE startupl.obj %LIBDIR%\zilog\StartupF64XXL.obj
IF "%SAVELISTFILES%" == "1" COPY Startupl.lst listsave\startupl.lst
IF "%SAVELISTFILES%" == "1" MOVE Startupl.lst listsave\startupsF64XXL.lst

REM -- build/copy startup64XXWPageE --
REM
%ASM% -quiet -debug -cpu=Z8F6482XT -define:_Z8F6423=1 -define:HavePageE -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startups
MOVE startups.obj %LIBDIR%\zilog\StartupF64XXWPageES.obj
IF "%SAVELISTFILES%" == "1" MOVE Startups.lst listsave\startupsF64XXWPageES.lst

%ASM% -quiet -debug -cpu=Z8F6482XT -define:_Z8F6423=1 -define:HavePageE -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startupl
MOVE startupl.obj %LIBDIR%\zilog\StartupF64XXWPageEL.obj
IF "%SAVELISTFILES%" == "1" MOVE Startups.lst listsave\startupsF64XXWPageEL.lst

@REM -- build/copy startupF08X --
@REM -- replacement for startupF04A
@REM -- Interrupt vectors upto 0x3C
@REM    Use for XP_8022, XP_F0823, XP_F82A, FMX16100, and ZMOTION series
%ASM% -quiet -debug -cpu=Z8F082A -define:_Z8F082A=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startups
MOVE startups.obj %LIBDIR%\zilog\StartupF08XS.obj
IF "%SAVELISTFILES%" == "1" MOVE startups.lst listsave\StartupF08XS.lst

%ASM% -quiet -debug -cpu=Z8F082A -define:_Z8F082A=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startupl
MOVE startupl.obj %LIBDIR%\zilog\StartupF08XL.obj
IF "%SAVELISTFILES%" == "1" MOVE startupl.lst listsave\StartupF08XL.lst


@REM -- build/copy StartupF083XS --
@REM -- Replacement for startupf01as
@REM -- Interrupt vectors upto 0x3C
@REM -- No initialization of Edata
@REM -- Use for F0830, F083A series and those for which startup F08X could be
@REM -- Used, but having only 256 bytes of ram
%ASM% -quiet -debug -cpu=Z8F083A -define:_Z8F083A=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startups
MOVE startups.obj %LIBDIR%\zilog\StartupF083XS.obj
IF "%SAVELISTFILES%" == "1" MOVE startups.lst listsave\StartupF083XS.lst


@REM -- build/copy startupF1680 --
@REM -- Interrupt vectors upto 0x3C
@REM -- Support for PRAM
@REM -- Use for XP_F1680 series
%ASM% -quiet -debug -cpu=Z8F1680XN -define:_Z8F1680XN=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startups
MOVE startups.obj %LIBDIR%\zilog\StartupF1680S.obj
IF "%SAVELISTFILES%" == "1" MOVE startups.lst listsave\StartupF1680S.lst

%ASM% -quiet -debug -cpu=Z8F1680XN -define:_Z8F1680XN=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startupl
MOVE startupl.obj %LIBDIR%\zilog\StartupF1680L.obj
IF "%SAVELISTFILES%" == "1" MOVE startupl.lst listsave\StartupF1680L.lst

@REM -- build/copy startupF648 --
@REM -- Interrupt vectors upto 0x4A
@REM -- Must build simulator/non-simulator versions to deal with FLLDONE
@REM -- Use for XP_64XX, XP_6482, and XP_F3224 series
%ASM% -quiet -debug -cpu=Z8F6482XT -define:_Z8F6482XT=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startups
MOVE startups.obj %LIBDIR%\zilog\StartupF6482S.obj
IF "%SAVELISTFILES%" == "1" MOVE startups.lst listsave\StartupF6482S.lst

%ASM% -quiet -debug -cpu=Z8F6482XT -define:_Z8F6482XT=1 -define:_SIMULATE=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startups
MOVE startups.obj %LIBDIR%\zilog\StartupF6482SSIM.obj
IF "%SAVELISTFILES%" == "1" MOVE startups.lst listsave\StartupF6482SSIM.lst

%ASM% -quiet -debug -cpu=Z8F6482XT -define:_Z8F6482XT=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startupl
MOVE startupl.obj %LIBDIR%\zilog\StartupF6482L.obj
IF "%SAVELISTFILES%" == "1" MOVE startupl.lst listsave\StartupF6482L.lst

%ASM% -quiet -debug -cpu=Z8F6482XT -define:_Z8F6482XT=1 -define:_SIMULATE=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startupl
MOVE startupl.obj %LIBDIR%\zilog\StartupF6482LSIM.obj
IF "%SAVELISTFILES%" == "1" MOVE startupl.lst listsave\StartupF6482LSIM.lst

@REM -- build/copy StartupF6482WPageE --
@REM -- Interrupt vectors upto 0x4A
@REM -- Initialization of PageE
@REM -- Use for CPUs for which startupF648 would be applicable if application
@REM -- needs to use PageE to program variables.
%ASM% -quiet -debug -cpu=Z8F6482XT -define:_Z8F6482XT=1 -define:HavePageE -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startups
MOVE startups.obj %LIBDIR%\zilog\StartupF6482WPageES.obj
IF "%SAVELISTFILES%" == "1" MOVE startups.lst listsave\StartupF6482WPageES.lst

%ASM% -quiet -debug -cpu=Z8F6482XT -define:_Z8F6482XT=1 -define:HavePageE -define:_SIMULATE=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startups
MOVE startups.obj %LIBDIR%\zilog\StartupF6482WPageESSIM.obj
IF "%SAVELISTFILES%" == "1" MOVE startups.lst listsave\StartupF6482WPageESSIM.lst

%ASM% -quiet -debug -cpu=Z8F6482XT -define:_Z8F6482XT=1 -define:HavePageE -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startupl
MOVE startupl.obj %LIBDIR%\zilog\StartupF6482WPageEL.obj
IF "%SAVELISTFILES%" == "1" MOVE startupl.lst listsave\StartupF6482WPageEL.lst

%ASM% -quiet -debug -cpu=Z8F6482XT -define:_Z8F6482XT=1 -define:HavePageE -define:_SIMULATE=1 -include:%INCSTD% -include:%INCZLG% %SRCPATH%\boot\common\startupl
MOVE startupl.obj %LIBDIR%\zilog\StartupF6482WPageELSIM.obj
IF "%SAVELISTFILES%" == "1" MOVE startupl.lst listsave\StartupF6482WPageELSIM.lst

REM GOTO DONE

REM ** build the libraries **
 
@REM ----------------------------------
@REM    Library naming conventions:
@REM 
@REM     {lib} {chip} {model} {frames} {fastcall} [{D}]
@REM      |      |      |       |         |       +- D if Debug exists
@REM      |      |      |       |         +--------- F for fastcalls
@REM      |      |      |       +------------------- S = static, D = dynamic
@REM      |      |      +--------------------------- S = Small model, L = large
@REM      |      +---------------------------------- revaa/f04a or empty 
@REM      +----------------------------------------- CRT = standard lib, FP = floating point


@REM Common assembly flags

@SET AFLAGS= -genobj -NOigcase -include:%INCSTD% -include:%INCZLG% -list -NOlistmac -name -pagelen:56 -pagewidth:80 -quiet -sdiopt -warn -NOzmasm 

@REM Common c flags

@SET CFLAGS=-quiet -define:__FPLIB__=1 -define:_PG_E_ENABLED -stdinc:"%INCSTD%;%INCZLG%" -asmsw:"-include:%INCSTD% -include:%INCZLG%" -pagee

@SET CFLAGS_DEBUG=-debug -noreduceopt

@SET CFLAGS_NODEBUG=-NOdebug -noreduceopt

@SET AFLAGS_DEBUG=-debug

@SET AFLAGS_NODEBUG=-nodebug

@SET DEFAULT_C_CPU=-define:_Z8F6423 -define:_Z8ENCORE_F642X -cpu:Z8F6423 -asmsw:"-cpu:Z8F6423 -define:_Z8F6423=1 -define:_Z8ENCORE_F642X=1"

@SET DEFAULT_A_CPU=-define:_Z8F6423=1 -define:_Z8ENCORE_F642X=1 -cpu:Z8F6423

@SET COMMON_C_SRC=crt_common_src

@SET COMMON_ASM_SRC=get_freq.asm

@SET Z8F04A_C_CPU=-define:_Z8F042A -define:_Z8ENCORE_F04XA -cpu:Z8F042A -asmsw:"-cpu:Z8F042A -define:_Z8F042A=1 -define:_Z8ENCORE_F04XA=1"

@SET Z8F04A_A_CPU=-define:_Z8F042A=1 -define:_Z8ENCORE_F04XA=1 -cpu:Z8F042A

@SET Z8FMC_C_CPU=-define:_Z8FMC16100 -define:_Z8ENCORE_Z8FMC16100_SERIES -cpu:Z8FMC16100 -asmsw:"-cpu:Z8FMC16100 -define:_Z8FMC16100=1 -define:__Z8ENCORE_Z8FMC16100_SERIES=1"

@SET Z8F1680_C_CPU=-define:_Z8F1680XN -define:_Z8ENCORE_XP_F1680_SERIES_16K -cpu:Z8F1680XN -asmsw:"-cpu:Z8F1680XN -define:_Z8F1680XN=1 -define:_Z8ENCORE_XP_F1680_SERIES_16K=1"

@SET Z8F8PIN_C_CPU=-define:_Z8F042AXB -define:_Z8ENCORE_XP_4K_8PIN_SERIES -cpu:Z8F042AXB -asmsw:"-cpu:Z8F042AXB -define:_Z8F042AXB=1 -define:_Z8ENCORE_XP_4K_8PIN_SERIES=1"

@REM -----------------------------------------------------------------

@echo Building crtss.lib crtrevaass.lib ...

@SET MODEL_C_FLAGS=-model:Small -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=divss.asm ldivss.asm flash.asm sbrkss.asm sbrkls.asm longjmpss.asm setjmpss.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtss
call buildlib crtss.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtrevaass
call buildlib crtrevaass.lib

@SET SPECIFIC_ASM_SRC=divsf.asm ldivssf.asm flashf.asm sbrksf.asm sbrklf.asm longjmpsf.asm setjmpsf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtssf
call buildlib crtssf.lib

@echo Building crtssd.lib crtrevaassd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=divss.asm ldivss.asm flash.asm sbrkss.asm sbrkls.asm longjmpss.asm setjmpss.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtssd
call buildlib crtssd.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtrevaassd
call buildlib crtrevaassd.lib 


@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

@SET SPECIFIC_ASM_SRC=divsf.asm ldivssf.asm flashf.asm sbrksf.asm sbrklf.asm longjmpsf.asm setjmpsf.asm

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtssfd
call buildlib crtssfd.lib

@REM -----------------------------------------------------------------

@echo Building crtf04ass.lib ...

@SET MODEL_C_FLAGS=-model:Small -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F04A_C_CPU% 

@SET SPECIFIC_ASM_SRC=divss.asm ldivss.asm flash.asm sbrkss.asm sbrkls.asm longjmpss.asm setjmpss.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %Z8F04A_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04ass
call buildlib crtf04ass.lib

@SET SPECIFIC_ASM_SRC=divsf.asm ldivssf.asm flashf.asm sbrksf.asm sbrklf.asm longjmpsf.asm setjmpsf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04assf
call buildlib crtf04assf.lib

@echo Building crtf04assd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F04A_C_CPU%

@SET SPECIFIC_ASM_SRC=divss.asm ldivss.asm flash.asm sbrkss.asm sbrkls.asm longjmpss.asm setjmpss.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %Z8F04A_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04assd
call buildlib crtf04assd.lib

@SET SPECIFIC_ASM_SRC=divsf.asm ldivssf.asm flashf.asm sbrksf.asm sbrklf.asm longjmpsf.asm setjmpsf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04assfd
call buildlib crtf04assfd.lib

@REM -----------------------------------------------------------------

@echo Building crtls.lib crtrevaals.lib ...

@SET MODEL_C_FLAGS=-model:Large -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=divls.asm ldivls.asm flash.asm sbrkss.asm sbrkls.asm longjmpls.asm setjmpls.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtls
call buildlib crtls.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtrevaals
call buildlib crtrevaals.lib

@SET SPECIFIC_ASM_SRC=divlf.asm ldivlsf.asm flashf.asm sbrksf.asm sbrklf.asm longjmplf.asm setjmplf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtlsf
call buildlib crtlsf.lib

@echo Building crtlsd.lib crtrevaalsd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=divls.asm ldivls.asm flash.asm sbrkss.asm sbrkls.asm longjmpls.asm setjmpls.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtlsd
call buildlib crtlsd.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtrevaalsd
call buildlib crtrevaalsd.lib

@SET SPECIFIC_ASM_SRC=divlf.asm ldivlsf.asm flashf.asm sbrksf.asm sbrklf.asm longjmplf.asm setjmplf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtlsfd
call buildlib crtlsfd.lib

@REM -----------------------------------------------------------------

@echo Building crtf04als.lib ...

@SET MODEL_C_FLAGS=-model:Large -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F04A_C_CPU% 

@SET SPECIFIC_ASM_SRC=divls.asm ldivls.asm flash.asm sbrkss.asm sbrkls.asm longjmpls.asm setjmpls.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %Z8F04A_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04als
call buildlib crtf04als.lib

@SET SPECIFIC_ASM_SRC=divlf.asm ldivlsf.asm flashf.asm sbrksf.asm sbrklf.asm longjmplf.asm setjmplf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04alsf
call buildlib crtf04alsf.lib

@echo Building crtf04alsd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F04A_C_CPU%

@SET SPECIFIC_ASM_SRC=divls.asm ldivls.asm flash.asm sbrkss.asm sbrkls.asm longjmpls.asm setjmpls.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %Z8F04A_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04alsd
call buildlib crtf04alsd.lib

@SET SPECIFIC_ASM_SRC=divlf.asm ldivlsf.asm flashf.asm sbrksf.asm sbrklf.asm longjmplf.asm setjmplf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04alsfd
call buildlib crtf04alsfd.lib

@REM -----------------------------------------------------------------

@echo Building crtsd.lib crtrevaasd.lib ...

@SET MODEL_C_FLAGS=-model:Small -NOoptlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=divsd.asm ldivsd.asm flash.asm sbrksd.asm sbrkld.asm longjmpsd.asm setjmpsd.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtsd
call buildlib crtsd.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtrevaasd
call buildlib crtrevaasd.lib

@SET SPECIFIC_ASM_SRC=divsf.asm ldivsdf.asm flashf.asm sbrksf.asm sbrklf.asm longjmpsf.asm setjmpsf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtsddf
call buildlib crtsdf.lib

@echo Building crtsdd.lib crtrevaasdd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=divsd.asm ldivsd.asm flash.asm sbrksd.asm sbrkld.asm longjmpsd.asm setjmpsd.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtsdd
call buildlib crtsdd.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtrevaasdd
call buildlib crtrevaasdd.lib

@SET SPECIFIC_ASM_SRC=divsf.asm ldivsdf.asm flashf.asm sbrksf.asm sbrklf.asm longjmpsf.asm setjmpsf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtsdfd
call buildlib crtsdfd.lib

@REM -----------------------------------------------------------------

@echo Building crtf04asd.lib ...

@SET MODEL_C_FLAGS=-model:Small -NOoptlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F04A_C_CPU% 

@SET SPECIFIC_ASM_SRC=divsd.asm ldivsd.asm flash.asm sbrksd.asm sbrkld.asm longjmpsd.asm setjmpsd.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %Z8F04A_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04asd
call buildlib crtf04asd.lib

@SET SPECIFIC_ASM_SRC=divsf.asm ldivsdf.asm flashf.asm sbrksf.asm sbrklf.asm longjmpsf.asm setjmpsf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04asdf
call buildlib crtf04asdf.lib

@echo Building crtf04asdd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F04A_C_CPU%

@SET SPECIFIC_ASM_SRC=divsd.asm ldivsd.asm flash.asm sbrksd.asm sbrkld.asm longjmpsd.asm setjmpsd.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %Z8F04A_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04asdd
call buildlib crtf04asdd.lib

@SET SPECIFIC_ASM_SRC=divsf.asm ldivsdf.asm flashf.asm sbrksf.asm sbrklf.asm longjmpsf.asm setjmpsf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04asdfd
call buildlib crtf04asdfd.lib

@REM -----------------------------------------------------------------

@echo Building crtld.lib crtrevaald.lib ...

@SET MODEL_C_FLAGS=-model:Large -NOoptlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=divld.asm ldivld.asm flash.asm sbrksd.asm sbrkld.asm longjmpld.asm setjmpld.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtld
call buildlib crtld.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtrevaald
call buildlib crtrevaald.lib

@SET SPECIFIC_ASM_SRC=divlf.asm ldivldf.asm flashf.asm sbrksf.asm sbrklf.asm longjmplf.asm setjmplf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtldf
call buildlib crtldf.lib

@echo Building crtldd.lib crtrevaaldd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=divld.asm ldivld.asm flash.asm sbrksd.asm sbrkld.asm longjmpld.asm setjmpld.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtldd
call buildlib crtldd.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtrevaaldd
call buildlib crtrevaaldd.lib

@SET SPECIFIC_ASM_SRC=divlf.asm ldivldf.asm flashf.asm sbrksf.asm sbrklf.asm longjmplf.asm setjmplf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtldfd
call buildlib crtldfd.lib

@REM -----------------------------------------------------------------

@echo Building crtf04ald.lib ...

@SET MODEL_C_FLAGS=-model:Large -NOoptlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F04A_C_CPU% 

@SET SPECIFIC_ASM_SRC=divld.asm ldivld.asm flash.asm sbrksd.asm sbrkld.asm longjmpld.asm setjmpld.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %Z8F04A_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04ald
call buildlib crtf04ald.lib

@SET SPECIFIC_ASM_SRC=divlf.asm ldivldf.asm flashf.asm sbrksf.asm sbrklf.asm longjmplf.asm setjmplf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04aldf
call buildlib crtf04aldf.lib

@echo Building crtf04aldd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F04A_C_CPU%

@SET SPECIFIC_ASM_SRC=divld.asm ldivld.asm flash.asm sbrksd.asm sbrkld.asm longjmpld.asm setjmpld.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %Z8F04A_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04aldd
call buildlib crtf04aldd.lib

@SET SPECIFIC_ASM_SRC=divlf.asm ldivldf.asm flashf.asm sbrksf.asm sbrklf.asm longjmplf.asm setjmplf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=crtf04alfd
call buildlib crtf04aldfd.lib

@REM -----------------------------------------------------------------

@SET COMMON_C_SRC=fp_common_src

@SET COMMON_ASM_SRC=ufltinfo.asm

@REM -----------------------------------------------------------------

@echo Building fpss.lib fprevaass.lib ...

@SET MODEL_C_FLAGS=-model:Small -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC= sqrtf.asm ufltinfoss.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpss
call buildlib fpss.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fprevaass
call buildlib fprevaass.lib

@SET SPECIFIC_ASM_SRC= sqrtff.asm ufltinfosf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpssf
call buildlib fpssf.lib

@echo Building fpssd.lib fprevaassd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC= sqrtf.asm ufltinfoss.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpssd
call buildlib fpssd.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fprevaassd
call buildlib fprevaassd.lib

@SET SPECIFIC_ASM_SRC= sqrtff.asm ufltinfosf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpssfd
call buildlib fpssfd.lib

@REM -----------------------------------------------------------------

@echo Building fpls.lib fprevaals.lib ...

@SET MODEL_C_FLAGS=-model:Large -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=sqrtf.asm ufltinfols.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpls
call buildlib fpls.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fprevaals
call buildlib fprevaals.lib

@SET SPECIFIC_ASM_SRC=sqrtff.asm ufltinfolf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fplsf
call buildlib fplsf.lib

@echo Building fplsd.lib fprevaalsd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=sqrtf.asm ufltinfols.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpcall buildlib fplsf.lib

@echo Building fplsd.lib fprevaalsd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=sqrtf.asm ufltinfols.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpcall buildlib fplsf.lib

@echo Building fplsd.lib fprevaalsd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=sqrtf.asm ufltinfols.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fplsd
call buildlib fplsd.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fprevaald
call buildlib fprevaalsd.lib

@SET SPECIFIC_ASM_SRC=sqrtff.asm ufltinfolf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fplsfd
call buildlib fplsfd.lib

@REM -----------------------------------------------------------------

@echo Building fpsd.lib fprevaasd.lib ...

@SET MODEL_C_FLAGS=-model:Small -NOoptlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=sqrtf.asm ufltinfosd.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpsd
call buildlib fpsd.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fprevaasd
call buildlib fprevaasd.lib

@SET SPECIFIC_ASM_SRC=sqrtff.asm ufltinfosf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpsdf
call buildlib fpsdf.lib

@echo Building fpsdd.lib fprevaasdd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=sqrtf.asm ufltinfosd.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpsdd
call buildlib fpsdd.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fprevaasdd
call buildlib fprevaasdd.lib

@SET SPECIFIC_ASM_SRC=sqrtff.asm ufltinfosf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpsdfd
call buildlib fpsdfd.lib

@REM -----------------------------------------------------------------

@echo Building fpld.lib fprevaald.lib ...

@SET MODEL_C_FLAGS=-model:Large -NOoptlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=sqrtf.asm ufltinfold.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpld
call buildlib fpld.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fprevaald
call buildlib fprevaald.lib

@SET SPECIFIC_ASM_SRC=sqrtff.asm ufltinfolf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpldf
call buildlib fpldf.lib

@echo Building fpldd.lib fprevaaldd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=sqrtf.asm ufltinfold.asm

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpldd
call buildlib fpldd.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fprevaaldd
call buildlib fprevaaldd.lib

@SET SPECIFIC_ASM_SRC=sqrtff.asm ufltinfolf.asm

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=fpldfd
call buildlib fpldfd.lib

@REM -----------------------------------------------------------------

@SET COMMON_C_SRC=  help_common_src

@SET COMMON_ASM_SRC= fpadd.asm fpcmp.asm fpdiv.asm fpftol.asm fpltof.asm fpmul.asm fppack.asm fpsub.asm fpultof.asm fpupop1.asm fpupop2.asm frame.asm framer.asm iframer.asm sbdiv.asm sldiv.asm swdiv.asm ubdiv.asm ubmul.asm ucase.asm uacase.asm ubcase.asm uwcase.asm ucasec.asm ulcase.asm uldiv.asm ulmul.asm ulmulc.asm uwdiv.asm uwmul.asm vect04.asm vect06.asm vect08.asm vect0a.asm vect0c.asm vect0e.asm vect10.asm vect12.asm vect14.asm vect16.asm vect18.asm vect1a.asm vect1c.asm vect1e.asm vect20.asm vect22.asm vect24.asm vect26.asm vect28.asm vect2a.asm vect2c.asm vect2e.asm vect30.asm vect32.asm vect34.asm vect36.asm vect38.asm vect3a.asm vect3c.asm vect3e.asm vect40.asm vect42.asm vect44.asm vect46.asm vect48.asm vect4a.asm lincr.asm ldecr.asm iincr.asm idecr.asm ldxl.asm cpxl.asm cpxlz.asm ldxlr0.asm ldxlr4.asm stxlr0.asm stxlr4.asm ldlr0.asm ldlr4.asm stlr0.asm stlr4.asm
 
@REM -----------------------------------------------------------------

@echo Building chelps.lib chelprevaas.lib ...

@SET MODEL_C_FLAGS=-model:Small -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=chelps
call buildlib chelps.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=chelprevaas
call buildlib chelprevaas.lib

@echo Building chelpsd.lib chelprevaasd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=chelpsd
call buildlib chelpsd.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=chelprevaasd
call buildlib chelprevaasd.lib

@REM -----------------------------------------------------------------

@echo Building chelpl.lib chelprevaal.lib ...

@SET MODEL_C_FLAGS=-model:Large -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=chelpl
call buildlib chelpl.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=chelprevaal
call buildlib chelprevaal.lib

@echo Building chelpld.lib chelprevaald.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=chelpld
call buildlib chelpld.lib

@SET REVAA_FLAG=-revaa -define:__REVAA=1

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=chelprevaald
call buildlib chelprevaald.lib

@REM -----------------------------------------------------------------

@SET COMMON_C_SRC= 
 
@SET COMMON_ASM_SRC=a_fpadd.asm a_fpcmp.asm a_fpdiv.asm a_fpftol.asm a_fpltof.asm a_fpmul.asm a_fppack.asm a_fpsub.asm a_fpultof.asm a_fpupop1.asm a_fpupop2.asm a_frame.asm a_framer.asm a_iframer.asm a_sbdiv.asm a_sldiv.asm a_swdiv.asm  a_ubdiv.asm a_ubmul.asm a_ucase.asm a_uacase.asm a_ubcase.asm a_uwcase.asm a_ucasec.asm a_ulcase.asm a_uldiv.asm a_ulmul.asm a_ulmulc.asm a_uwdiv.asm a_uwmul.asm a_lincr.asm a_ldecr.asm a_iincr.asm a_idecr.asm a_ldxl.asm a_cpxl.asm a_cpxlz.asm a_ldxlr0.asm a_ldxlr4.asm a_stxlr0.asm a_stxlr4.asm a_ldlr0.asm a_ldlr4.asm a_stlr0.asm a_stlr4.asm
 
@REM -----------------------------------------------------------------

@echo Building pchelp.lib ...

@SET MODEL_C_FLAGS=-model:Small -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

IF "SAVE_TEMPS" == "1" SET KEEPTEMPS=pchelp
call buildlib pchelp.lib
@echo Building pchelpd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

SET KEEPTEMPS=pchelpd
call buildlib pchelpd.lib

@REM -----------------------------------------------------------------

@SET COMMON_C_SRC= 

@SET COMMON_ASM_SRC=fpdumyl.asm a_fpdumy.asm
 
@REM -----------------------------------------------------------------

@echo Building fpdumyl.lib ...

@SET MODEL_C_FLAGS=-model:Small -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib fpdumyl.lib

@echo Building fpdumyld.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

call buildlib fpdumyld.lib

@REM -----------------------------------------------------------------

@SET COMMON_C_SRC= 

@SET COMMON_ASM_SRC=fpdumys.asm a_fpdumy.asm
 
@REM -----------------------------------------------------------------

@echo Building fpdumys.lib ...

@SET MODEL_C_FLAGS=-model:Small -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib fpdumys.lib

@echo Building fpdumysd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

call buildlib fpdumysd.lib

@REM -----------------------------------------------------------------
 
@SET COMMON_C_SRC= csio_common_src

@SET COMMON_ASM_SRC=

@REM -----------------------------------------------------------------

@echo Building csioss.lib csiofmcss.lib csiof1680ss.lib csiof8pinss.lib csiorevaass.lib ...

@SET MODEL_C_FLAGS=-model:Small -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csioss.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiossf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8FMC_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiofmcss.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiofmcssf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F1680_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof1680ss.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof1680ssf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F8PIN_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof8pinss.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof8pinssf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET REVAA_FLAG=-revaa -define:__REVAA=1

@SET C_SPL_FLAG=

call buildlib csiorevaass.lib

@echo Building csiossd.lib csiofmcssd.lib csiof1680ssd.lib csiof8pinssd.lib csiorevaassd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiossd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiossfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8FMC_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiofmcssd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiofmcssfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F1680_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof1680ssd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof1680ssfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F8PIN_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof8pinssd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof8pinssfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET REVAA_FLAG=-revaa -define:__REVAA=1

@SET C_SPL_FLAG=

call buildlib csiorevaassd.lib

@REM -----------------------------------------------------------------

@echo Building csiols.lib csiofmcls.lib csiof1680ls.lib csiof8pinls.lib csiorevaals.lib ...

@SET MODEL_C_FLAGS=-model:Large -optlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiols.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiolsf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8FMC_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiofmcls.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiofmclsf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F1680_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof1680ls.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof1680lsf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F8PIN_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof8pinls.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof8pinlsf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET REVAA_FLAG=-revaa -define:__REVAA=1

@SET C_SPL_FLAG=

call buildlib csiorevaals.lib

@echo Building csiolsd.lib csiofmclsd.lib csiof1680lsd.lib csiof8pinlsd.lib csiorevaalsd.lib ...
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiolsd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiolsfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8FMC_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiofmclsd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiofmclsfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F1680_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof1680lsd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof1680lsfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F8PIN_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof8pinlsd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof8pinlsfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET REVAA_FLAG=-revaa -define:__REVAA=1

@SET C_SPL_FLAG=

call buildlib csiorevaalsd.lib

@REM -----------------------------------------------------------------

@echo Building csiosd.lib csiofmcsd.lib csiof1680sd.lib csiof8pinsd.lib csiorevaasd.lib ....

@SET MODEL_C_FLAGS=-model:Small -NOoptlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiosd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiosdf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8FMC_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiofmcsd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiofmcsdf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F1680_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof1680sd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof1680sdf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F8PIN_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof8pinsd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof8pinsdf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET REVAA_FLAG=-revaa -define:__REVAA=1

@SET C_SPL_FLAG=

call buildlib csiorevaasd.lib

@echo Building csiosdd.lib csiofmcsdd.lib csiof1680sdd.lib csiof8pinsdd.lib csiorevaasdd.lib ....
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiosdd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiosdfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8FMC_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiofmcsdd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiofmcsdfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F1680_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof1680sdd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof1680sdfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F8PIN_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof8pinsdd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof8pinsdfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET REVAA_FLAG=-revaa -define:__REVAA=1

@SET C_SPL_FLAG=

call buildlib csiorevaasdd.lib

@REM -----------------------------------------------------------------

@echo Building csiold.lib csiofmcld.lib csiof1680ld.lib csiof8pinld.lib csiorevaald.lib ....

@SET MODEL_C_FLAGS=-model:Large -NOoptlink

@SET SPECIFIC_C_SRC=

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_ASM_SRC=

@SET SPECIFIC_AFLAGS=%AFLAGS_NODEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiold.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csioldf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8FMC_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiofmcld.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiofmcldf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F1680_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof1680ld.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof1680ldf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %Z8F8PIN_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof8pinld.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof8pinldf.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_NODEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET REVAA_FLAG=-revaa -define:__REVAA=1

@SET C_SPL_FLAG=

call buildlib csiorevaald.lib

@echo Building csioldd.lib csiofmcldd.lib csiof1680ldd.lib csiof8pinldd.lib csiorevaaldd.lib ....
 
@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET SPECIFIC_AFLAGS=%AFLAGS_DEBUG% %DEFAULT_A_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csioldd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csioldfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8FMC_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiofmcldd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiofmcldfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F1680_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof1680ldd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof1680ldfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %Z8F8PIN_C_CPU%

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=

call buildlib csiof8pinldd.lib

@SET REVAA_FLAG=-norevaa

@SET C_SPL_FLAG=-fastcall

call buildlib csiof8pinldfd.lib

@SET SPECIFIC_CFLAGS=%CFLAGS_DEBUG% %MODEL_C_FLAGS% %DEFAULT_C_CPU%

@SET REVAA_FLAG=-revaa -define:__REVAA=1

@SET C_SPL_FLAG=

call buildlib csiorevaaldd.lib

@REM -----------------------------------------------------------------

REM -- copy the libraries --

copy csio*.lib %LIBDIR%\zilog
del csio*.lib

copy *.lib %LIBDIR%\std
del *.lib

@REM :DONE
REM ** cleanup intermediate files **

del *.obj
del *.wsp
del *.lst
del *.bak
del *.ir*

IF "%SAVELISTFILES%" == "1" (
   MOVE listsave\* .
   RMDIR listsave
)
