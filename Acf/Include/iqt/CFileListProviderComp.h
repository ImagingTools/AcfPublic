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


#ifndef iqt_CFileListProviderComp_included
#define iqt_CFileListProviderComp_included


// Qt includes
#include <QtCore/QFileSystemWatcher>

#include "iser/IFileLoader.h"

#include "imod/IModel.h"
#include "imod/CSingleModelObserverBase.h"

#include "icomp/CComponentBase.h"

#include "ibase/IFileListProvider.h"

#include "iprm/IFileNameParam.h"

#include "iqt/iqt.h"


namespace iqt
{


/**
	Provide list of file pathes using recursive search of some file directory.
*/
class CFileListProviderComp:
			public QObject,
			public icomp::CComponentBase,
			virtual public ibase::IFileListProvider,
			protected imod::CSingleModelObserverBase
{
	Q_OBJECT
public:
	typedef icomp::CComponentBase BaseClass;

	I_BEGIN_COMPONENT(CFileListProviderComp);
		I_REGISTER_INTERFACE(istd::IChangeable);
		I_REGISTER_INTERFACE(ibase::IFileListProvider);

		I_ASSIGN(m_dirParamCompPtr, "DirParam", "Parameter storing root directory", true, "DirParam");
		I_ASSIGN(m_dirParamModelCompPtr, "DirParam", "Parameter storing root directory", false, "DirParam");
		I_ASSIGN(m_fileLoaderCompPtr, "FileLoader", "File loader used to create file filters", false, "FileLoader");
		I_ASSIGN_MULTI_0(m_filtersAttrPtr, "Filters", "List of filters if no loader is specified", false);
		I_ASSIGN(m_minRecurDepthAttrPtr, "MinRecurDepth", "Minimal recursion depth for file search", true, 0);
		I_ASSIGN(m_maxRecurDepthAttrPtr, "MaxRecurDepth", "Maximal recursion depth for file search, negative value means no depth limit", true, 0);
	I_END_COMPONENT;

	// reimplemented (ibase::IFileListProvider)
	virtual QStringList GetFileList() const;

protected:
	// reimplemented (imod::CSingleModelObserverBase)
	virtual void OnUpdate(int updateFlags, istd::IPolymorphic* updateParamsPtr);

	// reimplemented (icomp::CComponentBase)
	virtual void OnComponentCreated();
	virtual void OnComponentDestroyed();

private Q_SLOTS:
	void OnDirectoryContentChanged(const QString& directoryPath);

private:
	I_REF(iprm::IFileNameParam, m_dirParamCompPtr);
	I_REF(imod::IModel, m_dirParamModelCompPtr);
	I_REF(iser::IFileLoader, m_fileLoaderCompPtr);
	I_MULTIATTR(QString, m_filtersAttrPtr);
	I_ATTR(int, m_minRecurDepthAttrPtr);
	I_ATTR(int, m_maxRecurDepthAttrPtr);

	QStringList m_fileList;

	QFileSystemWatcher m_directoryWatcher;

};


} // namespace iqt


#endif //!iqt_CFileListProviderComp_included


