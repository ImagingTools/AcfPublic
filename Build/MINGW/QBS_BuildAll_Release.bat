echo off

cd /d %~dp0\..\..

qbs install -f %~dp0../Qbs/AcfWorldWorkspace.qbs --install-root %~dp0../.. profile:MINGW acf.targetBinSubdir:"Bin/ReleaseMINGW" acf.targetPckSubdir:"Bin/ReleaseMINGW" acf.targetLibSubdir:"Lib/ReleaseMINGW" acf.installIncludes:true acf.installProjectSubdirs:true release

pause
