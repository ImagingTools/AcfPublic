@echo off

set QTDIR=%QTDIR_64%
set COMPILER_EXT=VC12_64
set QMAKESPEC=%QTDIR%\mkspecs\win32-msvc2013
set path=%path%;%QTDIR%\bin
cd %~dp0\..\..
set ACFDIR_BUILD=%CD%\Acf

echo Generating %COMPILER_EXT% ACF projects...
cd Build\QMake
%QTDIR%\bin\qmake -recursive -tp vc

cd %~dp0\..\..\Acf\Docs\Tutorial\Build\QMake

echo Generating %COMPILER_EXT% ACF projects...
cd Build\QMake
%QTDIR%\bin\qmake -recursive -tp vc

cd %~dp0\..\..

call Acf\Config\QMake\CopyVCProjToSubdir.js %COMPILER_EXT% -replace%QTDIR%\=$(QTDIR)\ -replace%CD%\=$(RelativePath)\


cd %~dp0\
