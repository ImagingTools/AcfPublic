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


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QLabel>
#else
#include <QtGui/QLabel>
#endif

// ACF includes
#include <istd/IInformationProvider.h>
#include <imod/TSingleModelObserverBase.h>
#include <iqtgui/TGuiComponentBase.h>
#include <iqtgui/TGuiObserverWrap.h>
#include <iqtgui/TMakeStateIconWrapper.h>


namespace iqtgui
{


class CStatusGuiComp:
			public iqtgui::StateIconWrapper< 
				iqtgui::TGuiObserverWrap<
						iqtgui::TGuiComponentBase<QLabel>,
						imod::TSingleModelObserverBase<istd::IInformationProvider> > >
{
public:
	typedef iqtgui::StateIconWrapper< 
		iqtgui::TGuiObserverWrap<
				iqtgui::TGuiComponentBase<QLabel>,
				imod::TSingleModelObserverBase<istd::IInformationProvider> > > BaseClass;

	I_BEGIN_COMPONENT(CStatusGuiComp);
		I_ASSIGN(m_iconSizeAttrPtr, "IconSize", "Size of status icon", true, 64);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();

private:
	I_ATTR(int, m_iconSizeAttrPtr);
};


} // namespace iqtgui


