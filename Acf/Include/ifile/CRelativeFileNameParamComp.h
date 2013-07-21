/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef ifile_CRelativeFileNameParamComp_included
#define ifile_CRelativeFileNameParamComp_included


// ACF includes
#include "imod/CMultiModelBridgeBase.h"

#include "ifile/CFileNameParamComp.h"


namespace ifile
{


class CRelativeFileNameParamComp:
			public ifile::CFileNameParamComp,
			protected imod::CMultiModelBridgeBase
{
public:
	typedef ifile::CFileNameParamComp BaseClass;

	I_BEGIN_COMPONENT(CRelativeFileNameParamComp);
		I_ASSIGN(m_relativeToCompPtr, "ReferencePath", "Reference path, relative to this file or directory internal path representation will be calculated", false, "ReferencePath");
		I_ASSIGN_TO(m_relativeToModelCompPtr, m_relativeToCompPtr, false);
	I_END_COMPONENT;

	// reimplemented (ifile::IFileNameParam)
	virtual const QString& GetPath() const;
	virtual void SetPath(const QString& path);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(ifile::IFileNameParam, m_relativeToCompPtr);
	I_REF(imod::IModel, m_relativeToModelCompPtr);

	mutable QString m_relativePath;
};


} // namespace ifile


#endif // !ifile_CRelativeFileNameParamComp_included


