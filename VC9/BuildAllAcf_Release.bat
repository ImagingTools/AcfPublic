echo off

set ACFDIR="%ACFPUBLICDIR%\Acf"
set ACFSLNDIR="%ACFPUBLICDIR%\AcfSln"
set IACFDIR="%ACFPUBLICDIR%\Iacf"

call "%VS90COMNTOOLS%vsvars32.bat" x86

echo Building ACF in %ACFDIR%
echo Building ACF-Solutions in %ACFSLNDIR%
echo Building IACF in %IACFDIR%

cd %ACFDIR%\Impl\VC9
msbuild AcfAll.sln /p:Configuration=Release

cd %ACFSLNDIR%\Impl\VC9
msbuild AcfSlnAll.sln /p:Configuration=Release

cd %IACFDIR%\Impl\VC9
msbuild IacfAll.sln /p:Configuration=Release

pause
