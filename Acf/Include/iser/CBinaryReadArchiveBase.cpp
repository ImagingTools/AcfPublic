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


#include "iser/CBinaryReadArchiveBase.h"


// Qt includes
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QVarLengthArray>

// ACF includes
#include "iser/CArchiveTag.h"


namespace iser
{


bool CBinaryReadArchiveBase::BeginTag(const CArchiveTag& tag)
{
	quint32 readId;
	bool retVal = Process(readId);

	if (!retVal){
		return false;
	}

	if (readId != tag.GetBinaryId()){
		if (IsLogConsumed()){
			SendLogMessage(
						istd::IInformationProvider::IC_ERROR,
						MI_TAG_ERROR,
						QObject::tr("Bad tag begin code, is %1, should be %2 (tag '%3')").arg(readId).arg(tag.GetBinaryId()).arg(QString(tag.GetId())),
						"iser::CBinaryReadArchiveBase",
						istd::IInformationProvider::ITF_SYSTEM);
		}

		return false;
	}

	return true;
}


bool CBinaryReadArchiveBase::EndTag(const CArchiveTag& tag)
{
	quint32 readId;
	bool retVal = Process(readId);

	if (!retVal){
		return false;
	}

	if (~readId != tag.GetBinaryId()){
		if (IsLogConsumed()){
			SendLogMessage(
						istd::IInformationProvider::IC_ERROR,
						MI_TAG_ERROR,
						QObject::tr("Bad tag begin code, is %1, should be %2 (tag '%3')").arg(~readId).arg(tag.GetBinaryId()).arg(QString(tag.GetId())),
						"iser::CBinaryReadArchiveBase",
						istd::IInformationProvider::ITF_SYSTEM);
		}

		return false;
	}

	return true;
}


bool CBinaryReadArchiveBase::Process(bool& value)
{
	return ProcessData(&value, int(sizeof(bool)));
}


bool CBinaryReadArchiveBase::Process(char& value)
{
	return ProcessData(&value, int(sizeof(char)));
}


bool CBinaryReadArchiveBase::Process(quint8& value)
{
	return ProcessData(&value, int(sizeof(quint8)));
}


bool CBinaryReadArchiveBase::Process(qint8& value)
{
	return ProcessData(&value, int(sizeof(qint8)));
}


bool CBinaryReadArchiveBase::Process(quint16& value)
{
	return ProcessData(&value, int(sizeof(quint16)));
}


bool CBinaryReadArchiveBase::Process(qint16& value)
{
	return ProcessData(&value, int(sizeof(qint16)));
}


bool CBinaryReadArchiveBase::Process(quint32& value)
{
	return ProcessData(&value, int(sizeof(quint32)));
}


bool CBinaryReadArchiveBase::Process(qint32& value)
{
	return ProcessData(&value, int(sizeof(qint32)));
}


bool CBinaryReadArchiveBase::Process(quint64& value)
{
	return ProcessData(&value, int(sizeof(quint64)));
}


bool CBinaryReadArchiveBase::Process(qint64& value)
{
	return ProcessData(&value, int(sizeof(qint64)));
}


bool CBinaryReadArchiveBase::Process(float& value)
{
	return ProcessData(&value, int(sizeof(float)));
}


bool CBinaryReadArchiveBase::Process(double& value)
{
	return ProcessData(&value, int(sizeof(double)));
}


bool CBinaryReadArchiveBase::Process(QByteArray& value)
{			
	int stringLength;

	bool retVal = Process(stringLength);

	if (!retVal){
		return false;
	}

	if (stringLength > 0) {
		if (stringLength > GetMaxStringLength()){
			if (IsLogConsumed()){
				SendLogMessage(
							istd::IInformationProvider::IC_ERROR,
							MI_STRING_TOO_LONG,
							QString("Read string size is ") + QString("%1").arg(stringLength) + " and it is longer than maximum size",
							"iser::CBinaryReadArchiveBase",
							istd::IInformationProvider::ITF_SYSTEM);
			}

			return false;
		}

		QVarLengthArray<char> buffer(stringLength);

		retVal = ProcessData(buffer.data(), stringLength * int(sizeof(char)));	

		if (retVal){
			value = QByteArray(buffer.constData(), stringLength);
		}
	}
	else{
		// just clear the string
		value.clear();
	}

	return retVal;
}


bool CBinaryReadArchiveBase::Process(QString& value)
{
	int stringLength;

	bool retVal = Process(stringLength);

	if (!retVal){
		return false;
	}

	if (stringLength > 0) {
		if (stringLength > GetMaxStringLength()){
			if (IsLogConsumed()){
				SendLogMessage(
							istd::IInformationProvider::IC_ERROR,
							MI_STRING_TOO_LONG,
							QString("Read string size is ") + QString("%1").arg(stringLength) + " and it is longer than maximum size",
							"iser::CBinaryReadArchiveBase",
							istd::IInformationProvider::ITF_SYSTEM);
			}

			return false;
		}

		QVarLengthArray<QChar> buffer(stringLength);

		retVal = ProcessData(buffer.data(), stringLength * int(sizeof(QChar)));	

		if (retVal){
			value = QString(buffer.constData(), stringLength);
		}
	}
	else{
		// just clear the string
		value.clear();
	}

	return retVal;
}


// protected methods

int CBinaryReadArchiveBase::GetMaxStringLength() const
{
	return 100000;
}


} // namespace iser

