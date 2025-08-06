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


#ifndef iinsp_CComposedInformationProviderComp_included
#define iinsp_CComposedInformationProviderComp_included


// ACF includes
#include <istd/IInformationProvider.h>
#include <icomp/CComponentBase.h>
#include <imod/CModelUpdateBridge.h>


namespace iinsp
{


/**
	General information provider returning always stored state.
	Stored result state can be changed only copying their from another result provider using CopyFrom method.
	This object will be used to manage threading barrier for object supplier chain.
*/
class CComposedInformationProviderComp:
			public icomp::CComponentBase,
			virtual public istd::IInformationProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CComposedInformationProviderComp);
		I_REGISTER_INTERFACE(IInformationProvider);
		I_ASSIGN(m_defaultSourceAttrPtr, "DefaultSource", "Default source of information", false, "");
		I_ASSIGN(m_defaultDescriptionAttrPtr, "DefaultDescription", "Default description for the information", false, "");
		I_ASSIGN_MULTI_0(m_slaveInformationProvidersCompPtr, "InformationProviders", "List of underlaying information providers", true);
		I_ASSIGN_TO(m_slaveInformationProviderModelsCompPtr, m_slaveInformationProvidersCompPtr, false);
	I_END_COMPONENT;

	CComposedInformationProviderComp();

	// reimplemented (iinsp::IInformationProvider)
	virtual QDateTime GetInformationTimeStamp() const;
	virtual InformationCategory GetInformationCategory() const;
	virtual int GetInformationId() const;
	virtual QString GetInformationDescription() const;
	virtual QString GetInformationSource() const;
	virtual int GetInformationFlags() const;

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated() override;
	virtual void OnComponentDestroyed() override;

private:
	I_ATTR(QString, m_defaultSourceAttrPtr);
	I_TEXTATTR(m_defaultDescriptionAttrPtr);
	I_MULTIREF(istd::IInformationProvider, m_slaveInformationProvidersCompPtr);
	I_MULTIREF(imod::IModel, m_slaveInformationProviderModelsCompPtr);

	imod::CModelUpdateBridge m_updateBridge;
};


} // namespace iinsp


#endif // !iinsp_CComposedInformationProviderComp_included


