cd %ACFPUBLICDIR%

MsBuild.exe %ACFPUBLICDIR%\Acf\Impl\VC9\AcfAll.sln
MsBuild.exe %ACFPUBLICDIR%\AcfSln\Impl\VC9\AcfSlnAll.sln
MsBuild.exe %ACFPUBLICDIR%\Iacf\Impl\VC9\IacfAll.sln

pause