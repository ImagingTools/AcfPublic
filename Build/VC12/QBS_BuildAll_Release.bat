echo off

cd /d %~dp0\..\..

call "%VS100COMNTOOLS%vsvars32.bat" x86

qbs install -f %~dp0../Qbs/AcfWorldWorkspace.qbs --install-root %~dp0../.. profile:VC12 acf.targetBinSubdir:"Bin/ReleaseVC12" acf.targetPckSubdir:"Bin/ReleaseVC12" acf.targetLibSubdir:"Lib/ReleaseVC12" acf.installIncludes:true acf.installProjectSubdirs:true release

pause
