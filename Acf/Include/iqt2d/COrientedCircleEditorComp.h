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


#ifndef iqt2d_COrientedCircleEditorComp_included
#define iqt2d_COrientedCircleEditorComp_included


// ACF includes
#include "i2d/COrientedCircle.h"
#include "iview/COrientedCircleShape.h"
#include "iqt2d/TCircleBasedParamsGuiComp.h"


namespace iqt2d
{


class COrientedCircleEditorComp:
			public iqt2d::TCircleBasedParamsGuiComp<
						iview::COrientedCircleShape,
						i2d::COrientedCircle>
{
	Q_OBJECT

public:
	typedef iqt2d::TCircleBasedParamsGuiComp<
				iview::COrientedCircleShape,
				i2d::COrientedCircle> BaseClass;

	I_BEGIN_COMPONENT(COrientedCircleEditorComp);
	I_END_COMPONENT;

	COrientedCircleEditorComp();

protected:
	// reimplemented (iqt2d::TCircleBasedParamsGuiComp)
	virtual bool PopulateActions(CActionAdapter& host, imod::IModel* modelPtr);

protected Q_SLOTS:
	void OnParamsChanged(double value);
	void OnActionTriggered(QAction* actionPtr);

protected:
	QAction m_reversePolarityAction;
};


} // namespace iqt2d


#endif // !iqt2d_COrientedCircleEditorComp_included


