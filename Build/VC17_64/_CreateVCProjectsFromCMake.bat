@echo off

set COMPILER_EXT=VC17_64
set QMAKESPEC=%QTDIR%\mkspecs\win32-msvc
set path=%path%;%QTDIR%\bin

rmdir BuildVs
mkdir BuildVs

cd %~dp0\..\..
set ACFDIR_BUILD=%CD%\Acf
set ACFSLNDIR_BUILD=%CD%\AcfSln
set IACFDIR_BUILD=%CD%\IAcf

echo Generating %COMPILER_EXT% ACF projects...

cd Build\VC17_64\BuildVs
cmake ../../CMake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug
cd ..

