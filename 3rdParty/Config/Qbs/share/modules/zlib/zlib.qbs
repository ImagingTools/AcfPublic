import qbs.base 1.0

Module{
	name: "zlib"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "cpp" }

	cpp.libraryPaths: [
		path + "/../../../../../zlib/lib"
	]
	cpp.staticLibraries: [
		"zlib", "libmmd"
	]
	cpp.includePaths: [
		path + "/../../../../../zlib/include"
	]
}
