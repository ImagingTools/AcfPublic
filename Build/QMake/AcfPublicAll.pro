TEMPLATE = subdirs
CONFIG -= flat

SUBDIRS += Acf
SUBDIRS += AcfSln
SUBDIRS += IAcf

Acf.file = ../../Acf/Build/QMake/AcfAll.pro
AcfSln.file = ../../AcfSln/Build/QMake/AcfSlnAll.pro
AcfSln.depends = Acf
IAcf.file = ../../IAcf/Build/QMake/IAcfAll.pro
IAcf.depends = AcfSln
