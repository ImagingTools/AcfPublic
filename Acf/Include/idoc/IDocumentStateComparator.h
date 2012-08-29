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


#ifndef idoc_IDocumentStateComparator_included
#define idoc_IDocumentStateComparator_included


// ACF includes
#include "istd/IChangeable.h"


namespace idoc
{


/**
	Allows to store some document state used as reference for comarision.
*/
class IDocumentStateComparator: virtual public istd::IChangeable
{
public:
	enum DocumentChangeFlag
	{
		/**
			There is no information about document change.
		*/
		DCF_UNKNOWN,
		/**
			Current document state equals the stored one.
		*/
		DCF_EQUAL,
		/**
			Current document state equals the stored one.
		*/
		DCF_DIFFERENT
	};

	/**
		Check if there is stored document available.
	*/
	virtual bool HasStoredDocumentState() const = 0;
	/**
		Store state of some document.
	*/
	virtual bool StoreDocumentState() = 0;
	/**
		Restore last stored document state.
	*/
	virtual bool RestoreDocumentState() = 0;
	/**
		Check if document state is the same as stored state.
	*/
	virtual DocumentChangeFlag GetDocumentChangeFlag() const = 0;
};


} // namespace idoc


#endif // !idoc_IDocumentStateComparator_included


