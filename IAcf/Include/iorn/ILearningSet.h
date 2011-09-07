/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
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
**	by Skype to ACF_infoline for further information about the IACF.
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


