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


#ifndef iedgegui_CEdgeLineContainerShape_included
#define iedgegui_CEdgeLineContainerShape_included


// ACF includes
#include <icmm/IColorTransformation.h>
#include <iview/CShapeBase.h>


namespace iedgegui
{


class CEdgeLineContainerShape: public iview::CShapeBase
{
public:
	typedef iview::CShapeBase BaseClass;

	// reimplemented (iview::IShape)
	virtual void Draw(QPainter& drawContext) const;

	// reimplemented (imod::IObserver)
	virtual bool OnModelAttached(imod::IModel* modelPtr, istd::IChangeable::ChangeSet& changeMask);

	// reimplemented (iview::CShapeBase)
	virtual i2d::CRect CalcBoundingBox() const;

	virtual QString GetShapeDescriptionAt(istd::CIndex2d position) const;
	
	iview::ITouchable::TouchState IsTouched(istd::CIndex2d /*position*/) const;
};


} // namespace iedgegui


#endif // !iedgegui_CEdgeLineContainerShape_included


