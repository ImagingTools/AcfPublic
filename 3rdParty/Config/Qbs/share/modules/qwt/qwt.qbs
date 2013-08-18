import qbs.base 1.0
import qbs.FileInfo

Module{
	name: "qwt"

	Depends{ name: "Qt.gui" }
	Depends{ name: "Qt.core" }
	Depends{ name: "cpp" }

	prefix: "Debug"
	Properties{
		condition: cpp.debugInformation === false
		prefix: "Release"
	}

	base: "QMake"
	Properties{
		condition: cpp.compilerPath.contains("2005") || cpp.compilerPath.contains("VC8")
		base: "VC8"
	}
	Properties{
		condition: cpp.compilerPath.contains("2008") || cpp.compilerPath.contains("VC9")
		base: "VC9"
	}
	Properties{
		condition: cpp.compilerPath.contains("2010") || cpp.compilerPath.contains("VC10")
		base: "VC10"
	}

	modulePath: qbs.getenv("EXTLIBDIR")

	cpp.staticLibraries: FileInfo.joinPaths(modulePath, "Qwt/6.0.0/Lib/" + prefix + base + "/qwt")
	cpp.includePaths: [
		FileInfo.joinPaths(modulePath, "Qwt/6.0.0/Include")
	]
}
