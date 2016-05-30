echo off

cd /d %~dp0\..\..

call "%VS100COMNTOOLS%vsvars32.bat" x86

qbs install -f %~dp0../Qbs/AcfWorldWorkspace.qbs --install-root %~dp0../.. profile:VC12_64 acf.targetBinSubdir:"Bin/ReleaseVC12_64" acf.targetPckSubdir:"Bin/ReleaseVC12_64" acf.targetLibSubdir:"Lib/ReleaseVC12_64" acf.targetGeneratedSubdir:"AuxInclude/Qt5_64" release

pause
