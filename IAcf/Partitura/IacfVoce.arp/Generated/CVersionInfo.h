#ifndef CVersionInfo_included
#define CVersionInfo_included


// ACF includes
#include "icomp/IRegistriesManager.h"
#include "icomp/CRegistry.h"
#include "icomp/CCompositeComponent.h"
#include "icomp/CCompositeComponentContext.h"
#include "icomp/CCompositeComponentStaticInfo.h"
#include "icomp/CPackageStaticInfo.h"
#include "icomp/CCompositePackageStaticInfo.h"
#include "icomp/CEnvironmentManagerBase.h"


/**
	Version information for modules based directly on IACF.
*/
class CVersionInfo: protected icomp::CCompositeComponent
{
public:
	typedef icomp::CCompositeComponent BaseClass;
	
	template <class InterfaceType>
	InterfaceType* GetInterface(const std::string& subId = ""){return GetComponentInterface<InterfaceType>(subId);}

	CVersionInfo();

protected:
	/**
		Version information for modules based directly on IACF.
	*/
	class CMainRegistry: public icomp::CRegistry
	{
	public:
		CMainRegistry();
	};

	//	composited packages

	class CAcfSlnVocePck: public icomp::CCompositePackageStaticInfo
	{
	public:
		CAcfSlnVocePck(const icomp::IComponentEnvironmentManager* managerPtr);

		/**
			Version information for modules based directly on ACF-Solutions.
		*/
		class CVersionInfoRegistry: public icomp::CRegistry
		{
		public:
			CVersionInfoRegistry();
		};
	};

	class CAcfVocePck: public icomp::CCompositePackageStaticInfo
	{
	public:
		CAcfVocePck(const icomp::IComponentEnvironmentManager* managerPtr);

		/**
			Version information for modules based directly on ACF.
		*/
		class CVersionInfoRegistry: public icomp::CRegistry
		{
		public:
			CVersionInfoRegistry();
		};
	};

	//	real packages

	class CBasePck: public icomp::CPackageStaticInfo
	{
	public:
		typedef icomp::CPackageStaticInfo BaseClass;

		CBasePck();
	};

	class CLocalEnvironmentManager: public icomp::CEnvironmentManagerBase
	{
	public:
		typedef icomp::CEnvironmentManagerBase BaseClass;

		CLocalEnvironmentManager();

		// reimplemented (icomp::IRegistriesManager)
		virtual const icomp::IRegistry* GetRegistry(const icomp::CComponentAddress& address, const icomp::IRegistry* contextRegistryPtr = NULL) const;

	protected:
		typedef istd::TDelPtr<icomp::IRegistry> RegistryPtr;typedef std::map<icomp::CComponentAddress, RegistryPtr> RegistriesMap;

	private:
		CBasePck m_subBasePck;

		istd::TDelPtr<icomp::IComponentStaticInfo> m_packageAcfSlnVoceInfoPtr;
		istd::TDelPtr<icomp::IComponentStaticInfo> m_packageAcfVoceInfoPtr;

		RegistriesMap m_registriesMap;
	};

private:
	static icomp::CRegistryElement s_mainElement;
	static CMainRegistry s_mainRegistry;
	static CLocalEnvironmentManager s_localEnvironmentManager;
	static icomp::CCompositeComponentContext s_mainComponentContext;
};


#endif // !CVersionInfo_included

