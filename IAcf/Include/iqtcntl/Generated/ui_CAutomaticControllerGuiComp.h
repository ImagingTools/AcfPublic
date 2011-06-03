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
** Form generated from reading UI file 'CAutomaticControllerGuiComp.ui'
**
** Created: Fri 3. Jun 13:46:18 2011
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAUTOMATICCONTROLLERGUICOMP_H
#define UI_CAUTOMATICCONTROLLERGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CAutomaticControllerGuiComp
{
public:
    QVBoxLayout *vboxLayout;
    QFrame *frame;
    QVBoxLayout *vboxLayout1;
    QPushButton *AutomaticButton;

    void setupUi(QWidget *CAutomaticControllerGuiComp)
    {
        if (CAutomaticControllerGuiComp->objectName().isEmpty())
            CAutomaticControllerGuiComp->setObjectName(QString::fromUtf8("CAutomaticControllerGuiComp"));
        CAutomaticControllerGuiComp->resize(242, 163);
        vboxLayout = new QVBoxLayout(CAutomaticControllerGuiComp);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        frame = new QFrame(CAutomaticControllerGuiComp);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        vboxLayout1 = new QVBoxLayout(frame);
#ifndef Q_OS_MAC
        vboxLayout1->setSpacing(6);
#endif
        vboxLayout1->setContentsMargins(0, 0, 0, 0);
        vboxLayout1->setObjectName(QString::fromUtf8("vboxLayout1"));
        AutomaticButton = new QPushButton(frame);
        AutomaticButton->setObjectName(QString::fromUtf8("AutomaticButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AutomaticButton->sizePolicy().hasHeightForWidth());
        AutomaticButton->setSizePolicy(sizePolicy1);
        AutomaticButton->setCheckable(true);

        vboxLayout1->addWidget(AutomaticButton);


        vboxLayout->addWidget(frame);


        retranslateUi(CAutomaticControllerGuiComp);

        QMetaObject::connectSlotsByName(CAutomaticControllerGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CAutomaticControllerGuiComp)
    {
        CAutomaticControllerGuiComp->setWindowTitle(QApplication::translate("CAutomaticControllerGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        AutomaticButton->setText(QApplication::translate("CAutomaticControllerGuiComp", "Automatic", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CAutomaticControllerGuiComp: public Ui_CAutomaticControllerGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAUTOMATICCONTROLLERGUICOMP_H
