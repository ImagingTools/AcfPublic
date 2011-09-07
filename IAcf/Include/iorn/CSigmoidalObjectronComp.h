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


#ifndef iorn_CSigmoidalObjectronComp_included
#define iorn_CSigmoidalObjectronComp_included


// ACF includes
#include "imath/CVarMatrix.h"

#include "iorn/IObjectron.h"


namespace iorn
{


class CSigmoidalObjectronComp: virtual public IObjectron
{
public:
	// reimplemented (iorn::IObjectron)
	virtual double GetOperationQuality(int qualityQuery) const;
	virtual bool ProcessHypotheses(
				const CHypothesesSet& inputSet,
				CHypothesesSet& outputSet) const;
	virtual bool BackpropagateHypotheses(
				const CHypothesesSet* inputSetPtr,
				const CHypothesesSet& outputSet,
				CHypothesesSet& approxInputSet) const;
	virtual bool BackpropagateError(
				const CHypothesesSet& inputSet,
				double outputError,
				double& approxInputError,
				double& approxQuality) const;
	virtual int DoLearning(
				const ILearningSet& learningSet,
				const ILearnFeedback* learnFeedbackPtr,
				bool isProgressive = false);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	imath::CVarMatrix m_transformMatrix;
};


} // namespace iorn


#endif // !iorn_CSigmoidalObjectronComp_included


