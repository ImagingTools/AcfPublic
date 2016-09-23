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


#ifndef iqtprm_CParamsManagerGuiComp_included
#define iqtprm_CParamsManagerGuiComp_included


// ACF includes
#include <iqtprm/CParamsManagerGuiCompBase.h>


namespace iqtprm
{


/**
	Simple parameter manager editor using single paramer element editor.
	Due of single editor instance only one kind of elements is supported.
*/
class CParamsManagerGuiComp: public CParamsManagerGuiCompBase
{
public:
	typedef CParamsManagerGuiCompBase BaseClass;

	I_BEGIN_COMPONENT(CParamsManagerGuiComp);
		I_ASSIGN(m_paramsGuiCompPtr, "ParamsGui", "GUI object used to display parameters", false, "ParamsGui");
		I_ASSIGN_TO(m_paramsObserverCompPtr, m_paramsGuiCompPtr, false);
	I_END_COMPONENT;

protected:
	// reimplemented (CParamsManagerGuiCompBase)
	virtual imod::IObserver* GetObserverPtr(const iprm::IParamsSet* paramsSetPtr) const;
	virtual iqtgui::IGuiObject* GetEditorGuiPtr(const iprm::IParamsSet* paramsSetPtr) const;
	
	// reimplemented (iqtgui::CComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

private:
	I_REF(iqtgui::IGuiObject, m_paramsGuiCompPtr);
	I_REF(imod::IObserver, m_paramsObserverCompPtr);
};


} // namespace iqtprm


#endif // !iqtprm_CParamsManagerGuiComp_included


