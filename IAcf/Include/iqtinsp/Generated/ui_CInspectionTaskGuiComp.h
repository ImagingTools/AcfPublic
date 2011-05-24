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
** Form generated from reading UI file 'CInspectionTaskGuiComp.ui'
**
** Created: Thu 21. Apr 15:49:21 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CINSPECTIONTASKGUICOMP_H
#define UI_CINSPECTIONTASKGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CInspectionTaskGuiComp
{
public:
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QStackedWidget *PreviewStack;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *StateIconLabel;
    QGridLayout *gridLayout;
    QPushButton *TestAllButton;
    QToolButton *AutoTestButton;
    QFrame *LoaderFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *LoadParamsButton;
    QPushButton *SaveParamsButton;
    QWidget *GeneralParamsFrame;
    QVBoxLayout *verticalLayout_4;
    QFrame *ParamsFrame;

    void setupUi(QWidget *CInspectionTaskGuiComp)
    {
        if (CInspectionTaskGuiComp->objectName().isEmpty())
            CInspectionTaskGuiComp->setObjectName(QString::fromUtf8("CInspectionTaskGuiComp"));
        CInspectionTaskGuiComp->resize(543, 437);
        verticalLayout_3 = new QVBoxLayout(CInspectionTaskGuiComp);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        splitter = new QSplitter(CInspectionTaskGuiComp);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        PreviewStack = new QStackedWidget(splitter);
        PreviewStack->setObjectName(QString::fromUtf8("PreviewStack"));
        splitter->addWidget(PreviewStack);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        StateIconLabel = new QLabel(groupBox);
        StateIconLabel->setObjectName(QString::fromUtf8("StateIconLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StateIconLabel->sizePolicy().hasHeightForWidth());
        StateIconLabel->setSizePolicy(sizePolicy);
        StateIconLabel->setMinimumSize(QSize(64, 64));
        StateIconLabel->setMaximumSize(QSize(64, 64));
        StateIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/Icons/StateUnknown.svg")));
        StateIconLabel->setScaledContents(true);

        horizontalLayout_2->addWidget(StateIconLabel);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TestAllButton = new QPushButton(groupBox);
        TestAllButton->setObjectName(QString::fromUtf8("TestAllButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Play.svg"), QSize(), QIcon::Normal, QIcon::Off);
        TestAllButton->setIcon(icon);
        TestAllButton->setIconSize(QSize(32, 32));
        TestAllButton->setDefault(true);
        TestAllButton->setFlat(false);

        gridLayout->addWidget(TestAllButton, 0, 0, 1, 1);

        AutoTestButton = new QToolButton(groupBox);
        AutoTestButton->setObjectName(QString::fromUtf8("AutoTestButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AutoTestButton->sizePolicy().hasHeightForWidth());
        AutoTestButton->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/AutoUpdate.svg"), QSize(), QIcon::Normal, QIcon::Off);
        AutoTestButton->setIcon(icon1);
        AutoTestButton->setIconSize(QSize(32, 32));
        AutoTestButton->setCheckable(true);

        gridLayout->addWidget(AutoTestButton, 0, 1, 1, 1);

        LoaderFrame = new QFrame(groupBox);
        LoaderFrame->setObjectName(QString::fromUtf8("LoaderFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LoaderFrame->sizePolicy().hasHeightForWidth());
        LoaderFrame->setSizePolicy(sizePolicy2);
        LoaderFrame->setFrameShape(QFrame::NoFrame);
        LoaderFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(LoaderFrame);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        LoadParamsButton = new QPushButton(LoaderFrame);
        LoadParamsButton->setObjectName(QString::fromUtf8("LoadParamsButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(LoadParamsButton->sizePolicy().hasHeightForWidth());
        LoadParamsButton->setSizePolicy(sizePolicy3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/Open.svg"), QSize(), QIcon::Normal, QIcon::Off);
        LoadParamsButton->setIcon(icon2);

        horizontalLayout->addWidget(LoadParamsButton);

        SaveParamsButton = new QPushButton(LoaderFrame);
        SaveParamsButton->setObjectName(QString::fromUtf8("SaveParamsButton"));
        sizePolicy3.setHeightForWidth(SaveParamsButton->sizePolicy().hasHeightForWidth());
        SaveParamsButton->setSizePolicy(sizePolicy3);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/Save.svg"), QSize(), QIcon::Normal, QIcon::Off);
        SaveParamsButton->setIcon(icon3);

        horizontalLayout->addWidget(SaveParamsButton);


        gridLayout->addWidget(LoaderFrame, 1, 0, 1, 2);


        horizontalLayout_2->addLayout(gridLayout);


        verticalLayout->addWidget(groupBox);

        GeneralParamsFrame = new QWidget(layoutWidget);
        GeneralParamsFrame->setObjectName(QString::fromUtf8("GeneralParamsFrame"));
        verticalLayout_4 = new QVBoxLayout(GeneralParamsFrame);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));

        verticalLayout->addWidget(GeneralParamsFrame);

        ParamsFrame = new QFrame(layoutWidget);
        ParamsFrame->setObjectName(QString::fromUtf8("ParamsFrame"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ParamsFrame->sizePolicy().hasHeightForWidth());
        ParamsFrame->setSizePolicy(sizePolicy4);
        ParamsFrame->setFrameShape(QFrame::NoFrame);
        ParamsFrame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(ParamsFrame);

        splitter->addWidget(layoutWidget);

        verticalLayout_3->addWidget(splitter);


        retranslateUi(CInspectionTaskGuiComp);

        QMetaObject::connectSlotsByName(CInspectionTaskGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CInspectionTaskGuiComp)
    {
        CInspectionTaskGuiComp->setWindowTitle(QApplication::translate("CInspectionTaskGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CInspectionTaskGuiComp", "Inspection", 0, QApplication::UnicodeUTF8));
        StateIconLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        TestAllButton->setToolTip(QApplication::translate("CInspectionTaskGuiComp", "Recalculate all processing steps", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        TestAllButton->setText(QApplication::translate("CInspectionTaskGuiComp", "Test All", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        AutoTestButton->setToolTip(QApplication::translate("CInspectionTaskGuiComp", "Do processing steps automatically", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        AutoTestButton->setText(QApplication::translate("CInspectionTaskGuiComp", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        LoadParamsButton->setToolTip(QApplication::translate("CInspectionTaskGuiComp", "Load inspection data", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        LoadParamsButton->setText(QApplication::translate("CInspectionTaskGuiComp", "Load...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SaveParamsButton->setToolTip(QApplication::translate("CInspectionTaskGuiComp", "Save inspection data", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        SaveParamsButton->setText(QApplication::translate("CInspectionTaskGuiComp", "Save...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CInspectionTaskGuiComp: public Ui_CInspectionTaskGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CINSPECTIONTASKGUICOMP_H
