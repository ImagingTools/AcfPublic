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


#ifndef iser_CXmlStringReadArchive_included
#define iser_CXmlStringReadArchive_included


// Qt includes
#include <QtCore/QBuffer>

// ACF includes
#include <iser/CXmlStreamReadArchiveBase.h>


namespace iser
{


/**
	Simple implementation for reading of a XML from a string.
	This imlementation uses only single pass and is very fast,
	but it needs \c counter attribute idicating number of subtags for each mutli tag node.

	\ingroup Persistence
*/
class CXmlStringReadArchive: public CXmlStreamReadArchiveBase
{
public:
	typedef CXmlStreamReadArchiveBase BaseClass;

	CXmlStringReadArchive(const QByteArray& inputString, bool serializeHeader = true, const CArchiveTag& rootTag = s_acfRootTag);

private:
	QBuffer m_buffer;
};


} // namespace iser


#endif // !iser_CXmlStringReadArchive_included

