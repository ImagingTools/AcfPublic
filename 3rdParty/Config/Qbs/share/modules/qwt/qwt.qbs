import qbs.base 1.0
import qbs.FileInfo

Module{
	name: "qwt"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "acf" }
	Depends{ name: "cpp" }

	modulePath: qbs.getenv("EXTLIBDIR")

	cpp.libraryPaths: FileInfo.joinPaths(modulePath, "Qwt/6.0.0/Lib/" + acf.compilerDir)
	cpp.staticLibraries: "qwt"
	cpp.includePaths: [
		FileInfo.joinPaths(modulePath, "Qwt/6.0.0/Include")
	]
}
