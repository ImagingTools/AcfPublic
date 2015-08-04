/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iqtsig_CSampleContainerView_included
#define iqtsig_CSampleContainerView_included


#include <QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif

// ACF includes
#include "istd/TRange.h"
#include "imod/TSingleModelObserverBase.h"
#include "imeas/IDataSequence.h"


namespace iqtsig
{


class CSampleContainerView: public QWidget, public imod::TSingleModelObserverBase<imeas::IDataSequence>
{
public:
	typedef QWidget BaseClass;
	typedef imod::TSingleModelObserverBase<imeas::IDataSequence> BaseClass2;

	CSampleContainerView(QWidget* parentPtr = NULL);

	void SetDisplayedRange(const istd::CRange& range);

	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (QWidget)
	virtual void paintEvent(QPaintEvent* event);

private:
	istd::CRange m_displayedRange;
};


} // namespace iqtsig


#endif // !iqtsig_CSampleContainerView_included


