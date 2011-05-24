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
** Form generated from reading UI file 'CSampleAcquisitionGuiComp.ui'
**
** Created: Thu 21. Apr 15:47:58 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSAMPLEACQUISITIONGUICOMP_H
#define UI_CSAMPLEACQUISITIONGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSampleAcquisitionGuiComp
{
public:
    QVBoxLayout *vboxLayout;
    QSplitter *splitter;
    QFrame *frame;
    QVBoxLayout *vboxLayout1;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *StopButton;
    QPushButton *StartButton;
    QPushButton *SaveSampleButton;
    QGroupBox *ParamsGB;
    QVBoxLayout *vboxLayout2;
    QFrame *ParamsFrame;
    QVBoxLayout *vboxLayout3;
    QPushButton *LoadParamsButton;
    QPushButton *SaveParamsButton;
    QSpacerItem *spacerItem;
    QFrame *SampleViewFrame;
    QVBoxLayout *vboxLayout4;

    void setupUi(QWidget *CSampleAcquisitionGuiComp)
    {
        if (CSampleAcquisitionGuiComp->objectName().isEmpty())
            CSampleAcquisitionGuiComp->setObjectName(QString::fromUtf8("CSampleAcquisitionGuiComp"));
        CSampleAcquisitionGuiComp->resize(769, 386);
        vboxLayout = new QVBoxLayout(CSampleAcquisitionGuiComp);
#ifndef Q_OS_MAC
        vboxLayout->setSpacing(6);
#endif
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        splitter = new QSplitter(CSampleAcquisitionGuiComp);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        vboxLayout1 = new QVBoxLayout(frame);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        vboxLayout1->setContentsMargins(0, 0, -1, 0);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        StopButton = new QPushButton(groupBox);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(StopButton->sizePolicy().hasHeightForWidth());
        StopButton->setSizePolicy(sizePolicy2);
        StopButton->setCheckable(true);
        StopButton->setAutoExclusive(true);

        gridLayout->addWidget(StopButton, 0, 0, 1, 1);

        StartButton = new QPushButton(groupBox);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        sizePolicy2.setHeightForWidth(StartButton->sizePolicy().hasHeightForWidth());
        StartButton->setSizePolicy(sizePolicy2);
        StartButton->setCheckable(true);
        StartButton->setAutoExclusive(true);

        gridLayout->addWidget(StartButton, 0, 1, 1, 1);

        SaveSampleButton = new QPushButton(groupBox);
        SaveSampleButton->setObjectName(QString::fromUtf8("SaveSampleButton"));

        gridLayout->addWidget(SaveSampleButton, 1, 0, 1, 2);


        vboxLayout1->addWidget(groupBox);

        ParamsGB = new QGroupBox(frame);
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
        sizePolicy2.setHeightForWidth(LoadParamsButton->sizePolicy().hasHeightForWidth());
        LoadParamsButton->setSizePolicy(sizePolicy2);

        vboxLayout2->addWidget(LoadParamsButton);

        SaveParamsButton = new QPushButton(ParamsGB);
        SaveParamsButton->setObjectName(QString::fromUtf8("SaveParamsButton"));
        sizePolicy2.setHeightForWidth(SaveParamsButton->sizePolicy().hasHeightForWidth());
        SaveParamsButton->setSizePolicy(sizePolicy2);

        vboxLayout2->addWidget(SaveParamsButton);


        vboxLayout1->addWidget(ParamsGB);

        spacerItem = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout1->addItem(spacerItem);

        splitter->addWidget(frame);
        SampleViewFrame = new QFrame(splitter);
        SampleViewFrame->setObjectName(QString::fromUtf8("SampleViewFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(100);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(SampleViewFrame->sizePolicy().hasHeightForWidth());
        SampleViewFrame->setSizePolicy(sizePolicy3);
        SampleViewFrame->setFrameShape(QFrame::StyledPanel);
        SampleViewFrame->setFrameShadow(QFrame::Raised);
        vboxLayout4 = new QVBoxLayout(SampleViewFrame);
        vboxLayout4->setSpacing(6);
        vboxLayout4->setObjectName(QString::fromUtf8("vboxLayout4"));
        vboxLayout4->setContentsMargins(-1, 0, 0, 0);
        splitter->addWidget(SampleViewFrame);

        vboxLayout->addWidget(splitter);

        QWidget::setTabOrder(StopButton, StartButton);
        QWidget::setTabOrder(StartButton, SaveSampleButton);
        QWidget::setTabOrder(SaveSampleButton, LoadParamsButton);
        QWidget::setTabOrder(LoadParamsButton, SaveParamsButton);

        retranslateUi(CSampleAcquisitionGuiComp);

        QMetaObject::connectSlotsByName(CSampleAcquisitionGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CSampleAcquisitionGuiComp)
    {
        CSampleAcquisitionGuiComp->setWindowTitle(QApplication::translate("CSampleAcquisitionGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CSampleAcquisitionGuiComp", "Sampling", 0, QApplication::UnicodeUTF8));
        StopButton->setText(QApplication::translate("CSampleAcquisitionGuiComp", "Stop", 0, QApplication::UnicodeUTF8));
        StartButton->setText(QApplication::translate("CSampleAcquisitionGuiComp", "Start", 0, QApplication::UnicodeUTF8));
        SaveSampleButton->setText(QApplication::translate("CSampleAcquisitionGuiComp", "Save Samples...", 0, QApplication::UnicodeUTF8));
        ParamsGB->setTitle(QApplication::translate("CSampleAcquisitionGuiComp", "Parameters", 0, QApplication::UnicodeUTF8));
        LoadParamsButton->setText(QApplication::translate("CSampleAcquisitionGuiComp", "Load...", 0, QApplication::UnicodeUTF8));
        SaveParamsButton->setText(QApplication::translate("CSampleAcquisitionGuiComp", "Save...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CSampleAcquisitionGuiComp: public Ui_CSampleAcquisitionGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSAMPLEACQUISITIONGUICOMP_H
