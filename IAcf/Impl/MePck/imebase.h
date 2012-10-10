/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef imebase_included
#define imebase_included

#include <QtCore/QList>
#include <QtCore/QVector>

#include "isig/isig.h"
#include "iqt/iqt.h"

#include "medriver.h"
#include "medefines.h"
#include "metypes.h"
#include "meerror.h"



namespace imebase
{

	
/**
	Logical address of hardware endpoint.
*/
class CMeAddr
{
public:
	int device;
	int subdevice;
	int channel;
};


typedef QList<CMeAddr> CMeList;

typedef QVector<double> imebase_Buffer;


} // namespace imebase


#endif // !imebase_included
