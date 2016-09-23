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


#ifndef iattr_CAttributesMetaInfoProvider_included
#define iattr_CAttributesMetaInfoProvider_included


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include <istd/TOptDelPtr.h>
#include <iattr/IAttributesMetaInfoProvider.h>


namespace iattr
{


/**
	Common interface for a container of properties.
*/
class CAttributesMetaInfoProvider: virtual public IAttributesMetaInfoProvider
{
public:
	/**
		Remove all attribute meta infos.
	*/
	virtual void RemoveAllAttributeMetaInfos();
	/**
		Insert an property into the object.
		\param	attributeId				unique ID of the property in the properties repository.
		\param	attributeMetaInfoPtr	attribute meta info object.
		\param	releaseFlag				if true, this attribute meta info will be deleted by manager.
		\return	true, if this attribute could be added or false elesewhere.
	*/
	virtual bool InsertAttributeMetaInfo(
				const QByteArray& attributeId,
				IAttributeMetaInfo* attributeMetaInfoPtr,
				bool releaseFlag);
	/**
		Check if this provider has some attribute ID.
	*/
	bool HasAttributeMetaId(const QByteArray& attributeId) const;

	// reimplemented (iattr::IAttributesMetaInfoProvider)
	virtual IAttributesProvider::AttributeIds GetAttributeMetaIds() const;
	virtual const IAttributeMetaInfo* GetAttributeMetaInfo(const QByteArray& attributeId) const;

private:
	typedef istd::TOptDelPtr<IAttributeMetaInfo> AttributeMetaInfoPtr;
	typedef QMap<QByteArray, AttributeMetaInfoPtr> AttributesMetaInfoMap;
	AttributesMetaInfoMap m_attributesMetaInfoMap;
};


} // namespace iattr


#endif // !iattr_CAttributesMetaInfoProvider_included


