import qbs.base 1.0

Module{
	name: "cbios"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "acf" }
	Depends{ name: "cpp" }

	cpp.staticLibraries: path + "/../../../../CBios/lib/VC9/CBIOS"
	cpp.includePaths: [
		path + "/../../../../CBios/include"
	]
}
