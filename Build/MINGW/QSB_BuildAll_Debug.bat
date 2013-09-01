echo off

qbs build -f ../Qbs/AcfWorldAll.qbs debug profile:qtc_MINGW
qbs install -f ../Qbs/AcfWorldAll.qbs --install-root ../../Acf --no-build debug profile:qtc_MINGW

pause
