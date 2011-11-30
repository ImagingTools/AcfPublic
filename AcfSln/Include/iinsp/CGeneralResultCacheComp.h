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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iinsp_CGeneralResultCacheComp_included
#define iinsp_CGeneralResultCacheComp_included


// ACF includes
#include "icomp/CComponentBase.h"

// ACF-Solutions includes
#include "iinsp/IGeneralResultProvider.h"


namespace iinsp
{


class CGeneralResultCacheComp:
			public icomp::CComponentBase,
			virtual public IGeneralResultProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CGeneralResultCacheComp);
		I_REGISTER_INTERFACE(IGeneralResultProvider);
	I_END_COMPONENT;

	CGeneralResultCacheComp();

	// reimplemented (iinsp::IGeneralResultProvider)
	virtual GeneralResult GetGeneralResult() const;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object);

private:
	GeneralResult m_result;
};


} // namespace iinsp


#endif // !iinsp_CGeneralResultCacheComp_included


