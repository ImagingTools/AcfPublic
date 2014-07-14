echo off

cd /d %~dp0\..\..

call "%VS90COMNTOOLS%vsvars32.bat" x86

qbs install -f %~dp0../Qbs/AcfWorldWorkspace.qbs --install-root %~dp0../.. profile:VC9 acf.targetBinSubdir:"Bin/DebugVC9" acf.targetPckSubdir:"Bin/DebugVC9" acf.targetLibSubdir:"Lib/DebugVC9"  acf.targetGeneratedSubdir:"AuxInclude/Qt5" acf.installProjectSubdirs:true debug

pause
