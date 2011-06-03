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
** Form generated from reading UI file 'CCircleFinderParamsGuiComp.ui'
**
** Created: Fri 3. Jun 13:43:24 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCIRCLEFINDERPARAMSGUICOMP_H
#define UI_CCIRCLEFINDERPARAMSGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CCircleFinderParamsGuiComp
{
public:
    QGridLayout *gridLayout;
    QCheckBox *EnableOutliersElimination;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *MinOutliersDistanceLabel;
    QLabel *label_4;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *MinOutliersDistance;
    QSpinBox *MaxRaysCount;
    QComboBox *CaliperMode;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CCircleFinderParamsGuiComp)
    {
        if (CCircleFinderParamsGuiComp->objectName().isEmpty())
            CCircleFinderParamsGuiComp->setObjectName(QString::fromUtf8("CCircleFinderParamsGuiComp"));
        CCircleFinderParamsGuiComp->resize(232, 124);
        gridLayout = new QGridLayout(CCircleFinderParamsGuiComp);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        EnableOutliersElimination = new QCheckBox(CCircleFinderParamsGuiComp);
        EnableOutliersElimination->setObjectName(QString::fromUtf8("EnableOutliersElimination"));

        gridLayout->addWidget(EnableOutliersElimination, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        MinOutliersDistanceLabel = new QLabel(CCircleFinderParamsGuiComp);
        MinOutliersDistanceLabel->setObjectName(QString::fromUtf8("MinOutliersDistanceLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MinOutliersDistanceLabel->sizePolicy().hasHeightForWidth());
        MinOutliersDistanceLabel->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(MinOutliersDistanceLabel);

        label_4 = new QLabel(CCircleFinderParamsGuiComp);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_4);

        label = new QLabel(CCircleFinderParamsGuiComp);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        MinOutliersDistance = new QDoubleSpinBox(CCircleFinderParamsGuiComp);
        MinOutliersDistance->setObjectName(QString::fromUtf8("MinOutliersDistance"));
        MinOutliersDistance->setMinimum(0.1);
        MinOutliersDistance->setMaximum(100);
        MinOutliersDistance->setValue(5);

        verticalLayout_2->addWidget(MinOutliersDistance);

        MaxRaysCount = new QSpinBox(CCircleFinderParamsGuiComp);
        MaxRaysCount->setObjectName(QString::fromUtf8("MaxRaysCount"));
        MaxRaysCount->setMinimum(2);
        MaxRaysCount->setMaximum(1000);
        MaxRaysCount->setValue(2);

        verticalLayout_2->addWidget(MaxRaysCount);

        CaliperMode = new QComboBox(CCircleFinderParamsGuiComp);
        CaliperMode->setObjectName(QString::fromUtf8("CaliperMode"));

        verticalLayout_2->addWidget(CaliperMode);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(CCircleFinderParamsGuiComp);
        QObject::connect(EnableOutliersElimination, SIGNAL(toggled(bool)), MinOutliersDistanceLabel, SLOT(setVisible(bool)));
        QObject::connect(EnableOutliersElimination, SIGNAL(toggled(bool)), MinOutliersDistance, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(CCircleFinderParamsGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CCircleFinderParamsGuiComp)
    {
        CCircleFinderParamsGuiComp->setWindowTitle(QApplication::translate("CCircleFinderParamsGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        EnableOutliersElimination->setText(QApplication::translate("CCircleFinderParamsGuiComp", "Enable Outlier Elimination", 0, QApplication::UnicodeUTF8));
        MinOutliersDistanceLabel->setText(QApplication::translate("CCircleFinderParamsGuiComp", "Minimal Outlier Distance", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CCircleFinderParamsGuiComp", "Maximal Ray Count", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CCircleFinderParamsGuiComp", "Caliper Mode", 0, QApplication::UnicodeUTF8));
        MinOutliersDistance->setSuffix(QApplication::translate("CCircleFinderParamsGuiComp", " pixels", 0, QApplication::UnicodeUTF8));
        MaxRaysCount->setSpecialValueText(QApplication::translate("CCircleFinderParamsGuiComp", "Automatic", 0, QApplication::UnicodeUTF8));
        CaliperMode->clear();
        CaliperMode->insertItems(0, QStringList()
         << QApplication::translate("CCircleFinderParamsGuiComp", "First", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CCircleFinderParamsGuiComp", "Best", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class CCircleFinderParamsGuiComp: public Ui_CCircleFinderParamsGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCIRCLEFINDERPARAMSGUICOMP_H
