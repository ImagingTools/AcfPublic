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


#ifndef iview_ITextLabelParams_included
#define iview_ITextLabelParams_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include <istd/IChangeable.h>
#include <istd/CIndex2d.h>


namespace iview
{


/**
	Interface for text label drawing parameters.
*/
class ITextLabelParams: virtual public istd::IChangeable
{
public:
	/**
		Text alignment mode.
	*/
	enum TextAlign
	{
		TAL_CENTER,
		TAL_LEFT_TOP,
		TAL_RIGHT_TOP,
		TAL_LEFT_BOTTOM,
		TAL_RIGHT_BOTTOM,
		TAL_AUTOMATIC,
		TAL_LAST = TAL_AUTOMATIC
	};

	/**
		Get text alignment modein label shape.
	*/
	virtual TextAlign GetTextAlign() const = 0;

	/**
		Set text alignment mode.
	*/
	virtual void SetTextAlign(TextAlign align) = 0;

	/**
		Get the drawing offset for the label.
	*/
	virtual const istd::CIndex2d& GetDrawOffset() const = 0;

	/**
		Set the drawing offset for the label.
	*/
	virtual void SetDrawOffset(const istd::CIndex2d& offset) = 0;
};


} // namespace iview


#endif // !iview_ITextLabelParams_included


