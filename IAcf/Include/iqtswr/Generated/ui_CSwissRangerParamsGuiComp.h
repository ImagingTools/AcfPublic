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
** Form generated from reading UI file 'CSwissRangerParamsGuiComp.ui'
**
** Created: Thu 21. Apr 15:47:32 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSWISSRANGERPARAMSGUICOMP_H
#define UI_CSWISSRANGERPARAMSGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSwissRangerParamsGuiComp
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QComboBox *ModulationFrequencyModeCombo;
    QDoubleSpinBox *AmplitudeThresholdSpin;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *MedianFilterCheck;
    QCheckBox *AdaptiveFilterCheck;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CSwissRangerParamsGuiComp)
    {
        if (CSwissRangerParamsGuiComp->objectName().isEmpty())
            CSwissRangerParamsGuiComp->setObjectName(QString::fromUtf8("CSwissRangerParamsGuiComp"));
        CSwissRangerParamsGuiComp->resize(337, 130);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CSwissRangerParamsGuiComp->sizePolicy().hasHeightForWidth());
        CSwissRangerParamsGuiComp->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(CSwissRangerParamsGuiComp);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(CSwissRangerParamsGuiComp);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label = new QLabel(CSwissRangerParamsGuiComp);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ModulationFrequencyModeCombo = new QComboBox(CSwissRangerParamsGuiComp);
        ModulationFrequencyModeCombo->setObjectName(QString::fromUtf8("ModulationFrequencyModeCombo"));

        verticalLayout_2->addWidget(ModulationFrequencyModeCombo);

        AmplitudeThresholdSpin = new QDoubleSpinBox(CSwissRangerParamsGuiComp);
        AmplitudeThresholdSpin->setObjectName(QString::fromUtf8("AmplitudeThresholdSpin"));
        AmplitudeThresholdSpin->setDecimals(2);
        AmplitudeThresholdSpin->setMaximum(100);
        AmplitudeThresholdSpin->setSingleStep(0.01);
        AmplitudeThresholdSpin->setValue(0.1);

        verticalLayout_2->addWidget(AmplitudeThresholdSpin);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        line = new QFrame(CSwissRangerParamsGuiComp);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        MedianFilterCheck = new QCheckBox(CSwissRangerParamsGuiComp);
        MedianFilterCheck->setObjectName(QString::fromUtf8("MedianFilterCheck"));

        horizontalLayout_2->addWidget(MedianFilterCheck);

        AdaptiveFilterCheck = new QCheckBox(CSwissRangerParamsGuiComp);
        AdaptiveFilterCheck->setObjectName(QString::fromUtf8("AdaptiveFilterCheck"));

        horizontalLayout_2->addWidget(AdaptiveFilterCheck);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(CSwissRangerParamsGuiComp);

        QMetaObject::connectSlotsByName(CSwissRangerParamsGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CSwissRangerParamsGuiComp)
    {
        CSwissRangerParamsGuiComp->setWindowTitle(QApplication::translate("CSwissRangerParamsGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CSwissRangerParamsGuiComp", "Modulation Frequency", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CSwissRangerParamsGuiComp", "Amplitude Threshold", 0, QApplication::UnicodeUTF8));
        ModulationFrequencyModeCombo->clear();
        ModulationFrequencyModeCombo->insertItems(0, QStringList()
         << QApplication::translate("CSwissRangerParamsGuiComp", "40MHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CSwissRangerParamsGuiComp", "30MHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CSwissRangerParamsGuiComp", "21MHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CSwissRangerParamsGuiComp", "20MHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CSwissRangerParamsGuiComp", "19MHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CSwissRangerParamsGuiComp", "60MHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CSwissRangerParamsGuiComp", "15MHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CSwissRangerParamsGuiComp", "10MHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CSwissRangerParamsGuiComp", "29MHz", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CSwissRangerParamsGuiComp", "31MHz", 0, QApplication::UnicodeUTF8)
        );
        AmplitudeThresholdSpin->setSuffix(QApplication::translate("CSwissRangerParamsGuiComp", "%", 0, QApplication::UnicodeUTF8));
        MedianFilterCheck->setText(QApplication::translate("CSwissRangerParamsGuiComp", "Enable Median Filter", 0, QApplication::UnicodeUTF8));
        AdaptiveFilterCheck->setText(QApplication::translate("CSwissRangerParamsGuiComp", "Enable Adaptive Filter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CSwissRangerParamsGuiComp: public Ui_CSwissRangerParamsGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSWISSRANGERPARAMSGUICOMP_H
