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


#ifndef iqt2d_CQuadrangleParamsGuiComp_included
#define iqt2d_CQuadrangleParamsGuiComp_included


// ACF includes
#include <i2d/CQuadrangle.h>

#include <iview/CParallelogramShape.h>

#include <iqt2d/TShapeParamsGuiCompBase.h>
#include <GeneratedFiles/iqt2d/ui_CQuadrangleParamsGuiComp.h>


namespace iqt2d
{


class CQuadrangleParamsGuiComp:
			public iqt2d::TShapeParamsGuiCompBase<
						Ui::CQuadrangleParamsGuiComp,
						iview::CParallelogramShape,
						i2d::CQuadrangle>
{
	Q_OBJECT

public:
	typedef iqt2d::TShapeParamsGuiCompBase<
				Ui::CQuadrangleParamsGuiComp,
				iview::CParallelogramShape,
				i2d::CQuadrangle> BaseClass;

	I_BEGIN_COMPONENT(CQuadrangleParamsGuiComp);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void UpdateModel() const;
	virtual void UpdateGui(const istd::IChangeable::ChangeSet& changeSet);

	// reimplemented (iqtgui::CGuiComponentBase)
	virtual void OnGuiCreated();
	virtual void OnGuiDestroyed();
	virtual void OnGuiRetranslate();

protected Q_SLOTS:
	void OnParamsChanged(double value);
};


} // namespace iqt2d


#endif // !iqt2d_CQuadrangleParamsGuiComp_included


