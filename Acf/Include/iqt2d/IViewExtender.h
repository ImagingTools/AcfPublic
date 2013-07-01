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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt2d_IViewExtender_included
#define iqt2d_IViewExtender_included


// ACF includes
#include "istd/IPolymorphic.h"


namespace iqt2d
{


class IViewProvider;


/**
	Interface for GUI objects presenting its results using extern view objects.
*/
class IViewExtender: virtual public istd::IPolymorphic
{
public:
	/**
		Standard flags for items .
	*/
	enum SceneFlags
	{
		/**
			This flag is active if only shown elements will be used as background for other elements.
		*/
		SF_BACKGROUND = 1,
		/**
			This flag is set if this objects are added in direct call and will be reseted by delegation call to slave GUI's.
		 */
		SF_DIRECT = 2
	};

	/**
		Called when items should be added to specified scene.
	*/
	virtual void AddItemsToScene(IViewProvider* providerPtr, int flags) = 0;

	/**
		Called when items should be removed from specified scene.
	*/
	virtual void RemoveItemsFromScene(IViewProvider* providerPtr) = 0;
};


} // namespace iqt2d


#endif // !iqt2d_IViewExtender_included


