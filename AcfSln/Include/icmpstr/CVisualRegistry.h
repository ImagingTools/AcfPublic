/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF-Solutions Toolkit.
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


#ifndef icmpstr_CVisualRegistryComp_included
#define icmpstr_CVisualRegistryComp_included


// Qt includes
#include <QtCore/QObject>


// ACF includes
#include <icomp/CRegistry.h>

#include <icmpstr/IComponentNoteController.h>
#include <icmpstr/CVisualRegistryElement.h>


namespace icmpstr
{


class CVisualRegistry:
			public QObject,
			public icomp::CRegistry,
			virtual public IComponentNoteController
{
public:
	typedef icomp::CRegistry BaseClass;

	enum MessageId
	{
		MI_CANNOT_CREATE_ELEMENT = 650
	};

	CVisualRegistry();

	virtual bool SerializeComponentsLayout(iser::IArchive& archive);
	virtual bool SerializeRegistry(iser::IArchive& archive);
	virtual bool SerializeUserData(iser::IArchive& archive);

	// reimplemented (icmpstr::IComponentNoteController)
	virtual QString GetComponentNote(const QByteArray& componentName);
	virtual void SetComponentNote(const QByteArray& componentName, const QString& componentNote);

	// reimplemented (icomp::IRegistry)
	virtual ElementInfo* InsertElementInfo(
				const QByteArray& elementId,
				const icomp::CComponentAddress& address,
				bool ensureElementCreated = true);
	virtual bool RenameElement(const QByteArray& oldElementId, const QByteArray& newElementId);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	typedef imod::TModelWrap<istd::TChangeDelegator<CVisualRegistryElement> > Element;
	typedef istd::TDelPtr<QIcon> IconPtr;
	typedef QMap<icomp::CComponentAddress, IconPtr> IconMap;

	bool SerializeComponentInfo(
				iser::IArchive& archive,
				QByteArray& componentName,
				i2d::CVector2d& position,
				QString& note);

	// reimplemented (icomp::CRegistry)
	virtual icomp::IRegistryElement* CreateRegistryElement(
				const QByteArray& elementId,
				const icomp::CComponentAddress& address) const;
	virtual icomp::IRegistry* InsertEmbeddedRegistry(const QByteArray& registryId);

private:
	bool m_serializeUserData;
};


} // namespace icmpstr


#endif // !icmpstr_CVisualRegistryComp_included


