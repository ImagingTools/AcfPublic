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


#ifndef iqt_CSignalBlocker_included
#define iqt_CSignalBlocker_included


#include "iqt/iqt.h"


#include <QtCore/QObject>


namespace iqt
{


/**
	Simple helper class blocking Qt signals of specified QObject.
*/
class CSignalBlocker
{
public:
	CSignalBlocker(QObject* objectPtr, bool blockChilds = false);
	virtual ~CSignalBlocker();

private:
	void BlockChilds(QObject* objectPtr, bool block);

private:
	QObject* m_objectPtr;
	bool m_blockChilds;
};


} // namespace iqt


#endif // !iqt_CSignalBlocker_included

