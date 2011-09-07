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


#ifndef iser_TXmlStreamWriteArchiveBase_included
#define iser_TXmlStreamWriteArchiveBase_included


// ACF includes
#include "iser/CXmlWriteArchiveBase.h"


namespace iser
{


/**
	Base implementation of archive for writing in XML format using a stream implementation.
*/
template <class StreamClass>
class TXmlStreamWriteArchiveBase: public CXmlWriteArchiveBase
{
public:
	typedef CXmlWriteArchiveBase BaseClass;

	virtual ~TXmlStreamWriteArchiveBase();

protected:
	TXmlStreamWriteArchiveBase(const IVersionInfo* versionInfoPtr, const CArchiveTag& rootTag);

	// reimplemented (iser::CXmlWriteArchiveBase)
	virtual bool WriteString(const std::string& value);

protected:
	StreamClass m_stream;
};


// public methods

template <class StreamClass>
TXmlStreamWriteArchiveBase<StreamClass>::~TXmlStreamWriteArchiveBase()
{
	Flush();
}


// protected methods

template <class StreamClass>
TXmlStreamWriteArchiveBase<StreamClass>::TXmlStreamWriteArchiveBase(const IVersionInfo* versionInfoPtr, const CArchiveTag& rootTag)
:	BaseClass(versionInfoPtr, rootTag)
{
}


// reimplemented (iser::CXmlWriteArchiveBase)

template <class StreamClass>
bool TXmlStreamWriteArchiveBase<StreamClass>::WriteString(const std::string& value)
{
	m_stream << value;

	return !m_stream.fail();
}


} // namespace iser


#endif // !iser_TXmlStreamWriteArchiveBase_included


