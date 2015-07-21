/********************************************************************************
**
**	Copyright (c) 2007-2014 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtmm_CSvgBitmapLoaderComp_included
#define iqtmm_CSvgBitmapLoaderComp_included


// ACF includes
#include "ifile/IFilePersistence.h"
#include "icomp/CComponentBase.h"
#include "ilog/TLoggerCompWrap.h"
#include "iimg/CBitmap.h"

// ACF-Solutions includes
#include "iqtmm/iqtmm.h"


namespace iqtmm
{


/**
	Load SVG files to bitmap.
*/
class CSvgBitmapLoaderComp:
			public QObject,
			public ilog::CLoggerComponentBase,
			virtual public ifile::IFilePersistence
{
	Q_OBJECT

public:
	typedef ilog::CLoggerComponentBase BaseClass;

	I_BEGIN_COMPONENT(CSvgBitmapLoaderComp);
		I_REGISTER_INTERFACE(ifile::IFileTypeInfo);
		I_REGISTER_INTERFACE(ifile::IFilePersistence);
		I_ASSIGN(m_bitmapWidthAttrPtr, "BitmapWidth", "Width of rendered bitmap in pixels", true, 100);
		I_ASSIGN(m_bitmapHeightAttrPtr, "BitmapHeight", "Height of rendered bitmap in pixels", true, 100);
	I_END_COMPONENT;

	enum MessageId
	{
		MI_BAD_EXTENSION = 0xa7e0,
		MI_FILE_NOT_EXIST,
		MI_BAD_FORMAT,
		MI_BITMAP_TYPE
	};

	// reimplemented (ifile::IFilePersistence)
	virtual bool IsOperationSupported(
				const istd::IChangeable* dataObjectPtr,
				const QString* filePathPtr = NULL,
				int flags = -1,
				bool beQuiet = true) const;
	virtual int LoadFromFile(
				istd::IChangeable& data,
				const QString& filePath = QString(),
				ibase::IProgressManager* progressManagerPtr = NULL) const;
	virtual int SaveToFile(
				const istd::IChangeable& data,
				const QString& filePath = QString(),
				ibase::IProgressManager* progressManagerPtr = NULL) const;

	// reimplemented (ifile::IFileTypeInfo)
	virtual bool GetFileExtensions(QStringList& result, const istd::IChangeable* dataObjectPtr = NULL, int flags = -1, bool doAppend = false) const;
	virtual QString GetTypeDescription(const QString* extensionPtr = NULL) const;

private:
	I_ATTR(int, m_bitmapWidthAttrPtr);
	I_ATTR(int, m_bitmapHeightAttrPtr);

	mutable QString m_lastFilePath;
	mutable iimg::CBitmap m_lastBitmap;
};


} // namespace iqtmm


#endif // !iqtmm_CSvgBitmapLoaderComp_included


