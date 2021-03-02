# For non-shadow build use lib directory inside source tree:

link_libraries("iqt ipackage idoc ifile iimg icmm i2d i3d iprm ilog ibase icomp iattr iser imod imath istd")

if(${MSVC})
	link_libraries("Mpr")
endif()
