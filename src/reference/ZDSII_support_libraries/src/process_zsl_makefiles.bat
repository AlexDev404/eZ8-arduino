@REM ------------------------------------------------------
@REM  Batch file to run ZDS II and build drivers for
@REM  Z8 Encore! ZiLOG Standard Library
@REM 
@REM  ZiLOG, Inc.
@REM ------------------------------------------------------

@REM +--Setting environment variables-----------------------------+
@REM | NOTE: Uncomment the following 'set' commands if            |
@REM |       you are running this batch file separately           |
@REM +------------------------------------------------------------+
@REM @set ZDSPATH=..
@REM @set INCPATH=%ZDSPATH%\include
@REM @set LIBPATH=%ZDSPATH%\lib
@REM @set SRCPATH=%ZDSPATH%\src
@REM ---Setting environment variables------------------------------

@REM -- The debug and the release directories must exist

@rem @mkdir ".\LTD"
@rem @mkdir ".\LYD"
@rem @mkdir ".\STD"
@rem @mkdir ".\SYD"
@rem @mkdir ".\LT"
@rem @mkdir ".\LY"
@rem @mkdir ".\ST"
@rem @mkdir ".\SY"

@REM -- make sure zilog dir under lib exists
@mkdir %LIBPATH%\zilog

@echo --Building ZSL libraries...



@REM ;-------------------------------------------------------------------------
@REM ; Process all Debug builds

@REM ;-------------------------------------------------------------------------
@REM ; zslSTD
@REM ; Model:  Small
@REM ; Frames: Static
@REM ; Debug:  Yes
@cd STD
if %OSTYPE%==NT goto ntOS_1
:win98_1
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslSTD.mak"
goto lab1
:ntOS_1
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslSTD.mak"
:lab1
@cd ..

@REM ;-------------------------------------------------------------------------
@REM ; zslSTFD
@REM ; Model:  Small
@REM ; Frames: Static
@REM ; Debug:  Yes
@cd STD
if %OSTYPE%==NT goto ntOS_1a
:win98_1a
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslSTFD.mak"
goto lab1a
:ntOS_1a
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslSTFD.mak"
:lab1a
@cd ..


@REM ;-------------------------------------------------------------------------
@REM ; zslSYD
@REM ; Model:  Small
@REM ; Frames: Dynamic
@REM ; Debug:  Yes
@cd SYD
if %OSTYPE%==NT goto ntOS_3
:win98_3
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslSYD.mak"
goto lab3
:ntOS_3
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslSYD.mak"
:lab3
@cd ..

@REM ;-------------------------------------------------------------------------
@REM ; zslSYFD
@REM ; Model:  Small
@REM ; Frames: Dynamic
@REM ; Debug:  Yes
@cd SYD
if %OSTYPE%==NT goto ntOS_3a
:win98_3a
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslSYFD.mak"
goto lab3a
:ntOS_3a
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslSYFD.mak"
:lab3a
@cd ..


@REM ;-------------------------------------------------------------------------
@REM ; zslLTD
@REM ; Model:  Large
@REM ; Frames: Static
@REM ; Debug:  Yes
@cd LTD
if %OSTYPE%==NT goto ntOS_5
:win98_5
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslLTD.mak"
goto lab5
:ntOS_5
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslLTD.mak"
:lab5
@cd ..

@REM ;-------------------------------------------------------------------------
@REM ; zslLTFD
@REM ; Model:  Large
@REM ; Frames: Static
@REM ; Debug:  Yes
@cd LTD
if %OSTYPE%==NT goto ntOS_5a
:win98_5a
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslLTFD.mak"
goto lab5a
:ntOS_5a
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslLTFD.mak"
:lab5a
@cd ..

@REM ;-------------------------------------------------------------------------
@REM ; zslLYD
@REM ; Model:  Large
@REM ; Frames: Dynamic
@REM ; Debug:  Yes
@cd LYD
if %OSTYPE%==NT goto ntOS_7
:win98_7
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslLYD.mak"
goto lab7
:ntOS_7
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslLYD.mak"
:lab7
@cd ..


@REM ;-------------------------------------------------------------------------
@REM ; zslLYFD
@REM ; Model:  Large
@REM ; Frames: Dynamic
@REM ; Debug:  Yes
@cd LYD
if %OSTYPE%==NT goto ntOS_7a
:win98_7a
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslLYFD.mak"
goto lab7a
:ntOS_7a
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslLYFD.mak"
:lab7a
@cd ..


