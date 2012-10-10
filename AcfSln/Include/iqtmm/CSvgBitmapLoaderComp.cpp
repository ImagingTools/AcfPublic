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


#include "iqtmm/CSvgBitmapLoaderComp.h"


// Qt includes
#include <QtCore/QFileInfo>
#include <QtSvg/QSvgRenderer>
#include <QtGui/QPainter>


// ACF includes
#include "iimg/IBitmap.h"

#include "iqt/IQImageProvider.h"


namespace iqtmm
{


// public methods


// reimplemented (iser::IFileLoader)

bool CSvgBitmapLoaderComp::IsOperationSupported(
			const istd::IChangeable* dataObjectPtr,
			const QString* filePathPtr,
			int flags,
			bool beQuiet) const
{
	if (		(dataObjectPtr != NULL) &&
				(dynamic_cast<const iimg::IRasterImage*>(dataObjectPtr) == NULL)){
		if (!beQuiet){
			SendInfoMessage(MI_BAD_OBJECT_TYPE, tr("Object is not a valid"));
		}

		return false;
	}

	if (filePathPtr != NULL){
		if (filePathPtr->isEmpty()){
			return false;
		}

		QFileInfo info(*filePathPtr);

		QStringList extensions;
		if (GetFileExtensions(extensions, flags)){
			QStringList extensionsList = (extensions);

			if (!extensionsList.contains(info.suffix(), Qt::CaseInsensitive)){
				if (!beQuiet){
					SendInfoMessage(MI_BAD_EXTENSION, tr("Bad SVG file extension %1").arg(info.suffix()));
				}

				return false;
			}
		}
	}

	return ((flags & QF_FILE) != 0) && ((flags & QF_LOAD) != 0);
}


int CSvgBitmapLoaderComp::LoadFromFile(istd::IChangeable& data, const QString& filePath) const
{
	if (IsOperationSupported(&data, &filePath, QF_LOAD | QF_FILE, false)){
		I_ASSERT(!filePath.isEmpty());	// should be checked by IsOperationSupported

		iimg::IRasterImage* imagePtr = dynamic_cast<iimg::IBitmap*>(&data);
		I_ASSERT(imagePtr != NULL);	// should be checked by IsOperationSupported
		if (filePath != m_lastFilePath){
			QSvgRenderer renderer;
			if (renderer.load(filePath)){
				if (!m_lastBitmap.CreateBitmap(iimg::IBitmap::PF_RGBA, istd::CIndex2d(*m_bitmapWidthAttrPtr, *m_bitmapHeightAttrPtr))){
					m_lastFilePath.clear();

					SendInfoMessage(MI_BITMAP_TYPE, tr("Cannot create bitmap"));

					return StateFailed;
				}

				QPainter painter(&m_lastBitmap.GetQImageRef());

				renderer.render(&painter);

				m_lastFilePath = filePath;
			}
			else{
				SendInfoMessage(MI_CANNOT_LOAD, tr("Cannot load SVG file '%1'").arg(filePath));

				return StateFailed;
			}
		}

		if (imagePtr->CopyFrom(m_lastBitmap)){
			return StateOk;
		}
		else{
			SendInfoMessage(MI_BITMAP_TYPE, tr("Cannot copy bitmap from Qt bitmap"));
		}
	}

	return StateFailed;
}


int CSvgBitmapLoaderComp::SaveToFile(const istd::IChangeable&/* data*/, const QString&/* filePath*/) const
{
	return StateFailed;
}


// reimplemented (iser::IFileTypeInfo)

bool CSvgBitmapLoaderComp::GetFileExtensions(QStringList& result, int flags, bool doAppend) const
{
	if (!doAppend){
		result.clear();
	}

	if ((flags & QF_LOAD) != 0){
		result.push_back("svg");
	}

	return true;
}


QString CSvgBitmapLoaderComp::GetTypeDescription(const QString* extensionPtr) const
{
	bool isKnown = (extensionPtr == NULL);

	if (!isKnown){
		QStringList extensions;
		if (GetFileExtensions(extensions)){
			QStringList extensionsList = (extensions);
			if (!extensionsList.contains(*extensionPtr, Qt::CaseInsensitive)){
				isKnown = true;
			}
		}
	}

	if (isKnown){
		return tr("SVG image");
	}

	return "";
}


} // namespace iqtmm


