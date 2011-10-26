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


#ifndef iwiz_CWizardPageComp_included
#define iwiz_CWizardPageComp_included


#include "imod/CMultiModelDispatcherBase.h"

#include "iprm/CComposedParamsSetComp.h"

#include "iwiz/IWizardPageInfo.h"
#include "iwiz/IWizardPageController.h"


namespace iwiz
{


/**
	Component implementation of a wizard page.
*/
class CWizardPageComp:
			public iprm::CComposedParamsSetComp,
			protected imod::CMultiModelDispatcherBase,
			virtual public iwiz::IWizardPageInfo
{
public:
	typedef iprm::CComposedParamsSetComp BaseClass;
	typedef imod::CMultiModelDispatcherBase BaseClass2;

	I_BEGIN_COMPONENT(CWizardPageComp);
		I_REGISTER_INTERFACE(iwiz::IWizardPageInfo);
		I_ASSIGN(m_pageControllerCompPtr, "PageController", "Wizard page controller", false, "PageController");
	I_END_COMPONENT;

	CWizardPageComp();

	// reimplemented (iwiz::IWizardPageInfo)
	virtual bool IsPageFinished() const;
	virtual void SetPageFinished(bool isPageFinished = true);

protected:
	// reimplemented (imod::CMultiModelDispatcherBase)
	virtual void OnModelChanged(int modelId, int changeFlags, istd::IPolymorphic* updateParamsPtr);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	bool m_isPageFinished;

	I_REF(iwiz::IWizardPageController, m_pageControllerCompPtr);
};


} // namespace iwiz


#endif // !iwiz_CWizardPageComp_included


