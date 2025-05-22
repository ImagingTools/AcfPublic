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


#ifndef iprm_CVariableParamComp_included
#define iprm_CVariableParamComp_included


// ACF includes
#include <imod/CModelUpdateBridge.h>
#include <icomp/CComponentBase.h>
#include <iprm/IVariableParam.h>


namespace iprm
{


class CVariableParamComp:
			public icomp::CComponentBase,
			virtual public IVariableParam
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CVariableParamComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(IVariableParam);
		I_ASSIGN_MULTI_0(m_factoriesFact, "Factories", "List of factories for each type", true);
		I_ASSIGN_MULTI_0(m_factoryIdsAttrPtr, "TypeIds", "List of factory ID for each factory object", true);
	I_END_COMPONENT;

	CVariableParamComp();

	// reimplemented (iprm::IVariableParam)
	virtual TypeIds GetKnownTypeIds() const;
	virtual QByteArray GetParameterTypeId() const;
	virtual iser::ISerializable* GetParameter() const;
	virtual bool AssignTypeId(const QByteArray& typeId);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;
	virtual quint32 GetMinimalVersion(int versionId) const override;

private:
	I_MULTIFACT(iser::ISerializable, m_factoriesFact);
	I_MULTIATTR(QString, m_factoryIdsAttrPtr);

	QByteArray m_paramTypeId;
	iser::ISerializableUniquePtr m_paramPtr;

	imod::CModelUpdateBridge m_updateBridge;
};


} // namespace iprm


#endif // !iprm_CVariableParamComp_included


