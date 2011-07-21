/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iprm_CParamsManagerComp_included
#define iprm_CParamsManagerComp_included


// STL includes
#include <vector>


// ACF includes
#include "istd/TSmartPtr.h"

#include "imod/CMultiModelBridgeBase.h"

#include "icomp/CComponentBase.h"

#include "iprm/IParamsSet.h"
#include "iprm/ISelectionParam.h"
#include "iprm/ISelectionConstraints.h"
#include "iprm/IParamsManager.h"


namespace iprm
{


/**
	Implementation of parameter manager.
*/
class CParamsManagerComp:
			public icomp::CComponentBase,
			virtual public IParamsManager,
			virtual public ISelectionConstraints,
			protected imod::CMultiModelBridgeBase
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CParamsManagerComp);
		I_REGISTER_INTERFACE(ISelectionParam);
		I_REGISTER_INTERFACE(IParamsManager);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(ISelectionConstraints);
		I_ASSIGN_MULTI_0(m_fixedParamSetsCompPtr, "FixedParamSets", "List of references to fixed parameter set", false);
		I_ASSIGN_MULTI_0(m_fixedSetNamesCompPtr, "FixedSetNames", "List of fixed parameter names", false);
		I_ASSIGN(m_defaultSetNameCompPtr, "DefaultSetName", "Default name of parameter set", true, "<noname>");
		I_ASSIGN(m_paramSetsFactPtr, "ParamsSetFactory", "Factory of variable parameter set", false, "ParamsSet");
	I_END_COMPONENT;

	CParamsManagerComp();

	bool SetSetsCount(int count);

	// reimplemented (iprm::IParamsManager)
	virtual int GetManagerFlags() const;
	virtual int GetParamsSetsCount() const;
	virtual bool InsertParamsSet(int index = -1);
	virtual bool RemoveParamsSet(int index);
	virtual IParamsSet* GetParamsSet(int index) const;
	virtual const istd::CString& GetParamsSetName(int index) const;
	virtual bool SetParamsSetName(int index, const istd::CString& name);

	// reimplemented (iprm::ISelectionParam)
	virtual const ISelectionConstraints* GetConstraints() const;
	virtual int GetSelectedOptionIndex() const;
	virtual bool SetSelectedOptionIndex(int index);
	virtual ISelectionParam* GetActiveSubselection() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (iprm::ISelectionConstraints)
	virtual int GetOptionsCount() const;
	virtual istd::CString GetOptionName(int index) const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_MULTIREF(IParamsSet, m_fixedParamSetsCompPtr);
	I_MULTIATTR(istd::CString, m_fixedSetNamesCompPtr);
	I_ATTR(istd::CString, m_defaultSetNameCompPtr);
	I_FACT(IParamsSet, m_paramSetsFactPtr);

	struct ParamSet
	{
		istd::TSmartPtr<IParamsSet> paramSetPtr;
		istd::CString name;
	};

	typedef std::vector<ParamSet> ParamSets;

	ParamSets m_paramSets;

	int m_selectedIndex;
};


} // namespace iprm


#endif // !iprm_CParamsManagerComp_included


