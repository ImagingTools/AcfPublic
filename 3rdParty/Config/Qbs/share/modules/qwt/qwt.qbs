import qbs.base 1.0

Module{
	name: "qwt"

	Depends{ name: "Qt.gui" }
	Depends{ name: "Qt.core" }
	Depends{ name: "cpp" }

	Properties{
		condition: cpp.debugInformation === true
		cpp.staticLibraries: '../../../../../../Qwt/6.0.0/Lib/DebugQMake/qwt'
	}
	Properties{
		condition: cpp.debugInformation === false
		cpp.staticLibraries: '../../../../../../Qwt/6.0.0/Lib/ReleaseQMake/qwt'
	}
	cpp.includePaths: [
		'../../../../../../Qwt/6.0.0/Include'
	]
}
