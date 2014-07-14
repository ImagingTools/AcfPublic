echo off

cd /d %~dp0\..\..

qbs install -f %~dp0../Qbs/AcfWorldWorkspace.qbs --install-root %~dp0../.. profile:MINGW acf.targetBinSubdir:"Bin/DebugMINGW" acf.targetPckSubdir:"Bin/DebugMINGW" acf.targetLibSubdir:"Lib/DebugMINGW" acf.targetGeneratedSubdir:"AuxInclude/Qt5" acf.installProjectSubdirs:true debug

pause
