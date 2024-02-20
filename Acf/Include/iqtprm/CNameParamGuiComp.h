/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtprm_CNameParamGuiComp_included
#define iqtprm_CNameParamGuiComp_included


// ACF includes
#include <iprm/INameParam.h>

#include <iqtgui/TDesignerGuiObserverCompBase.h>

#include <GeneratedFiles/iqtprm/ui_CNameParamGuiComp.h>


namespace iqtprm
{


class CNameParamGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CNameParamGuiComp,
			iprm::INameParam>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CNameParamGuiComp,
				iprm::INameParam> BaseClass;
	/**
		Command label position
	*/
	enum LabelPosition
	{
		/**
			Left from the name field
		*/
		LP_LEFT,

		/**
			On top of the name field
		*/
		LP_TOP
	};

	I_BEGIN_COMPONENT(CNameParamGuiComp);
		I_ASSIGN(m_labelAttrPtr, "Label", "Label for the named object", false, "");
		I_ASSIGN(m_labelPositionAttrPtr, "LabelPosition", "Selection label position. 0 - Left from the selector,\n1 - On top of the selector", false, LP_LEFT);
		I_ASSIGN(m_regularExpressionAttrPtr, "InputFilter", "Input filter in form of a regular expression", false, "");
		I_ASSIGN(m_updateOnEveryChangeAttrPtr, "UpdateOnEveryTextChange", "If set the model will be updated after every text change, else only if Enter pressed or focus lost", true, true);
	I_END_COMPONENT;

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateModel() const override;
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet) override;

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated() override;

private Q_SLOTS:
	void OnNameChanged(const QString& text);
	void OnNameEdited();

private:
	I_TEXTATTR(m_labelAttrPtr);
	I_ATTR(int, m_labelPositionAttrPtr);
	I_ATTR(QByteArray, m_regularExpressionAttrPtr);
	I_ATTR(bool, m_updateOnEveryChangeAttrPtr);
};


} // namespace iqtprm


#endif // !iqtprm_CNameParamGuiComp_included


