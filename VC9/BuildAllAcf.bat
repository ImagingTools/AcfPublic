echo off

call "%VS90COMNTOOLS%vsvars32.bat"

set ACFDIR=%ACFPUBLICDIR%\Acf
set ACFSLNDIR=%ACFPUBLICDIR%\AcfSln
set IACFDIR=%ACFPUBLICDIR%\Iacf

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
