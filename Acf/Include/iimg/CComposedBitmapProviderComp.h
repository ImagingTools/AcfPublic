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


#ifndef iimg_CComposedBitmapProviderComp_included
#define iimg_CComposedBitmapProviderComp_included


// ACF includes
#include <iimg/IBitmapProvider.h>
#include <iimg/IMultiBitmapProvider.h>
#include <icomp/CComponentBase.h>
#include <imod/CModelUpdateBridge.h>
#include <iprm/COptionsManager.h>


namespace iimg
{


/**
	Component for composition/grouping of more single bitmap providers.

	\ingroup ImageProcessing
	\ingroup Geometry
*/
class CComposedBitmapProviderComp: 
			public icomp::CComponentBase,
			virtual public iimg::IMultiBitmapProvider,
			protected iprm::COptionsManager
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CComposedBitmapProviderComp);
		I_REGISTER_INTERFACE(iimg::IMultiBitmapProvider);
		I_ASSIGN_MULTI_0(m_bitmapProvidersCompPtr, "BitmapProviders", "List of input bitmap providers", true);
		I_ASSIGN_TO(m_bitmapProviderModelsCompPtr, m_bitmapProvidersCompPtr, false);
		I_ASSIGN_MULTI_0(m_bitmapLabelsAttrPtr, "BitmapLabels", "List of bitmap labels", false);
		I_ASSIGN_MULTI_0(m_bitmapDescriptionsAttrPtr, "BitmapDescriptions", "List of bitmap descriptions", false);
	I_END_COMPONENT;

	CComposedBitmapProviderComp();

	// reimplemented (iimg::IMultiBitmapProvider)
	virtual const iprm::IOptionsList* GetBitmapListInfo() const override;
	virtual int GetBitmapsCount() const override;
	virtual const iimg::IBitmap* GetBitmap(int bitmapIndex) const override;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;
	virtual void OnComponentDestroyed() override;

private:
	I_MULTIREF(iimg::IBitmapProvider, m_bitmapProvidersCompPtr);
	I_MULTIREF(imod::IModel, m_bitmapProviderModelsCompPtr);
	I_MULTITEXTATTR(m_bitmapLabelsAttrPtr);
	I_MULTITEXTATTR(m_bitmapDescriptionsAttrPtr);

	imod::CModelUpdateBridge m_updateBridge;
};


} // namespace iimg


#endif // !iimg_CComposedBitmapProviderComp_included


