@REM --------------------------------------------------------------
@REM  Batch file to run ZDS II and build ZSL driver library for
@REM  Z8 Encore!
@REM 
@REM  ZiLOG, Inc.
@REM --------------------------------------------------------------

@REM ---Setting environment variables------------------------------
@set ZDSPATH=..
@set BINPATH=%ZDSPATH%\bin
@set INCPATH=%ZDSPATH%\include
@set LIBPATH=%ZDSPATH%\lib
@set SRCPATH=%ZDSPATH%\src
@REM ---Setting environment variables------------------------------

@REM ---Building libraries-----------------------------------------
@title Building ZSL1680 libraries...
@echo --Building ZSL1680 libraries...

@REM --Determine the OS type and set a variable accordingly--------
set OSTYPE=DOS
if %OS%!==Windows_NT! set OSTYPE=NT

@call _buildzsl1680.bat

@echo --Creating zsldevinitdummy.obj-------------------------------
@cd boot
@cd common
@..\..\%BINPATH%\ez8asm -quiet -debug -cpu=Z8F2481XN zsldevinitdummy
@copy zsldevinitdummy.obj ..\..\%LIBPATH%\zilog
@del *.lst
@del *.obj
@cd..
@cd..

@del *.obj
@del *.bak

