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


#ifndef ifpf_CDirectoryMonitorParams_included
#define ifpf_CDirectoryMonitorParams_included


// AcfSln includes
#include "ifpf/IDirectoryMonitorParams.h"


namespace ifpf
{


/**
	Implementation of the IDirectoryMonitorParams interface.
*/
class CDirectoryMonitorParams: virtual public ifpf::IDirectoryMonitorParams
{
public:
	CDirectoryMonitorParams();

	// reimüplemented (ifpf::IDirectoryMonitorParams)
	virtual double GetPoolingIntervall() const;
	virtual void SetPoolingIntervall(double poolingIntervall);
	virtual int GetObservedItemTypes() const;
	virtual void SetObservedItemTypes(int observedItemTypes);
	virtual int GetObservedChanges() const;
	virtual void SetObservedChanges(int ovservedChanges);
	virtual istd::CStringList GetAcceptPatterns() const;
	virtual void SetAcceptPatterns(const istd::CStringList& acceptPatterns);
	virtual istd::CStringList GetIgnorePatterns() const;
	virtual void SetIgnorePatterns(const istd::CStringList& acceptPatterns);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	double m_poolingIntervall;
	int m_observedItemTypes;
	int m_observedChanges;

	istd::CStringList m_acceptPatterns;
	istd::CStringList m_ignorePatterns;
};


} // namespace ifpf


#endif // !ifpf_CDirectoryMonitorParams_included


