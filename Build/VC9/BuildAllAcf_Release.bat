echo off

call "%VS90COMNTOOLS%vsvars32.bat" x86

set ACFDIR=%~dp0\..\..\Acf
set ACFSLNDIR=%~dp0\..\..\AcfSln
set IACFDIR=%~dp0\..\..\Iacf

echo Building ACF in %ACFDIR%
echo Building ACF-Solutions in %ACFSLNDIR%
echo Building IACF in %IACFDIR%

cd %ACFDIR%\Build\VC9
msbuild AcfAll.sln /p:Configuration=Release /m

cd %ACFDIR%\Docs\Tutorial\Build\VC9
msbuild TutorialAcf.sln /p:Configuration=Release /m

cd %ACFSLNDIR%\Build\VC9
msbuild AcfSlnAll.sln /p:Configuration=Release /m

cd %ACFSLNDIR%\Docs\Tutorial\Build\VC9
msbuild TutorialAcfSln.sln /p:Configuration=Release /m

cd %IACFDIR%\Build\VC9
msbuild IacfAll.sln /p:Configuration=Release /m

pause
