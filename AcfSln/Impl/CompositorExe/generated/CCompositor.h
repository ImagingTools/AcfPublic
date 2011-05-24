#ifndef CCompositor_included
#define CCompositor_included


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
	Compositor application used to graphical edit ACF registry files.
*/
class CCompositor: protected icomp::CCompositeComponent
{
public:
	typedef icomp::CCompositeComponent BaseClass;
	
	template <class InterfaceType>
	InterfaceType* GetInterface(const std::string& subId = ""){return GetComponentInterface<InterfaceType>(subId);}

	CCompositor();

protected:
	/**
		Compositor application used to graphical edit ACF registry files.
	*/
	class CMainRegistry: public icomp::CRegistry
	{
	public:
		CMainRegistry();
	};

	//	composited packages

	class CAcfGuiVocePck: public icomp::CCompositePackageStaticInfo
	{
	public:
		CAcfGuiVocePck(const icomp::IComponentEnvironmentManager* managerPtr);

		/**
			Standard logging component with binded UI.
		*/
		class CLogRegistry: public icomp::CRegistry
		{
		public:
			CLogRegistry();
		};

		/**
			Log widget used as dock window.
		*/
		class CLogDockRegistry: public icomp::CRegistry
		{
		public:
			CLogDockRegistry();
		};

		/**
			Framework for multi-document applications.
		*/
		class CMultiDocAppRegistry: public icomp::CRegistry
		{
		public:
			CMultiDocAppRegistry();
		};

		/**
			Realization of the object persistence over Qt registry mechanism.
		*/
		class CSettingsPersistenceRegistry: public icomp::CRegistry
		{
		public:
			CSettingsPersistenceRegistry();
		};
	};

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

	class CCmpstrVocePck: public icomp::CCompositePackageStaticInfo
	{
	public:
		CCmpstrVocePck(const icomp::IComponentEnvironmentManager* managerPtr);

		/**
			Compositor attributes editor as docking window.
		*/
		class CAttributeEditorDockRegistry: public icomp::CRegistry
		{
		public:
			CAttributeEditorDockRegistry();
		};

		/**
			Docking window with compositor "Quick Help".
		*/
		class CClassHelpDockRegistry: public icomp::CRegistry
		{
		public:
			CClassHelpDockRegistry();
		};

		/**
			Compositor application component.
		*/
		class CCompositorApplicationRegistry: public icomp::CRegistry
		{
		public:
			CCompositorApplicationRegistry();
		};

		/**
			Main UI components of the Compositor.
		*/
		class CCompositorDockWidgetsRegistry: public icomp::CRegistry
		{
		public:
			CCompositorDockWidgetsRegistry();
		};

		/**
			Compositor settings.
		*/
		class CCompositorSettingsRegistry: public icomp::CRegistry
		{
		public:
			CCompositorSettingsRegistry();
		};

		/**
			Dialog displaying and managing compositor settings.
		*/
		class CCompositorSettingsDialogRegistry: public icomp::CRegistry
		{
		public:
			CCompositorSettingsDialogRegistry();
		};

		/**
			Document template for Compositor.
		*/
		class CCompositorTemplateRegistry: public icomp::CRegistry
		{
		public:
			CCompositorTemplateRegistry();
		};

		class CPackageOverviewDockRegistry: public icomp::CRegistry
		{
		public:
			CPackageOverviewDockRegistry();
		};

		class CVisualRegistryViewRegistry: public icomp::CRegistry
		{
		public:
			CVisualRegistryViewRegistry();
		};
	};

	//	real packages

	class CBasePck: public icomp::CPackageStaticInfo
	{
	public:
		typedef icomp::CPackageStaticInfo BaseClass;

		CBasePck();
	};

	class CCmpstrPck: public icomp::CPackageStaticInfo
	{
	public:
		typedef icomp::CPackageStaticInfo BaseClass;

		CCmpstrPck();
	};

	class CQtGuiPck: public icomp::CPackageStaticInfo
	{
	public:
		typedef icomp::CPackageStaticInfo BaseClass;

		CQtGuiPck();
	};

	class CQtPck: public icomp::CPackageStaticInfo
	{
	public:
		typedef icomp::CPackageStaticInfo BaseClass;

		CQtPck();
	};

	class CQtViewPck: public icomp::CPackageStaticInfo
	{
	public:
		typedef icomp::CPackageStaticInfo BaseClass;

		CQtViewPck();
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
		CCmpstrPck m_subCmpstrPck;
		CQtGuiPck m_subQtGuiPck;
		CQtPck m_subQtPck;
		CQtViewPck m_subQtViewPck;

		istd::TDelPtr<icomp::IComponentStaticInfo> m_packageAcfGuiVoceInfoPtr;
		istd::TDelPtr<icomp::IComponentStaticInfo> m_packageAcfSlnVoceInfoPtr;
		istd::TDelPtr<icomp::IComponentStaticInfo> m_packageAcfVoceInfoPtr;
		istd::TDelPtr<icomp::IComponentStaticInfo> m_packageCmpstrVoceInfoPtr;

		RegistriesMap m_registriesMap;
	};

private:
	static icomp::CRegistryElement s_mainElement;
	static CMainRegistry s_mainRegistry;
	static CLocalEnvironmentManager s_localEnvironmentManager;
	static icomp::CCompositeComponentContext s_mainComponentContext;
};


#endif // !CCompositor_included

