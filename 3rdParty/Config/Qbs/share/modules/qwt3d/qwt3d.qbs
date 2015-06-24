import qbs.base 1.0
import qbs.FileInfo

Module{
	name: "qwt3d"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "acf" }
	Depends{ name: "cpp" }

	cpp.staticLibraries: path + "/../../../../../Qwt3D/0.3.1/Lib/" + acf.compilerAndQtDir + "/qwt3d"
	cpp.includePaths: [
		path + "/../../../../../Qwt3D/0.3.1/Include"
	]
}
