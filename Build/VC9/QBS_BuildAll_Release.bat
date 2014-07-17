echo off

cd /d %~dp0\..\..

call "%VS90COMNTOOLS%vsvars32.bat" x86

qbs install -f %~dp0../Qbs/AcfWorldWorkspace.qbs --install-root %~dp0../.. profile:VC9 acf.targetBinSubdir:"Bin/ReleaseVC9" acf.targetPckSubdir:"Bin/ReleaseVC9" acf.targetLibSubdir:"Lib/ReleaseVC9" acf.targetGeneratedSubdir:"AuxInclude/Qt5" release

pause
