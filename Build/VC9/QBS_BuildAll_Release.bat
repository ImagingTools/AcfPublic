echo off

call "%VS90COMNTOOLS%vsvars32.bat" x86

qbs build -f ../Qbs/AcfWorldAll.qbs release profile:qtc_VC9
qbs install -f ../Qbs/AcfWorldAll.qbs --install-root ../../Acf --no-build release profile:qtc_VC9

pause
