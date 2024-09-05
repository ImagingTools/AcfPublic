call "%VS_2019_ROOT%\VC\Auxiliary\Build\vcvars64.bat"
set COMPILER_EXT=VC16_64
echo %QTDIR%
set QMAKESPEC=%QTDIR%\mkspecs\win32-msvc
set path=%path%;%QTDIR%\bin
cd %~dp0\..\..
cd Build\QMake
%QTDIR%\bin\qmake AcfPublicAll.pro
nmake
nmake debug
