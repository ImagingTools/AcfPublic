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


#pragma once


// ACF includes
#include <istd/IInformationProvider.h>
#include <iview/IShapeFactory.h>
#include <iview/IColorSchema.h>


namespace iqtinsp
{


template <class Base>
class TResultShapeCreatorWrap: public Base
{
public:
	typedef Base BaseClass;

	I_BEGIN_BASE_COMPONENT(TResultShapeCreatorWrap);
		I_ASSIGN(m_noneStatusSchemeCompPtr, "NoneStatusColorSchema", "Color schema used for shapes without any status", false, "NoneStatusColorSchema");
		I_ASSIGN(m_okColorSchemeCompPtr, "OkColorSchema", "Color schema used for ok shapes", false, "OkColorSchema");
		I_ASSIGN(m_warningColorSchemeCompPtr, "WarningColorSchema", "Color schema used for warning shapes", false, "WarningColorSchema");
		I_ASSIGN(m_errorColorSchemeCompPtr, "ErrorColorSchema", "Color schema used for error shapes", false, "ErrorColorSchema");
        I_ASSIGN_MULTI_0(m_resultColorShemaListCompPtr, "ResultColorSchemeList", "List of color schema used for related results (according to the list of corresponding IDs)", false);
        I_ASSIGN_MULTI_0(m_resultIdListAttrPtr, "ResultIdList", "List of result IDs for mapping related result color schema", false);
	I_END_COMPONENT;

	/**
		Create a shape for the result object and corresponding status information.
	*/
	virtual iview::IShape* CreateResultShape(
				const iview::IShapeFactory* shapeFactoryPtr,
				const istd::IChangeable* objectPtr,
				const istd::IInformationProvider* infoPtr,
				bool connectToModel = true) const;
private:
	I_REF(iview::IColorSchema, m_noneStatusSchemeCompPtr);
	I_REF(iview::IColorSchema, m_okColorSchemeCompPtr);
	I_REF(iview::IColorSchema, m_warningColorSchemeCompPtr);
	I_REF(iview::IColorSchema, m_errorColorSchemeCompPtr);
    I_MULTIREF(iview::IColorSchema, m_resultColorShemaListCompPtr);
    I_MULTIATTR(int, m_resultIdListAttrPtr);
};


// public methods

template <class Base>
iview::IShape* TResultShapeCreatorWrap<Base>::CreateResultShape(
			const iview::IShapeFactory* shapeFactoryPtr,
			const istd::IChangeable* objectPtr,
			const istd::IInformationProvider* infoPtr,
			bool connectToModel) const
{
	if (shapeFactoryPtr != NULL){
		iview::IShape* shapePtr = shapeFactoryPtr->CreateShape(objectPtr, connectToModel);
		if (shapePtr == NULL){
			return NULL;
		}

		if (infoPtr == NULL){
			return shapePtr;
		}

		int category = infoPtr->GetInformationCategory();

		const iview::IColorSchema* userColorSchemaPtr = shapePtr->GetUserColorSchema();

		switch (category){
			case istd::IInformationProvider::IC_ERROR:
			case istd::IInformationProvider::IC_CRITICAL:
				if ((userColorSchemaPtr == NULL) && m_errorColorSchemeCompPtr.IsValid()){
					shapePtr->SetUserColorSchema(m_errorColorSchemeCompPtr.GetPtr());
				}
				break;

			case istd::IInformationProvider::IC_WARNING:
				if ((userColorSchemaPtr == NULL) && m_warningColorSchemeCompPtr.IsValid()){
					shapePtr->SetUserColorSchema(m_warningColorSchemeCompPtr.GetPtr());
				}
				break;

			case istd::IInformationProvider::IC_INFO:
				if ((userColorSchemaPtr == NULL) && m_okColorSchemeCompPtr.IsValid()){
					shapePtr->SetUserColorSchema(m_okColorSchemeCompPtr.GetPtr());
				}
				break;

			case istd::IInformationProvider::IC_NONE:
				if ((userColorSchemaPtr == NULL) && m_noneStatusSchemeCompPtr.IsValid()){
					shapePtr->SetUserColorSchema(m_noneStatusSchemeCompPtr.GetPtr());
				}
				break;

			default:;
		}

		// Check for result-specific user color schema:
		int resultId = infoPtr->GetInformationId();
		if (resultId >= 0){
			int schemaIndex = m_resultIdListAttrPtr.FindValue(resultId);
			if ((schemaIndex >= 0) && (schemaIndex < m_resultColorShemaListCompPtr.GetCount())){
				if ((userColorSchemaPtr == NULL) && m_resultColorShemaListCompPtr[schemaIndex] != nullptr){
					shapePtr->SetUserColorSchema(m_resultColorShemaListCompPtr[schemaIndex]);
				}
			}
		}

		return shapePtr;
	}

	return NULL;
}


} // namespace iqtinsp


