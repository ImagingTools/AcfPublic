echo off

cd /d %~dp0\..\..

call "%VS100COMNTOOLS%vsvars32.bat" x86

qbs build -f %~dp0/../Qbs/AcfWorldAll.qbs release profile:qtc_VC10
qbs install -f %~dp0/../Qbs/AcfWorldAll.qbs --install-root %~dp0/../../Acf --no-build release profile:qtc_VC10

pause
