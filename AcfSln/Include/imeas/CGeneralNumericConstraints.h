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


#ifndef imeas_CGeneralNumericConstraints_included
#define imeas_CGeneralNumericConstraints_included


// ACF includes
#include <imath/CGeneralUnitInfo.h>

// ACF-Solutions includes
#include <imeas/INumericValue.h>
#include <imeas/INumericConstraints.h>


namespace imeas
{


/**
	Simple implementation of imeas::INumericConstraints interface.
*/
class CGeneralNumericConstraints:
			virtual public INumericConstraints,
			virtual protected iprm::IOptionsList
{
public:
	/**
		Removes all value informations.
	*/
	void Reset();
	/**
		Add new value information.
	*/
	virtual bool InsertValueInfo(
				const QString& name,
				const QString& description,
				const QByteArray& valueId,
				const imath::CGeneralUnitInfo& unitInfo,
				int index = -1);

	/**
		Remove single value information.
	*/
	void RemoveValueInfo(int index);

	/**
		Get unit info stored alway in this structure.
	*/
	const imath::CGeneralUnitInfo& GetGeneralUnitInfo(int index) const;

	// reimplemented (imeas::INumericConstraints)
	virtual const iprm::IOptionsList& GetValueListInfo() const;
	virtual const imath::IUnitInfo* GetNumericValueUnitInfo(int index) const;

	// reimplemented (iprm::IOptionsList)
	virtual int GetOptionsFlags() const;
	virtual int GetOptionsCount() const;
	virtual QString GetOptionName(int index) const;
	virtual QString GetOptionDescription(int index) const;
	virtual QByteArray GetOptionId(int index) const;
	virtual bool IsOptionEnabled(int index) const;

private:
	struct Info
	{
		QString name;
		QString description;
		QByteArray id;
		imath::CGeneralUnitInfo unitInfo;
	};

	QVector<Info> m_valueInfos;
};


} // namespace imeas


#endif // !imeas_CGeneralNumericConstraints_included


