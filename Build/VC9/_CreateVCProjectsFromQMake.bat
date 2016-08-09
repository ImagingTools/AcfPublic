@echo off

set QTDIR=%QTDIR_32%
set COMPILER_EXT=VC9
set QMAKESPEC=%QTDIR%\mkspecs\win32-msvc2008
set path=%path%;%QTDIR%\bin
set ACFDIR_BUILD=..\..\..\..\Acf

cd %~dp0\..\..

echo Generating %COMPILER_EXT% projects...
cd Build\QMake
%QTDIR%\bin\qmake -recursive -tp vc
cd %~dp0\..\..

call Acf\Config\QMake\CopyVCProjToSubdir.js %COMPILER_EXT% -replace%QTDIR%=$(QTDIR) -replace%ACF_TOOLS_BIN%\=$(ACF_TOOLS_BIN)\ -replace%CD%\=$(RelativePath)\ -qt_verWin32=QT_VC9_32


cd %~dp0\
