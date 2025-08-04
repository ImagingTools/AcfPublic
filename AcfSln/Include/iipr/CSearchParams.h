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


#ifndef iipr_CSearchParams_included
#define iipr_CSearchParams_included


// ACF includes
#include <iimg/CGeneralBitmap.h>

// ACF-Solutions includes
#include <iipr/ISearchParams.h>


namespace iipr
{


/**
	Definition of standard search parameters.
*/
class CSearchParams: virtual public iipr::ISearchParams
{
public:
	CSearchParams();
	
	// reimplemented (iipr::ISearchParams)
	virtual const ISearchConstraints* GetSearchConstraints() const override;
	virtual double GetMinScore() const override;
	virtual void SetMinScore(double minScore) override;
	virtual const istd::CRange& GetRotationRange() const override;
	virtual void SetRotationRange(const istd::CRange& angleRange) override;
	virtual const istd::CRange& GetScaleRange() const override;
	virtual void SetScaleRange(const istd::CRange& scaleRange) override;
	virtual int GetNominalModelsCount() const override;
	virtual void SetNominalModelsCount(int nominalModelsCount) override;
	virtual bool IsRotationEnabled() const; 
	virtual void SetRotationEnabled(bool isRotationEnabled);
	virtual bool IsScaleEnabled() const;
	virtual void SetScaleEnabled(bool isScaleEnabled);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive) override;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const istd::IChangeable& object, istd::IChangeable::CompatibilityMode /*mode*/ = CM_WITHOUT_REFS) override;

protected:
	istd::CRange m_angleRange;
	istd::CRange m_scaleRange;
	int m_nominalModelsCount = -1;
	double m_minScore = 0.6;
	bool m_isRotationEnabled = false;
	bool m_isScaleEnabled = false;
};


} // namespace iipr


#endif // !iipr_CSearchParams_included


