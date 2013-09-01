echo off

call "%VS90COMNTOOLS%vsvars32.bat" x86

qbs build -f ../Qbs/AcfWorldAll.qbs debug profile:qtc_VC9
qbs install -f ../Qbs/AcfWorldAll.qbs --install-root ../../Acf --no-build debug profile:qtc_VC9

pause
