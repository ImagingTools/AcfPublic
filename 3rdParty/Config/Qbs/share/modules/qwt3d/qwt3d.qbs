import qbs.base 1.0
import qbs.FileInfo

Module{
	name: "qwt3d"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "acf" }
	Depends{ name: "cpp" }

	modulePath: qbs.getenv("EXTLIBDIR")

	cpp.staticLibraries: FileInfo.joinPaths(modulePath, "Qwt3D/Lib/" + acf.compilerDir + "/qwt3dlib")
	cpp.includePaths: [
		FileInfo.joinPaths(modulePath, "Qwt3D/Include")
	]
}
