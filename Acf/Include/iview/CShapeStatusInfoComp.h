/********************************************************************************
**
**	Copyright (C) 2007-2014 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iview_CShapeStatusInfoComp_included
#define iview_CShapeStatusInfoComp_included


// ACF includes
#include "icomp/CComponentBase.h"

#include "iview/IShapeStatusInfo.h"


namespace iview
{


/**
	Standard implementation of IShapeStatusInfo interface.
*/
class CShapeStatusInfoComp: public icomp::CComponentBase, virtual public IShapeStatusInfo
{
public:
	typedef icomp::CComponentBase BaseClass;
	I_BEGIN_COMPONENT(CShapeStatusInfoComp);
		I_REGISTER_INTERFACE(IShapeStatusInfo);
	I_END_COMPONENT;

	CShapeStatusInfoComp();

	// reimplemented (iview::IShapeStatusInfo)
	virtual i2d::CVector2d GetLogicalPosition() const;
	virtual void SetLogicalPosition(const i2d::CVector2d& logicalPosition);
	virtual i2d::CVector2d GetPixelPosition() const;
	virtual void SetPixelPosition(const i2d::CVector2d& pixelPosition);
	virtual QString GetInfoText() const;
	virtual void SetInfoText(const QString& infoText);

private:
	i2d::CVector2d m_logicalPosition;
	i2d::CVector2d m_pixelPosition;
	QString m_infoText;
};


} // namespace iview


#endif // !iview_CShapeStatusInfoComp_included


