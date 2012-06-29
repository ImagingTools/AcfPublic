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


#ifndef iqt2d_IViewProvider_included
#define iqt2d_IViewProvider_included


// ACF includes
#include "istd/IPolymorphic.h"

#include "iqt2d/iqt2d.h"


namespace iview
{
	class IShapeView;
}


namespace iqt2d
{


/**
	Interface for GUI objects managing view.
*/
class IViewProvider: virtual public istd::IPolymorphic
{
public:
	/**
		Get ID indentifing this view.
		Typically this ID is 0 for first view, 1 for the second etc.
	*/
	virtual int GetViewId() const = 0;

	/**
		Called when items should be removed from specified view.
	*/
	virtual iview::IShapeView* GetView() const = 0;
};


} // namespace iqt2d


#endif // !iqt2d_IViewProvider_included


