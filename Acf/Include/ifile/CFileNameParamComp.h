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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef ifile_CFileNameParamComp_included
#define ifile_CFileNameParamComp_included


#include "iser/ISerializable.h"

#include "icomp/CComponentBase.h"

#include "ifile/IFileNameParam.h"


namespace ifile
{


/**
	Basic implementation of interface ifile::IFileNameParam as component.
*/
class CFileNameParamComp:
			public icomp::CComponentBase,
			virtual public IFileNameParam
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CFileNameParamComp);
		I_REGISTER_INTERFACE(iser::ISerializable);
		I_REGISTER_INTERFACE(IFileNameParam);
		I_ASSIGN(m_defaultDirAttrPtr, "DefaultPath", "Default path of file or directory", false, ".");
		I_ASSIGN(m_pathTypeAttrPtr, "PathType", "Type of path: 0 - unknown, 1 - PT_FILE, 2 - PT_DIRECTORY, 3 - PT_URL", true, PT_UNKNOWN);
	I_END_COMPONENT;

	// reimplemented (ifile::IFileNameParam)
	virtual int GetPathType() const;
	virtual const QString& GetPath() const;
	virtual void SetPath(const QString& path);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

protected:
	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();

private:
	QString m_path;

	I_ATTR(QString, m_defaultDirAttrPtr);
	I_ATTR(int, m_pathTypeAttrPtr);
};


} // namespace ifile


#endif // !ifile_CFileNameParamComp_included


