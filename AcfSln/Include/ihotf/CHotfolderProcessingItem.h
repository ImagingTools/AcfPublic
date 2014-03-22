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


#ifndef ihotf_CHotfolderProcessingItem_included
#define ihotf_CHotfolderProcessingItem_included


// Qt includes
#include <QtCore/QDateTime>

// ACF includes
#include "imod/TModelWrap.h"

// AcfSln includes
#include "ihotf/IHotfolderProcessingItem.h"


namespace ihotf
{


/**
	Interface for a single processing item in the hotfolder.
*/
class CHotfolderProcessingItem: virtual public ihotf::IHotfolderProcessingItem
{
public:
	CHotfolderProcessingItem();

	// reimplemented (ihotf::IHotfolderProcessingItem)
	virtual QByteArray GetItemUuid() const;
	virtual int GetProcessingState() const;
	virtual void SetProcessingState(int processingState);
	virtual QString GetInputFile() const;
	virtual void SetInputFile(const QString& inputFile);
	virtual QString GetOutputFile() const;
	virtual void SetOutputFile(const QString& outputFile);
	virtual double GetProcessingTime() const;
	virtual void SetProcessingTime(double processingTime);
	virtual const QDateTime& GetStartTime() const;
	virtual void SetStartTime(const QDateTime& startTime);

	// reimplemented (iser::ISerializable)
	virtual bool Serialize(iser::IArchive& archive);

private:
	QString m_inputFile;
	QString m_outputFile;
	int m_processingState;
	double m_processingTime;
	QDateTime m_startTime;

	mutable QByteArray m_itemId;
};


} // namespace ihotf


#endif // !ihotf_CHotfolderProcessingItem_included


