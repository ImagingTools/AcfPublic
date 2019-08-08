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


#include <iipr/CGeometryMessage.h>


// ACF includes
#include <ilog/CMessageContainer.h>


namespace iipr
{


// public methods

CGeometryMessage::CGeometryMessage()
	:BaseClass(&s_factory)
{
}


CGeometryMessage::CGeometryMessage(
			istd::IInformationProvider::InformationCategory category,
			int id,
			const QString& text,
			const QString& source,
			int flags,
			const QDateTime* timeStampPtr)
	:BaseClass(category, id, text, source, flags, timeStampPtr, &s_factory)
{
}


QByteArray CGeometryMessage::GetFactoryId() const
{
	return GetTypeName();
}


// reimplemented (iser::IChangeable)

istd::IChangeable * CGeometryMessage::CloneMe(CompatibilityMode mode) const
{
	istd::TDelPtr<CGeometryMessage> clonedPtr(new CGeometryMessage);
	if (clonedPtr->CopyFrom(*this, mode)){
		return clonedPtr.PopPtr();
	}

	return NULL;
}


QByteArray CGeometryMessage::GetTypeName()
{
	return istd::CClassInfo::GetName<CGeometryMessage>();
}


// private static members

i2d::CObject2dFactory CGeometryMessage::s_factory;


I_REGISTER_MESSAGE_TYPE(CGeometryMessage, CGeometryMessage::GetTypeName());


} // namespace iipr


