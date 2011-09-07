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


