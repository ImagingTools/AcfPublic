echo off

qbs build -f ../Qbs/AcfWorldAll.qbs --jobs 8 release profile:qtc_MINGW
qbs install -f ../Qbs/AcfWorldAll.qbs --jobs 8 --install-root ../../Acf --no-build release profile:qtc_MINGW

pause
