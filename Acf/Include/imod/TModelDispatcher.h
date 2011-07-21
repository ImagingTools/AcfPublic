/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef imod_TModelDispatcher_included
#define imod_TModelDispatcher_included


// STL includes
#include <map>


// ACF includes
#include "imod/CMultiModelObserverBase.h"


namespace imod
{


/**
	Generic implementation of a model change notifier.

	Notifier class must implement the method 
	\code void OnModelChanged(int modelId, int changeFlags, istd::IPolymorphic* updateParamsPtr),
	to support the notification callback.
*/
template <class NotifyReceiver>
class TModelDispatcher: protected imod::CMultiModelObserverBase
{
public:
	TModelDispatcher(NotifyReceiver& parent)
		:m_parent(parent)
	{
	}

	bool RegisterModel(imod::IModel* modelPtr, int modelId = 0)
	{
		if (modelPtr->AttachObserver(this)){
			m_modelMap[modelPtr] = modelId;

			return true;
		}

		return false;
	}

	void UnregisterModel(int modelId = 0)
	{
		for (ModelMap::iterator index = m_modelMap.begin(); index != m_modelMap.end(); index++){
			if (modelId == index->second){
				imod::IModel* modelPtr = index->first;

				m_modelMap.erase(index);

				modelPtr->DetachObserver(this);
			}
		}
	}

protected:
	// reimplemented (imod::CMultiModelObserverBase)

	virtual void OnUpdate(imod::IModel* modelPtr, int changeFlags, istd::IPolymorphic* updateParamsPtr)
	{
		ModelMap::iterator foundModelIter = m_modelMap.find(modelPtr);
		if (foundModelIter != m_modelMap.end()){
			int modelId = foundModelIter->second;

			m_parent.OnModelChanged(modelId, changeFlags, updateParamsPtr);
		}
	}

private:
	typedef std::map<imod::IModel*, int> ModelMap;

	ModelMap m_modelMap;

	NotifyReceiver& m_parent;
};

} // namespace imod


#endif // !imod_TModelDispatcher_included

