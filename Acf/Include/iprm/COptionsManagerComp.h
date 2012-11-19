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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
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
	virtual QString GetOptionName(int index) const;
	virtual QString GetOptionDescription(int index) const;
	virtual QByteArray GetOptionId(int index) const;
	virtual bool IsOptionEnabled(int index) const;
	virtual void SetOptionEnabled(int index, bool isEnabled = true);

	// reimplemented (iprm::IOptionsManager)
	virtual void RemoveOption(int index);
	virtual bool InsertOption(
					QString& optionName,
					const QByteArray& optionId,
					const QString& optionDescription = QString(), 
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

		OptionInfo(const QString& optionName, QByteArray optionId, const QString& optionDescription)
			:optionName(optionName),
			optionId(optionId),
			optionDescription(optionDescription)
		{
		}

		QString optionName;
		QByteArray optionId;
		QString optionDescription;
		bool isEnabled;
	};

	typedef QVector<OptionInfo> Options;

	Options m_options;


private:
	I_REF(iprm::ISelectionConstraints, m_slaveSelectionConstraintsCompPtr);
};


} // namespace iprm


#endif // !iprm_COptionsManagerComp_included


