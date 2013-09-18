echo off

cd /d %~dp0\..\..

qbs build -f %~dp0/../Qbs/AcfWorldAll.qbs release profile:qtc_MINGW
qbs install -f %~dp0/../Qbs/AcfWorldAll.qbs --install-root %~dp0/../../Acf --no-build release profile:qtc_MINGW

pause
