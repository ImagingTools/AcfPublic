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
** Form generated from reading UI file 'CBitmapSupplierGuiComp.ui'
**
** Created: Thu 21. Apr 15:45:03 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CBITMAPSUPPLIERGUICOMP_H
#define UI_CBITMAPSUPPLIERGUICOMP_H

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
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CBitmapSupplierGuiComp
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QPushButton *SnapImageButton;
    QPushButton *SaveImageButton;
    QFrame *ImageParamsLabel;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLabel *SizeLabel;
    QGroupBox *ParamsGB;
    QVBoxLayout *vboxLayout2;
    QFrame *ParamsFrame;
    QVBoxLayout *vboxLayout3;
    QPushButton *LoadParamsButton;
    QPushButton *SaveParamsButton;

    void setupUi(QWidget *CBitmapSupplierGuiComp)
    {
        if (CBitmapSupplierGuiComp->objectName().isEmpty())
            CBitmapSupplierGuiComp->setObjectName(QString::fromUtf8("CBitmapSupplierGuiComp"));
        CBitmapSupplierGuiComp->resize(323, 285);
        vboxLayout = new QVBoxLayout(CBitmapSupplierGuiComp);
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(CBitmapSupplierGuiComp);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        vboxLayout1 = new QVBoxLayout(groupBox);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        SnapImageButton = new QPushButton(groupBox);
        SnapImageButton->setObjectName(QString::fromUtf8("SnapImageButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SnapImageButton->sizePolicy().hasHeightForWidth());
        SnapImageButton->setSizePolicy(sizePolicy1);

        vboxLayout1->addWidget(SnapImageButton);

        SaveImageButton = new QPushButton(groupBox);
        SaveImageButton->setObjectName(QString::fromUtf8("SaveImageButton"));
        sizePolicy1.setHeightForWidth(SaveImageButton->sizePolicy().hasHeightForWidth());
        SaveImageButton->setSizePolicy(sizePolicy1);

        vboxLayout1->addWidget(SaveImageButton);

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

        SizeLabel = new QLabel(ImageParamsLabel);
        SizeLabel->setObjectName(QString::fromUtf8("SizeLabel"));
        SizeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        hboxLayout->addWidget(SizeLabel);


        vboxLayout1->addWidget(ImageParamsLabel);


        vboxLayout->addWidget(groupBox);

        ParamsGB = new QGroupBox(CBitmapSupplierGuiComp);
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


        retranslateUi(CBitmapSupplierGuiComp);

        QMetaObject::connectSlotsByName(CBitmapSupplierGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CBitmapSupplierGuiComp)
    {
        CBitmapSupplierGuiComp->setWindowTitle(QApplication::translate("CBitmapSupplierGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CBitmapSupplierGuiComp", "Image", 0, QApplication::UnicodeUTF8));
        SnapImageButton->setText(QApplication::translate("CBitmapSupplierGuiComp", "Snap", 0, QApplication::UnicodeUTF8));
        SaveImageButton->setText(QApplication::translate("CBitmapSupplierGuiComp", "Save...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CBitmapSupplierGuiComp", "Size", 0, QApplication::UnicodeUTF8));
        SizeLabel->setText(QString());
        ParamsGB->setTitle(QApplication::translate("CBitmapSupplierGuiComp", "Parameters", 0, QApplication::UnicodeUTF8));
        LoadParamsButton->setText(QApplication::translate("CBitmapSupplierGuiComp", "Load...", 0, QApplication::UnicodeUTF8));
        SaveParamsButton->setText(QApplication::translate("CBitmapSupplierGuiComp", "Save...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CBitmapSupplierGuiComp: public Ui_CBitmapSupplierGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CBITMAPSUPPLIERGUICOMP_H
