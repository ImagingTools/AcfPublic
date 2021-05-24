/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iattr_CEnumAttributeMetaInfo_included
#define iattr_CEnumAttributeMetaInfo_included


// Qt includes
#include <QtCore/QList>

// ACF includes
#include <istd/TOptDelPtr.h>

// ACF-Solutions includes
#include <iattr/IEnumAttributeMetaInfo.h>
#include <iattr/CAttributeMetaInfo.h>


namespace iattr
{


/**
	Represents constraints of properties allowing values from enumerated set.
*/
class CEnumAttributeMetaInfo:
			public CAttributeMetaInfo,
			virtual public IEnumAttributeMetaInfo
{
public:
	typedef CAttributeMetaInfo BaseClass;

	explicit CEnumAttributeMetaInfo(const QByteArray& typeId = "");

	void SetOtherValueAllowed(bool state);
	/**
		Get descrition of unknown value;
		\sa	iattr::IEnumAttributeMetaInfo::GetValueDescription()
	*/
	const QString& GetUnknownDescription() const;
	/**
		Set descrition of unknown value;
		\sa	iattr::IEnumAttributeMetaInfo::GetValueDescription()
	*/
	void SetUnknownDescription(const QString& description);

	/**
		Insert new enumeration element.
		\param	description	human readable description of this enumeration element.
		\param	valuePtr	value of this enumeration element.
		\param	releaseFlag	if true, the value object will be managed by this object, it means it will be deleted from memory during destruction.
	*/
	bool InsertOption(const QString& description, const iser::IObject* valuePtr, bool releaseFlag);

	// reimplemented (iattr::IEnumAttributeMetaInfo)
	virtual bool IsAnyValueAllowed() const;
	virtual int GetEnumsCount() const;
	virtual QString GetValueDescription(const iser::IObject& value) const;
	virtual const iser::IObject& GetEnum(int index) const;

private:
	bool m_isAnyValueAllowed;
	struct EnumInfo
	{
		QString description;
		istd::TOptDelPtr<const iser::IObject> attributePtr;
	};
	typedef QList<EnumInfo> Enums;
	Enums m_enums;

	/**
		Description of unknown type;
	*/
	QString m_unknownDescription;
};


} // namespace iattr


#endif // !iattr_CEnumAttributeMetaInfo_included


