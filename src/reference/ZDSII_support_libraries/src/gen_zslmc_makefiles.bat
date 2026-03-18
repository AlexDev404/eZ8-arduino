@REM ----------------------------------------------------------
@REM  Batch file to run ZDS II and generate makes files for
@REM  Z8 Encore! Flash Motor Controller ZiLOG Standard Library
@REM 
@REM  ZiLOG, Inc.
@REM ----------------------------------------------------------

@REM +--Setting environment variables-------------------+
@REM | NOTE: Uncomment the following 'set' commands if  |
@REM |       you are running this batch file separately |
@REM +--------------------------------------------------+
@REM @set ZDSPATH=..
@REM @set BINPATH=%ZDSPATH%\bin
@REM ---Setting environment variables--------------------

@REM -- The debug and the release directories must exist
@mkdir ".\LTD"
@mkdir ".\LYD"
@mkdir ".\STD"
@mkdir ".\SYD"
@mkdir ".\LT"
@mkdir ".\LY"
@mkdir ".\ST"
@mkdir ".\SY"

@echo Generating make files...
if %OSTYPE%==NT goto ntOS
:win98
@start /MIN /WAIT "%BINPATH%\zds2ide.exe" @gen_zslmc_makefiles.scr
goto exit1
:ntOS
@start "dummy" /MIN /WAIT %BINPATH%\zds2ide @gen_zslmc_makefiles.scr
:exit1
