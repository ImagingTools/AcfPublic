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


#ifndef iqtgui_CIconProviderComp_included
#define iqtgui_CIconProviderComp_included


// ACF includes
#include "iqtgui/IIconProvider.h"

#include "icomp/CComponentBase.h"


namespace iqtgui
{


class CIconProviderComp: public icomp::CComponentBase, public iqtgui::IIconProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CIconProviderComp)
		I_REGISTER_INTERFACE(iqtgui::IIconProvider)
		I_ASSIGN_MULTI_0(m_iconFilesAttrPtr, "IconFiles", "Names of the icon files", true)
		I_ASSIGN(m_iconPathAttrPtr, "IconsPath", "Path to the icon files", true, ".")
	I_END_COMPONENT

	// reimplemented (iqtgui::IIconProvider)
	virtual int GetIconCount() const;
	virtual QIcon GetIcon(int index) const;

private:
	I_MULTIATTR(istd::CString, m_iconFilesAttrPtr);
	I_ATTR(istd::CString, m_iconPathAttrPtr);
};


} // namespace iqtgui


#endif // !iqtgui_CIconProviderComp_included

