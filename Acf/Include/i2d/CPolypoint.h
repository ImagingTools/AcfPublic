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


#ifndef i2d_CPolypoint_included
#define i2d_CPolypoint_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include "iser/CArchiveTag.h"
#include "iser/ISerializable.h"

#include "i2d/CVector2d.h"


namespace i2d
{


class CPolypoint: public iser::ISerializable
{
public:
	CPolypoint();

	void Insert(const i2d::CVector2d& vector);
	void Clear();
	const ::QVector<i2d::CVector2d>& GetPoints() const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	::QVector<i2d::CVector2d> m_points;
};


// inline methods

inline CPolypoint::CPolypoint()
{
}


inline void CPolypoint::Insert(const i2d::CVector2d& vector)
{
	m_points.push_back(vector);
}


inline void CPolypoint::Clear()
{
	m_points.clear();
}


inline const ::QVector<i2d::CVector2d>& CPolypoint::GetPoints() const
{
	return m_points;
}


} // namespace i2d


#endif // !i2d_CPolypoint_included

