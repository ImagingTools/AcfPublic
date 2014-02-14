import qbs.base 1.0

Module{
	name: "dc1394"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "cpp" }

	cpp.staticLibraries: [
		path + "/../../../../../libdc1394/2.2.0/lib/dc1394",
	]
	cpp.includePaths: [
		path + "/../../../../../libdc1394/2.2.0/dc1394"
	]
}
