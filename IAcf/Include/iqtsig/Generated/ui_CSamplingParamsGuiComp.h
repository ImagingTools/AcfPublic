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
** Form generated from reading UI file 'CSamplingParamsGuiComp.ui'
**
** Created: Thu 21. Apr 15:47:58 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSAMPLINGPARAMSGUICOMP_H
#define UI_CSAMPLINGPARAMSGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSamplingParamsGuiComp
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *IntervalSB;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *ModeCB;

    void setupUi(QWidget *CSamplingParamsGuiComp)
    {
        if (CSamplingParamsGuiComp->objectName().isEmpty())
            CSamplingParamsGuiComp->setObjectName(QString::fromUtf8("CSamplingParamsGuiComp"));
        CSamplingParamsGuiComp->resize(220, 70);
        gridLayout = new QGridLayout(CSamplingParamsGuiComp);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(CSamplingParamsGuiComp);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        IntervalSB = new QDoubleSpinBox(CSamplingParamsGuiComp);
        IntervalSB->setObjectName(QString::fromUtf8("IntervalSB"));
        IntervalSB->setDecimals(3);

        gridLayout->addWidget(IntervalSB, 0, 1, 1, 1);

        label_2 = new QLabel(CSamplingParamsGuiComp);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(CSamplingParamsGuiComp);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        ModeCB = new QComboBox(CSamplingParamsGuiComp);
        ModeCB->setObjectName(QString::fromUtf8("ModeCB"));

        gridLayout->addWidget(ModeCB, 1, 1, 1, 2);


        retranslateUi(CSamplingParamsGuiComp);

        QMetaObject::connectSlotsByName(CSamplingParamsGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CSamplingParamsGuiComp)
    {
        CSamplingParamsGuiComp->setWindowTitle(QApplication::translate("CSamplingParamsGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CSamplingParamsGuiComp", "Interval", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CSamplingParamsGuiComp", "ms", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CSamplingParamsGuiComp", "Mode", 0, QApplication::UnicodeUTF8));
        ModeCB->clear();
        ModeCB->insertItems(0, QStringList()
         << QApplication::translate("CSamplingParamsGuiComp", "Single", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CSamplingParamsGuiComp", "Periodic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CSamplingParamsGuiComp", "Synchronized", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class CSamplingParamsGuiComp: public Ui_CSamplingParamsGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSAMPLINGPARAMSGUICOMP_H
