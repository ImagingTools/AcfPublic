/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iipr_CGeometryMessage_included
#define iipr_CGeometryMessage_included


// ACF includes
#include <ilog/CExtMessage.h>
#include <i2d/CObject2dFactory.h>


namespace iipr
{


/**
	Message implementation for transport of 2D-objects.
*/
class CGeometryMessage: public ilog::CExtMessage
{
public:
	typedef ilog::CExtMessage BaseClass;

	static QByteArray GetTypeName();

	CGeometryMessage();
	CGeometryMessage(istd::IInformationProvider::InformationCategory category,
				int id,
				const QString& text,
				const QString& source,
				int flags = 0,
				const QDateTime* timeStampPtr = NULL);

	// reimplemented (iser::IObject)
	virtual QByteArray GetFactoryId() const override;

	// reimplemented (iser::IChangeable)
	virtual istd::IChangeable* CloneMe(CompatibilityMode mode = CM_WITHOUT_REFS) const;

private:
	static i2d::CObject2dFactory s_factory;
};


} // namespace iipr


#endif // !iipr_CGeometryMessage_included


