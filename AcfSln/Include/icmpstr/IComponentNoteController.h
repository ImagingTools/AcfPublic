/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef icmpstr_IComponentNoteController_included
#define icmpstr_IComponentNoteController_included


#include "istd/IChangeable.h"

#include "icmpstr/icmpstr.h"


namespace icmpstr
{


/**
	Interface for management of notes in the component registry.
	A note is a user defined description of the component in the diagram context.
	Using of notes make it easier for non-authors to understand, what is the meaning of the given component in the concrete context.
*/
class IComponentNoteController: virtual public istd::IChangeable
{
public:
	enum ChangeFlags
	{
		CF_NOTE_CHANGED = 1 << 29
	};

	/**
		Get the note text to the component with the given name \c componentName.
	*/
	virtual QString GetComponentNote(const QByteArray& componentName) = 0;

	/**
		Add a note \c componentNote to the component with the given name \c componentName.
	*/
	virtual void SetComponentNote(const QByteArray& componentName, const QString& componentNote) = 0;
};


} // namespace icmpstr


#endif // !icmpstr_IComponentNoteController_included

