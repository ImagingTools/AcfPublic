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


#ifndef istd_CStaticServicesProvider_included
#define istd_CStaticServicesProvider_included


// STL includes
#include <map>


// ACF includes
#include "istd/IServicesProvider.h"
#include "istd/TIFactory.h"
#include "istd/TSmartPtr.h"
#include "istd/CClassInfo.h"


namespace istd
{


/**
	Manage list of global services.

	\ingroup System
*/
class CStaticServicesProvider
{
public:
	/**
		Set parent provider.
		This provider will be used if this static service provider has no registered service for specified type.
	*/
	static void InitServices(const IServicesProvider* parentPtr);
	/**
		Register service for specified ID.
	*/
	static bool RegisterService(const istd::CClassInfo& info, void* servicePtr);
	/**
		Register factory for specified ID.
	*/
	static bool RegisterFactory(const istd::CClassInfo& info, const IVoidFactory* factoryPtr);
	/**
		Register service for specified ID.
	*/
	template <class Service>
	static bool RegisterService(Service* servicePtr);
	/**
		Register service for specified ID.
	*/
	template <class Interface>
	static bool RegisterFactory(const TIFactory<Interface>* factoryPtr);
	static void* GetService(const istd::CClassInfo& info);
	static void* CreateService(const istd::CClassInfo& info);
	static IServicesProvider& GetProviderInstance();

protected:
	class Provider: virtual public IServicesProvider
	{
	public:
		// reimplemented (istd::IServicesProvider)
		virtual void* GetService(const istd::CClassInfo& info) const;
		virtual void* CreateService(const istd::CClassInfo& info) const;
	};

private:
	/**
		Lock of constructor.
	*/
	CStaticServicesProvider(){}

	typedef std::map<istd::CClassInfo, void*> Services;
	typedef std::map<istd::CClassInfo, const IVoidFactory*> Factories;

	static Services s_registeredServices;
	static Factories s_registeredFactories;
	static Provider s_providerInstance;
	static const IServicesProvider* s_parentPtr;
};


// public template methods

template <class Service>
bool CStaticServicesProvider::RegisterService(Service* servicePtr)
{
	static istd::CClassInfo info = istd::CClassInfo::GetInfo<Service>();

	return RegisterService(info, servicePtr);
}


template <class Interface>
bool CStaticServicesProvider::RegisterFactory(const TIFactory<Interface>* factoryPtr)
{
	static istd::CClassInfo info = istd::CClassInfo::GetInfo<Interface>();

	return RegisterFactory(info, reinterpret_cast<const IVoidFactory*>(factoryPtr));
}


// public template functions

/**
	Allow to access some global service from anywhere.

	\ingroup System
*/
template <typename Service>
Service* GetService()
{
	static istd::CClassInfo info = istd::CClassInfo::GetInfo<Service>();

	return static_cast<Service*>(CStaticServicesProvider::GetService(info));
}


/**
	Allow to create a new service instance from anywhere.

	\ingroup System
*/
template <typename Service>
TTransPtr<Service> CreateService()
{
	static istd::CClassInfo info = istd::CClassInfo::GetInfo<Service>();

	void* instancePtr = CStaticServicesProvider::CreateService(info);

	return TSmartPtr<Service>(static_cast<Service*>(instancePtr));
}


} // namespace istd


#endif // !istd_CStaticServicesProvider_included


