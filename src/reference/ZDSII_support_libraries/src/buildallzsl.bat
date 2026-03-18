@REM -----------------------------------------------------------------
@REM  Batch file to run ZDS II and build all ZSL driver libraries for
@REM  Z8 Encore! and Z8 Encore! Flash Motor Controllers.
@REM 
@REM  ZiLOG, Inc.
@REM -----------------------------------------------------------------

@REM ---Setting environment variables------------------------------
@set ZDSPATH=..
@set BINPATH=%ZDSPATH%\bin
@set INCPATH=%ZDSPATH%\include
@set LIBPATH=%ZDSPATH%\lib
@set SRCPATH=%ZDSPATH%\src
@REM ---Setting environment variables------------------------------

@REM ---Building libraries-----------------------------------------
@title Building all ZSL libraries...
@echo --Building all ZSL libraries...

@REM --Determine the OS type and set a variable accordingly--------
set OSTYPE=DOS
if %OS%!==Windows_NT! set OSTYPE=NT

@call _buildzsl.bat
@call _buildzslmc.bat

@echo --Creating zsldevinitdummy.obj-------------------------------
@cd boot
@cd common
@..\..\%BINPATH%\ez8asm -quiet -debug -cpu=Z8F6423 zsldevinitdummy
@del *.lib
@..\..\%BINPATH%\ez8lib -warn zsldevinitdummy.lib=+zsldevinitdummy.obj
@copy zsldevinitdummy.obj ..\..\%LIBPATH%\zilog
@copy zsldevinitdummy.lib ..\..\%LIBPATH%\zilog
@del *.lst
@del *.obj
@del *.lib

@cd..
@cd..

@del *.obj
@del *.bak





@REM ---Building libraries-----------------------------------------
@title Building all ZSL1680 libraries...
@echo --Building all ZSL1680 libraries...

@REM --Determine the OS type and set a variable accordingly--------
set OSTYPE=DOS
if %OS%!==Windows_NT! set OSTYPE=NT

@call _buildzsl1680.bat

@echo --Creating zsldevinitdummy.obj-------------------------------
@cd boot
@cd common
@..\..\%BINPATH%\ez8asm -quiet -debug -cpu=Z8F2481XN zsldevinitdummy
@del *.lib
@..\..\%BINPATH%\ez8lib -warn zsldevinitdummy.lib=+zsldevinitdummy.obj
@copy zsldevinitdummy.obj ..\..\%LIBPATH%\zilog
@copy zsldevinitdummy.lib ..\..\%LIBPATH%\zilog
@del *.lst
@del *.obj
@del *.lib
@cd..
@cd..

@del *.obj
@del *.bak

