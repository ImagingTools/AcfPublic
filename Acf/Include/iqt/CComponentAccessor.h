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


#ifndef iqt_CComponentAccessor_included
#define iqt_CComponentAccessor_included


#include "icomp/CCompositeComponent.h"
#include "icomp/CCompositeComponentStaticInfo.h"
#include <icomp/CPackageStaticInfo.h>

namespace iqt
{


/**
 Loads a registry from an ARX file and provides access to its component interfaces.
 */
class CComponentAccessor
{
public:
	explicit CComponentAccessor(
			const QString& registryFile,
			const QString& configFile = QString());

	~CComponentAccessor();

	template <class InterfaceType>
	InterfaceType* GetComponentInterface(const QByteArray& componentId = QByteArray());

private:
	QString m_registryFile;

	icomp::CCompositeComponent m_composite;

	bool m_isAutoInitBlocked;

	icomp::CPackageStaticInfo* m_packageStaticInfo;
};


template <class InterfaceType>
InterfaceType* CComponentAccessor::GetComponentInterface(const QByteArray& componentId)
{
	InterfaceType* interfacePtr = m_composite.GetComponentInterface<InterfaceType > (componentId);

	if ((interfacePtr != NULL) && m_isAutoInitBlocked){
		m_composite.EndAutoInitBlock();

		m_isAutoInitBlocked = false;
	}

	return interfacePtr;
}


} // namespace iqt


#endif // !iqt_CComponentAccessor_included


