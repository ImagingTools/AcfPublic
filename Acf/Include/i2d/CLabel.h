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


#ifndef i2d_CLabel_included
#define i2d_CLabel_included


// ACF includes
#include "istd/CIndex2d.h"

#include "iser/CArchiveTag.h"

#include "i2d/CPosition2d.h"


namespace i2d
{


class CLabel: public i2d::CPosition2d
{
public:
	typedef i2d::CPosition2d BaseClass;

	CLabel(const i2d::CVector2d& position = i2d::CVector2d(0, 0), const istd::CString& labelText = "Label");

	virtual const istd::CString& GetText() const;
	virtual void SetText(const istd::CString& labelText);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	istd::CString m_text;
};


// inline methods

inline const istd::CString& CLabel::GetText() const
{
	return m_text;
}


} // namespace i2d


#endif // !i2d_CLabel_included


