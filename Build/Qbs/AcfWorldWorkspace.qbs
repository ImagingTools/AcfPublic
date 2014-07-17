import qbs.base 1.0

Project{
	name: "AcfWorld"

	qbsSearchPaths: ["../../Acf/Config/Qbs", "../../3rdParty/Config/Qbs/share"]

	Project{
		name: "Acf"

		property string acfInstallSubDir: "Acf"

		references: ["../../Acf/Build/Qbs/AcfProject.qbs", "../../Acf/Docs/Tutorial/Build/Qbs/TutorialAcfProject.qbs"]
	}

	Project{
		name: "AcfSln"

		property string acfInstallSubDir: "AcfSln"

		references: ["../../AcfSln/Build/Qbs/AcfSlnProject.qbs"]
	}

	Project{
		name: "Iacf"

		property string acfInstallSubDir: "Iacf"

		references: ["../../Iacf/Build/Qbs/IacfProject.qbs"]
	}
}
