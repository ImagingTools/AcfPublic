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


#ifndef iqt_ITranslationManager_included
#define iqt_ITranslationManager_included


#include "iqt/iqt.h"


#include <QString>

#include "istd/IPolymorphic.h"



namespace iqt
{


class ITranslationManager: virtual public istd::IPolymorphic
{
public:
	/**
		Returns number of languages supported by translation manager.
	*/
	virtual	int GetLanguageCount() const = 0;

	/**
		Returns language ID for the language with the index \c index.
	*/
	virtual	QString GetLanguageId(int index) const = 0;

	/**
		Returns language icon for the language with the index \c index.
	*/
	virtual	QIcon GetLanguageIcon(int index) const = 0;

	/**
		Returns currently selected language ID.
	*/
	virtual	QString GetSelectedLanguageId() const = 0;

	/**
		Select a language.
	*/
	virtual	void SetSelectedLanguage(const QString& languageId) = 0;
	
	/**
		Sets default language.
	*/
	virtual void SetDefaultLanguage(const QString& laguageId) = 0;
};


} // namespace iqt


#endif // !iqt_ITranslationManager_included
