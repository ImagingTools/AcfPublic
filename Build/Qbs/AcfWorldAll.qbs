import qbs.base 1.0

Project{
	name: "AcfWorld"

	moduleSearchPaths: ["../../Acf/Config/Qbs"]

	SubProject{
		filePath: "../../Acf/Build/Qbs/AcfAll.qbs"
	}
	SubProject{
		filePath: "../../AcfSln/Build/Qbs/AcfSlnAll.qbs"
	}
}
