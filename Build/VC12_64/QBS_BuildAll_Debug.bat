echo off

cd /d %~dp0\..\..

call "%VS100COMNTOOLS%vsvars32.bat" x86

qbs install -f %~dp0../Qbs/AcfWorldWorkspace.qbs --install-root %~dp0../.. profile:VC12_64 acf.targetBinSubdir:"Bin/DebugVC12_64" acf.targetPckSubdir:"Bin/DebugVC12_64" acf.targetLibSubdir:"Lib/DebugVC12_64" acf.targetGeneratedSubdir:"AuxInclude/Qt5_VC12_64" debug

pause
