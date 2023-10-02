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


#ifndef icomp_CComponentContext_included
#define icomp_CComponentContext_included


// Qt includes
#include <QtCore/QByteArray>
#include <QtCore/QMap>
#include <QtCore/QMutex>

// ACF includes
#include <icomp/IComponentContext.h>


namespace icomp
{


class IRegistryElement;


/**
	Base implementation of component session context.
	This implementation uses icomp::IRegistryElement to generate lilst of attributes.
	Please note that resolving of exported attribute is done.
*/
class CComponentContext: virtual public IComponentContext
{
public:
	CComponentContext(
				const IRegistryElement* elementPtr,
				const IComponentStaticInfo* staticInfoPtr,
				const IComponentContext* parentPtr,
				const QByteArray& contextId);

	QByteArray GetCompleteContextId() const;

	// reimplemented (icomp::IComponentContext)
	virtual const QByteArray& GetContextId() const;
	virtual const IRegistryElement& GetRegistryElement() const;
	virtual const IComponentStaticInfo& GetStaticInfo() const;
	virtual const IComponentContext* GetParentContext() const;
	virtual const iser::IObject* GetAttribute(const QByteArray& attributeId, int* definitionLevelPtr = NULL) const;

	// static methods
	/**
		Get address of this component identifying it in component topology hierarchy.
	*/
	static QByteArray GetHierarchyAddress(const IComponentContext* contextPtr);

protected:
	struct AttributeInfo
	{
		const iser::IObject* attributePtr;
		int definitionLevel;
	};

	bool CalcAttributeInfo(const QByteArray& attributeId, AttributeInfo& result) const;

private:
	const IRegistryElement& m_registryElement;
	const IComponentStaticInfo& m_staticInfo;

	const IComponentContext* m_parentPtr;

	typedef QMap<QByteArray, AttributeInfo> AttributeMap;
	mutable AttributeMap m_attributeMap;

	QByteArray m_contextId;

#if QT_VERSION >= 0x060000
	mutable QRecursiveMutex m_attributeMapMutex;
#else
	mutable QMutex m_attributeMapMutex;
#endif
};


} // namespace icomp


#endif // !icomp_CComponentContext_included


