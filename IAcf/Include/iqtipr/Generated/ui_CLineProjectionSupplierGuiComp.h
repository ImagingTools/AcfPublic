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
** Form generated from reading UI file 'CLineProjectionSupplierGuiComp.ui'
**
** Created: Thu 21. Apr 15:46:13 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLINEPROJECTIONSUPPLIERGUICOMP_H
#define UI_CLINEPROJECTIONSUPPLIERGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLineProjectionSupplierGuiComp
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QPushButton *TestButton;
    QGroupBox *ProjectionFrame;
    QVBoxLayout *verticalLayout;
    QGroupBox *ParamsGB;
    QVBoxLayout *vboxLayout2;
    QFrame *ParamsFrame;
    QVBoxLayout *vboxLayout3;
    QPushButton *LoadParamsButton;
    QPushButton *SaveParamsButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CLineProjectionSupplierGuiComp)
    {
        if (CLineProjectionSupplierGuiComp->objectName().isEmpty())
            CLineProjectionSupplierGuiComp->setObjectName(QString::fromUtf8("CLineProjectionSupplierGuiComp"));
        CLineProjectionSupplierGuiComp->resize(467, 505);
        vboxLayout = new QVBoxLayout(CLineProjectionSupplierGuiComp);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(CLineProjectionSupplierGuiComp);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        vboxLayout1 = new QVBoxLayout(groupBox);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        TestButton = new QPushButton(groupBox);
        TestButton->setObjectName(QString::fromUtf8("TestButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TestButton->sizePolicy().hasHeightForWidth());
        TestButton->setSizePolicy(sizePolicy1);

        vboxLayout1->addWidget(TestButton);


        vboxLayout->addWidget(groupBox);

        ProjectionFrame = new QGroupBox(CLineProjectionSupplierGuiComp);
        ProjectionFrame->setObjectName(QString::fromUtf8("ProjectionFrame"));
        verticalLayout = new QVBoxLayout(ProjectionFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        vboxLayout->addWidget(ProjectionFrame);

        ParamsGB = new QGroupBox(CLineProjectionSupplierGuiComp);
        ParamsGB->setObjectName(QString::fromUtf8("ParamsGB"));
        vboxLayout2 = new QVBoxLayout(ParamsGB);
#ifndef Q_OS_MAC
        vboxLayout2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout2->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout2->setObjectName(QString::fromUtf8("vboxLayout2"));
        ParamsFrame = new QFrame(ParamsGB);
        ParamsFrame->setObjectName(QString::fromUtf8("ParamsFrame"));
        ParamsFrame->setFrameShape(QFrame::NoFrame);
        ParamsFrame->setFrameShadow(QFrame::Raised);
        vboxLayout3 = new QVBoxLayout(ParamsFrame);
#ifndef Q_OS_MAC
        vboxLayout3->setSpacing(6);
#endif
        vboxLayout3->setContentsMargins(0, 0, 0, 0);
        vboxLayout3->setObjectName(QString::fromUtf8("vboxLayout3"));

        vboxLayout2->addWidget(ParamsFrame);

        LoadParamsButton = new QPushButton(ParamsGB);
        LoadParamsButton->setObjectName(QString::fromUtf8("LoadParamsButton"));
        sizePolicy1.setHeightForWidth(LoadParamsButton->sizePolicy().hasHeightForWidth());
        LoadParamsButton->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(LoadParamsButton);

        SaveParamsButton = new QPushButton(ParamsGB);
        SaveParamsButton->setObjectName(QString::fromUtf8("SaveParamsButton"));
        sizePolicy1.setHeightForWidth(SaveParamsButton->sizePolicy().hasHeightForWidth());
        SaveParamsButton->setSizePolicy(sizePolicy1);

        vboxLayout2->addWidget(SaveParamsButton);


        vboxLayout->addWidget(ParamsGB);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(verticalSpacer);


        retranslateUi(CLineProjectionSupplierGuiComp);

        QMetaObject::connectSlotsByName(CLineProjectionSupplierGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CLineProjectionSupplierGuiComp)
    {
        CLineProjectionSupplierGuiComp->setWindowTitle(QApplication::translate("CLineProjectionSupplierGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CLineProjectionSupplierGuiComp", "Point", 0, QApplication::UnicodeUTF8));
        TestButton->setText(QApplication::translate("CLineProjectionSupplierGuiComp", "Test", 0, QApplication::UnicodeUTF8));
        ProjectionFrame->setTitle(QApplication::translate("CLineProjectionSupplierGuiComp", "Projection", 0, QApplication::UnicodeUTF8));
        ParamsGB->setTitle(QApplication::translate("CLineProjectionSupplierGuiComp", "Parameters", 0, QApplication::UnicodeUTF8));
        LoadParamsButton->setText(QApplication::translate("CLineProjectionSupplierGuiComp", "Load...", 0, QApplication::UnicodeUTF8));
        SaveParamsButton->setText(QApplication::translate("CLineProjectionSupplierGuiComp", "Save...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CLineProjectionSupplierGuiComp: public Ui_CLineProjectionSupplierGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLINEPROJECTIONSUPPLIERGUICOMP_H
