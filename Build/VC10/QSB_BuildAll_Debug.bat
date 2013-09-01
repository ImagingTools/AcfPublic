echo off

call "%VS100COMNTOOLS%vsvars32.bat" x86

qbs build -f ../Qbs/AcfWorldAll.qbs debug profile:qtc_VC10
qbs install -f ../Qbs/AcfWorldAll.qbs --install-root ../../Acf --no-build debug profile:qtc_VC10

pause
