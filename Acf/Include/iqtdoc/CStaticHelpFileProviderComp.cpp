/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#include "iqtdoc/CStaticHelpFileProviderComp.h"


// QT includes
#include <QFileInfo>
#include <QDir>

// ACF includes
#include "iqt/iqt.h"


namespace iqtdoc
{


// reimplemented (idoc::IHelpFileProvider)

double CStaticHelpFileProviderComp::GetHelpQuality(const QString& contextText, const istd::IPolymorphic* contextObjectPtr) const
{
	QString filePath = GetHelpFilePath(contextText, contextObjectPtr);
	if (filePath.isEmpty()){
		return 0;
	}

	QFileInfo fileInfo(filePath);
	if (fileInfo.isFile()){
		return 1;
	}
	else{
		return 0;
	}
}


QString CStaticHelpFileProviderComp::GetHelpFilePath(const QString& contextText, const istd::IPolymorphic* /*contextObjectPtr*/) const
{
	if (!m_helpFileDirCompPtr.IsValid()){
		return QString();
	}

	QDir helpDir(m_helpFileDirCompPtr->GetPath());
	QString fileName;
	if (contextText.isEmpty()){
		fileName = *m_defaultFileNameAttrPtr;
	}
	else{
		fileName = *m_contextPrefixAttrPtr + contextText + *m_contextSuffixAttrPtr;
	}

	return helpDir.absoluteFilePath(fileName);
}


} // namespace iqtdoc


