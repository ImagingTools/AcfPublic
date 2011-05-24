/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef ifpf_CHotfolderStatistics_included
#define ifpf_CHotfolderStatistics_included


// STL includes
#include <map>


// ACF includes
#include "imod/TSingleModelObserverBase.h"


// AcfSln includes
#include "ifpf/IHotfolderStatistics.h"
#include "ifpf/IHotfolderProcessingInfo.h"


namespace ifpf
{


/**
	Standard implementation if the IHotfolderStatistics interface.
	Statistics data is calculated and updated by observing the changes in the hotfolder state model.
*/
class CHotfolderStatistics: 
			virtual public ifpf::IHotfolderStatistics,
			public imod::TSingleModelObserverBase<ifpf::IHotfolderProcessingInfo>
{
public:
	typedef imod::TSingleModelObserverBase<ifpf::IHotfolderProcessingInfo> BaseClass;

	CHotfolderStatistics();

	// reimplemented (ifpf::IHotfolderStatistics)
	virtual int GetItemsCount(const istd::CString& directoryPath = istd::CString()) const;
	virtual int GetSuccessCount(const istd::CString& directoryPath = istd::CString()) const;
	virtual int GetErrorsCount(const istd::CString& directoryPath = istd::CString()) const;
	virtual int GetAbortedCount(const istd::CString& directoryPath = istd::CString()) const;
	virtual double GetProcessingTime(const istd::CString& directoryPath = istd::CString()) const;

	// reimplemented (imod::TSingleModelObserverBase)
	virtual void OnUpdate(int updateFlags, istd::IPolymorphic* updateParamsPtr);

	// reimplemented (imod::IObserver)
	virtual bool OnAttached(imod::IModel* modelPtr);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	void ResetStatistics();
	void RebuildStatistics();
	void UpdateStateMaps(int itemState, const istd::CString& directoryPath);
	static istd::CString GetDirectoryPath(const ifpf::IHotfolderProcessingItem& item);

private:
	typedef std::map<istd::CString, int> CounterMap;
	CounterMap m_itemsCount;
	CounterMap m_successCount;
	CounterMap m_errorsCount;
	CounterMap m_abortedCount;

	typedef std::map<istd::CString, double> ProcessingTimeMap;
	ProcessingTimeMap m_processingTimeMap;
};


} // namespace ifpf


#endif // !ifpf_CHotfolderStatistics_included


