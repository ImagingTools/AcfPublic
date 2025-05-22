/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// ACF includes
#include <istd/IInformationProvider.h>
#include <iqtgui/TMakeIconProviderCompWrap.h>


/**
	Standard GUI specific interfaces and components based on Qt.
*/
namespace iqtgui
{


template<class ThemedComp>
class StateIconWrapper : public ThemedComp
{
public:
	QIcon GetCategoryIcon(istd::IInformationProvider::InformationCategory category) const
	{
		switch (category) {
		case istd::IInformationProvider::IC_INFO:
			return ThemedComp::GetIcon(":/Icons/StateOk");

		case istd::IInformationProvider::IC_WARNING:
			return ThemedComp::GetIcon(":/Icons/StateWarning");

		case istd::IInformationProvider::IC_ERROR:
			return ThemedComp::GetIcon(":/Icons/StateInvalid");

		case istd::IInformationProvider::IC_CRITICAL:
			return ThemedComp::GetIcon(":/Icons/Error");

		default:
			return ThemedComp::GetIcon(":/Icons/StateUnknown");
		}
	}


	QIcon GetCategoryLogIcon(istd::IInformationProvider::InformationCategory category) const
	{
		switch (category) {
		case istd::IInformationProvider::IC_INFO:
			return ThemedComp::GetIcon(":/Icons/StateOk");

		case istd::IInformationProvider::IC_WARNING:
			return ThemedComp::GetIcon(":/Icons/StateWarning");

		case istd::IInformationProvider::IC_ERROR:
			return ThemedComp::GetIcon(":/Icons/StateInvalid");

		case istd::IInformationProvider::IC_CRITICAL:
			return ThemedComp::GetIcon(":/Icons/Error");

		default:
			return ThemedComp::GetIcon(":/Icons/Log");
		}
	}


	QPixmap GetCategoryPixmap(istd::IInformationProvider::InformationCategory category) const
	{
		switch (category) {
		case istd::IInformationProvider::IC_INFO:
			return QPixmap(ThemedComp::GetIconPath(":/Icons/StateOk"));

		case istd::IInformationProvider::IC_WARNING:
			return QPixmap(ThemedComp::GetIconPath(":/Icons/StateWarning"));

		case istd::IInformationProvider::IC_ERROR:
			return QPixmap(ThemedComp::GetIconPath(":/Icons/StateInvalid"));

		case istd::IInformationProvider::IC_CRITICAL:
			return QPixmap(ThemedComp::GetIconPath(":/Icons/Error"));

		default:
			return QPixmap(ThemedComp::GetIconPath(":/Icons/StateUnknown"));
		}
	}
};


template<class NonThemedComp>
class TMakeStateIconWrapper : public StateIconWrapper<TMakeIconProviderCompWrap<NonThemedComp>>
{};



} // namespace iqtgui


