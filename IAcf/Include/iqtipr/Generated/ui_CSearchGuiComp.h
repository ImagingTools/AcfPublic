/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


/********************************************************************************
** Form generated from reading UI file 'CSearchGuiComp.ui'
**
** Created: Thu 21. Apr 15:46:13 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSEARCHGUICOMP_H
#define UI_CSEARCHGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSearchGuiComp
{
public:
    QVBoxLayout *vboxLayout;
    QFrame *ParamsFrame;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout;
    QHBoxLayout *hboxLayout1;
    QPushButton *FindButton;
    QPushButton *TeachButton;

    void setupUi(QWidget *CSearchGuiComp)
    {
        if (CSearchGuiComp->objectName().isEmpty())
            CSearchGuiComp->setObjectName(QString::fromUtf8("CSearchGuiComp"));
        CSearchGuiComp->resize(377, 263);
        vboxLayout = new QVBoxLayout(CSearchGuiComp);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        ParamsFrame = new QFrame(CSearchGuiComp);
        ParamsFrame->setObjectName(QString::fromUtf8("ParamsFrame"));
        ParamsFrame->setFrameShape(QFrame::NoFrame);
        ParamsFrame->setFrameShadow(QFrame::Raised);
        vboxLayout1 = new QVBoxLayout(ParamsFrame);
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));

        vboxLayout1->addLayout(hboxLayout);


        vboxLayout->addWidget(ParamsFrame);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        FindButton = new QPushButton(CSearchGuiComp);
        FindButton->setObjectName(QString::fromUtf8("FindButton"));

        hboxLayout1->addWidget(FindButton);

        TeachButton = new QPushButton(CSearchGuiComp);
        TeachButton->setObjectName(QString::fromUtf8("TeachButton"));

        hboxLayout1->addWidget(TeachButton);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(CSearchGuiComp);

        QMetaObject::connectSlotsByName(CSearchGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CSearchGuiComp)
    {
        CSearchGuiComp->setWindowTitle(QApplication::translate("CSearchGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        FindButton->setText(QApplication::translate("CSearchGuiComp", "Find Model", 0, QApplication::UnicodeUTF8));
        TeachButton->setText(QApplication::translate("CSearchGuiComp", "Teach Model...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CSearchGuiComp: public Ui_CSearchGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSEARCHGUICOMP_H
