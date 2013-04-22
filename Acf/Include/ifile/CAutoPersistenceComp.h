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


#ifndef ifile_CAutoPersistenceComp_included
#define ifile_CAutoPersistenceComp_included


// ACF includes
#include "istd/IChangeable.h"
#include "imod/IModel.h"
#include "imod/CSingleModelObserverBase.h"
#include "icomp/CComponentBase.h"
#include "ifile/IFilePersistence.h"
#include "ifile/IFileNameParam.h"


namespace ifile
{


/**
	Allow automatic object persistence.
	Referenced object will be restored during creation and stored during destruction.
*/
class CAutoPersistenceComp:
			public icomp::CComponentBase,
			protected imod::CSingleModelObserverBase
{
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CAutoPersistenceComp);
		I_ASSIGN(m_objectCompPtr, "Object", "Object will be restored and stored", true, "Object");
		I_ASSIGN_TO(m_objectModelCompPtr, m_objectCompPtr, false);
		I_ASSIGN(m_fileLoaderCompPtr, "FileLoader", "File loader used to store and restore object", true, "FileLoader");
		I_ASSIGN(m_filePathCompPtr, "FilePath", "File path where object data will be stored if non anonymous loader is used", false, "FilePath");
		I_ASSIGN(m_restoreOnBeginAttrPtr, "RestoreonBegin", "Flag indicating that object should be restored on begin", true, true);
		I_ASSIGN(m_storeOnEndAttrPtr, "StoreOnEnd", "Flag indicating that object should be stored on end", true, true);
		I_ASSIGN(m_storeOnChangeAttrPtr, "StoreOnChange", "Flag indicating that object should be stored on each data change", true, false);
	I_END_COMPONENT;

protected:
	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(int updateFlags, istd::IPolymorphic* updateParamsPtr);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private:
	I_REF(istd::IChangeable, m_objectCompPtr);
	I_REF(imod::IModel, m_objectModelCompPtr);
	I_REF(ifile::IFilePersistence, m_fileLoaderCompPtr);
	I_REF(ifile::IFileNameParam, m_filePathCompPtr);
	I_ATTR(bool, m_restoreOnBeginAttrPtr);
	I_ATTR(bool, m_storeOnEndAttrPtr);
	I_ATTR(bool, m_storeOnChangeAttrPtr);
};


} // namespace ifile


#endif // !ifile_CAutoPersistenceComp_included


