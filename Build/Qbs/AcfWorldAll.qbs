import qbs.base 1.0

Project{
	name: "AcfWorld"

	SubProject{
		filePath: "../../Acf/Build/Qbs/AcfAll.qbs"
	}
	SubProject{
		filePath: "../../AcfSln/Build/Qbs/AcfSlnAll.qbs"
	}
	SubProject{
		filePath: "../../Iacf/Build/Qbs/IacfAll.qbs"
	}
}
