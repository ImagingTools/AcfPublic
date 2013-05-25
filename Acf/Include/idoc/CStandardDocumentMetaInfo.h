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


#ifndef idoc_CStandardDocumentMetaInfo_included
#define idoc_CStandardDocumentMetaInfo_included


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include "iser/ISerializable.h"
#include "idoc/IDocumentMetaInfo.h"


namespace idoc
{


/**
	Simple implementation of a text document model.
*/
class CStandardDocumentMetaInfo:
			virtual public IDocumentMetaInfo,
			virtual public iser::ISerializable
{
public:
	// reimplemented (IDocumentMetaInfo)
	virtual MetaInfoTypes GetSupportedMetaInfoTypes() const;
	virtual QVariant GetDocumentMetaInfo(MetaInfoType metaInfoType) const;
	virtual bool SetDocumentMetaInfo(MetaInfoType metaInfoType, const QVariant& metaInfo);
	virtual QString GetMetaInfoName(MetaInfoType metaInfoType) const;
	virtual QString GetMetaInfoDescription(MetaInfoType metaInfoType) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (istd::IChangeable)
	virtual bool IsEqual(const IChangeable& object) const;

private:
	typedef QMap<int, QVariant> MetaInfoMap;

	QMap<int, QVariant> m_infosMap;
};


} // namespace idoc


#endif // !idoc_CStandardDocumentMetaInfo_included


