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


#ifndef iview_IShapeStatusInfo_included
#define iview_IShapeStatusInfo_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include <istd/IChangeable.h>
#include <i2d/CVector2d.h>


namespace iview
{


/**
	Interface for access local bitmap information.
*/
class IShapeStatusInfo: virtual public istd::IChangeable
{
public:
	/**
		Get logical position on the bitmap.
	*/
//	virtual i2d::CVector2d GetLogicalPosition() const = 0;

	/**
		Set logical position on the bitmap.
	*/
//	virtual void SetLogicalPosition(const i2d::CVector2d& logicalPosition) = 0;

	/**
		Get position in pixel on the bitmap.
	*/
//	virtual i2d::CVector2d GetPixelPosition() const = 0;

	/**
		Set position in pixel on the bitmap.
	*/
//	virtual void SetPixelPosition(const i2d::CVector2d& pixelPosition) = 0;

	/**
		Get information text for the current position.
	*/
	virtual QString GetInfoText() const = 0;

	/**
		Set information text for the current position.
	*/
	virtual void SetInfoText(const QString& infoText) = 0;
};


} // namespace iview


#endif // !iview_IShapeStatusInfo_included


