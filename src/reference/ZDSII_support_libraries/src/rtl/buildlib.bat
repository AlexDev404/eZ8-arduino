
@REM Build the library given as first argument
@REM Expected Enviroment Variables:
@REM    COMMON_C_SRC - file giving C source files common to all libs of given type
@REM    SPECIFIC_C_SRC - file giving C source files specific to given library
@REM    COMMON_ASM_SRC - List of ASM source files common to all libs of given type
@REM    SPECIFIC_ASM_SRC - List of ASM source files specific to given library
@REM
@REM    To keep the temporary files created (.src, .ir*), set KEEPTEMPS to
@REM    the name of a directory to put them in.

@REM The list of C files are themselves files because of the very long list
@REM going into the CRT library

@DEL *.obj

@echo building %1

@SET ALL_SPECIFIC_CFLAGS= %SPECIFIC_CFLAGS% %REVAA_FLAG% %MULTTHREAD_FLAG% %C_SPL_FLAG%
@IF NOT "%KEEPTEMPS%" == "" SET ALL_SPECIFIC_CFLAGS=%ALL_SPECIFIC_CFLAGS% -KEEPASM -KEEPIR1 -KEEPIR2 -SPAWN -LIST -LISTINC
@echo ALL_SPECIFIC CFLAGS: %ALL_SPECIFIC_CFLAGS%

@DEL %1

@SET ALL_ASM_SRC= %COMMON_ASM_SRC% %SPECIFIC_ASM_SRC%

for /f "eol=;" %%i in (%COMMON_C_SRC%) do %CC% %CFLAGS% %ALL_SPECIFIC_CFLAGS% common\%%i
for /f "eol=;" %%i in (%COMMON_C_SRC%) do  %LIB% -warn %1=+%%~ni.obj
for /f "eol=;" %%i in (%SPECIFIC_C_SRC%) do %CC% %CFLAGS% %ALL_SPECIFIC_CFLAGS% common\%%i
for /f "eol=;" %%i in (%SPECIFIC_C_SRC%) do  %LIB% -warn %1=+%%~ni.obj

for %%i in (%ALL_ASM_SRC%) do %ASM% %AFLAGS% %SPECIFIC_AFLAGS% common\%%i 
for %%i in (%ALL_ASM_SRC%) do %LIB% -warn %1=+%%~ni.obj 

@IF "%KEEPTEMPS%" == "" GOTO done
@       MKDIR %KEEPTEMPS%
@       MOVE *.src %KEEPTEMPS%
@       MOVE *.ir* %KEEPTEMPS%
@       MOVE *.lis %KEEPTEMPS%
@       SET KEEPTEMPS=
:done
