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


#ifndef iipr_CSearchParamsComp_included
#define iipr_CSearchParamsComp_included


// ACF includes
#include <icomp/CComponentBase.h>

// ACF-Solutions includes
#include <iipr/ISearchConstraints.h>
#include <iipr/CSearchParams.h>


namespace iipr
{


class CSearchParamsComp: 
			public icomp::CComponentBase,
			public CSearchParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSearchParamsComp);
		I_REGISTER_INTERFACE(iipr::ISearchParams);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_searchConstraintsCompPtr, "SearchConstaints", "Search parameters constraints", false, "SearchConstaints");
		I_ASSIGN(m_defaultModelOccuranceAttrPtr, "DefaultModelOccurance", "Default model occurance\n\t-1 - all models,\n\t0 - no models", true, -1);
		I_ASSIGN(m_defaultMinRotationAngleAttrPtr, "DefaultMinRotationAngle", "Default minimum rotation angle in degrees. Must be set together with DefaultMaxRotationAngle", false, -5.0);
		I_ASSIGN(m_defaultMaxRotationAngleAttrPtr, "DefaultMaxRotationAngle", "Default maximum rotation angle in degrees. Must be set together with DefaultMinRotationAngle", false, 5.0);
	I_END_COMPONENT;

	// reimplemented (iipr::ISearchParams)
	virtual const ISearchConstraints* GetSearchConstraints() const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(iipr::ISearchConstraints, m_searchConstraintsCompPtr);
	I_ATTR(int, m_defaultModelOccuranceAttrPtr);
	I_ATTR(double, m_defaultMinRotationAngleAttrPtr);
	I_ATTR(double, m_defaultMaxRotationAngleAttrPtr);
};


} // namespace iipr


#endif // !iipr_CSearchParamsComp_included


