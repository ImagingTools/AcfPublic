import qbs.base 1.0

Module{
	name: "cbios"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "acf" }
	Depends{ name: "cpp" }

	cpp.staticLibraries: [
		path + "/../../../../../FFMpeg/20121010/lib/avcodec",
		path + "/../../../../../FFMpeg/20121010/lib/avdevice",
		path + "/../../../../../FFMpeg/20121010/lib/avfilter",
		path + "/../../../../../FFMpeg/20121010/lib/avformat",
		path + "/../../../../../FFMpeg/20121010/lib/avutil"
	]
	cpp.includePaths: [
		path + "/../../../../../FFMpeg/20121010/include"
	]
}
