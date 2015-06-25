/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#include "iser/CTextWriteArchiveBase.h"


namespace iser
{


bool CTextWriteArchiveBase::Process(bool& value)
{
	QByteArray elementText = value? "true": "false";

	return Process(elementText);
}


bool CTextWriteArchiveBase::Process(char& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(quint8& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(qint8& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(quint16& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(qint16& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(quint32& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(qint32& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(quint64& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(qint64& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(float& value)
{
	return ProcessInternal(value);
}


bool CTextWriteArchiveBase::Process(double& value)
{
	return Process(QString::number(value, 'g', 12));
}


bool CTextWriteArchiveBase::ProcessData(void* dataPtr, int size)
{
	QByteArray encodedString = QByteArray((const char*)dataPtr, size).toBase64();

	return Process(encodedString);
}


// protected methods

CTextWriteArchiveBase::CTextWriteArchiveBase(const IVersionInfo* versionInfoPtr)
:	BaseClass(versionInfoPtr)
{
}


} // namespace iser


