/********************************************************************************
**
**	Copyright (C) 2007-2013 Witold Gantzke & Kirill Lepskiy
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


#ifndef iqtdoc_CDocumentMetaInfoEditorComp_included
#define iqtdoc_CDocumentMetaInfoEditorComp_included


// Qt includes
#include <QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#else
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#endif

// ACF includes
#include "idoc/IDocumentMetaInfo.h"
#include "imod/TSingleModelObserverBase.h"
#include "ibase/TModelObserverCompWrap.h"
#include "iqtgui/TGuiObserverWrap.h"
#include "iqtgui/TGuiComponentBase.h"


namespace iqtdoc
{


class CDocumentMetaInfoEditorComp:
			public ibase::TModelObserverCompWrap<
						iqtgui::TGuiObserverWrap<
									iqtgui::TGuiComponentBase<QWidget>,
									imod::TSingleModelObserverBase<idoc::IDocumentMetaInfo> > >
{
	Q_OBJECT
public:
	typedef ibase::TModelObserverCompWrap<
		iqtgui::TGuiObserverWrap<
		iqtgui::TGuiComponentBase<QWidget>,
		imod::TSingleModelObserverBase<idoc::IDocumentMetaInfo> > > BaseClass;

	I_BEGIN_COMPONENT(CDocumentMetaInfoEditorComp);
	I_END_COMPONENT;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiModelAttached();
	virtual void OnGuiModelDetached();
	virtual void UpdateGui(int updateFlags = 0);

	// reimplemented (iqtgui::CComponentBase)
	virtual void OnGuiCreated();

private:
	void ResetItems();

private:
	struct MetaInfoItem
	{
		MetaInfoItem()
			:labelPtr(NULL),
			editPtr(NULL)
		{
		}

		QLabel* labelPtr;
		QLineEdit* editPtr;
	};

	typedef QMap<int, MetaInfoItem> MetaInfoItemsMap;

	MetaInfoItemsMap m_metaInfoItemsMap;
};


} // namespace iqtdoc


#endif // !iqtdoc_CDocumentMetaInfoEditorComp_included


