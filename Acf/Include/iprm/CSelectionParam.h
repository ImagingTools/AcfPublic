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


#ifndef iprm_CSelectionParam_included
#define iprm_CSelectionParam_included


#include "iser/ISerializable.h"

#include "iprm/ISelectionParam.h"


namespace iprm
{


/**
	Basic implementation of selection parameter.
*/
class CSelectionParam: virtual public ISelectionParam
{
public:
	CSelectionParam();

	void SetSelectionConstraints(const ISelectionConstraints* constraintsPtr);

	/**
		Set selection index according to a given option ID.
	*/
	bool SetSelectedOptionById(const QByteArray& selectedOptionId);

	// reimplemented (iprm::ISelectionParam)
	virtual const ISelectionConstraints* GetSelectionConstraints() const;
	virtual int GetSelectedOptionIndex() const;
	virtual bool SetSelectedOptionIndex(int index);
	virtual ISelectionParam* GetActiveSubselection() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	int m_selectedOptionIndex;

private:
	const ISelectionConstraints* m_constraintsPtr;
};


} // namespace iprm


#endif // !iprm_CSelectionParam_included


