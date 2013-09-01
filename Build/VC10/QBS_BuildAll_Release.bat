echo off

call "%VS100COMNTOOLS%vsvars32.bat" x86

qbs build -f ../Qbs/AcfWorldAll.qbs release profile:qtc_VC10
qbs install -f ../Qbs/AcfWorldAll.qbs --install-root ../../Acf --no-build release profile:qtc_VC10

pause
