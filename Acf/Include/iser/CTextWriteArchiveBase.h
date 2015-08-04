/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iser_CTextWriteArchiveBase_included
#define iser_CTextWriteArchiveBase_included


// Qt includes
#include <QtCore/QTextStream>
#include <QtCore/QIODevice>

// ACF includes
#include "iser/CWriteArchiveBase.h"


namespace iser
{


/**
	Common archive implementation of text-based storing archives.
*/
class CTextWriteArchiveBase: public CWriteArchiveBase
{
public:
	typedef CWriteArchiveBase BaseClass;

	// reimplemented (iser::IArchive)
	using BaseClass::Process;
	virtual bool Process(bool& value);
	virtual bool Process(char& value);
	virtual bool Process(quint8& value);
	virtual bool Process(qint8& value);
	virtual bool Process(quint16& value);
	virtual bool Process(qint16& value);
	virtual bool Process(quint32& value);
	virtual bool Process(qint32& value);
	virtual bool Process(quint64& value);
	virtual bool Process(qint64& value);
	virtual bool Process(float& value);
	virtual bool Process(double& value);
	virtual bool ProcessData(void* dataPtr, int size);

protected:
	CTextWriteArchiveBase(const IVersionInfo* versionInfoPtr);

	// template methods
	template <typename Type>
	bool ProcessInternal(const Type& value);
};


// template methods

template <typename Type>
bool CTextWriteArchiveBase::ProcessInternal(const Type& value)
{
	QByteArray string;

	{
		QTextStream stream(&string,  QIODevice::WriteOnly);

		stream << value;
	}

	return Process(string);
}


} // namespace iser


#endif // !iser_CTextWriteArchiveBase_included


