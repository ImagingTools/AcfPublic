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


#ifndef iqtgui_CWidgetUpdateBlocker_included
#define iqtgui_CWidgetUpdateBlocker_included



namespace iqtgui
{


/**
	Help class used to block widget update till it is destructed.
*/
class CWidgetUpdateBlocker
{
public:
	CWidgetUpdateBlocker(QWidget* widgetPtr);
	~CWidgetUpdateBlocker();

private:
	QWidget* m_widgetPtr;
};


// inline methods

inline CWidgetUpdateBlocker::CWidgetUpdateBlocker(QWidget* widgetPtr)
	:m_widgetPtr(widgetPtr)
{
	I_ASSERT(widgetPtr != NULL);

	m_widgetPtr->setUpdatesEnabled(false);
}


inline CWidgetUpdateBlocker::~CWidgetUpdateBlocker()
{
	m_widgetPtr->setUpdatesEnabled(true);
}


} // namespace iqtgui


#endif // !iqtgui_CWidgetUpdateBlocker_included


