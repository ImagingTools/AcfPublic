/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


#ifndef iorn_ILearningSet_included
#define iorn_ILearningSet_included


// ACF includes
#include "istd/IChangeable.h"

#include "iorn/iorn.h"


namespace iorn
{


class CHypothesesSet;


/**
	Represent learning set.
	Learning set consists of set of hypothesis sets, one hypothesis set for one example.
*/
class ILearningSet: virtual istd::IChangeable
{
public:
	/**
		Get number of possible hypotheses.
	*/
	virtual int GetSetsCount() const = 0;

	/**
		Get access to single hypothesis set.
		\param	index	index of hypothesis set.
						For performance reasons the progressive access will be prefered.
		\param	weight	output value of weight of hypothesis set.
		\return	hypothesis set at specified index, or NULL if no hypothesis set can be accessed.
	*/
	virtual const CHypothesesSet* GetSingleSet(int index, double& weight) const;
};


} // namespace iorn


#endif // !iorn_ILearningSet_included


