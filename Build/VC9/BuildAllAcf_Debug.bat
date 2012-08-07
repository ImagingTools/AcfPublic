echo off

set ACFDIR="%ACFPUBLICDIR%\Acf"
set ACFSLNDIR="%ACFPUBLICDIR%\AcfSln"
set IACFDIR="%ACFPUBLICDIR%\Iacf"

call "%VS90COMNTOOLS%vsvars32.bat" x86

echo Building ACF in %ACFDIR%
echo Building ACF-Solutions in %ACFSLNDIR%
echo Building IACF in %IACFDIR%

cd %ACFDIR%\Build\VC9
msbuild AcfAll.sln

cd %ACFDIR%\Docs\Tutorial\Build\VC9
msbuild TutorialAcf.sln

cd %ACFSLNDIR%\Build\VC9
msbuild AcfSlnAll.sln

cd %ACFSLNDIR%\Docs\Tutorial\Build\VC9
msbuild TutorialAcfSln.sln

cd %IACFDIR%\Build\VC9
msbuild IacfAll.sln

pause
