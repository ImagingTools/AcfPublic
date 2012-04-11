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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iser_CTextReadArchiveBase_included
#define iser_CTextReadArchiveBase_included


// Qt includes
#include <QtCore/QTextStream>

// ACF includes
#include "iser/CReadArchiveBase.h"


namespace iser
{


/**
	Common archive implementation of text-based reading archives.
*/
class CTextReadArchiveBase: public CReadArchiveBase
{
public:
	typedef CReadArchiveBase BaseClass;

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
	// template methods
	template <typename Type>
	bool ProcessInternal(Type& value);
};


// template methods

template <typename Type>
bool CTextReadArchiveBase::ProcessInternal(Type& value)
{
	QByteArray elementText;

	if (Process(elementText) && !elementText.isEmpty()){
		QTextStream stream(&elementText, QIODevice::ReadOnly);

		stream >> value;

		return true;
	}

	return false;
}


} // namespace iser


#endif // !iser_CTextReadArchiveBase_included


