echo off

cd /d %~dp0\..\..

qbs build -f %~dp0/../Qbs/AcfWorldAll.qbs debug profile:qtc_MINGW
qbs install -f %~dp0/../Qbs/AcfWorldAll.qbs --install-root %~dp0/../../Acf --no-build debug profile:qtc_MINGW

pause
