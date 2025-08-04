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


#ifndef iprm_CFilteredOptionsListComp_included
#define iprm_CFilteredOptionsListComp_included


// ACF includes
#include <iser/ISerializable.h>
#include <icomp/CComponentBase.h>
#include <iprm/IOptionsList.h>


namespace iprm
{


/**
	Implementation of an option list filter.
*/
class CFilteredOptionsListComp:
			public icomp::CComponentBase,
			virtual public iprm::IOptionsList
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CFilteredOptionsListComp);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_REGISTER_INTERFACE(iprm::IOptionsList);
		I_ASSIGN_MULTI_0(m_includeIdsAttrPtr, "IncludeOptionIds", "List of included (passed by filter) option IDs", true);
		I_ASSIGN(m_inputOptionsCompPtr, "InputOptionsList", "List of options to be filtered", true, "InputOptionsList");
	I_END_COMPONENT;

	// reimplemented (iprm::IOptionsList)
	virtual int GetOptionsFlags() const;
	virtual int GetOptionsCount() const;
	virtual QString GetOptionName(int index) const;
	virtual QString GetOptionDescription(int index) const;
	virtual QByteArray GetOptionId(int index) const;
	virtual bool IsOptionEnabled(int index) const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;

private:
	void UpdateOptions();

	static int GetOptionById(const iprm::IOptionsList& options, const QByteArray& optionId);

private:
	I_MULTIATTR(QByteArray, m_includeIdsAttrPtr);

	I_REF(iprm::IOptionsList, m_inputOptionsCompPtr);

	struct Option
	{
		QString description;
		QString name;
		QByteArray id;
		bool isEnabled;
	};

	typedef QVector<Option> Options;

	Options m_options;
};


} // namespace iprm


#endif // !iprm_CFilteredOptionsListComp_included


