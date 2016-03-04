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


#include "ifile/CSystemRelativeFileNameParamComp.h"

//Qt includes
#include <QtCore/QStandardPaths>


#define APPID               "%APPID%"
#define COMPANY_NAME        "%COMPANY_NAME%"
#define PRODUCT_NAME        "%PRODUCT_NAME%"
#define APPLICATION_NAME    "%APPLICATION_NAME%"
#define APPLICATION_SUBNAME "%APPLICATION_SUBNAME%"
#define APPLICATION_TYPE    "%APPLICATION_TYPE%"
#define MAIN_VERSION        "%MAIN_VERSION%"
#define USER                "%USER%"

namespace ifile
{

// public methods

// reimplemented (ifile::IFileNameParam)

const QString& CSystemRelativeFileNameParamComp::GetPath() const
{
    QString relativePath = BaseClass::GetPath();

    //Replace jokers with real values
    if (relativePath.contains(APPID,Qt::CaseInsensitive))
    {
        relativePath = relativePath.replace(QString(APPID), QString::number(QCoreApplication::applicationPid()), Qt::CaseInsensitive);
    }
    if (m_applicationInfoCompPtr.IsValid())
    {
        //Replace jokers with real values
        if (relativePath.contains(COMPANY_NAME, Qt::CaseInsensitive))
        {
            relativePath = relativePath.replace(QString(COMPANY_NAME), 
                m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_COMPANY_NAME), 
                Qt::CaseInsensitive);
        }

        if (relativePath.contains(PRODUCT_NAME, Qt::CaseInsensitive))
        {
            relativePath = relativePath.replace(QString(PRODUCT_NAME),
                m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_PRODUCT_NAME),
                Qt::CaseInsensitive);
        }

        if (relativePath.contains(APPLICATION_NAME, Qt::CaseInsensitive))
        {
            relativePath = relativePath.replace(QString(APPLICATION_NAME),
                m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_NAME),
                Qt::CaseInsensitive);
        }

        if (relativePath.contains(APPLICATION_SUBNAME, Qt::CaseInsensitive))
        {
            relativePath = relativePath.replace(QString(APPLICATION_SUBNAME),
                m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_SUBNAME),
                Qt::CaseInsensitive);
        }

        if (relativePath.contains(APPLICATION_TYPE, Qt::CaseInsensitive))
        {
            relativePath = relativePath.replace(QString(APPLICATION_TYPE),
                m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_APPLICATION_TYPE),
                Qt::CaseInsensitive);
        }

        if (relativePath.contains(MAIN_VERSION, Qt::CaseInsensitive))
        {
            relativePath = relativePath.replace(QString(MAIN_VERSION),
                m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_MAIN_VERSION),
                Qt::CaseInsensitive);
        }

        if (relativePath.contains(USER, Qt::CaseInsensitive))
        {
            relativePath = relativePath.replace(QString(USER),
                m_applicationInfoCompPtr->GetApplicationAttribute(ibase::IApplicationInfo::AA_USER),
                Qt::CaseInsensitive);
        }
    }

    m_filePath = relativePath;
    
    return m_filePath;
}

} // namespace ifile


