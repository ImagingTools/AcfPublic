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


#ifndef iqtprm_CSelectionParamGuiComp_included
#define iqtprm_CSelectionParamGuiComp_included


// Qt includes
#include <QComboBox>
#include <QRadioButton>


// ACF includes
#include "istd/TPointerVector.h"

#include "iprm/ISelectionParam.h"

#include "iqtgui/TDesignerGuiObserverCompBase.h"

#include "iqtprm/Generated/ui_CSelectionParamGuiComp.h"


namespace iqtprm
{


/**
	Simple editor for an exclusive option selection.
*/
class CSelectionParamGuiComp:
			public iqtgui::TDesignerGuiObserverCompBase<
						Ui::CSelectionParamGuiComp, iprm::ISelectionParam>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CSelectionParamGuiComp, iprm::ISelectionParam> BaseClass;

	/**
		GUI mode for selection representation
	*/
	enum UiMode
	{
		/**
			Combo box selection
		*/
		UM_COMBOBOX,

		/**
			Horizontal radio buttons group
		*/
		UM_RADIOBUTTON_HORIZONTAL,

		/**
			Vertical radio buttons group
		*/
		UM_RADIOBUTTON_VERTICAL
	};

	I_BEGIN_COMPONENT(CSelectionParamGuiComp);
		I_ASSIGN(m_optionsLabelAttrPtr, "OptionsLabel", "Label for the options selector", false, "Select");
		I_ASSIGN(m_uiModeAttrPtr, "UiMode", "Selection representation mode. 0 - Combo box,\n1 - Horizonal layouted radio button group\n2 - Vertical layouted radio button group", false, 0);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();

protected Q_SLOTS:
	void OnSelectionChanged(int index);
	void OnRadioButtonSelectionChanged(bool isSelected);

private:
	void UpdateComboBoxesView();
	void UpdateRadioButtonView(bool useVerticalLayout = false);

private:
	I_ATTR(istd::CString, m_optionsLabelAttrPtr);
	I_ATTR(int, m_uiModeAttrPtr);

	istd::TPointerVector<QComboBox> m_comboBoxes;
	istd::TPointerVector<QRadioButton> m_radioButtons;
	istd::TDelPtr<QFrame> m_radioButtonFramePtr;
};


} // namespace iqtprm


#endif // !iqtprm_CSelectionParamGuiComp_included


