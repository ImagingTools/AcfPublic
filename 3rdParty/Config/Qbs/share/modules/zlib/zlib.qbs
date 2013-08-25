import qbs.base 1.0

Module{
	name: "zlib"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "acf" }
	Depends{ name: "cpp" }

	cpp.staticLibraries: [
		path + "/../../../../../zlib/include",
	]
	cpp.includePaths: [
		path + "/../../../../../lib/zlib"
	]
}
