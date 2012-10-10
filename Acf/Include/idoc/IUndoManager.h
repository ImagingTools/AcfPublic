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


#ifndef idoc_IUndoManager_included
#define idoc_IUndoManager_included


// ACF includes
#include "idoc/IDocumentStateComparator.h"


namespace idoc
{


/**
	Interface providing UNDO/REDO functionality.
*/
class IUndoManager: virtual public IDocumentStateComparator
{
public:
	/**
		Check, if UNDO operation is available.
	*/
	virtual bool IsUndoAvailable() const = 0;
	/**
		Check, if REDO operation is available.
	*/
	virtual bool IsRedoAvailable() const = 0;
	/**
		Reset all UNDO and REDO steps.
	*/
	virtual void ResetUndo() = 0;
	/**
		Process single UNDO step.
	*/
	virtual bool DoUndo() = 0;
	/**
		Process single REDO step.
	*/
	virtual bool DoRedo() = 0;
};


} // namespace idoc


#endif // !idoc_IUndoManager_included


