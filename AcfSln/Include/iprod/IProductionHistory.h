/********************************************************************************
**
**	Copyright (C) 2007-2017 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#ifndef iprod_IProductionHistory_included
#define iprod_IProductionHistory_included


// Qt includes
#include <QtCore/QUuid>

// ACF includes
#include <iprm/IOptionsList.h>
#include <ilog/IMessageContainer.h>


namespace iprod
{


/**
	Interface for describing the chronological review of the production process.
	Production history is a container of all data related to the executed inspections for a produced part.
*/
class IProductionHistory: virtual public istd::IChangeable
{
public:
	struct ProcessingInfo
	{
		ProcessingInfo()
			:status(istd::IInformationProvider::IC_NONE)
		{
		}

		istd::IInformationProvider::InformationCategory status;
		QDateTime time;
	};

	/**
		Part information
	*/
	struct PartInfo
	{
		QString serialNumber;
		QString productName;
		QByteArray productId;
		ProcessingInfo processingInfo;
	};

	/**
		Description of the data object used as input or as output of the inspection.
	*/
	struct ObjectInfo
	{
		ObjectInfo()
		{
			uuid = QUuid::createUuid().toByteArray();
		}

		/**
			Unique identifier.
		*/
		QByteArray uuid;

		/**
			Path to the object's data.
		*/
		QString filePath;

		/**
			Type-ID of the obect. Used for factorization.
		*/
		QByteArray typeId;
	};

	typedef QList<ObjectInfo> ObjectInfoList;

	/**
		Description of a single inspection result.
	*/
	struct ResultInfo
	{
		ResultInfo()
		{
			uuid = QUuid::createUuid().toByteArray();
		}

		QByteArray uuid;
		QString name;
		QByteArray inspectionId;
		ObjectInfoList inputObjects;
		ObjectInfoList outputObjects;
		ProcessingInfo processingInfo;
	};

	/**
		Get the list of the produced parts.
	*/
	virtual const iprm::IOptionsList& GetPartsInfoList() const = 0;

	/**
		Get the information about the processed part.
	*/
	virtual PartInfo GetPartInfo(const QByteArray& productionPartId) const = 0;

	/**
		Get the list of the executed inspections for the given part-ID.
	*/
	virtual const iprm::IOptionsList& GetResultInfoList(const QByteArray& productionPartId) const = 0;

	/**
		Get the list of the input objects for the given part-ID and inspection-ID.
	*/
	virtual ResultInfo GetResultInfo(const QByteArray& productionPartId, const QByteArray& resultId) const = 0;
};


} // namespace iprod


#endif // !iprod_IProductionHistory_included

