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


#ifndef ifile_CTimeStampFileNameParamComp_included
#define ifile_CTimeStampFileNameParamComp_included


// ACF includes
#include <ifile/CRelativeFileNameParamComp.h>


namespace ifile
{


/**
	File path generation using time stamp.
*/
class CTimeStampFileNameParamComp: public ifile::CRelativeFileNameParamComp
{
public:
	typedef ifile::CRelativeFileNameParamComp BaseClass;

	I_BEGIN_COMPONENT(CTimeStampFileNameParamComp);
		I_ASSIGN(m_fileExtensionAttrPtr, "FileExtension", "Extension of file, if path type is set to file", false, "");
		I_ASSIGN(m_dateFormatAttrPtr, "DateFormat", "Format of timestamp string in name of file", true,"yyyyMMdd");
		I_ASSIGN(m_prefixAttrPtr, "PrefixText", "Timestamp prefix text in name of log file", false, "");
		I_ASSIGN(m_suffixAttrPtr, "SuffixText", "Timestamp suffix text in name of log file", false, "");
	I_END_COMPONENT;

	// reimplemented (ifile::IFileNameParam)
	virtual const QString& GetPath() const;

private:
	I_ATTR(QString, m_fileExtensionAttrPtr);
	I_ATTR(QString, m_dateFormatAttrPtr);
	I_ATTR(QString, m_prefixAttrPtr);
	I_ATTR(QString, m_suffixAttrPtr);

	mutable QString m_generatedPath;
};


} // namespace ifile


#endif // !ifile_CTimeStampFileNameParamComp_included


