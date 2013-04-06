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


#ifndef icmpstr_IElementSelectionInfo_included
#define icmpstr_IElementSelectionInfo_included


// Qt includes
#include <QtCore/QSet>
#include <QtGui/QIcon>

// ACF includes
#include "istd/IChangeable.h"

#include "iser/ISerializable.h"

#include "icomp/IRegistry.h"
#include "icomp/CComponentAddress.h"

#include "icmpstr/icmpstr.h"


namespace icmpstr
{


/**
	Interface containing all information about registry selected element.
*/
class IElementSelectionInfo: virtual public istd::IChangeable
{
public:
	enum ChangeFlags
	{
		CF_SELECTION = 1 << 31
	};

	typedef QMap<QByteArray, const icomp::IRegistry::ElementInfo*> Elements;

	/**
		Get registry containing selected element.
		\return	pointer to registry or NULL if no registry is selected.
	*/
	virtual icomp::IRegistry* GetSelectedRegistry() const = 0;
	/**
		Get set of selected elements.
		\return	map from element name to element information object.
				This map doesn't include pointers to NULL element info.
	*/
	virtual Elements GetSelectedElements() const = 0;
};


} // namespace icmpstr


#endif // !icmpstr_IElementSelectionInfo_included


