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


#ifndef isig_CSamplingParamsComp_included
#define isig_CSamplingParamsComp_included


// ACF includes
#include <iser/ISerializable.h>
#include <icomp/CComponentBase.h>

#include <isig/ISamplingConstraints.h>
#include <isig/ISamplingParams.h>


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
		I_ASSIGN(m_samplingConstraintsCompPtr, "Constraints", "Information about acceptable values for this parameters", false, "Constraints");
	I_END_COMPONENT;

	CSamplingParamsComp();

	// reimplemented (isig::ISamplingParams)
	virtual const ISamplingConstraints* GetSamplingConstraints() const;
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


