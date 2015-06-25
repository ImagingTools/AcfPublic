import qbs.base 1.0
import qbs.FileInfo

Module{
	name: "qwt"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "acf" }
	Depends{ name: "cpp" }
	Depends{ name: "Qt.opengl" }
	Depends{ name: "Qt.svg" }

	cpp.staticLibraries: path + "/../../../../../Qwt/6.1.0/Lib/" + acf.compilerAndQtDir + "/qwt"
	cpp.includePaths: [
		path + "/../../../../../Qwt/6.1.0/src"
	]
}
