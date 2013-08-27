echo off

call "%VS90COMNTOOLS%vsvars32.bat" x86

qbs build -f ../Qbs/AcfWorldAll.qbs --jobs 8 release profile:qtc_VC9
qbs install -f ../Qbs/AcfWorldAll.qbs --jobs 8 --install-root ../../Acf --no-build release profile:qtc_VC9

pause
