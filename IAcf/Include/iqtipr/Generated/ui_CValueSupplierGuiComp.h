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
** Form generated from reading UI file 'CValueSupplierGuiComp.ui'
**
** Created: Fri 3. Jun 13:43:24 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CVALUESUPPLIERGUICOMP_H
#define UI_CVALUESUPPLIERGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CValueSupplierGuiComp
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *TestButton;
    QToolButton *AutoUpdateButton;
    QFrame *ImageParamsLabel;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLabel *PositionLabel;
    QGroupBox *ParamsGB;
    QVBoxLayout *vboxLayout;
    QFrame *ParamsFrame;
    QVBoxLayout *vboxLayout1;
    QPushButton *LoadParamsButton;
    QPushButton *SaveParamsButton;
    QGroupBox *IntResultsFrame;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *CValueSupplierGuiComp)
    {
        if (CValueSupplierGuiComp->objectName().isEmpty())
            CValueSupplierGuiComp->setObjectName(QString::fromUtf8("CValueSupplierGuiComp"));
        CValueSupplierGuiComp->resize(637, 733);
        verticalLayout_3 = new QVBoxLayout(CValueSupplierGuiComp);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(CValueSupplierGuiComp);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox);
#ifndef Q_OS_MAC
        verticalLayout_2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
#endif
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        TestButton = new QPushButton(groupBox);
        TestButton->setObjectName(QString::fromUtf8("TestButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TestButton->sizePolicy().hasHeightForWidth());
        TestButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(TestButton);

        AutoUpdateButton = new QToolButton(groupBox);
        AutoUpdateButton->setObjectName(QString::fromUtf8("AutoUpdateButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(AutoUpdateButton->sizePolicy().hasHeightForWidth());
        AutoUpdateButton->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/AutoUpdate.svg"), QSize(), QIcon::Normal, QIcon::Off);
        AutoUpdateButton->setIcon(icon);
        AutoUpdateButton->setCheckable(true);

        horizontalLayout->addWidget(AutoUpdateButton);


        verticalLayout_2->addLayout(horizontalLayout);

        ImageParamsLabel = new QFrame(groupBox);
        ImageParamsLabel->setObjectName(QString::fromUtf8("ImageParamsLabel"));
        ImageParamsLabel->setFrameShape(QFrame::NoFrame);
        ImageParamsLabel->setFrameShadow(QFrame::Raised);
        hboxLayout = new QHBoxLayout(ImageParamsLabel);
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        label = new QLabel(ImageParamsLabel);
        label->setObjectName(QString::fromUtf8("label"));

        hboxLayout->addWidget(label);

        PositionLabel = new QLabel(ImageParamsLabel);
        PositionLabel->setObjectName(QString::fromUtf8("PositionLabel"));
        PositionLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hboxLayout->addWidget(PositionLabel);


        verticalLayout_2->addWidget(ImageParamsLabel);


        verticalLayout_3->addWidget(groupBox);

        ParamsGB = new QGroupBox(CValueSupplierGuiComp);
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

        IntResultsFrame = new QGroupBox(ParamsGB);
        IntResultsFrame->setObjectName(QString::fromUtf8("IntResultsFrame"));
        verticalLayout = new QVBoxLayout(IntResultsFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        vboxLayout->addWidget(IntResultsFrame);


        verticalLayout_3->addWidget(ParamsGB);


        retranslateUi(CValueSupplierGuiComp);

        QMetaObject::connectSlotsByName(CValueSupplierGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CValueSupplierGuiComp)
    {
        CValueSupplierGuiComp->setWindowTitle(QApplication::translate("CValueSupplierGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CValueSupplierGuiComp", "Point", 0, QApplication::UnicodeUTF8));
        TestButton->setText(QApplication::translate("CValueSupplierGuiComp", "Test", 0, QApplication::UnicodeUTF8));
        AutoUpdateButton->setText(QString());
        label->setText(QApplication::translate("CValueSupplierGuiComp", "Found Position", 0, QApplication::UnicodeUTF8));
        PositionLabel->setText(QString());
        ParamsGB->setTitle(QApplication::translate("CValueSupplierGuiComp", "Parameters", 0, QApplication::UnicodeUTF8));
        LoadParamsButton->setText(QApplication::translate("CValueSupplierGuiComp", "Load...", 0, QApplication::UnicodeUTF8));
        SaveParamsButton->setText(QApplication::translate("CValueSupplierGuiComp", "Save...", 0, QApplication::UnicodeUTF8));
        IntResultsFrame->setTitle(QApplication::translate("CValueSupplierGuiComp", "Intermediate Results", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CValueSupplierGuiComp: public Ui_CValueSupplierGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CVALUESUPPLIERGUICOMP_H
