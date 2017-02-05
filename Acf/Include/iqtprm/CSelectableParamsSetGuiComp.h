/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtprm_CSelectableParamsSetGuiComp_included
#define iqtprm_CSelectableParamsSetGuiComp_included


// ACF includes
#include <iprm/IParamsSet.h>
#include <iqtprm/CSelectableGuiComp.h>


namespace iqtprm
{


/**
	Editor for the selected parameter in the parameter manager.
	\sa iprm::IParamsManager
*/
class CSelectableParamsSetGuiComp: public iqtprm::CSelectableGuiComp
{
public:
	typedef iqtprm::CSelectableGuiComp BaseClass;

	I_BEGIN_COMPONENT(CSelectableParamsSetGuiComp);
		I_ASSIGN_MULTI_0(m_slaveObserversCompPtr, "Editors", "Editors for the parameters in the parameter set", true);
	I_END_COMPONENT;

public:
	CSelectableParamsSetGuiComp();

	// reimplemented (imod::CSingleModelObserverBase)
	virtual void BeforeUpdate(imod::IModel* modelPtr);
	virtual void AfterUpdate(imod::IModel* modelPtr, const istd::IChangeable::ChangeSet& changeSet);

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void OnGuiModelDetached();

private:
	void EnsureDetachLastEditor();
	void ConnectCurrentEditor();

	iprm::IParamsSet* ExtractParamsSetPtr(imod::IModel* modelPtr) const;

private:
	int m_currentParamsSetIndex;

	I_MULTIREF(imod::IObserver, m_slaveObserversCompPtr);
};


} // namespace iqtprm


#endif // !iqtprm_CSelectableParamsSetGuiComp_included


