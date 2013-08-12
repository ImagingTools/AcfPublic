/********************************************************************************
**
**	Copyright (c) 2007-2011 Witold Gantzke & Kirill Lepskiy
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


#ifndef _qqtauth_CUserManagerDialog_included
#define _qqtauth_CUserManagerDialog_included


// Qt includes
#include <QtCore/QString>
#include<QtCore/QtGlobal>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QItemDelegate>
#include <QtWidgets/QDialog>
#else
#include <QtGui/QItemDelegate>
#include <QtGui/QDialog>
#endif

// ACF includes
#include "iser/CMemoryWriteArchive.h"

// ACF-Solutions includes
#include "iauth/ILogin.h"
#include "iauth/IUsersManager.h"

#include "iqtauth/Generated/ui_CUserManagerDialog.h"


namespace iqtauth
{


class CUserManagerDialog:
			public QDialog,
			public Ui::CUserManagerDialog
{
	Q_OBJECT
public:
	CUserManagerDialog(const iauth::ILogin& login, iauth::IUsersManager& manager);

	void SaveCurUsername(const QString& Username);
	int GetUserGroupSize();

protected Q_SLOTS:
	void on_AddUserButton_clicked();
	void on_ResetPasswordButton_clicked();
	void on_RemoveUserButton_clicked();
	void OnCancel();

private:
	enum ListColumn
	{
		LC_NAME,
		LC_GROUP
	};

	class CUserManagerItemDelegate: public QItemDelegate
	{
	public:
		typedef QItemDelegate BaseClass;

		CUserManagerItemDelegate(CUserManagerDialog& parent);

		// reimplemented (QItemDelegate)
		virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;

		// reimplemented (QAbstractItemDelegate)
		virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;

		// reimplemented (QWidget)
		virtual QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;

	private:
		CUserManagerDialog& m_parent;
		int m_loggedUserLevel;
	};

	const iauth::ILogin& m_login;
	iauth::IUsersManager& m_manager;

	void ResetGui();
	void UpdateUserList();

	QString m_curUserName;

	void* userManagerMemBufferPtr;
	int userManagerMemBufferSize;

	iser::CMemoryWriteArchive m_storedUsersManager;
};


} // namespace iqtauth


#endif	// !_qqtauth_CUserManagerDialog_included


