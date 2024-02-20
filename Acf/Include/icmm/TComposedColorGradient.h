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


#ifndef icmm_TComposedColorGradient_included
#define icmm_TComposedColorGradient_included	


// Qt includes
#include <QtCore/QPair>

// ACF includes
#include <istd/TRange.h>
#include <icmm/TColorGradient.h>


namespace icmm
{


/**
	Implementation of color gradient based 
	on set of defined gradients for each subintervall of the full range.
*/
template <class Gradient>
class TComposedColorGradient: virtual public IColorTransformation
{
public:
	void AddGradient(const istd::CRange& intervall, const Gradient& gradient);

	// reimplemented (icmm::IColorTransformation)
	virtual bool GetValueAt(const Argument& argument, Result& result) const;
	virtual Result GetValueAt(const Argument& argument) const;

private:
	typedef QPair<istd::CRange, Gradient> IntervalGradient;
	typedef QVector<IntervalGradient> Gradients;
	
	Gradients m_gradients;
};


// public methods

template <class GradientFunction>
void TColorGradient<GradientFunction>::AddGradient(const istd::CRange& intervall, const Gradient& gradient)
{
	m_gradients.push_back(std::make_pair<istd::CRange, Gradient>(intervall, gradient));
}


// reimplemented (icmm::IColorTransformation)

template <class GradientFunction>
bool TColorGradient<GradientFunction>::GetValueAt(const Argument& argument, Result& result) const
{
	for (int gradientIndex = 0; gradientIndex < int(m_gradients.size()); gradientIndex++){
		IntervalGradient gradient = m_gradients[gradientIndex];

		if (gradient.first.Contains(argument)){
			return gradient.second.GetValueAt(argument, result);
		}
	}
	
	return false;
}


template <class GradientFunction>
TColorGradient<GradientFunction>::Result TColorGradient<GradientFunction>::GetValueAt(const Argument& argument) const
{
	ResultType result;

	GetValueAt(argument, result);

	return result;
}


typedef TComposedColorGradient<CLinearGradient> CComposedLinearGradient;


} // namespace icmm


#endif // !icmm_TComposedColorGradient_included


