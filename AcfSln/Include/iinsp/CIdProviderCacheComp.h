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


#ifndef iinsp_CIdProviderCacheComp_included
#define iinsp_CIdProviderCacheComp_included


// ACF includes
#include <icomp/CComponentBase.h>

// ACF-Solutions includes
#include <iinsp/IIdProvider.h>


namespace iinsp
{


/**
	General ID provider returning always stored ID.
	Stored ID can be changed only copying their from another ID provider using CopyFrom method.
	This object will be used to manage threading barrier for object supplier chain.
*/
class CIdProviderCacheComp:
			public icomp::CComponentBase,
			virtual public IIdProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CIdProviderCacheComp);
		I_REGISTER_INTERFACE(IIdProvider);
	I_END_COMPONENT;

	CIdProviderCacheComp();

	// reimplemented (iinsp::IIdProvider)
	virtual quint32 GetCurrentId() const;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);

private:
	int m_currentId;
};


} // namespace iinsp


#endif // !iinsp_CIdProviderCacheComp_included


