import qbs.base 1.0

Module{
	condition: false
	name: "openCV"

	property string selectedVersion	// the user requested version can be placed here

	Depends{ name: "acf" }
	Depends{ name: "cpp" }

    property string cvModuleName

    Properties{
        condition: cvModuleName != undefined

        cpp.includePaths: [
			path + "/../../../../OpenCV/" + qbs.architecture + "/" + acf.compilerName + "lib/opencv_" + cvModuleName + "242"
		]

		cpp.includePaths: [
			path + "/../../../../OpenCV/Include"
		]
    }
}
