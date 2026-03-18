@REM --------------------------------------------------------------
@REM  Batch file to run ZDS II and build ZSL driver library for
@REM  Z8 Encore!
@REM 
@REM  ZiLOG, Inc.
@REM --------------------------------------------------------------

@call gen_zsl_project.bat
@call gen_zsl_makefiles.bat
@call process_zsl_makefiles.bat

@del *.lst
@del *.obj
