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


#ifndef iprm_COptionsManagerComp_included
#define iprm_COptionsManagerComp_included


#include "icomp/CComponentBase.h"

#include "iprm/IOptionsManager.h"
#include "iprm/ISelectionConstraints.h"


namespace iprm
{


/**
	Implementation of selection constraints.
*/
class COptionsManagerComp:
			public icomp::CComponentBase,
			virtual public iprm::IOptionsManager,
			virtual public iser::ISerializable,
			virtual public iprm::ISelectionConstraints
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(COptionsManagerComp);
		I_REGISTER_INTERFACE(iprm::ISelectionConstraints);
		I_REGISTER_INTERFACE(iprm::IOptionsManager);
		I_ASSIGN(m_slaveSelectionConstraintsCompPtr, "SlaveConstraints", "Slave constraints object", false, "SlaveConstraints");
	I_END_COMPONENT;

	// reimplemented (iprm::ISelectionConstraints)
	virtual int GetConstraintsFlags() const;
	virtual int GetOptionsCount() const;
	virtual istd::CString GetOptionName(int index) const;
	virtual istd::CString GetOptionDescription(int index) const;
	virtual std::string GetOptionId(int index) const;

	// reimplemented (iprm::IOptionsManager)
	virtual void RemoveOption(int index);
	virtual bool InsertOption(
					istd::CString& optionName,
					const std::string& optionId,
					const istd::CString& optionDescription = istd::CString(), 
					int index = -	1);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	struct OptionInfo
	{
		OptionInfo()
		{
		}

		OptionInfo(const istd::CString& optionName, std::string optionId, const istd::CString& optionDescription)
			:optionName(optionName),
			optionId(optionId),
			optionDescription(optionDescription)
		{
		}

		istd::CString optionName;
		std::string optionId;
		istd::CString optionDescription;
	};

	typedef std::vector<OptionInfo> Options;

	Options m_options;


private:
	I_REF(iprm::ISelectionConstraints, m_slaveSelectionConstraintsCompPtr);
};


} // namespace iprm


#endif // !iprm_COptionsManagerComp_included


