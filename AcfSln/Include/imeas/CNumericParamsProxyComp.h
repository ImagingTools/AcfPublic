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


#pragma once


// ACF includes
#include <icomp/CComponentBase.h>
#include <imod/CModelUpdateBridge.h>
#include <iprm/IOptionsList.h>
#include <imeas/INumericValue.h>
#include <imeas/INumericConstraints.h>
#include <iser/IArchive.h>


namespace imeas
{


/**
	Component implementating proxy for several imeas::INumericValue interfaces.
*/
class CNumericParamsProxyComp:
			public icomp::CComponentBase,
			virtual public imeas::INumericValue,
			virtual public imeas::INumericConstraints,
			virtual public iprm::IOptionsList,
			protected imod::CModelUpdateBridge
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef imod::CModelUpdateBridge BaseClass2;

	I_BEGIN_COMPONENT(CNumericParamsProxyComp);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(imeas::INumericValue);
		I_REGISTER_INTERFACE(imeas::INumericConstraints);
		I_ASSIGN_MULTI_0(m_valuesPtr, "Values", "Values to proxy", true);
		I_ASSIGN_TO(m_valueModelsPtr, m_valuesPtr, true);
		I_ASSIGN_MULTI_0(m_valueIndexPtr, "Indexes", "Value indexes to proxy", true);
	I_END_COMPONENT;

	CNumericParamsProxyComp();

	// reimplemented (imeas::INumericConstraints)
	virtual const iprm::IOptionsList& GetValueListInfo() const override;
	virtual const imath::IUnitInfo* GetNumericValueUnitInfo(int index) const override;

	// reimplemented (imeas::INumericValue)
	virtual bool IsValueTypeSupported(ValueTypeId valueTypeId) const override;
	virtual const INumericConstraints* GetNumericConstraints() const override;
	virtual imath::CVarVector GetComponentValue(ValueTypeId valueTypeId) const override;
	virtual imath::CVarVector GetValues() const override;
	virtual bool SetValues(const imath::CVarVector& values) override;

	// reimplemented (iprm::IOptionsList)
	virtual int GetOptionsFlags() const override;
	virtual int GetOptionsCount() const override;
	virtual QString GetOptionName(int index) const override;
	virtual QString GetOptionDescription(int index) const override;
	virtual QByteArray GetOptionId(int index) const override;
	virtual bool IsOptionEnabled(int index) const override;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

	// reimplemented (IChangeable)
	virtual bool CopyFrom(const IChangeable& /*object*/, CompatibilityMode /*mode*/) override;

protected:
	// reimplemented (imeas::INumericValue)
	//virtual void OnUpdate(const istd::IChangeable::ChangeSet& changeSet) override;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;
	virtual void OnComponentDestroyed() override;

private:
	I_MULTIREF(imeas::INumericValue, m_valuesPtr);
	I_MULTIREF(imod::IModel, m_valueModelsPtr);
	I_MULTIATTR(int, m_valueIndexPtr);
};


} // namespace imeas

