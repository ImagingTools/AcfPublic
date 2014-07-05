echo off

cd /d %~dp0\..\..

call "%VS100COMNTOOLS%vsvars32.bat" x86

qbs install -f %~dp0../Qbs/AcfWorldWorkspace.qbs --install-root %~dp0../.. profile:VC12 acf.targetBinSubdir:"Bin/DebugVC12" acf.targetPckSubdir:"Bin/DebugVC12" acf.targetLibSubdir:"Lib/DebugVC12" acf.installIncludes:true acf.installProjectSubdirs:true debug

pause
