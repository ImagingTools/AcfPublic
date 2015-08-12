/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
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



#ifndef imeas_CGeneralNumericConstraints_included
#define imeas_CGeneralNumericConstraints_included


// ACF includes
#include "iser/ISerializable.h"
#include "icomp/CComponentBase.h"
#include "imath/CGeneralUnitInfo.h"

// ACF-Solutions includes
#include "imeas/INumericValue.h"
#include "imeas/INumericConstraints.h"


namespace imeas
{


/**
	Simple implementation of imeas::INumericConstraints interface.
*/
class CGeneralNumericConstraints: virtual public INumericConstraints
{
public:
	typedef icomp::CComponentBase BaseClass;

	/**
		Removes all value informations.
	*/
	void Reset();
	/**
		Add new value information.
	*/
	void InsertValueInfo(const QString& name, const QString& description, const imath::CGeneralUnitInfo& unitInfo, int index = -1);
	/**
		Remove single value information.
	*/
	void RemoveValueInfo(int index);

	// reimplemented (imeas::INumericConstraints)
	virtual int GetNumericValuesCount() const;
	virtual QString GetNumericValueName(int index) const;
	virtual QString GetNumericValueDescription(int index) const;
	virtual const imath::IUnitInfo* GetNumericValueUnitInfo(int index) const;

private:
	struct Info
	{
		QString name;
		QString description;
		imath::CGeneralUnitInfo unitInfo;
	};

	QVector<Info> m_valueInfos;
};


} // namespace imeas


#endif // !imeas_CGeneralNumericConstraints_included


