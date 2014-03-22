/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef i2d_TObject2dCompWrap_included
#define i2d_TObject2dCompWrap_included


// ACF includes
#include "icomp/CComponentBase.h"
#include "i2d/ICalibration2d.h"
#include "i2d/IObject2d.h"


namespace i2d
{


/**
	Base class for all components implementing 2D objects.
	The template parameter \c BaseObject2d should be set to non-component 2D object implementing interface \c i2d::IObject2d.
*/
template <class BaseObject2d>
class TObject2dCompWrap: public icomp::CComponentBase, public BaseObject2d
{
public:
	typedef icomp::CComponentBase BaseClass;
	typedef BaseObject2d BaseClass2;

	I_BEGIN_COMPONENT(TObject2dCompWrap);
		I_REGISTER_INTERFACE(IObject2d);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_ASSIGN(m_calibrationCompPtr, "Calibration", "Calibration associated with this 2d object", false, "Calibration");
	I_END_COMPONENT;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	I_REF(i2d::ICalibration2d, m_calibrationCompPtr);
};


// protected methods

// reimplemented (icomp::CComponentBase)

template <class BaseObject2d>
void TObject2dCompWrap<BaseObject2d>::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	BaseClass2::SetCalibration(m_calibrationCompPtr.GetPtr(), false);
}


} // namespace i2d


#endif // !i2d_TObject2dCompWrap_included


