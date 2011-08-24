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
** Form generated from reading UI file 'CNumericParamsGuiComp.ui'
**
** Created: Fri 17. Jun 09:28:27 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMULTIDIMENSIONALFILTERPARAMSGUICOMP_H
#define UI_CMULTIDIMENSIONALFILTERPARAMSGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMultidimensionalFilterParamsGuiComp
{
public:
    QGridLayout *gridLayout;
    QLabel *FilterWidthLabel;
    QSlider *FilterWidthSlider;
    QLabel *FilterHeightLabel;
    QSlider *FilterHeightSlider;
    QLabel *FilterWidthValueLabel;
    QLabel *FilterHeightValueLabel;
    QLabel *WidthUnitNameLabel;
    QLabel *HeightUnitNameLabel;

    void setupUi(QWidget *CNumericParamsGuiComp)
    {
        if (CNumericParamsGuiComp->objectName().isEmpty())
            CNumericParamsGuiComp->setObjectName(QString::fromUtf8("CNumericParamsGuiComp"));
        CNumericParamsGuiComp->resize(473, 70);
        gridLayout = new QGridLayout(CNumericParamsGuiComp);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        FilterWidthLabel = new QLabel(CNumericParamsGuiComp);
        FilterWidthLabel->setObjectName(QString::fromUtf8("FilterWidthLabel"));
        FilterWidthLabel->setText(QString::fromUtf8("Filter Width"));

        gridLayout->addWidget(FilterWidthLabel, 0, 0, 1, 1);

        FilterWidthSlider = new QSlider(CNumericParamsGuiComp);
        FilterWidthSlider->setObjectName(QString::fromUtf8("FilterWidthSlider"));
        FilterWidthSlider->setMinimum(1);
        FilterWidthSlider->setMaximum(100);
        FilterWidthSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(FilterWidthSlider, 0, 1, 1, 1);

        FilterHeightLabel = new QLabel(CNumericParamsGuiComp);
        FilterHeightLabel->setObjectName(QString::fromUtf8("FilterHeightLabel"));
        FilterHeightLabel->setText(QString::fromUtf8("Filter Height"));

        gridLayout->addWidget(FilterHeightLabel, 1, 0, 1, 1);

        FilterHeightSlider = new QSlider(CNumericParamsGuiComp);
        FilterHeightSlider->setObjectName(QString::fromUtf8("FilterHeightSlider"));
        FilterHeightSlider->setMinimum(1);
        FilterHeightSlider->setMaximum(100);
        FilterHeightSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(FilterHeightSlider, 1, 1, 1, 1);

        FilterWidthValueLabel = new QLabel(CNumericParamsGuiComp);
        FilterWidthValueLabel->setObjectName(QString::fromUtf8("FilterWidthValueLabel"));
        FilterWidthValueLabel->setText(QString::fromUtf8("1"));

        gridLayout->addWidget(FilterWidthValueLabel, 0, 2, 1, 1);

        FilterHeightValueLabel = new QLabel(CNumericParamsGuiComp);
        FilterHeightValueLabel->setObjectName(QString::fromUtf8("FilterHeightValueLabel"));
        FilterHeightValueLabel->setText(QString::fromUtf8("1"));

        gridLayout->addWidget(FilterHeightValueLabel, 1, 2, 1, 1);

        WidthUnitNameLabel = new QLabel(CNumericParamsGuiComp);
        WidthUnitNameLabel->setObjectName(QString::fromUtf8("WidthUnitNameLabel"));
        WidthUnitNameLabel->setText(QString::fromUtf8("-"));

        gridLayout->addWidget(WidthUnitNameLabel, 0, 3, 1, 1);

        HeightUnitNameLabel = new QLabel(CNumericParamsGuiComp);
        HeightUnitNameLabel->setObjectName(QString::fromUtf8("HeightUnitNameLabel"));
        HeightUnitNameLabel->setText(QString::fromUtf8("-"));

        gridLayout->addWidget(HeightUnitNameLabel, 1, 3, 1, 1);


        retranslateUi(CNumericParamsGuiComp);

        QMetaObject::connectSlotsByName(CNumericParamsGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CNumericParamsGuiComp)
    {
        CNumericParamsGuiComp->setWindowTitle(QApplication::translate("CNumericParamsGuiComp", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CNumericParamsGuiComp: public Ui_CMultidimensionalFilterParamsGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMULTIDIMENSIONALFILTERPARAMSGUICOMP_H
