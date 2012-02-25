/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
**
**	This file may be used under the terms of the GNU Lesser
**	General Public License version 2.1 as published by the Free Software
**	Foundation and appearing in the file LicenseLGPL.txt included in the
**	packaging of this file.  Please review the following information to
**	ensure the GNU Lesser General Public License version 2.1 requirements
**	will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtgui_CSplashScreen_included
#define iqtgui_CSplashScreen_included


// Qt includes
#include <QSplashScreen>


// ACF includes
#include "ibase/IApplicationInfo.h"

#include "icomp/TAttribute.h"

#include "iqtgui/TDesignerGuiCompBase.h"

#include "iqtgui/Generated/ui_CSplashScreenGuiComp.h"


namespace iqtgui
{


/**
	Splash screen component.
	This component allows to create splash screen with additionally information about version, copyright an so on.
*/
class CSplashScreenGuiComp: public TDesignerGuiCompBase<Ui::CSplashScreenGuiComp, QSplashScreen>
{
public:
	typedef TDesignerGuiCompBase<Ui::CSplashScreenGuiComp, QSplashScreen> BaseClass;

	I_BEGIN_COMPONENT(CSplashScreenGuiComp);
		I_ASSIGN(m_applicationInfoCompPtr, "ApplicationInfo", "Version management for application", false, "Application");
		I_ASSIGN(m_imagePathAttrPtr, "ImagePath", "Path of image shown as splash screen", true, "Splash.jpg");
		I_ASSIGN(m_showProductNameAttrPtr, "ShowProductName", "If true, product name will be shown, disable it, if it was painted on background image", true, true);
		I_ASSIGN(m_showApplicationNameAttrPtr, "ShowApplicationName", "If true, application name will be shown, disable it, if it was painted on background image", true, true);
		I_ASSIGN(m_showApplicationSubnameAttrPtr, "ShowApplicationSubName", "If true, application subname will be shown, disable it, if it was painted on background image", true, false);
		I_ASSIGN(m_showProductTypeAttrPtr, "ShowProductType", "Additional product description shown over version info", true, false);
		I_ASSIGN(m_showLegalCopyrightAttrPtr, "ShowLegalCopyright", "If enabled legal copyrights will be shown", true, true);
		I_ASSIGN_MULTI_1(m_versionIdsAttrPtr, "VersionIds", "List of version ID's for version information should be displayed", false, 0);
		I_ASSIGN_MULTI_1(m_versionNamesAttrPtr, "VersionNames", "List of version names will be used as version description", false, "Version");
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiRetranslate();

private:
	I_REF(ibase::IApplicationInfo, m_applicationInfoCompPtr);
	I_ATTR(QString, m_imagePathAttrPtr);
	I_ATTR(bool, m_showProductNameAttrPtr);
	I_ATTR(bool, m_showApplicationNameAttrPtr);
	I_ATTR(bool, m_showApplicationSubnameAttrPtr);
	I_ATTR(bool, m_showProductTypeAttrPtr);
	I_ATTR(bool, m_showLegalCopyrightAttrPtr);
	I_MULTIATTR(int, m_versionIdsAttrPtr);
	I_MULTIATTR(QString, m_versionNamesAttrPtr);

	int m_mainVersionId;
};


} // namespace iqtgui


#endif // iqtgui_CSplashScreen_included


