echo off

cd /d %~dp0\..\..

call "%VS100COMNTOOLS%vsvars32.bat" x86

qbs install -f %~dp0../Qbs/AcfWorldWorkspace.qbs --install-root %~dp0../.. profile:VC10 acf.targetBinSubdir:"Bin/ReleaseVC10" acf.targetPckSubdir:"Bin/ReleaseVC10" acf.targetLibSubdir:"Lib/ReleaseVC10" acf.targetGeneratedSubdir:"AuxInclude/Qt5" acf.installProjectSubdirs:true release

pause
