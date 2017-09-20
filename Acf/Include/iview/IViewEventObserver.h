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


#ifndef iview_IViewEventObserver_included
#define iview_IViewEventObserver_included


// Qt includes
#include <QtCore/QtGlobal>

// ACF includes
#include <istd/IPolymorphic.h>
#include <imod/IModel.h>
#include <iview/IShapeView.h>
#include <iview/IMouseActionObserver.h>


namespace iview
{


/**
	Interface for external view event observer.
*/
class IViewEventObserver: virtual public istd::IPolymorphic
{
public:
	/**
		Message handler for selection changes.
		\return	true, if this event was consumed by this listener and should not be further processed.
	*/
	virtual bool OnSelectChange(const IShapeView& view, const istd::CIndex2d& position, const IInteractiveShape& shape, bool state) = 0;
	
	/**
		Message handler for mouse button click.
		\return	true, if this event was consumed by this listener and should not be further processed.
	*/
	virtual bool OnViewMouseButton(const IShapeView& view, const istd::CIndex2d& position, Qt::MouseButton buttonType, bool state, const IInteractiveShape* shapePtr) = 0;
};



} // namespace iview



#endif // !iview_IViewEventObserver_included



