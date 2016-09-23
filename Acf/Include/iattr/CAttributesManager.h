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


#ifndef iattr_CAttributesManager_included
#define iattr_CAttributesManager_included


// Qt includes
#include <QtCore/QMap>

// ACF includes
#include <istd/TOptDelPtr.h>
#include <imod/CMultiModelBridgeBase.h>
#include <iser/IArchive.h>
#include <iser/IObject.h>
#include <iser/CArchiveTag.h>
#include <iattr/IAttributesManager.h>
#include <iattr/CStandardAttributesFactory.h>


namespace iattr
{


/**
	Basic implementation of an property container.
*/
class CAttributesManager: virtual public IAttributesManager
{
public:
	explicit CAttributesManager(const iser::IObjectFactory* factoryPtr = &CStandardAttributesFactory::GetInstance());

	void SetAttributesFactory(const iser::IObjectFactory* factoryPtr);

	// reimplemented (iattr::IAttributesManager)
	virtual void RemoveAllAttributes();
	virtual bool InsertAttribute(
				const QByteArray& attributeId,
				iser::IObject* attributePtr,
				bool releaseFlag);

	// reimplemented (iattr::IAttributesProvider)
	virtual AttributeIds GetAttributeIds() const;
	virtual iser::IObject* GetAttribute(const QByteArray& attributeId) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	typedef istd::TOptDelPtr<iser::IObject> AttributePtr;
	typedef QMap<QByteArray, AttributePtr> AttributesMap;
	AttributesMap m_attributesMap;

	const iser::IObjectFactory* m_attributesFactoryPtr;

	imod::CMultiModelBridgeBase m_attributesUpdateBridge;
};


} // namespace iattr


#endif // !iattr_CAttributesManager_included


