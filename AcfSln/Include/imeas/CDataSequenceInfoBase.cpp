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


#include "imeas/CDataSequenceInfoBase.h"


// Qt includes
#include <QtCore/QObject>


namespace imeas
{


// reimplemented (imeas::IDataSequenceInfo)

int CDataSequenceInfoBase::GetSequenceInfoFlags() const
{
	return 0;
}


int CDataSequenceInfoBase::GetDefaultSamplesCount() const
{
	return 0;
}


int CDataSequenceInfoBase::GetDefaultChannelsCount() const
{
	return 0;
}


int CDataSequenceInfoBase::GetWeightMode() const
{
	return WM_NONE;
}


// reimplemented (imeas::INumericConstraints)

int CDataSequenceInfoBase::GetNumericValuesCount() const
{
	return std::max(0, GetDefaultChannelsCount());
}


QString CDataSequenceInfoBase::GetNumericValueName(int index) const
{
	return QObject::tr("Channel %1").arg(index + 1);
}


QString CDataSequenceInfoBase::GetNumericValueDescription(int /*index*/) const
{
	return QString();
}


const imath::IUnitInfo* CDataSequenceInfoBase::GetNumericValueUnitInfo(int /*index*/) const
{
	return NULL;
}


// reimplemented (iser::ISerializable)

bool CDataSequenceInfoBase::Serialize(iser::IArchive& /*archive*/)
{
	return true;
}


} // namespace imeas


