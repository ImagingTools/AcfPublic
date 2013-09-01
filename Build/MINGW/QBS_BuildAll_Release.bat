echo off

qbs build -f ../Qbs/AcfWorldAll.qbs release profile:qtc_MINGW
qbs install -f ../Qbs/AcfWorldAll.qbs --install-root ../../Acf --no-build release profile:qtc_MINGW

pause
