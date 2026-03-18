@REM --------------------------------------------------------------
@REM  Batch file to run ZDS II and build ZSL driver library for
@REM  Z8 Encore! Flash Motor Controllers.
@REM 
@REM  ZiLOG, Inc.
@REM --------------------------------------------------------------

@call gen_zslmc_project.bat
@call gen_zslmc_makefiles.bat
@call process_zslmc_makefiles.bat

@del *.lst
@del *.obj
