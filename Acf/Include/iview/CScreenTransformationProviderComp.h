/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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


#ifndef iview_CScreenTransformationProviderComp_included
#define iview_CScreenTransformationProviderComp_included


// ACF includes
#include <icomp/CComponentBase.h>
#include <iview/IScreenTransformationProvider.h>


namespace iview
{


class CScreenTransformationProviderComp : public icomp::CComponentBase, public IScreenTransformationProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CScreenTransformationProviderComp);
		I_REGISTER_INTERFACE(IScreenTransformationProvider);
	I_END_COMPONENT;

	CScreenTransformationProviderComp();

	virtual istd::TSmartPtr<iview::CScreenTransform> GetTransformation() const override;

private:
	istd::TSmartPtr<iview::CScreenTransform> m_transformPtr;
};




} // namespace iview


#endif // !iview_CColorSchemaComp_included


