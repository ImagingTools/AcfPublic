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


#ifndef ipackage_CComponentAccessor_included
#define ipackage_CComponentAccessor_included


// ACF includes
#include "istd/TDelPtr.h"
#include "icomp/IComponentStaticInfo.h"
#include "icomp/IComponentContext.h"
#include "icomp/CCompositeComponent.h"


namespace ipackage
{

	
/**
	A helper class to access public interfaces of a composite component.
*/
class CComponentAccessor
{
public:
	/**
		Constructor.
		
		\param	registryFile	The registry file.
		\param	configFile  	(Optional) the configuration file.
	*/
	explicit CComponentAccessor(
				const QString& registryFile, 
				const QString& configFile = QString());

	/**
		Gets component interface.
	
		\tparam	InterfaceType	Type of the interface.
		\param	componentId	(Optional) identifier for the component.
		
		\return	null if it fails, else the requested component interface.
	*/
	template <class InterfaceType>
	InterfaceType* GetComponentInterface(const QByteArray& componentId = QByteArray());

private:
	icomp::CCompositeComponent m_mainComponent;

	istd::TDelPtr<icomp::IComponentStaticInfo> m_mainComponentStaticInfoPtr;
	istd::TDelPtr<icomp::IComponentContext> m_mainComponentContextPtr;

	bool m_isAutoInitBlocked;
};


template <class InterfaceType>
InterfaceType* CComponentAccessor::GetComponentInterface(const QByteArray& componentId)
{
	InterfaceType* interfacePtr = m_mainComponent.GetComponentInterface<InterfaceType>(componentId);

	return interfacePtr;
}


} // namespace ipackage


#endif // !ipackage_CComponentAccessor_included


