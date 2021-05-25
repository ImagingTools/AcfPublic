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


#ifndef iqtgui_TMakeIconProviderCompWrap_included
#define iqtgui_TMakeIconProviderCompWrap_included


// Qt includes
#include <QtGui/QIcon>

// ACF includes
#include <icomp/CComponentBase.h>
#include <ifile/IFileNameParam.h>


namespace iqtgui
{


template <class Base>
class TMakeIconProviderCompWrap: public Base
{
public:
	typedef Base BaseClass;

	I_BEGIN_BASE_COMPONENT(TMakeIconProviderCompWrap);
		I_ASSIGN(m_prefixAttrPtr, "IconResourcePrefix", "Icon resource prefix", true, "");
	I_END_COMPONENT;

	virtual QIcon GetIcon(const QString& iconName) const;

private:
	I_ATTR(QString, m_prefixAttrPtr);
};


template <class Base>
QIcon TMakeIconProviderCompWrap<Base>::GetIcon(const QString& iconName) const
{
	if ((*m_prefixAttrPtr).isEmpty()){
		return QIcon(iconName);
	}

	QString prefix = *m_prefixAttrPtr + "/";

	QIcon icon;
	QPixmap pixmap;

	if (pixmap.load(prefix + iconName + "_Off_Normal")){
		icon.addPixmap(pixmap, QIcon::Normal, QIcon::Off);
	}

	if (pixmap.load(prefix + iconName + "_Off_Disabled")){
		icon.addPixmap(pixmap, QIcon::Disabled, QIcon::Off);
	}

	if (pixmap.load(prefix + iconName + "_Off_Active")){
		icon.addPixmap(pixmap, QIcon::Active, QIcon::Off);
	}

	if (pixmap.load(prefix + iconName + "_Off_Selected")){
		icon.addPixmap(pixmap, QIcon::Selected, QIcon::Off);
	}

	if (pixmap.load(prefix + iconName + "_On_Normal")){
		icon.addPixmap(pixmap, QIcon::Normal, QIcon::On);
	}

	if (pixmap.load(prefix + iconName + "_On_Disabled")){
		icon.addPixmap(pixmap, QIcon::Disabled, QIcon::On);
	}

	if (pixmap.load(prefix + iconName + "_On_Active")){
		icon.addPixmap(pixmap, QIcon::Active, QIcon::On);
	}

	if (pixmap.load(prefix + iconName + "_On_Selected")){
		icon.addPixmap(pixmap, QIcon::Selected, QIcon::On);
	}

	return icon;
}


} // namespace iqtgui


#endif // !iqtgui_TMakeIconProviderCompWrap_included


