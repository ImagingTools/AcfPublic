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


#ifndef isig_CSamplingParamsComp_included
#define isig_CSamplingParamsComp_included


// ACF includes
#include "iser/ISerializable.h"
#include "icomp/CComponentBase.h"

#include "isig/ISamplingConstraints.h"
#include "isig/ISamplingParams.h"


namespace isig
{


/**
	General implementation of sampling parameters.
	In this implementation the boundaries are fix defined using component attributes.
*/
class CSamplingParamsComp: public icomp::CComponentBase, virtual public isig::ISamplingParams
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSamplingParamsComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(isig::ISamplingParams);
		I_ASSIGN(m_samplingConstraintsCompPtr, "SamplingConstraints", "Information about acceptable values for this parameters", false, "SamplingConstraints");
	I_END_COMPONENT

	CSamplingParamsComp();

	// reimplemented (isig::ISamplingParams)
	virtual const ISamplingConstraints* GetConstraints() const;
	virtual double GetInterval() const;
	virtual void SetInterval(double value);
	virtual int GetSamplingMode() const;
	virtual bool SetSamplingMode(int mode);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	double m_interval;
	int m_samplingMode;

	I_REF(ISamplingConstraints, m_samplingConstraintsCompPtr);
};


} // namespace isig


#endif // !isig_CSamplingParamsComp_included


