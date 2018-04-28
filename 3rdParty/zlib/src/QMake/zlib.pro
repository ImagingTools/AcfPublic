include($(ACFCONFIGDIR)/QMake/StaticConfig.pri)

QT -= core gui

TARGET = zlib

TEMPLATE = lib

SOURCES += $$_PRO_FILE_PWD_/../adler32.c
SOURCES += $$_PRO_FILE_PWD_/../compress.c
SOURCES += $$_PRO_FILE_PWD_/../crc32.c
SOURCES += $$_PRO_FILE_PWD_/../deflate.c
SOURCES += $$_PRO_FILE_PWD_/../gzclose.c
SOURCES += $$_PRO_FILE_PWD_/../gzlib.c
SOURCES += $$_PRO_FILE_PWD_/../gzread.c
SOURCES += $$_PRO_FILE_PWD_/../gzwrite.c
SOURCES += $$_PRO_FILE_PWD_/../infback.c
SOURCES += $$_PRO_FILE_PWD_/../inffast.c
SOURCES += $$_PRO_FILE_PWD_/../inflate.c
SOURCES += $$_PRO_FILE_PWD_/../inftrees.c
SOURCES += $$_PRO_FILE_PWD_/../trees.c
SOURCES += $$_PRO_FILE_PWD_/../uncompr.c
SOURCES += $$_PRO_FILE_PWD_/../zutil.c

SOURCES -= $$_PRO_FILE_PWD_/../*.cpp


DESTDIR = $$OUT_PWD/../../Lib/$$COMPILER_DIR

win32-msvc*{
    QMAKE_CXXFLAGS += /Zi /Fd$$DESTDIR/"$$TARGET".pdb
}
