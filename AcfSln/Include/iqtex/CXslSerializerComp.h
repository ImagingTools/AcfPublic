/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#ifndef iqtex_CXslSerializerComp_included
#define iqtex_CXslSerializerComp_included


// Qt includes
#include <QtCore/QString>

// ACF includes
#include "ibase/CFileSerializerCompBase.h"
#include "ifile/IFileNameParam.h"


namespace iqtex
{


/**
	Template implementation of file serializer using loading and storing archive implementation.
*/
class CXslSerializerComp: public ibase::CFileSerializerCompBase
{
public:	
	typedef ibase::CFileSerializerCompBase BaseClass;

	I_BEGIN_COMPONENT(CXslSerializerComp);
		I_ASSIGN(m_xslReadFilePath, "ReadTransformationFile", "Transformation file for reading action", true, "ReadTransformationFile");
		I_ASSIGN(m_xslWriteFilePath, "WriteTransformationFile", "Transformation file for writing action", true, "WriteTransformationFile");
	I_END_COMPONENT;

	// reimplemented (iser::IFileLoader)
	virtual int LoadFromFile(istd::IChangeable& data, const QString& filePath = QString()) const;
	virtual int SaveToFile(const istd::IChangeable& data, const QString& filePath = QString()) const;

protected:
	/**
		Called if read error is occured.
	*/
	virtual void OnReadError(const iser::IArchive& archive, const istd::IChangeable& data, const QString& filePath) const;

private:
	I_REF(ifile::IFileNameParam, m_xslReadFilePath);
	I_REF(ifile::IFileNameParam, m_xslWriteFilePath);
};


} // namespace iqtex


#endif // !iqtex_CXslSerializerComp_included


