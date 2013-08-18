import qbs.base 1.0
import qbs.FileInfo

Module{
	name: "qwt"

	Depends{ name: "acf" }
	Depends{ name: "cpp" }

	modulePath: qbs.getenv("EXTLIBDIR")

	cpp.staticLibraries: FileInfo.joinPaths(modulePath, "Qwt/6.0.0/Lib/" + acf.compilerDir + "/qwt")
	cpp.includePaths: [
		FileInfo.joinPaths(modulePath, "Qwt/6.0.0/Include")
	]
}
