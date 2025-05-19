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


#ifndef iedge_CEdgeLineContainer_included
#define iedge_CEdgeLineContainer_included


// ACF includes
#include <ibase/TSerializableContainer.h>
#include <i2d/CObject2dBase.h>

// ACF-Solutions includes
#include <iedge/CEdgeLine.h>


namespace iedge
{


class CEdgeLineContainer:
			public ibase::TSerializableContainer<CEdgeLine, std::vector<CEdgeLine> >,
			public i2d::CObject2dBase
{
public:
	typedef ibase::TSerializableContainer<CEdgeLine, std::vector<CEdgeLine> > BaseClass;
	typedef i2d::CObject2dBase BaseClass2;

	// reimplemented (ibase::TContainer)
	virtual void Reserve(int count) override;
	virtual void Resize(int count) override;

	// reimplemented (i2d::CObject2dBase)
	virtual void SetCalibration(const i2d::ICalibration2d* calibrationPtr, bool releaseFlag = false) override;

	// reimplemented (i2d::IObject2d)
	virtual i2d::CVector2d GetCenter() const override;
	virtual void MoveCenterTo(const i2d::CVector2d& position) override;
	virtual i2d::CRectangle GetBoundingBox() const override;
	virtual bool Transform(
				const i2d::ITransformation2d& transformation,
				i2d::ITransformation2d::ExactnessMode mode = i2d::ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) override;
	virtual bool InvTransform(
				const i2d::ITransformation2d& transformation,
				i2d::ITransformation2d::ExactnessMode mode = i2d::ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) override;
	virtual bool GetTransformed(
				const i2d::ITransformation2d& transformation,
				i2d::IObject2d& result,
				i2d::ITransformation2d::ExactnessMode mode = i2d::ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) const override;
	virtual bool GetInvTransformed(
				const i2d::ITransformation2d& transformation,
				i2d::IObject2d& result,
				i2d::ITransformation2d::ExactnessMode mode = i2d::ITransformation2d::EM_NONE,
				double* errorFactorPtr = NULL) const override;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const istd::IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS) override;

protected:
	// reimplemented (ibase::TSerializableContainer)
	virtual bool SerializeItem(CEdgeLine& item, iser::IArchive& archive, iser::CArchiveTag* parentTagPtr = NULL) override;
};


inline void CEdgeLineContainer::Reserve(int count)
{
	if (count >= 0){
		m_items.reserve(count);
	}
}


inline void CEdgeLineContainer::Resize(int count)
{
	if (count >= 0){
		m_items.resize(count);
	}
}


} // namespace iedge


#endif // !iedge_CEdgeLineContainer_included


