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


#ifndef iimg_CBitmapLoaderComp_included
#define iimg_CBitmapLoaderComp_included


// Qt includes
#include <QtCore/QDir>
#include <QtCore/QStringList>

// ACF includes
#include <ifile/IFilePersistence.h>
#include <icomp/CComponentBase.h>
#include <ilog/TLoggerCompWrap.h>
#include <iimg/iimg.h>


namespace iimg
{


/**
	Bitmap loader component implementing interfaces \c ifile::IFilePersistence.

	\ingroup ImageProcessing
	\ingroup Geometry
*/
class CBitmapLoaderComp:
			public QObject,
			public ilog::CLoggerComponentBase,
			virtual public ifile::IFilePersistence
{
	Q_OBJECT

public:
	typedef ilog::CLoggerComponentBase BaseClass;

	enum MessageId
	{
		MI_BAD_FORMAT = 0xe1a7d0
	};

	I_BEGIN_COMPONENT(CBitmapLoaderComp);
		I_REGISTER_INTERFACE(ifile::IFileTypeInfo);
		I_REGISTER_INTERFACE(ifile::IFilePersistence);
		I_ASSIGN_MULTI_0(m_extensionFilterAttrPtr, "ExtensionFilter", "Optional filter of extensions, lowercase as returned by Qt", false)
	I_END_COMPONENT;

	// reimplemented (ifile::IFilePersistence)
	virtual bool IsOperationSupported(
				const istd::IChangeable* dataObjectPtr,
				const QString* filePathPtr = NULL,
				int flags = -1,
				bool beQuiet = true) const override;
	virtual int LoadFromFile(
				istd::IChangeable& data,
				const QString& filePath = QString(),
				ibase::IProgressManager* progressManagerPtr = NULL) const override;
	virtual int SaveToFile(
				const istd::IChangeable& data,
				const QString& filePath = QString(),
				ibase::IProgressManager* progressManagerPtr = NULL) const override;

	// reimplemented (ifile::IFileTypeInfo)
	virtual bool GetFileExtensions(
		QStringList& result, 
		const istd::IChangeable* dataObjectPtr = NULL, 
		int flags = -1, 
		bool doAppend = false) const override;

	virtual QString GetTypeDescription(const QString* extensionPtr = NULL) const override;

protected:
	bool IsOperationSupportedIntern(
				const istd::IChangeable* dataObjectPtr,
				const QString* filePathPtr,
				bool forLoading,
				bool forSaving,
				bool useLog) const;

private:
	I_MULTIATTR(QByteArray, m_extensionFilterAttrPtr);
};


} // namespace iimg


#endif // !iimg_CBitmapLoaderComp_included


