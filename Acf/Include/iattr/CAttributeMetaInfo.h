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


#ifndef iattr_CAttributeMetaInfo_included
#define iattr_CAttributeMetaInfo_included


// ACF includes
#include "istd/TOptDelPtr.h"

// ACF-Solutions includes
#include "iattr/IAttributeMetaInfo.h"


namespace iattr
{


/**
	Represents constraints of properties allowing values from enumerated set.
*/
class CAttributeMetaInfo: virtual public IAttributeMetaInfo
{
public:
	void SetAttributeDescription(const QString& description);
	void SetAttributeTypeId(const QByteArray& typeId);
	void SetAttributeFlags(int attributeFlags);
	void SetAttributeDefaultValue(const iser::IObject* defaultValuePtr, bool releaseFlag);

	// reimplemented (iattr::IAttributeMetaInfo)
	virtual QString GetAttributeDescription() const;
	virtual const iser::IObject* GetAttributeDefaultValue() const;
	virtual QByteArray GetAttributeTypeId() const;
	virtual int GetAttributeFlags() const;

private:
	QString m_description;
	QByteArray m_attributeTypeId;
	int m_attributeFlags;
	istd::TOptDelPtr<const iser::IObject> m_defaultValuePtr;
};


} // namespace iattr


#endif // !iattr_CAttributeMetaInfo_included


