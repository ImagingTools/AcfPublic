echo off

call "%VS90COMNTOOLS%vsvars32.bat" x86_amd64

echo Building ACF
cd ..\Acf\Impl\VC9
vcbuild AcfAll.sln $All

echo Building ACF-Solutions
cd ..\..\..\AcfSln\Impl\VC9
vcbuild AcfSlnAll.sln $All

echo Building IACF
cd ..\..\..\Iacf\Impl\VC9
vcbuild IacfAll.sln $All

pause
