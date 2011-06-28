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


// ACF includes
#include "istd/IPolymorphic.h"


class QTranslator;


namespace iqt
{


class ITranslationManager: virtual public istd::IPolymorphic
{
public:
	/**
		Get number of provided languages.
	*/
	virtual int GetLanguagesCount() const = 0;

	/**
		Get current language index.
	*/
	virtual int GetCurrentLanguageIndex() const = 0;

	/**
		Get Qt translator for a given language.
	*/
	virtual const QTranslator* GetLanguageTranslator(int languageIndex) const = 0;

	/**
		Get slave translation manager, if set.
	*/
	virtual const ITranslationManager* GetSlaveTranslationManager() const = 0;

	/**
		Switch the current language to the language with the index \c languageIndex.
	*/
	virtual void SwitchLanguage(int languageIndex) = 0;

	/**
		Set default system's language.
	*/
	virtual void SetSystemLanguage() = 0;
};


} // namespace iqt


#endif // !iqt_ITranslationManager_included


