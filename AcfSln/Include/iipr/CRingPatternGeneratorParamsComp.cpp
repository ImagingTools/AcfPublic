/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#include <iipr/CRingPatternGeneratorParamsComp.h>


// ACF includes
#include <iser/IArchive.h>
#include <iser/CArchiveTag.h>


#include <istd/CChangeNotifier.h>


namespace iipr
{


// public methods

CRingPatternGeneratorParamsComp::CRingPatternGeneratorParamsComp()
	:m_patternMode(PT_FIXED_WAVELENGTH),
	m_waveLength(4)
{
}


// reimplemented (iipr::IRingPatternGeneratorParams)

int CRingPatternGeneratorParamsComp::GetPatternMode() const
{
	return m_patternMode;
}


void CRingPatternGeneratorParamsComp::SetPatternMode(int patternMode)
{
	if (m_patternMode != patternMode){
		istd::CChangeNotifier changePtr(this);

		m_patternMode = patternMode;
	}
}


double CRingPatternGeneratorParamsComp::GetWaveLength() const
{
	return m_waveLength;
}


void CRingPatternGeneratorParamsComp::SetWaveLength(double waveLength)
{
	if (m_waveLength != waveLength){
		istd::CChangeNotifier changePtr(this);

		m_waveLength = waveLength;
	}
}


// reimplemented (iser::ISerializable)

bool CRingPatternGeneratorParamsComp::Serialize(iser::IArchive& archive)
{
	static iser::CArchiveTag patternModeTag("PatternMode", "Mode for pattern generation", iser::CArchiveTag::TT_LEAF);
	static iser::CArchiveTag waveLengthTag("WaveLength", "Pattern wave length", iser::CArchiveTag::TT_LEAF);

	istd::CChangeNotifier notifier(archive.IsStoring()? NULL: this);
	Q_UNUSED(notifier);

	bool retVal = true;

	retVal = retVal && archive.BeginTag(patternModeTag);
	retVal = retVal && archive.Process(m_patternMode);
	retVal = retVal && archive.EndTag(patternModeTag);

	retVal = retVal && archive.BeginTag(waveLengthTag);
	retVal = retVal && archive.Process(m_waveLength);
	retVal = retVal && archive.EndTag(waveLengthTag);

	return retVal;
}


// protected methods

// reimplemented (icomp::CComponentBase)

void CRingPatternGeneratorParamsComp::OnComponentCreated()
{
	BaseClass::OnComponentCreated();

	if (m_defaultPatternModeAttrPtr.IsValid()){
		m_patternMode = *m_defaultPatternModeAttrPtr;
	}

	if (m_defaultWaveLengthAttrPtr.IsValid()){
		m_waveLength = *m_defaultWaveLengthAttrPtr;
	}
}


} // namespace iipr


