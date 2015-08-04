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


#ifndef iipr_CColorPatternControllerComp_included
#define iipr_CColorPatternControllerComp_included


// ACF includes
#include "iser/ISerializable.h"
#include "imod/TModelWrap.h"
#include "ilog/TLoggerCompWrap.h"
#include "iimg/CGeneralBitmap.h"

// ACF-Solutions includes
#include "iproc/IProcessor.h"
#include "imeas/IDataSequenceProvider.h"
#include "imeas/TDiscreteDataSequence.h"
#include "iipr/IPatternController.h"
#include "iimg/IBitmapProvider.h"


namespace iipr
{


class CColorPatternControllerComp:
			virtual public ilog::CLoggerComponentBase,
			virtual public IPatternController,
			virtual public iimg::IBitmapProvider,
			virtual public imeas::IDataSequenceProvider,
			virtual public iser::ISerializable
{
public:
	typedef ilog::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(CColorPatternControllerComp);
		I_REGISTER_INTERFACE(IPatternController);
		I_REGISTER_INTERFACE(iimg::IBitmapProvider);
		I_REGISTER_INTERFACE(imeas::IDataSequenceProvider);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_ASSIGN(m_patternBitmapProviderCompPtr, "PatternBitmapProvider", "Provider of the bitmap pattern data used for teaching", true, "PatternBitmapProvider");
		I_ASSIGN(m_bitmapRegionCompPtr, "TeachingRegion", "Bitmap region used for teaching", true, "TeachingRegion");
		I_ASSIGN(m_histogramProgressorCompPtr, "HistogramProcessor", "Processor used for histogram calculation", true, "HistogramProcessor");
		I_ASSIGN(m_paramsSetCompPtr, "ProcessorParams", "Params set used by histogram processor", true, "ProcessorParams");
	I_END_COMPONENT;

	// reimplemented (iipr::IPatternController)
	virtual bool TeachPattern(const istd::IChangeable* sourceObjectPtr = NULL);
	virtual void ResetPattern();
	virtual bool IsPatternValid() const;
	const iser::ISerializable* GetPatternObject() const;

	// reimplemented (iimg::IBitmapProvider)
	virtual const iimg::IBitmap* GetBitmap() const;

	// reimplemented (imeas::IDataSequenceProvider)
	virtual const imeas::IDataSequence* GetDataSequence() const;
	
	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive & archive);

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);

private:
	imod::TModelWrap<iimg::CGeneralBitmap> m_patternBitmap;
	imod::TModelWrap<imeas::CSimpleSamplesSequence32> m_histogram;

	I_REF(iimg::IBitmapProvider, m_patternBitmapProviderCompPtr);
	I_REF(i2d::IObject2d, m_bitmapRegionCompPtr);
	I_REF(iproc::IProcessor, m_histogramProgressorCompPtr);
	I_REF(iprm::IParamsSet, m_paramsSetCompPtr);
};


} // namespace iipr


#endif // !iipr_CColorPatternControllerComp_included


