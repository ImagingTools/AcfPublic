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


#ifndef ibase_TLocalizableWrap_included
#define ibase_TLocalizableWrap_included


// Qt includes
#include <QtCore/QObject>
#include <QtCore/QCoreApplication>


namespace ibase
{


template <class Base>
class TLocalizableWrap: public Base
{
public:
	typedef Base BaseClass;

	TLocalizableWrap();

	/**
		If enabled, listen to the language change event from the application context.
	*/
	virtual void EnableLocalization(bool enableLocalization = true);

protected:
	// abstract methods
	virtual void OnLanguageChanged() = 0;

private:
	class LanguageChangeEventFilter: public QObject
	{
	public:
		typedef QObject BaseClass;

		LanguageChangeEventFilter(TLocalizableWrap& parent);

	protected:
		// reimplemented (QObject)
		bool eventFilter(QObject* sourcePtr, QEvent* eventPtr);

	private:
		TLocalizableWrap& m_parent;
	};

	LanguageChangeEventFilter m_languageChangeEventFilter;
};


// public methods of class TLocalizableWrap

template <class Base>
TLocalizableWrap<Base>::TLocalizableWrap()
	:m_languageChangeEventFilter(*this)
{
}


template <class Base>
void TLocalizableWrap<Base>::EnableLocalization(bool enableLocalization)
{
	QCoreApplication* applicationPtr = QCoreApplication::instance();
	if (applicationPtr != NULL){
		if (enableLocalization){
			applicationPtr->installEventFilter(&m_languageChangeEventFilter);
		}
		else{
			applicationPtr->removeEventFilter(&m_languageChangeEventFilter);
		}
	}
}


// public methods of the embedded class LanguageChangeEventFilter

template <class Base>
TLocalizableWrap<Base>::LanguageChangeEventFilter::LanguageChangeEventFilter(TLocalizableWrap& parent)
	:m_parent(parent)
{
}


// 	protected methods of the embedded class LanguageChangeEventFilter

// reimplemented (QObject)

template <class Base>
bool TLocalizableWrap<Base>::LanguageChangeEventFilter::eventFilter(QObject* sourcePtr, QEvent* eventPtr)
{
	if ((eventPtr->type() == QEvent::LanguageChange) && (sourcePtr == QCoreApplication::instance())){
        m_parent.OnLanguageChanged();
    }

	return BaseClass::eventFilter(sourcePtr, eventPtr);
}


} // namespace ibase


#endif // ibase_TLocalizableWrap_included

