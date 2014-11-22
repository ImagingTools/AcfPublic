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


#ifndef iprm_CParamsManagerComp_included
#define iprm_CParamsManagerComp_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include "istd/TDelPtr.h"
#include "imod/TModelWrap.h"
#include "iprm/CParamsManagerCompBase.h"


namespace iprm
{


/**
	Implementation of parameter manager.
*/
class CParamsManagerComp: public iprm::CParamsManagerCompBase
{
public:
	typedef CParamsManagerCompBase BaseClass;

	I_BEGIN_COMPONENT(CParamsManagerComp);
		I_REGISTER_INTERFACE(ISelectionParam);
		I_REGISTER_INTERFACE(IParamsManager);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(IOptionsManager);
		I_REGISTER_INTERFACE(IOptionsList);
		I_ASSIGN(m_paramSetsFactPtr, "ParamsSetFactory", "Factory of variable parameter set", false, "ParamsSet");
	I_END_COMPONENT;

	bool SetSetsCount(int count);

	// reimplemented (iprm::IParamsManager)
	virtual const IOptionsList* GetParamsTypeConstraints() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (iprm::IOptionsManager)
	virtual int GetOptionOperationFlags(int index = -1) const;
	virtual bool SetOptionEnabled(int index, bool isEnabled = true);
	virtual bool RemoveOption(int index);
	virtual bool InsertOption(
				const QString& optionName,
				const QByteArray& optionId,
				const QString& optionDescription = QString(),
				int index = -1);
	virtual bool SwapOptions(int index1, int index2);
	virtual bool SetOptionName(int optionIndex, const QString& optionName);
	virtual bool SetOptionDescription(int optionIndex, const QString& optionDescription);

protected:
	// reimplemented (CParamsManagerCompBase)
	virtual bool IsParameterCreationSupported() const;
	virtual int GetCreatedParamsSetsCount() const;
	virtual iprm::IParamsSet* CreateParamsSet(int typeIndex = -1) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	int FindParamSetIndex(const QString& name) const;

private:
	I_FACT(IParamsSet, m_paramSetsFactPtr);
};


} // namespace iprm


#endif // !iprm_CParamsManagerComp_included


