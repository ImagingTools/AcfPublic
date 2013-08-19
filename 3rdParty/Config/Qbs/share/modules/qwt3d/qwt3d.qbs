import qbs.base 1.0
import qbs.FileInfo

Module{
	name: "qwt3d"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "acf" }
	Depends{ name: "cpp" }
	Depends{ name: "Qt.opengl" }

	modulePath: qbs.getenv("EXTLIBDIR")

	cpp.libraryPaths: FileInfo.joinPaths(modulePath, "Qwt3D/Lib/" + acf.compilerDir)
	cpp.staticLibraries: "qwt3dlib"
	cpp.includePaths: [
		FileInfo.joinPaths(modulePath, "Qwt3D/Include")
	]
}
