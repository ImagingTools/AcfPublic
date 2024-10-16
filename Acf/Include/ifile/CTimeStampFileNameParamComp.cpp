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


#include <ifile/CTimeStampFileNameParamComp.h>


// Qt includes
#include <QtCore/QDate>


namespace ifile
{


// public methods

// reimplemented (ifile::IFileNameParam)

const QString& CTimeStampFileNameParamComp::GetPath() const
{
	const QString format = m_dateFormatAttrPtr.IsValid() ? *m_dateFormatAttrPtr : "yyyyMMdd";
	const QString prefix = m_prefixAttrPtr.IsValid() ? *m_prefixAttrPtr : "";
	const QString suffix = m_suffixAttrPtr.IsValid() ? *m_suffixAttrPtr : "";

	QString generatedPath = QDate::currentDate().toString(format);

	m_generatedPath = BaseClass::GetPath() + "/" + prefix + generatedPath + suffix;

	if (GetPathType() == PT_FILE){
		QString extension = m_fileExtensionAttrPtr.IsValid() ? *m_fileExtensionAttrPtr : "";
		m_generatedPath += extension;
	}

	return m_generatedPath;
}


} // namespace ifile


