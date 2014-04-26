/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtgui_IDropConsumer_included
#define iqtgui_IDropConsumer_included


// Qt includes
#include <QtCore/QMimeData>
#include <QtCore/QEvent>

// ACF includes
#include "istd/IPolymorphic.h"
#include "iqtgui/iqtgui.h"


namespace iqtgui
{


/**
	Interface for objects which can receive dragged objects
*/
class IDropConsumer: virtual public istd::IPolymorphic
{
public:
	/**
		Get the list of the possible mime IDs, which are accepted by the consumer.
	*/
	virtual QStringList GetAcceptedMimeIds() const = 0;

	/**
		Notification about drop action finish.
	*/
	virtual void OnDropFinished(const QMimeData& mimeData, QEvent* eventPtr) = 0;
};


} // namespace iqtgui


#endif // !iqtgui_IDropConsumer_included


