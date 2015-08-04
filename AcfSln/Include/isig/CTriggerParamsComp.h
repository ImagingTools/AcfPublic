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


#ifndef isig_CTriggerParamsComp_included
#define isig_CTriggerParamsComp_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include "icomp/CComponentBase.h"
#include "iprm/ISelectionParam.h"
#include "iprm/IOptionsList.h"

// ACF-Solutions includes
#include "isig/ITriggerConstraints.h"
#include "isig/ITriggerParams.h"


namespace isig
{


/**
	Implementation of standard trigger parameters set.
*/
class CTriggerParamsComp:
			public icomp::CComponentBase,
			virtual public isig::ITriggerParams,
			virtual public iprm::ISelectionParam,
			virtual protected iprm::IOptionsList
{
public:
	typedef icomp::CComponentBase BaseClass;

	CTriggerParamsComp();

	I_BEGIN_COMPONENT(CTriggerParamsComp);
		I_REGISTER_INTERFACE(isig::ITriggerParams);
		I_REGISTER_INTERFACE(iprm::ISelectionParam);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_triggerConstraintsCompPtr, "Constraints", "Describing allowed parameter state, typically implemented in camera component", false, "Constraints");
		I_ASSIGN(m_triggerModeAttrPtr, "TriggerMode", "Set trigger mode:\n\t0 - None\n\t1 - Continuous\n\t2 - Rising edge\n\t3 - Falling edge\n\t4 - Positive level\n\t5 - Negative level\n\t6 - Software", true, 0);
	I_END_COMPONENT;

	// reimplemented (isig::ITriggerParams)
	virtual const ITriggerConstraints* GetTriggerConstraints() const;
	virtual int GetTriggerMode() const;
	virtual void SetTriggerMode(int triggerMode);

	// reimplemented (iprm::ISelectionParam)
	virtual const iprm::IOptionsList* GetSelectionConstraints() const;
	virtual int GetSelectedOptionIndex() const;
	virtual bool SetSelectedOptionIndex(int index);
	virtual iprm::ISelectionParam* GetSubselection(int index) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	void InitializeSelectionList();

	// reimplemented (iprm::IOptionsList)
	virtual int GetOptionsFlags() const;
	virtual int GetOptionsCount() const;
	virtual QString GetOptionName(int index) const;
	virtual QString GetOptionDescription(int index) const;
	virtual QByteArray GetOptionId(int index) const;
	virtual bool IsOptionEnabled(int index) const;

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	int m_triggerMode;

	struct SelectionEntry
	{
		QString name;
		QString description;
		int triggerMode;
	};
	typedef QVector<SelectionEntry> SelectionList;
	SelectionList m_selectionList;

	I_REF(isig::ITriggerConstraints, m_triggerConstraintsCompPtr);
	I_ATTR(int, m_triggerModeAttrPtr);
};


} // namespace isig


#endif // !isig_CTriggerParamsComp_included


