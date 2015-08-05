TEMPLATE = subdirs
CONFIG -= flat

SUBDIRS += Acf
SUBDIRS += AcfSln

Acf.file = ../../Acf/Build/QMake/AcfAll.pro
AcfSln.file = ../../AcfSln/Build/QMake/AcfSlnAll.pro
AcfSln.depends = Acf
