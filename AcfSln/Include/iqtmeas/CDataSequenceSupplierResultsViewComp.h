/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtmeas_CDataSequenceSupplierResultsViewComp_included
#define iqtmeas_CDataSequenceSupplierResultsViewComp_included


// Qt includes
#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QVBoxLayout>
#else
#include <QtGui/QVBoxLayout>
#endif

// ACF includes
#include "imod/TSingleModelObserverBase.h"
#include "iinsp/ISupplier.h"
#include "iqtgui/TGuiObserverWrap.h"
#include "iqtgui/TGuiComponentBase.h"

// ACF-Solutions includes
#include "imeas/IDataSequenceProvider.h"


namespace iqtmeas
{


class CDataSequenceSupplierResultsViewComp:
			public iqtgui::TGuiObserverWrap<
						iqtgui::TGuiComponentBase<QWidget>,
						imod::TSingleModelObserverBase<imeas::IDataSequenceProvider> >
{
public:
	typedef iqtgui::TGuiObserverWrap<
				iqtgui::TGuiComponentBase<QWidget>,
				imod::TSingleModelObserverBase<imeas::IDataSequenceProvider> > BaseClass;

	I_BEGIN_COMPONENT(CDataSequenceSupplierResultsViewComp);
		I_REGISTER_INTERFACE(imod::IObserver);
		I_REGISTER_INTERFACE(imod::IModelEditor);
		I_ASSIGN(m_resultsGuiCompPtr, "ResultsGui", "GUI for the supplier's results", true, "ResultsGui");
		I_ASSIGN_TO(m_resultsObserverCompPtr, m_resultsGuiCompPtr, true);
	I_END_COMPONENT;


protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

private:
	I_REF(iqtgui::IGuiObject, m_resultsGuiCompPtr);
	I_REF(imod::IObserver, m_resultsObserverCompPtr);
};


} // namespace iqtmeas


#endif // !iqtmeas_CDataSequenceSupplierResultsViewComp_included


