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


#ifndef iinsp_CInformationProviderCacheComp_included
#define iinsp_CInformationProviderCacheComp_included


// ACF includes
#include <istd/IInformationProvider.h>
#include <icomp/CComponentBase.h>


namespace iinsp
{


/**
	General information provider returning always stored state.
	Stored result state can be changed only copying their from another result provider using CopyFrom method.
	This object will be used to manage threading barrier for object supplier chain.
*/
class CInformationProviderCacheComp:
			public icomp::CComponentBase,
			virtual public istd::IInformationProvider
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CInformationProviderCacheComp);
		I_REGISTER_INTERFACE(IInformationProvider);
		I_ASSIGN(m_defaultSourceAttrPtr, "DefaultSource", "Default source of information. Will be used if no information source was set", false, "Unknown");
	I_END_COMPONENT;

	CInformationProviderCacheComp();

	// reimplemented (iinsp::IInformationProvider)
	virtual QDateTime GetInformationTimeStamp() const;
	virtual InformationCategory GetInformationCategory() const;
	virtual int GetInformationId() const;
	virtual QString GetInformationDescription() const;
	virtual QString GetInformationSource() const;
	virtual int GetInformationFlags() const;

	// reimplemented (istd::IChangeable)
	virtual bool CopyFrom(const IChangeable& object, CompatibilityMode mode = CM_WITHOUT_REFS);
	virtual bool ResetData(CompatibilityMode mode = CM_WITHOUT_REFS);

private:
	QDateTime m_timeStamp;
	InformationCategory m_category;
	int m_id;
	QString m_description;
	QString m_source;
	int m_flags;

	I_ATTR(QString, m_defaultSourceAttrPtr);
};


} // namespace iinsp


#endif // !iinsp_CInformationProviderCacheComp_included


