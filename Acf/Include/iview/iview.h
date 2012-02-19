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


#ifndef iview_included
#define iview_included


/**
	In this library is defined 2D view concept and standard visualisation objects.
*/
namespace iview
{


/**
	Define possible display changes.
	Use binary or operator, to combine this flags.
*/
enum ChangeFlags
{
	/**
		All was changed.
	*/
	CF_ALL = -1,
	
	/**	
		No changes.
	*/
	CF_NONE = 0,
	
	/**
		View transform is changed.
	*/
	CF_TRANSFORM = 1,
	
	/**
		View colors are changed.
	*/
	CF_COLORS = 2,
	
	/**
		View size is changed.
	*/
	CF_SIZE = 4,
	
	/**
		Edit mode is changed.
	*/
	CF_EDIT_MODE = 8
};


enum ChangeSource
{
	/**	
		Indicate, that changes come from display console shapes.
	*/
	CS_CONSOLE = 32
};


} // namespace iview



#endif // !iview_included


