echo off

cd /d %~dp0..\..

call "%VS100COMNTOOLS%vsvars32.bat" x86

qbs build -f %~dp0../Qbs/AcfWorldWorkspace.qbs debug profile:qtc_VC10
qbs install -f %~dp0../Qbs/AcfWorldWorkspace.qbs --install-root %~dp0../../Acf --no-build debug profile:qtc_VC10

pause
