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
** Form generated from reading UI file 'CGeneralSupplierGuiComp.ui'
**
** Created: Thu 21. Apr 15:49:21 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGENERALSUPPLIERGUICOMP_H
#define UI_CGENERALSUPPLIERGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGeneralSupplierGuiComp
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *TestButton;
    QLabel *label;
    QLabel *InspectionTimeLabel;
    QLabel *label_2;
    QLabel *StatusLabel;
    QGroupBox *ParamsGB;
    QVBoxLayout *vboxLayout;
    QFrame *ParamsFrame;
    QVBoxLayout *vboxLayout1;
    QPushButton *LoadParamsButton;
    QPushButton *SaveParamsButton;

    void setupUi(QWidget *CGeneralSupplierGuiComp)
    {
        if (CGeneralSupplierGuiComp->objectName().isEmpty())
            CGeneralSupplierGuiComp->setObjectName(QString::fromUtf8("CGeneralSupplierGuiComp"));
        CGeneralSupplierGuiComp->resize(323, 451);
        verticalLayout = new QVBoxLayout(CGeneralSupplierGuiComp);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(CGeneralSupplierGuiComp);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TestButton = new QPushButton(groupBox);
        TestButton->setObjectName(QString::fromUtf8("TestButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TestButton->sizePolicy().hasHeightForWidth());
        TestButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(TestButton, 0, 0, 1, 3);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        InspectionTimeLabel = new QLabel(groupBox);
        InspectionTimeLabel->setObjectName(QString::fromUtf8("InspectionTimeLabel"));
        InspectionTimeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(InspectionTimeLabel, 1, 1, 1, 2);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        StatusLabel = new QLabel(groupBox);
        StatusLabel->setObjectName(QString::fromUtf8("StatusLabel"));
        StatusLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(StatusLabel, 2, 1, 1, 2);


        verticalLayout->addWidget(groupBox);

        ParamsGB = new QGroupBox(CGeneralSupplierGuiComp);
        ParamsGB->setObjectName(QString::fromUtf8("ParamsGB"));
        vboxLayout = new QVBoxLayout(ParamsGB);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        vboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        ParamsFrame = new QFrame(ParamsGB);
        ParamsFrame->setObjectName(QString::fromUtf8("ParamsFrame"));
        ParamsFrame->setFrameShape(QFrame::NoFrame);
        ParamsFrame->setFrameShadow(QFrame::Raised);
        vboxLayout1 = new QVBoxLayout(ParamsFrame);
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));

        vboxLayout->addWidget(ParamsFrame);

        LoadParamsButton = new QPushButton(ParamsGB);
        LoadParamsButton->setObjectName(QString::fromUtf8("LoadParamsButton"));
        sizePolicy1.setHeightForWidth(LoadParamsButton->sizePolicy().hasHeightForWidth());
        LoadParamsButton->setSizePolicy(sizePolicy1);

        vboxLayout->addWidget(LoadParamsButton);

        SaveParamsButton = new QPushButton(ParamsGB);
        SaveParamsButton->setObjectName(QString::fromUtf8("SaveParamsButton"));
        sizePolicy1.setHeightForWidth(SaveParamsButton->sizePolicy().hasHeightForWidth());
        SaveParamsButton->setSizePolicy(sizePolicy1);

        vboxLayout->addWidget(SaveParamsButton);


        verticalLayout->addWidget(ParamsGB);


        retranslateUi(CGeneralSupplierGuiComp);

        QMetaObject::connectSlotsByName(CGeneralSupplierGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CGeneralSupplierGuiComp)
    {
        CGeneralSupplierGuiComp->setWindowTitle(QApplication::translate("CGeneralSupplierGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CGeneralSupplierGuiComp", "Task", 0, QApplication::UnicodeUTF8));
        TestButton->setText(QApplication::translate("CGeneralSupplierGuiComp", "Test", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CGeneralSupplierGuiComp", "Inspection Time", 0, QApplication::UnicodeUTF8));
        InspectionTimeLabel->setText(QString());
        label_2->setText(QApplication::translate("CGeneralSupplierGuiComp", "Status", 0, QApplication::UnicodeUTF8));
        StatusLabel->setText(QString());
        ParamsGB->setTitle(QApplication::translate("CGeneralSupplierGuiComp", "Parameters", 0, QApplication::UnicodeUTF8));
        LoadParamsButton->setText(QApplication::translate("CGeneralSupplierGuiComp", "Load...", 0, QApplication::UnicodeUTF8));
        SaveParamsButton->setText(QApplication::translate("CGeneralSupplierGuiComp", "Save...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CGeneralSupplierGuiComp: public Ui_CGeneralSupplierGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGENERALSUPPLIERGUICOMP_H
