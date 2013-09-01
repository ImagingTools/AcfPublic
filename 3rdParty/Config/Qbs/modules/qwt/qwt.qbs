import qbs.base 1.0
import qbs.FileInfo

Module{
	name: "qwt"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "acf" }
	Depends{ name: "cpp" }

	cpp.staticLibraries: path + "/../../../../Qwt/6.0.0/Lib/" + acf.compilerDir + "/qwt"
	cpp.includePaths: [
		path + "/../../../../Qwt/6.0.0/Include"
	]
}
