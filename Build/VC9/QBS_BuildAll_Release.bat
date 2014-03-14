echo off

cd /d %~dp0..\..

call "%VS90COMNTOOLS%vsvars32.bat" x86

qbs build -f %~dp0../Qbs/AcfWorldWorkspace.qbs release profile:qtc_VC9
qbs install -f %~dp0../Qbs/AcfWorldWorkspace.qbs --install-root %~dp0../../Acf --no-build release profile:qtc_VC9

pause
