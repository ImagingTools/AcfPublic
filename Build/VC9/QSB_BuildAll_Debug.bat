echo off

cd /d %~dp0\..\..

call "%VS90COMNTOOLS%vsvars32.bat" x86

qbs build -f %~dp0/../Qbs/AcfWorldAll.qbs debug profile:qtc_VC9
qbs install -f %~dp0/../Qbs/AcfWorldAll.qbs --install-root %~dp0/../../Acf --no-build debug profile:qtc_VC9

pause
