/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iwiz_CWizardDocumentComp_included
#define iwiz_CWizardDocumentComp_included


#include <icomp/CComponentBase.h>

#include <iprm/CParamsManagerComp.h>

#include <iwiz/IWizardNavigationController.h>
#include <iwiz/IParamsManagerWizard.h>


namespace iwiz
{


/**
	Component implementation of a wizard controller.
*/
class CWizardDocumentComp:
			public iprm::CParamsManagerComp,
			virtual public IParamsManagerWizard
{
public:
	typedef iprm::CParamsManagerComp BaseClass;

	I_BEGIN_COMPONENT(CWizardDocumentComp);
		I_REGISTER_INTERFACE(IParamsManagerWizard);
		I_REGISTER_INTERFACE(IWizardNavigationController);
		I_ASSIGN(m_defaultPageIndexAttrPtr, "DefaultPageIndex", "Default page index", false, 0);
		I_ASSIGN_MULTI_0(m_additionalObjectsCompPtr, "AdditionalPersistentObjects", "List of components that have to be serialized together with wizard document", false);
	I_END_COMPONENT;

	// reimplemented (iwiz::IParamsManagerWizard)
	virtual bool IsPageSelectionAllowed(int pageIndex) const;

	// reimplemented (iwiz::IWizardNavigationController)
	virtual bool IsFinishAllowed() const;
	virtual int GetPrevPageIndex() const;
	virtual int GetNextPageIndex() const;
	virtual bool DoWizardFinish();

	// reimplemented (iprm::ISelectionParam)
	virtual bool SetSelectedOptionIndex(int index);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	virtual bool SerializeParamSets(iser::IArchive& archive);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_ATTR(int, m_defaultPageIndexAttrPtr);
	I_MULTIREF(iser::ISerializable, m_additionalObjectsCompPtr);
};


} // namespace iwiz


#endif // !iwiz_CWizardDocumentComp_included


