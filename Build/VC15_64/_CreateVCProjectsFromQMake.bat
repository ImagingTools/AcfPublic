@echo off

set COMPILER_EXT=VC15_64
set QMAKESPEC=%QTDIR%\mkspecs\win32-msvc
set path=%path%;%QTDIR%\bin
cd %~dp0\..\..
set ACFDIR_BUILD=%CD%\Acf
set ACFSLNDIR_BUILD=%CD%\AcfSln
set IACFDIR_BUILD=%CD%\IAcf

echo Generating %COMPILER_EXT% ACF projects...
cd Build\QMake
%QTDIR%\bin\qmake AcfPublicAll.pro -recursive -tp vc

cd %~dp0\..\..\Acf\Docs\Tutorial\Build\QMake

echo Generating %COMPILER_EXT% ACF projects...
cd Build\QMake
%QTDIR%\bin\qmake -recursive -tp vc

cd %~dp0\..\..

call Acf\Config\QMake\CopyVCProjToSubdir.js %COMPILER_EXT% -replace%QTDIR%\=$(QTDIR)\ -replace%CD%\=$(RelativePath)\


cd %~dp0\
