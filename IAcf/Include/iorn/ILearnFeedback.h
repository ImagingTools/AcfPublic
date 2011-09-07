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


#ifndef iorn_ILearnFeedback_included
#define iorn_ILearnFeedback_included


// ACF includes
#include "istd/IPolymorphic.h"


namespace iorn
{


/**
	Allow to calculate output for supervised learning.
*/
class ILearnFeedback: virtual public istd::IPolymorphic
{
public:
	enum LearningType
	{
		LT_EXAMPLE,
		LT_CRITIC
	};

	/**
		Get quality of some learning method supprted by this feedback.
		If returned value is smaller or equal to 0 requested learning type is not supported.
		\param	learningType	type of requested learning, \sa LearningType.
	*/
	virtual double GetLearningTypeQuality(int learningType) const = 0;

	/**
		Set enter learning step.
		\param	learningSet			reflected learning set from learn call.
		\param	learningSetIndex	index of hypotheses in learning set.
	*/
	virtual bool EnterLearningStep(
				const ILearningSet& learningSet,
				int learningSetIndex) = 0;

	/**
		Get output example for current learning step.
	*/
	virtual const CHypothesesSet* GetExample() const = 0;

	/**
		Get critic value for some output.
	*/
	virtual double GetCriticForOutput(const CHypothesesSet& outputSet) const = 0;
};


} // namespace iorn


#endif // !iorn_ILearnFeedback_included


