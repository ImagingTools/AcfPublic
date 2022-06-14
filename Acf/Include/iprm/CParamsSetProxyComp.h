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


#pragma once


#include <icomp/CComponentBase.h>
#include <imod/CModelUpdateBridge.h>
#include <imod/TModelWrap.h>
#include <iprm/COptionsManager.h>
#include <iprm/CSelectionParam.h>
#include <iprm/IEnableableParam.h>
#include <iprm/IParamsSet.h>


namespace iprm
{


class CParamsSetProxyComp:
			public icomp::CComponentBase,
			virtual public iprm::IParamsSet,
			virtual public iprm::ISelectionParam
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CParamsSetProxyComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(IParamsSet);
		I_REGISTER_INTERFACE(ISelectionParam);
		I_ASSIGN_MULTI_0(m_optionNamesAttrPtr, "OptionNames", "Names of selectable options", true);
		I_ASSIGN_MULTI_0(m_optionDescriptionsAttrPtr, "OptionDescriptions", "Descriptions of selectable options", true);
		I_ASSIGN_MULTI_0(m_optionIdsAttrPtr, "OptionIds", "List of option IDs", true);
		I_ASSIGN_MULTI_0(m_paramsSetCompPtr, "ParamsSet", "List of ParamsSet", false);
		I_ASSIGN(m_defaultOptionIndexAttrPtr, "DefaultOptionIndex", "Default selected ParamsSet index", true, -1);
	I_END_COMPONENT;

	CParamsSetProxyComp();

	// reimplemented (iprm::IParamsSet)
	virtual Ids GetParamIds(bool editableOnly = false) const;
	virtual const iser::ISerializable* GetParameter(const QByteArray& id) const;
	virtual iser::ISerializable* GetEditableParameter(const QByteArray& id);

	// reimplemented (iprm::ISelectionParam)
	virtual const IOptionsList* GetSelectionConstraints() const override;
	virtual int GetSelectedOptionIndex() const override;
	virtual bool SetSelectedOptionIndex(int index) override;
	virtual ISelectionParam* GetSubselection(int index) const override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	IParamsSet* GetSelectedParamsSet() const;

private:
	I_MULTITEXTATTR(m_optionNamesAttrPtr);
	I_MULTITEXTATTR(m_optionDescriptionsAttrPtr);
	I_MULTIATTR(QByteArray, m_optionIdsAttrPtr);
	I_MULTIREF(IParamsSet, m_paramsSetCompPtr);
	I_ATTR(int, m_defaultOptionIndexAttrPtr);

	imod::TModelWrap<COptionsManager> m_paramsSetList;

	imod::CModelUpdateBridge m_selectionUpdateBridge;
	imod::CModelUpdateBridge m_paramsSetUpdateBridge;
};


} // namespace iprm


