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


#ifndef idoc_IUndoManager_included
#define idoc_IUndoManager_included


// ACF includes
#include <idoc/IDocumentStateComparator.h>


namespace idoc
{


/**
	Interface providing UNDO/REDO functionality.
*/
class IUndoManager: virtual public IDocumentStateComparator
{
public:
	/**
		Get number of available UNDO levels.
		\return	number of UNDO levels, or 0 if there is no UNDO available.
	*/
	virtual int GetAvailableUndoSteps() const = 0;
	/**
		Get number of available REDO levels.
		\return	number of REDO levels, or 0 if there is no REDO available.
	*/
	virtual int GetAvailableRedoSteps() const = 0;
	/**
		Get description of single UNDO level.
	*/
	virtual QString GetUndoLevelDescription(int stepIndex) const = 0;
	/**
		Get description of single UNDO level.
	*/
	virtual QString GetRedoLevelDescription(int stepIndex) const = 0;
	/**
		Reset all UNDO and REDO steps.
	*/
	virtual void ResetUndo() = 0;
	/**
		Process UNDO steps.
		\param	level	level of UNDO.
	*/
	virtual bool DoUndo(int steps = 1) = 0;
	/**
		Process REDO steps.
		\param	level	level of REDO.
	*/
	virtual bool DoRedo(int steps = 1) = 0;
};


} // namespace idoc


#endif // !idoc_IUndoManager_included


