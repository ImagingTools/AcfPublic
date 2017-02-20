/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iqtsig_CSamplingParamsGuiComp_included
#define iqtsig_CSamplingParamsGuiComp_included


#include <isig/ISamplingParams.h>

#include <iqtgui/TDesignerGuiObserverCompBase.h>

#include <iqtsig/iqtsig.h>

#include <GeneratedFiles/iqtsig/ui_CSamplingParamsGuiComp.h>


namespace iqtsig
{


class CSamplingParamsGuiComp: public iqtgui::TDesignerGuiObserverCompBase<
			Ui::CSamplingParamsGuiComp,
			isig::ISamplingParams>
{
	Q_OBJECT

public:
	typedef iqtgui::TDesignerGuiObserverCompBase<
				Ui::CSamplingParamsGuiComp,
				isig::ISamplingParams> BaseClass;

	I_BEGIN_COMPONENT(CSamplingParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

protected Q_SLOTS:
	void on_IntervalSB_valueChanged(double value);
	void on_ModeCB_currentIndexChanged(int index);
};


} // namespace iqtsig


#endif // !iqtsig_CSamplingParamsGuiComp_included


