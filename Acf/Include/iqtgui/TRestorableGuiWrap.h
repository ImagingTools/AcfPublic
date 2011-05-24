/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtgui_TRestorableGuiWrap_included
#define iqtgui_TRestorableGuiWrap_included


// ACF includes
#include "iqt/ISettingsProvider.h"

#include "icomp/CComponentBase.h"


namespace iqtgui
{


/**
	A wrapper for saving/restoring of GUI component states in the application settings.

	\ingroup Helpers
*/
template <class Gui>
class TRestorableGuiWrap: public Gui
{
public:
	typedef Gui BaseClass;

	I_BEGIN_BASE_COMPONENT(TRestorableGuiWrap)
		I_ASSIGN(m_settingsProviderCompPtr, "SettingsProvider", "Application settings provider", false, "SettingsProvider")
	I_END_COMPONENT

protected:
	// abstract methods
	virtual void OnRestoreSettings(const QSettings& settings) = 0;
	virtual void OnSaveSettings(QSettings& settings) const = 0;

	// pseudo-reimplemented (iqtgui::CGuiComponentBase)
	virtual bool CreateGui(QWidget* parentPtr);
	virtual bool DestroyGui();

private:
	I_REF(iqt::ISettingsProvider, m_settingsProviderCompPtr);
};


// protected methods

template <class Gui>
bool TRestorableGuiWrap<Gui>::CreateGui(QWidget* parentPtr)
{
	bool retVal = BaseClass::CreateGui(parentPtr);

	if (m_settingsProviderCompPtr.IsValid()){
		OnRestoreSettings(m_settingsProviderCompPtr->GetSettings());
	}

	return retVal;
}


template <class Gui>
bool TRestorableGuiWrap<Gui>::DestroyGui()
{
	if (m_settingsProviderCompPtr.IsValid()){
		OnSaveSettings(m_settingsProviderCompPtr->GetSettings());
	}

	return BaseClass::DestroyGui();
}


} // namespace iqtgui


#endif // !iqtgui_TRestorableGuiWrap_included


