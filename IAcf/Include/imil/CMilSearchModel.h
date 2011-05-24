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


#ifndef imil_CMilSearchModel_included
#define imil_CMilSearchModel_included


#include "i2d/CRectangle.h"

#include "ibase/TLoggerCompWrap.h"

#include "iimg/CGeneralBitmap.h"

#include "iipr/ISearchModel.h"
#include "iipr/ISearchParams.h"

#include "imil/CMilEngine.h"


namespace imil
{


class CMilSearchParams;


class CMilSearchModel: virtual public iipr::ISearchModel
{
public:
	CMilSearchModel();
	~CMilSearchModel();

	void ReleaseMilContext();
	MIL_ID GetContextId() const;
	void EnsurePreprocessing(const imil::CMilSearchParams& params, bool preprocess = false) const;

	// reimplemented (iipr::ISearchModel)
	virtual bool IsModelValid() const;
	virtual void ResetModel();
	virtual const iimg::IBitmap& GetImage() const;
	bool CreateFromImage(const iimg::IBitmap& modelImage, const iipr::ISearchParams* params);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive & archive);
	
private:
	iimg::CGeneralBitmap m_modelImage;
	CMilEngine m_milEngine;
	MIL_ID m_milSearchContextId;
};


} // namespace imil


#endif // !imil_CMilSearchModel_included


