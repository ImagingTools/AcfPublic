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
** Form generated from reading UI file 'CCaliperParamsGuiComp.ui'
**
** Created: Wed 27. Jul 17:16:21 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCALIPERPARAMSGUICOMP_H
#define UI_CCALIPERPARAMSGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CCaliperParamsGuiComp
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *ThresholdSB;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *EdgePolarityCB;
    QLabel *label_4;
    QComboBox *DirectionCB;

    void setupUi(QWidget *CCaliperParamsGuiComp)
    {
        if (CCaliperParamsGuiComp->objectName().isEmpty())
            CCaliperParamsGuiComp->setObjectName(QString::fromUtf8("CCaliperParamsGuiComp"));
        CCaliperParamsGuiComp->resize(186, 99);
        gridLayout = new QGridLayout(CCaliperParamsGuiComp);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(CCaliperParamsGuiComp);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ThresholdSB = new QSpinBox(CCaliperParamsGuiComp);
        ThresholdSB->setObjectName(QString::fromUtf8("ThresholdSB"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ThresholdSB->sizePolicy().hasHeightForWidth());
        ThresholdSB->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(ThresholdSB, 0, 1, 1, 1);

        label_2 = new QLabel(CCaliperParamsGuiComp);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(CCaliperParamsGuiComp);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        EdgePolarityCB = new QComboBox(CCaliperParamsGuiComp);
        EdgePolarityCB->setObjectName(QString::fromUtf8("EdgePolarityCB"));
        sizePolicy1.setHeightForWidth(EdgePolarityCB->sizePolicy().hasHeightForWidth());
        EdgePolarityCB->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(EdgePolarityCB, 1, 1, 1, 2);

        label_4 = new QLabel(CCaliperParamsGuiComp);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        DirectionCB = new QComboBox(CCaliperParamsGuiComp);
        DirectionCB->setObjectName(QString::fromUtf8("DirectionCB"));
        sizePolicy1.setHeightForWidth(DirectionCB->sizePolicy().hasHeightForWidth());
        DirectionCB->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(DirectionCB, 2, 1, 1, 2);


        retranslateUi(CCaliperParamsGuiComp);

        QMetaObject::connectSlotsByName(CCaliperParamsGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CCaliperParamsGuiComp)
    {
        CCaliperParamsGuiComp->setWindowTitle(QApplication::translate("CCaliperParamsGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CCaliperParamsGuiComp", "Threshold", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CCaliperParamsGuiComp", "%", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CCaliperParamsGuiComp", "Edge polarity", 0, QApplication::UnicodeUTF8));
        EdgePolarityCB->clear();
        EdgePolarityCB->insertItems(0, QStringList()
         << QApplication::translate("CCaliperParamsGuiComp", "Rise", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CCaliperParamsGuiComp", "Drop", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CCaliperParamsGuiComp", "Any", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("CCaliperParamsGuiComp", "Direction", 0, QApplication::UnicodeUTF8));
        DirectionCB->clear();
        DirectionCB->insertItems(0, QStringList()
         << QApplication::translate("CCaliperParamsGuiComp", "Forwards", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CCaliperParamsGuiComp", "Backwards", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class CCaliperParamsGuiComp: public Ui_CCaliperParamsGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCALIPERPARAMSGUICOMP_H
