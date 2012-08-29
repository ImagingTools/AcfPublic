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


#ifndef iqtgui_CExtLineEdit_included
#define iqtgui_CExtLineEdit_included


// Qt includes
#include <QtCore/QList>
#include <QtGui/QLineEdit>
#include <QtGui/QIcon>
#include <QtGui/QLabel>

// ACF includes 
#include "istd/TDelPtr.h"

#include "iqtgui/iqtgui.h"


namespace iqtgui
{


/**
	Input editor with extended functionality.
	It's possible to add an icon to the edit field 
	or insert additional widgets (e.g control buttons) into the view.
*/
class CExtLineEdit: public QLineEdit
{
	Q_OBJECT

public:
	typedef QLineEdit BaseClass;

	/**
		Construct a line edit with the given properties.
	*/
	CExtLineEdit(
				const QString& startupText = QString(),
				int margins = 2,
				QWidget* parent = NULL);

	/**
		Set the text, that will be shown at the first time the editor becomes visible.
	*/
	virtual void SetStartupText(const QString& startupText);

	/**
		Get the startup text.
	*/
	virtual QString GetStartupText() const;

	/**
		Get editor text.
	*/
	virtual QString GetText() const;

	/**
		Set the icon, that will appeared on the left side of the line edit.
	*/
	void SetIcon(const QIcon& icon);

	/**
		Add a widget to the line edit area according to \c alginmentFlags.
		Only Qt::AlignLeft and Qt::AlignRight are possible.
		\note CExtLineEdit get the control over the \c widget object.
	*/
	void AddWidget(QWidget* widgetPtr, int alignmentFlags);

protected:
	// reimplemented (QWidget)
	virtual void resizeEvent(QResizeEvent* resizeEvent);
    virtual void focusInEvent(QFocusEvent* focusEvent);

private Q_SLOTS:
	void OnEditingFinished();
	void OnTextChanged(const QString& text);

private:
	void UpdateLayout();
	void UpdateStartupText();

private:
	QString m_startupText;
	int m_margins;

	struct SubWidgetInfo
	{
		QWidget* widget;
		int alignmentFlags;
		int margin;
	};

	typedef QList<SubWidgetInfo> SubWidgetsList;
	
	QLabel* m_iconPtr;
	SubWidgetsList m_subWidgets;
};


} // namespace iqtgui


#endif // !iqtgui_CExtLineEdit_included


