/********************************************************************************
** Form generated from reading UI file 'CSimulatedMultiTracerGuiComp.ui'
**
** Created: Thu 8. Sep 17:23:09 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSIMULATEDMULTITRACERGUICOMP_H
#define UI_CSIMULATEDMULTITRACERGUICOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSimulatedMultiTracerGuiComp
{
public:
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QDial *EncoderDial;
    QPushButton *RunButton;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *EncoderSB;
    QSpinBox *SpeedSB;
    QTableWidget *BitsTable;

    void setupUi(QWidget *CSimulatedMultiTracerGuiComp)
    {
        if (CSimulatedMultiTracerGuiComp->objectName().isEmpty())
            CSimulatedMultiTracerGuiComp->setObjectName(QString::fromUtf8("CSimulatedMultiTracerGuiComp"));
        CSimulatedMultiTracerGuiComp->resize(344, 721);
        vboxLayout = new QVBoxLayout(CSimulatedMultiTracerGuiComp);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        groupBox = new QGroupBox(CSimulatedMultiTracerGuiComp);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        EncoderDial = new QDial(groupBox);
        EncoderDial->setObjectName(QString::fromUtf8("EncoderDial"));
        EncoderDial->setMaximum(4095);
        EncoderDial->setSingleStep(16);
        EncoderDial->setPageStep(256);
        EncoderDial->setWrapping(true);
        EncoderDial->setNotchTarget(128);
        EncoderDial->setNotchesVisible(true);

        gridLayout->addWidget(EncoderDial, 0, 0, 1, 1);

        RunButton = new QPushButton(groupBox);
        RunButton->setObjectName(QString::fromUtf8("RunButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RunButton->sizePolicy().hasHeightForWidth());
        RunButton->setSizePolicy(sizePolicy);
        RunButton->setCheckable(true);

        gridLayout->addWidget(RunButton, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        EncoderSB = new QSpinBox(groupBox);
        EncoderSB->setObjectName(QString::fromUtf8("EncoderSB"));
        EncoderSB->setMaximum(4095);
        EncoderSB->setSingleStep(16);

        gridLayout->addWidget(EncoderSB, 2, 0, 1, 1);

        SpeedSB = new QSpinBox(groupBox);
        SpeedSB->setObjectName(QString::fromUtf8("SpeedSB"));
        SpeedSB->setMaximum(4095);

        gridLayout->addWidget(SpeedSB, 2, 1, 1, 1);


        vboxLayout->addWidget(groupBox);

        BitsTable = new QTableWidget(CSimulatedMultiTracerGuiComp);
        if (BitsTable->columnCount() < 3)
            BitsTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        BitsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        BitsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        BitsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (BitsTable->rowCount() < 16)
            BitsTable->setRowCount(16);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(8, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(9, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(10, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(11, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(12, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(13, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(14, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        BitsTable->setVerticalHeaderItem(15, __qtablewidgetitem18);
        BitsTable->setObjectName(QString::fromUtf8("BitsTable"));
        BitsTable->setGridStyle(Qt::DashLine);
        BitsTable->setCornerButtonEnabled(false);

        vboxLayout->addWidget(BitsTable);


        retranslateUi(CSimulatedMultiTracerGuiComp);
        QObject::connect(EncoderDial, SIGNAL(valueChanged(int)), EncoderSB, SLOT(setValue(int)));
        QObject::connect(EncoderSB, SIGNAL(valueChanged(int)), EncoderDial, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(CSimulatedMultiTracerGuiComp);
    } // setupUi

    void retranslateUi(QWidget *CSimulatedMultiTracerGuiComp)
    {
        CSimulatedMultiTracerGuiComp->setWindowTitle(QApplication::translate("CSimulatedMultiTracerGuiComp", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CSimulatedMultiTracerGuiComp", "Encoder", 0, QApplication::UnicodeUTF8));
        RunButton->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "Run", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "Value", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "Speed", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = BitsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "Input", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = BitsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "Output", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = BitsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "Counter", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = BitsTable->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "0", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = BitsTable->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = BitsTable->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = BitsTable->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = BitsTable->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = BitsTable->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = BitsTable->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = BitsTable->verticalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = BitsTable->verticalHeaderItem(8);
        ___qtablewidgetitem11->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = BitsTable->verticalHeaderItem(9);
        ___qtablewidgetitem12->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = BitsTable->verticalHeaderItem(10);
        ___qtablewidgetitem13->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = BitsTable->verticalHeaderItem(11);
        ___qtablewidgetitem14->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = BitsTable->verticalHeaderItem(12);
        ___qtablewidgetitem15->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = BitsTable->verticalHeaderItem(13);
        ___qtablewidgetitem16->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "13", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = BitsTable->verticalHeaderItem(14);
        ___qtablewidgetitem17->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "14", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = BitsTable->verticalHeaderItem(15);
        ___qtablewidgetitem18->setText(QApplication::translate("CSimulatedMultiTracerGuiComp", "15", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CSimulatedMultiTracerGuiComp: public Ui_CSimulatedMultiTracerGuiComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSIMULATEDMULTITRACERGUICOMP_H
