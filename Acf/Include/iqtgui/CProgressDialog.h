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
#include <QtWidgets/QProgressDialog>

// ACF includes
#include <ibase/IProgressManager.h>


namespace iqtgui
{


class CProgressDialog: public QProgressDialog, virtual public ibase::IProgressManager
{
public:
	typedef QProgressDialog BaseClass;

	CProgressDialog(QWidget* parentWidget = NULL);

	// reimplemented (ibase::IProgressManager)
	virtual int BeginProgressSession(
				const QByteArray& progressId,
				const QString& description,
				bool isCancelable) override;
	virtual void EndProgressSession(int sessionId);
	virtual void OnProgress(int sessionId, double currentProgress) override;
	virtual bool IsCanceled(int sessionId) const override;
};


} // namespace iqtgui


