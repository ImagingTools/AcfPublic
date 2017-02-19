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


#ifndef iattr_CNumericAttributeMetaInfo_included
#define iattr_CNumericAttributeMetaInfo_included


// ACF includes
#include <istd/TOptDelPtr.h>

// ACF-Solutions includes
#include <iattr/INumericAttributeMetaInfo.h>
#include <iattr/CAttributeMetaInfo.h>


namespace iattr
{


/**
	Represents constraints of properties allowing values from enumerated set.
*/
class CNumericAttributeMetaInfo:
			public CAttributeMetaInfo,
			virtual public INumericAttributeMetaInfo
{
public:
	typedef CAttributeMetaInfo BaseClass;

	CNumericAttributeMetaInfo(const QByteArray& typeId = "");

	/**
		Set minimal value of attribute.
		\param	releaseFlag	if true, the value object will be managed by this object, it means it will be deleted from memory during destruction.
	*/
	bool SetMinAttributeValue(const iser::IObject* valuePtr, bool releaseFlag);
	/**
		Set maximal value of attribute.
		\param	releaseFlag	if true, the value object will be managed by this object, it means it will be deleted from memory during destruction.
	*/
	bool SetMaxAttributeValue(const iser::IObject* valuePtr, bool releaseFlag);

	// reimplemented (iattr::IEnumAttributeMetaInfo)
	virtual bool GetMinimalValue(iser::IObject& result) const;
	virtual bool GetMaximalValue(iser::IObject& result) const;

private:
	istd::TOptDelPtr<const iser::IObject> m_minAttributePtr;
	istd::TOptDelPtr<const iser::IObject> m_maxAttributePtr;
};


} // namespace iattr


#endif // !iattr_CNumericAttributeMetaInfo_included


