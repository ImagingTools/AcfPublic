echo off

set ACFDIR="%ACFPUBLICDIR%\Acf"
set ACFSLNDIR="%ACFPUBLICDIR%\AcfSln"
set IACFDIR="%ACFPUBLICDIR%\Iacf"

call "%VS90COMNTOOLS%vsvars32.bat" x86

echo Building ACF in %ACFDIR%
echo Building ACF-Solutions in %ACFSLNDIR%
echo Building IACF in %IACFDIR%

cd %ACFDIR%\Build\VC9
msbuild AcfAll.sln /p:Configuration=Release

cd %ACFDIR%\Docs\Tutorial\Build\VC9
msbuild TutorialAcf.sln /p:Configuration=Release

cd %ACFSLNDIR%\Build\VC9
msbuild AcfSlnAll.sln /p:Configuration=Release

cd %ACFSLNDIR%\Docs\Tutorial\Build\VC9
msbuild TutorialAcfSln.sln /p:Configuration=Release

cd %IACFDIR%\Build\VC9
msbuild IacfAll.sln /p:Configuration=Release

pause
