/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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


#ifndef iprm_ITextParam_included
#define iprm_ITextParam_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include <iser/ISerializable.h>


namespace iprm
{


/**
	Interface for a object containing simple text.
*/
class ITextParam: virtual public iser::ISerializable
{
public:
	/**
		Get the text.
	*/
	virtual const QString& GetText() const = 0;

	/**
		Set the text.
	*/
	virtual void SetText(const QString& text) = 0;

	/**
		Return \c true, if the text is readonly.
	*/
	virtual bool IsReadonly() const = 0;
};


} // namespace iprm


#endif // !iprm_ITextParam_included
