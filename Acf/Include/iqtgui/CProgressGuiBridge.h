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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QAbstractButton>

// ACF includes
#include <ibase/CCumulatedProgressManagerBase.h>


namespace iqtgui
{


class CProgressGuiBridge: public QObject, virtual public ibase::CCumulatedProgressManagerBase
{
	Q_OBJECT
public:
	CProgressGuiBridge(QProgressBar* progressWidget, QAbstractButton* cancelButton = NULL);

protected:
	// reimplemented (ibase::CCumulatedProgressManagerBase)
	void OnProgressChanged(double cumulatedValue) override;

protected Q_SLOTS:
	void OnCancelButtonClicked();

Q_SIGNALS:
	void ProgressChanged(int progress);

private:
	QProgressBar* m_progresBarPtr;
	QAbstractButton* m_cancelButtonPtr;
	int m_lastProgressValue;
};


} // namespace iqtgui


