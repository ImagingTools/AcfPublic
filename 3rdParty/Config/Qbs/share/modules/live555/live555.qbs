import qbs.base 1.0

Module{
	name: "live555"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "cpp" }

	cpp.staticLibraries: [
		path + "/../../../../../live555/2012.10.24/lib/libliveMedia",
	]
	cpp.includePaths: [
		path + "/../../../../../live555/2012.10.24/liveMedia"
	]
}
