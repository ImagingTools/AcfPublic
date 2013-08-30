echo off

qbs build -f ../Qbs/AcfWorldAll.qbs --jobs 8 debug profile:qtc_MINGW
qbs install -f ../Qbs/AcfWorldAll.qbs --jobs 8 --install-root ../../Acf --no-build debug profile:qtc_MINGW

pause
