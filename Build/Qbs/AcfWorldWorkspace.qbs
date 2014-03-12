import qbs.base 1.0

Project{
	name: "AcfWorld"

	qbsSearchPaths: ["../../Acf/Config/Qbs", "../../3rdParty/Config/Qbs/share"]

	SubProject{
		filePath: "../../Acf/Build/Qbs/AcfProject.qbs"
	}
	SubProject{
		filePath: "../../AcfSln/Build/Qbs/AcfSlnProject.qbs"
	}
	SubProject{
		filePath: "../../Iacf/Build/Qbs/IacfProject.qbs"
	}
}