@REM ;-------------------------------------------------------------------------
@REM ; Process all Release builds

@REM ;-------------------------------------------------------------------------
@REM ; zslST
@REM ; Model:  Small
@REM ; Frames: Static
@REM ; Debug:  No
@cd ST
if %OSTYPE%==NT goto ntOS_2
:win98_2
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslST.mak"
goto lab2
:ntOS_2
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslST.mak"
:lab2
@cd ..

@REM ;-------------------------------------------------------------------------
@REM ; zslSTF
@REM ; Model:  Small
@REM ; Frames: Static
@REM ; Debug:  No
@cd ST
if %OSTYPE%==NT goto ntOS_2a
:win98_2a
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslSTF.mak"
goto lab2a
:ntOS_2a
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslSTF.mak"
:lab2a
@cd ..

@REM ;-------------------------------------------------------------------------
@REM ; zslSY
@REM ; Model:  Small
@REM ; Frames: Dynamic
@REM ; Debug:  No
@cd SY
if %OSTYPE%==NT goto ntOS_4
:win98_4
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslSY.mak"
goto lab4
:ntOS_4
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslSY.mak"
:lab4
@cd ..

@REM ;-------------------------------------------------------------------------
@REM ; zslSYF
@REM ; Model:  Small
@REM ; Frames: Dynamic
@REM ; Debug:  No
@cd SY
if %OSTYPE%==NT goto ntOS_4a
:win98_4a
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslSYF.mak"
goto lab4a
:ntOS_4a
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslSYF.mak"
:lab4a
@cd ..

@REM ;-------------------------------------------------------------------------
@REM ; zslLT
@REM ; Model:  Large
@REM ; Frames: Static
@REM ; Debug:  No
@cd LT
if %OSTYPE%==NT goto ntOS_6
:win98_6
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslLT.mak"
goto lab6
:ntOS_6
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslLT.mak"
:lab6
@cd ..


@REM ;-------------------------------------------------------------------------
@REM ; zslLTF
@REM ; Model:  Large
@REM ; Frames: Static
@REM ; Debug:  No
@cd LT
if %OSTYPE%==NT goto ntOS_6a
:win98_6a
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslLTF.mak"
goto lab6a
:ntOS_6a
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslLTF.mak"
:lab6a
@cd ..

@REM ;-------------------------------------------------------------------------
@REM ; zslLY
@REM ; Model:  Large
@REM ; Frames: Dynamic
@REM ; Debug:  No
@cd LY
if %OSTYPE%==NT goto ntOS_8
:win98_8
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslLY.mak"
goto lab8
:ntOS_8
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslLY.mak"
:lab8
@cd ..

@REM ;-------------------------------------------------------------------------
@REM ; zslLYF
@REM ; Model:  Large
@REM ; Frames: Dynamic
@REM ; Debug:  No
@cd LY
if %OSTYPE%==NT goto ntOS_8a
:win98_8a
start /MIN /WAIT "%ZDSPATH%\..\bin\make.exe" -k rebuildall -f "zslLYF.mak"
goto lab8a
:ntOS_8a
start "dummy" /MIN /WAIT %ZDSPATH%\..\bin\make -k rebuildall -f "zslLYF.mak"
:lab8a
@cd ..



@REM ;-------------------------------------------------------------------------
@REM ; Copy library files to the common repository
@echo Copying the libraries...
@del *.libcmd
@copy *.lib %LIBPATH%\zilog



@REM ;-------------------------------------------------------------------------
@REM ; Cleanup the directories
if %OSTYPE%==NT goto ntOS_CleanUp

:win98_CleanUp
@deltree /Y LTD
@deltree /Y LYD
@deltree /Y STD
@deltree /Y SYD
@deltree /Y LT
@deltree /Y LY
@deltree /Y ST
@deltree /Y SY
@del *.log
@del *.lib
@del *.bak
@del *.wsp
@del *.asm
goto done

:ntOS_CleanUp
@rmdir LTD /S /Q
@rmdir LYD /S /Q
@rmdir STD /S /Q
@rmdir SYD /S /Q
@rmdir LT /S /Q
@rmdir LY /S /Q
@rmdir ST /S /Q
@rmdir SY /S /Q
@del *.log /Q
@del *.lib /Q
@del *.bak /Q
@del *.wsp /Q
@del *.asm /Q

:done

