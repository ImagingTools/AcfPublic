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


#ifndef CPropertyObjectExampe_included
#define CPropertyObjectExampe_included


// ACF includes
#include "iprop/CPropertiesManager.h"
#include "iprop/TObjectProperty.h"


// Project includes
#include "IMyDataModel.h"


/**
	Demostration, how to create an implementation of a persistent data object over property manager.
*/
class CPropertyObjectExampe:
			virtual public IMyDataModel,
			public iprop::CPropertiesManager
{
public:
	typedef iprop::CPropertiesManager BaseClass;

	CPropertyObjectExampe();

	// reimplemented (IMyDataModel)
	virtual double GetNumber() const;
	virtual void SetNumber(double number);
	virtual QByteArray GetText() const;
	virtual void SetText(const QByteArray& text);
	virtual i2d::CRectangle GetRectangle() const;
	virtual void SetRectangle(const i2d::CRectangle& rectangle);

private:
	// specify the data model over properties:
	iprop::CDoubleProperty m_number;
	iprop::CStdStringProperty m_text;

	// Rectangle property is no standard property, so we have to define our own property type:
	typedef iprop::TObjectProperty<i2d::CRectangle> CRectangleProperty;
	
	CRectangleProperty m_rectangle;
};


#endif // !CPropertyObjectExampe_included


