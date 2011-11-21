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


#ifndef iqtwiz_CWizardOptionsListGuiComp_included
#define iqtwiz_CWizardOptionsListGuiComp_included


// Qt includes
#include <QComboBox>
#include <QRadioButton>


// ACF includes
#include "istd/TPointerVector.h"

#include "iprm/IParamsManager.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iqtwiz/Generated/ui_CWizardOptionsListGuiComp.h"


namespace iqtwiz
{


/**
	An editor for an exclusive option selection implemented as a list of options.
*/
class CWizardOptionsListGuiComp:
			public iqtgui::TDesignerGuiObserverCompBase<
						Ui::CWizardOptionsListGuiComp, iprm::IParamsManager>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CWizardOptionsListGuiComp, iprm::IParamsManager> BaseClass;

	enum DataRole
	{
		DR_SELECTION_INDEX = Qt::UserRole + 1,
	};

	I_BEGIN_COMPONENT(CWizardOptionsListGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

protected Q_SLOTS:
	void on_OptionsList_itemSelectionChanged();

private:
	void CreateOptionsTree(const iprm::IParamsManager* paramsManagerPtr, QTreeWidgetItem* parentItemPtr = NULL);
};


} // namespace iqtwiz


#endif // !iqtwiz_CWizardOptionsListGuiComp_included


