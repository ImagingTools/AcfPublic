TEMPLATE = subdirs
CONFIG -= flat

SUBDIRS += Acf
SUBDIRS += AcfSln
SUBDIRS += Iacf

Acf.file = ../../Acf/Build/QMake/AcfAll.pro
AcfSln.file = ../../AcfSln/Build/QMake/AcfSlnAll.pro
AcfSln.depends = Acf
Iacf.file = ../../IAcf/Build/QMake/IacfAll.pro
Iacf.depends = AcfSln
