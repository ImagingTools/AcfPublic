/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iwiz/CWizardDocumentComp.h"


// ACF includes
#include "istd/TChangeNotifier.h"

#include "iproc/IStateController.h"


namespace iwiz
{


// reimplemented (iwiz::IParamsManagerWizard)

bool CWizardDocumentComp::IsPageSelectionAllowed(int pageIndex) const
{
	if ((pageIndex < 0) || (pageIndex >= GetParamsSetsCount())){
		return false;
	}

	int currentPageIndex = GetSelectedOptionIndex();

	const iproc::IStateController* destPageInfoPtr = CompCastPtr<const iproc::IStateController>(GetParamsSet(pageIndex));
	if ((destPageInfoPtr != NULL) && !destPageInfoPtr->IsStateEnabled()){
		return false;
	}

	for (		int checkPageIndex = istd::Max(currentPageIndex, 0);
				checkPageIndex < pageIndex;
				++checkPageIndex){
		const iproc::IStateController* checkedPageInfoPtr = CompCastPtr<const iproc::IStateController>(GetParamsSet(checkPageIndex));
		if ((checkedPageInfoPtr != NULL) && checkedPageInfoPtr->IsStateEnabled() && !checkedPageInfoPtr->IsLeaveAllowed()){
			return false;
		}
	}

	return true;
}


// reimplemented (iwiz::IWizardNavigationController)

bool CWizardDocumentComp::IsFinishAllowed() const
{
	int pagesCount = GetParamsSetsCount();

	for (int checkPageIndex = 0; checkPageIndex < pagesCount; ++checkPageIndex){
		const iproc::IStateController* checkedPageInfoPtr = CompCastPtr<const iproc::IStateController>(GetParamsSet(checkPageIndex));
		if ((checkedPageInfoPtr != NULL) && checkedPageInfoPtr->IsStateEnabled() && !checkedPageInfoPtr->IsLeaveAllowed()){
			return false;
		}
	}

	return true;
}


int CWizardDocumentComp::GetPrevPageIndex() const
{
	int currentPageIndex = GetSelectedOptionIndex();

	for (int checkPageIndex = currentPageIndex - 1; checkPageIndex >= 0; --checkPageIndex){
		const iproc::IStateController* checkedPageInfoPtr = CompCastPtr<const iproc::IStateController>(GetParamsSet(checkPageIndex));
		if ((checkedPageInfoPtr == NULL) || checkedPageInfoPtr->IsStateEnabled()){
			return checkPageIndex;
		}
	}

	return -1;
}


int CWizardDocumentComp::GetNextPageIndex() const
{
	int pagesCount = GetParamsSetsCount();
	int currentPageIndex = GetSelectedOptionIndex();

	if (currentPageIndex >= 0){
		const iproc::IStateController* currentPageInfoPtr = CompCastPtr<const iproc::IStateController>(GetParamsSet(currentPageIndex));
		if ((currentPageInfoPtr != NULL) && !currentPageInfoPtr->IsLeaveAllowed()){
			return -1;
		}
	}

	for (int checkPageIndex = currentPageIndex + 1; checkPageIndex < pagesCount; ++checkPageIndex){
		const iproc::IStateController* checkedPageInfoPtr = CompCastPtr<const iproc::IStateController>(GetParamsSet(checkPageIndex));
		if ((checkedPageInfoPtr == NULL) || checkedPageInfoPtr->IsStateEnabled()){
			return checkPageIndex;
		}
	}

	return -1;
}


bool CWizardDocumentComp::DoWizardFinish()
{
	int pagesCount = GetParamsSetsCount();
	int currentPageIndex = GetSelectedOptionIndex();

	istd::CChangeNotifier notifier(this);

	for (int checkPageIndex = currentPageIndex + 1; checkPageIndex < pagesCount; ++checkPageIndex){
		iproc::IStateController* checkedPageInfoPtr = CompCastPtr<iproc::IStateController>(GetParamsSet(checkPageIndex));
		if ((checkedPageInfoPtr == NULL) || !checkedPageInfoPtr->IsStateEnabled()){
			continue;
		}

		if (!SetSelectedOptionIndex(checkPageIndex)){
			return false;
		}
	}

	return true;
}


// reimplemented (iprm::ISelectionParam)

bool CWizardDocumentComp::SetSelectedOptionIndex(int index)
{
	int currentPageIndex = BaseClass::GetSelectedOptionIndex();
	if (index == currentPageIndex){
		return true;
	}

	if (!IsPageSelectionAllowed(index)){
		return false;
	}

	int pagesCount = GetParamsSetsCount();

	iproc::IStateController* currentPageInfoPtr = NULL;
	if ((currentPageIndex >= 0) && (currentPageIndex < pagesCount)){
		currentPageInfoPtr = CompCastPtr<iproc::IStateController>(GetParamsSet(currentPageIndex));
	}

	iproc::IStateController* nextPageInfoPtr = NULL;
	if ((index >= 0) && (index < pagesCount)){
		nextPageInfoPtr = CompCastPtr<iproc::IStateController>(GetParamsSet(index));
	}

	istd::CChangeNotifier notifier(this);

	bool isNextPage = (index == GetNextPageIndex());

	if (currentPageInfoPtr != NULL){
		if (!currentPageInfoPtr->TryLeaveState(isNextPage, nextPageInfoPtr)){
			return false;
		}
	}

	if ((nextPageInfoPtr == NULL) || nextPageInfoPtr->TryEnterState(isNextPage, currentPageInfoPtr)){
		return BaseClass::SetSelectedOptionIndex(index);
	}
	else{
		return BaseClass::SetSelectedOptionIndex(-1);
	}
}


} // namespace iwiz


