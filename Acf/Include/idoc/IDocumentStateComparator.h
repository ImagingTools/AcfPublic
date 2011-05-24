/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef idoc_IDocumentStateComparator_included
#define idoc_IDocumentStateComparator_included


#include "istd/IChangeable.h"


namespace idoc
{


/**
	Allows to store some document state used as reference for comarision.
*/
class IDocumentStateComparator: virtual public istd::IPolymorphic
{
public:
	/**
		Store state of some document for later comarision.
	*/
	virtual void StoreState(const istd::IChangeable& document) = 0;
	/**
		Check if document state is the same as stored state.
	*/
	virtual bool CheckStateEquals(const istd::IChangeable& document) const = 0;
};


} // namespace idoc


#endif // !idoc_IDocumentStateComparator_included


