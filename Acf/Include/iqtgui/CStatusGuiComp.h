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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqtgui_CStatusGuiComp_included
#define iqtgui_CStatusGuiComp_included


// Qt includes
#include <QtGui/QLabel>

// ACF includes
#include "istd/IInformationProvider.h"
#include "ibase/TModelObserverCompWrap.h"
#include "iqtgui/TGuiComponentBase.h"
#include "iqtgui/TGuiObserverWrap.h"


namespace iqtgui
{


class CStatusGuiComp: 
			public ibase::TModelObserverCompWrap<
						iqtgui::TGuiObserverWrap<
									iqtgui::TGuiComponentBase<QLabel>,
									imod::TSingleModelObserverBase<istd::IInformationProvider> > >
{
public:
	typedef ibase::TModelObserverCompWrap<
				iqtgui::TGuiObserverWrap<
							iqtgui::TGuiComponentBase<QLabel>,
							imod::TSingleModelObserverBase<istd::IInformationProvider> > > BaseClass;

	I_BEGIN_COMPONENT(CStatusGuiComp);
		I_ASSIGN(m_iconSizeAttrPtr, "IconSize", "Size of status icon", true, 64);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

private:
	I_ATTR(int, m_iconSizeAttrPtr);
};


} // namespace iqtgui


#endif // !iqtgui_CStatusGuiComp_included

