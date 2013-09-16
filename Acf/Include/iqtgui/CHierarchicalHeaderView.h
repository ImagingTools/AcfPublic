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


#ifndef iqtgui_CHierarchicalHeaderView_included
#define iqtgui_CHierarchicalHeaderView_included


// Qt includes
#include <QtGui/QHeaderView>


namespace iqtgui
{


/**
	Hierarchical header view for QTableView.
	Header data is described by QAbstractItemModel.
	Table model's function "data" should return pointer to QAbstractItemModel, representing header structure,
	for horizontal header it uses HorizontalHeaderDataRole, for vertical - VerticalHeaderDataRole.
	If header's model function "data" with Qt::UserRole return valid QVariant, text in header cell is rotated.
*/
class CHierarchicalHeaderView: public QHeaderView
{
	Q_OBJECT
public:
	typedef QHeaderView BaseClass;

	enum HeaderDataModelRoles
	{
		HorizontalHeaderDataRole=Qt::UserRole,
		VerticalHeaderDataRole=Qt::UserRole+1
	};

	CHierarchicalHeaderView(Qt::Orientation orientation, QWidget* parent = 0);

	// reimplemented (QHeaderView)
	virtual void setModel(QAbstractItemModel* model);

protected:
	// reimplemented (QHeaderView)
	virtual void paintSection(
				QPainter* painter,
				const QRect& rect,
				int logicalIndex) const;
	virtual QSize sectionSizeFromContents(int logicalIndex) const;

private Q_SLOTS:
	void on_sectionResized(int logicalIndex);

private:
	QStyleOptionHeader GetStyleOptionForCell(int logicalIndex) const;
	QModelIndex GetChildIndex(int sectionIndex) const;
	QSize GetCellSize(
			   const QModelIndex& childIndex,
			   const QHeaderView* headerViewPtr,
			   QStyleOptionHeader styleOptions) const;
	void PaintHorizontalSection(
				QPainter *painter,
				const QRect& sectionRect,
				int logicalChildIndex,
				const QHeaderView* headerViewPtr,
				const QStyleOptionHeader& styleOptions,
				const QModelIndex& childIndex) const;
	void PaintVerticalSection(
				QPainter *painter,
				const QRect& sectionRect,
				int logicalChildIndex,
				const QHeaderView* headerViewPtr,
				const QStyleOptionHeader& styleOptions,
				const QModelIndex& childIndex) const;
	QModelIndexList GetChilds(const QModelIndex& searchedIndex) const;
	QModelIndexList SearchChilds(const QModelIndex& curentIndex) const;
	QModelIndex FindRootIndex(QModelIndex index) const;
	QModelIndexList GetParentIndexes(QModelIndex index) const;
	QModelIndex FindChild(const QModelIndex& curentIndex, int sectionIndex, int& curentChildIndex) const;
	void SetForegroundBrush(QStyleOptionHeader& opt, const QModelIndex& index) const;
	void SetBackgroundBrush(QStyleOptionHeader& opt, const QModelIndex& index) const;
	int	GetCurrentCellWidth(
				const QModelIndex& searchedIndex,
				const QModelIndex& childIndex,
				int sectionIndex,
				const QHeaderView* headerViewPtr) const;
	int	GetCurrentCellLeft(
				const QModelIndex& searchedIndex,
				const QModelIndex& childIndex,
				int sectionIndex,
				int left,
				const QHeaderView* headerViewPtr) const;
	int PaintHorizontalCell(
				QPainter *painter,
				const QHeaderView* headerViewPtr,
				const QModelIndex& cellIndex,
				const QModelIndex& childIndex,
				int logicalChildIndex,
				const QStyleOptionHeader& styleOptions,
				const QRect& sectionRect,
				int top) const;
	int PaintVerticalCell(
				QPainter *painter,
				const QHeaderView* headerViewPtr,
				const QModelIndex& cellIndex,
				const QModelIndex& childIndex,
				int logicalChildIndex,
				const QStyleOptionHeader& styleOptions,
				const QRect& sectionRect,
				int left) const;
};


} // namespace iqtgui


#endif // !iqtgui_CHierarchicalHeaderView_included

