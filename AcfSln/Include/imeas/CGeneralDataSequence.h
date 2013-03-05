/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef imeas_CGeneralDataSequence_included
#define imeas_CGeneralDataSequence_included


// Qt includes
#include <QtCore/QVector>

// ACF includes
#include "istd/TSmartPtr.h"
#include "istd/TOptDelPtr.h"
#include "imath/TISampledFunction.h"

#include "imeas/IDataSequence.h"


namespace imeas
{


/**
	General implementation of sample sequence interface IDataSequence.
*/
class CGeneralDataSequence:
			virtual public IDataSequence,
			virtual public imath::ISampledFunction2d
{
public:
	CGeneralDataSequence();

	const double* GetSamplesBuffer() const;
	double* GetSamplesBuffer();
	int GetSamplesBufferSize() const;

	// reimplemented (imeas::IDataSequence)
	virtual bool CreateSequence(int samplesCount, int channelsCount = 1);
	virtual bool CreateSequenceWithInfo(
				const istd::TTransPtr<const IDataSequenceInfo>& infoPtr,
				int samplesCount = -1,
				int channelsCount = -1);
	virtual const IDataSequenceInfo* GetSequenceInfo() const;
	virtual bool IsEmpty() const;
	virtual void ResetSequence();
	virtual int GetSamplesCount() const;
	virtual int GetChannelsCount() const;
	virtual double GetSample(int index, int channel = 0) const;
	virtual void SetSample(int index, int channel, double value);

	// reimplemented (imath::ISampledFunction2d)
	virtual bool CreateFunction(double* dataPtr, const ArgumentType& sizes);
	virtual int GetTotalSamplesCount() const;
	virtual int GetGridSize(int dimensionIndex) const;
	virtual istd::CRange GetLogicalRange(int dimensionIndex) const;
	virtual istd::CRange GetResultValueRange(int dimensionIndex, int resultDimension = -1) const;

	// reimplemented (imath::TIMathFunction)
	virtual bool GetValueAt(const ArgumentType& argument, ResultType& result) const;
	virtual ResultType GetValueAt(const ArgumentType& argument) const;

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (istd::IChangeable)
	virtual int GetSupportedOperations() const;
	virtual bool CopyFrom(const istd::IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);
	virtual istd::IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const;

private:
	typedef QVector<double> Samples;
	Samples m_samples;

	int m_channelsCount;

	istd::TSmartPtr<const IDataSequenceInfo> m_sequenceInfoPtr;
};


// inline methods

inline const double* CGeneralDataSequence::GetSamplesBuffer() const
{
	return &m_samples[0];
}


inline double* CGeneralDataSequence::GetSamplesBuffer()
{
	return &m_samples[0];
}


inline int CGeneralDataSequence::GetSamplesBufferSize() const
{
	return int(m_samples.size());
}


} // namespace imeas


#endif // !imeas_CGeneralDataSequence_included


