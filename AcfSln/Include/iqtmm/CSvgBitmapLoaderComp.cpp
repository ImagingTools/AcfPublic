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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF-Solutions.
**
********************************************************************************/


#include "iqtmm/CSvgBitmapLoaderComp.h"


// Qt includes
#include <QFileInfo>
#include <QtSvg/QSvgRenderer>
#include <QPainter>


// ACF includes
#include "iimg/IBitmap.h"

#include "iqt/IQImageProvider.h"


namespace iqtmm
{


// public methods


// reimplemented (iser::IFileLoader)

bool CSvgBitmapLoaderComp::IsOperationSupported(
			const istd::IChangeable* dataObjectPtr,
			const istd::CString* filePathPtr,
			int flags,
			bool beQuiet) const
{
	if (		(dataObjectPtr != NULL) &&
				(dynamic_cast<const iimg::IRasterImage*>(dataObjectPtr) == NULL)){
		if (!beQuiet){
			SendInfoMessage(MI_BAD_OBJECT_TYPE, iqt::GetCString(tr("Object is not a valid")));
		}

		return false;
	}

	if (filePathPtr != NULL){
		if (filePathPtr->IsEmpty()){
			return false;
		}

		QString qtFilePath = iqt::GetQString(*filePathPtr);
		QFileInfo info(qtFilePath);

		istd::CStringList extensions;
		if (GetFileExtensions(extensions, flags)){
			QStringList extensionsList = iqt::GetQStringList(extensions);

			if (!extensionsList.contains(info.suffix(), Qt::CaseInsensitive)){
				if (!beQuiet){
					SendInfoMessage(MI_BAD_EXTENSION, iqt::GetCString(tr("Bad SVG file extension %1").arg(info.suffix())));
				}

				return false;
			}
		}
	}

	return ((flags & QF_FILE) != 0) && ((flags & QF_LOAD) != 0);
}


int CSvgBitmapLoaderComp::LoadFromFile(istd::IChangeable& data, const istd::CString& filePath) const
{
	if (IsOperationSupported(&data, &filePath, QF_LOAD | QF_FILE, false)){
		I_ASSERT(!filePath.IsEmpty());	// should be checked by IsOperationSupported

		iimg::IRasterImage* imagePtr = dynamic_cast<iimg::IBitmap*>(&data);
		I_ASSERT(imagePtr != NULL);	// should be checked by IsOperationSupported
		if (filePath != m_lastFilePath){
			QSvgRenderer renderer;
			if (renderer.load(iqt::GetQString(filePath))){
				if (!m_lastBitmap.CreateBitmap(iimg::IBitmap::PF_RGBA, istd::CIndex2d(*m_bitmapWidthAttrPtr, *m_bitmapHeightAttrPtr))){
					m_lastFilePath.Reset();

					SendInfoMessage(MI_BITMAP_TYPE, iqt::GetCString(tr("Cannot create bitmap")));

					return StateFailed;
				}

				QPainter painter(&m_lastBitmap.GetQImageRef());

				renderer.render(&painter);

				m_lastFilePath = filePath;
			}
			else{
				SendInfoMessage(MI_CANNOT_LOAD, iqt::GetCString(tr("Cannot load SVG file '%1'").arg(iqt::GetQString(filePath))));

				return StateFailed;
			}
		}

		if (imagePtr->CopyFrom(m_lastBitmap)){
			return StateOk;
		}
		else{
			SendInfoMessage(MI_BITMAP_TYPE, iqt::GetCString(tr("Cannot copy bitmap from Qt bitmap")));
		}
	}

	return StateFailed;
}


int CSvgBitmapLoaderComp::SaveToFile(const istd::IChangeable&/* data*/, const istd::CString&/* filePath*/) const
{
	return StateFailed;
}


// reimplemented (iser::IFileTypeInfo)

bool CSvgBitmapLoaderComp::GetFileExtensions(istd::CStringList& result, int flags, bool doAppend) const
{
	if (!doAppend){
		result.clear();
	}

	if ((flags & QF_LOAD) != 0){
		result.push_back("svg");
	}

	return true;
}


istd::CString CSvgBitmapLoaderComp::GetTypeDescription(const istd::CString* extensionPtr) const
{
	bool isKnown = (extensionPtr == NULL);

	if (!isKnown){
		istd::CStringList extensions;
		if (GetFileExtensions(extensions)){
			QStringList extensionsList = iqt::GetQStringList(extensions);
			if (!extensionsList.contains(iqt::GetQString(*extensionPtr), Qt::CaseInsensitive)){
				isKnown = true;
			}
		}
	}

	if (isKnown){
		return iqt::GetCString(tr("SVG image"));
	}

	return "";
}


} // namespace iqtmm


