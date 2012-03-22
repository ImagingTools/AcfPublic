TEMPLATE = subdirs
CONFIG -= flat

SUBDIRS += Acf
SUBDIRS += AcfSln
SUBDIRS += Iacf

Acf.file = ../../Acf/Impl/QMake/AcfAll.pro
AcfSln.file = ../../AcfSln/Impl/QMake/AcfSlnAll.pro
AcfSln.depends = Acf
Iacf.file = ../../Iacf/Impl/QMake/IacfAll.pro
Iacf.depends = AcfSln
