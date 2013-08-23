/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef CAbGuiComp_included
#define CAbGuiComp_included


// ACF includes
#include "iqtgui/TDesignerGuiObserverCompBase.h"


// Tutorial includes
#include "IAb.h"

#include "GeneratedFiles/CAbGuiComp/ui_CAbGuiComp.h"


/**
	UI-observer component of IAb interface.
*/
class CAbGuiComp: public iqtgui::TDesignerGuiObserverCompBase<Ui::CAbGuiComp, IAb>
{
	Q_OBJECT
public:
	typedef iqtgui::TDesignerGuiObserverCompBase<Ui::CAbGuiComp, IAb> BaseClass;
	
	I_BEGIN_COMPONENT(CAbGuiComp);
	I_END_COMPONENT;

protected:
	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);
	virtual void OnGuiModelAttached();

	// reimplemented (CGuiComponentBase)
	virtual void OnGuiCreated();

private Q_SLOTS:
	/**
		The function will be triggered on changes of A.
	*/
	void OnAValueChanged(int value);

	/**
		The function will be triggered on changes of B.
	*/
	void OnBValueChanged(const QString& value);
};


#endif // !CAbGuiComp_included


