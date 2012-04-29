/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


#ifndef iqt2d_CPolygonParamsGuiComp_included
#define iqt2d_CPolygonParamsGuiComp_included


// Qt includes
#include <QtGui/QItemDelegate>
#include <QtGui/QLineEdit>
#include <QtGui/QDoubleValidator>


// ACF includes
#include "i2d/CPolygon.h"

#include "iview/CInteractivePolygonShape.h"

#include "iqt2d/TShapeParamsGuiCompBase.h"
#include "iqt2d/Generated/ui_CPolygonParamsGuiComp.h"


namespace iqt2d
{


class CPolygonParamsGuiComp:
		public iqt2d::TShapeParamsGuiCompBase<
				Ui::CPolygonParamsGuiComp,
				iview::CInteractivePolygonShape,
				i2d::CPolygon>
{
	Q_OBJECT

public:
	typedef iqt2d::TShapeParamsGuiCompBase<
			Ui::CPolygonParamsGuiComp,
			iview::CInteractivePolygonShape,
			i2d::CPolygon> BaseClass;

	I_BEGIN_COMPONENT(CPolygonParamsGuiComp);
	I_END_COMPONENT;

	// reimplemented (imod::IModelEditor)
	virtual void UpdateModel() const;

protected:
	// reimplemented (iqtgui::TGuiObserverWrap)
	virtual void OnGuiCreated();
	virtual void OnGuiModelAttached();
	virtual void OnGuiModelDetached();
	virtual void UpdateGui(int updateFlags = 0);

protected Q_SLOTS:
	void OnParamsChanged();

	void on_AppendButton_clicked();
	void on_InsertButton_clicked();
	void on_RemoveButton_clicked();

protected:
	/** 
		Internal item delegate class for input validation
	*/
	class CPolygonParamsGuiItemDelegate: public QItemDelegate
	{
	public:
		virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem&, const QModelIndex&) const
		{
			QLineEdit* editorPtr = new QLineEdit(parent);
			editorPtr->setValidator(new QDoubleValidator());
			return editorPtr;
		}
	};
};


} // namespace iqt2d


#endif // !iqt2d_CPolygonParamsGuiComp_included
