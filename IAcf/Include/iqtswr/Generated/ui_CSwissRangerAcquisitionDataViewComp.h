/********************************************************************************
** Form generated from reading UI file 'CSwissRangerAcquisitionDataViewComp.ui'
**
** Created: Thu 8. Sep 17:20:28 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSWISSRANGERACQUISITIONDATAVIEWCOMP_H
#define UI_CSWISSRANGERACQUISITIONDATAVIEWCOMP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSplitter>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSwissRangerAcquisitionDataViewComp
{
public:
    QHBoxLayout *horizontalLayout_4;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *DepthImageFrame2d;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *AmplitudeImageFrame;
    QHBoxLayout *horizontalLayout;
    QGroupBox *ConfidenceMapFrame;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *DepthImageFrame;
    QVBoxLayout *verticalLayout_31;
    QFrame *DepthImageFrame3d;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QSlider *MaximalDistanceCropSlider;
    QSlider *MinimalDistanceCropSlider;
    QVBoxLayout *verticalLayout_5;
    QLabel *MaximalDistanceCropLabel;
    QLabel *MinimalDistanceCropLabel;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_3;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_11;
    QSlider *ResolutionSlider;
    QSlider *CoherenceThresholdSlider;
    QVBoxLayout *verticalLayout_12;
    QLabel *ResolutionLabel;
    QLabel *CoherenceThresholdLabel;

    void setupUi(QWidget *CSwissRangerAcquisitionDataViewComp)
    {
        if (CSwissRangerAcquisitionDataViewComp->objectName().isEmpty())
            CSwissRangerAcquisitionDataViewComp->setObjectName(QString::fromUtf8("CSwissRangerAcquisitionDataViewComp"));
        CSwissRangerAcquisitionDataViewComp->resize(975, 707);
        horizontalLayout_4 = new QHBoxLayout(CSwissRangerAcquisitionDataViewComp);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        splitter = new QSplitter(CSwissRangerAcquisitionDataViewComp);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        DepthImageFrame2d = new QGroupBox(layoutWidget);
        DepthImageFrame2d->setObjectName(QString::fromUtf8("DepthImageFrame2d"));
        DepthImageFrame2d->setMinimumSize(QSize(256, 0));
        horizontalLayout_3 = new QHBoxLayout(DepthImageFrame2d);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        verticalLayout->addWidget(DepthImageFrame2d);

        AmplitudeImageFrame = new QGroupBox(layoutWidget);
        AmplitudeImageFrame->setObjectName(QString::fromUtf8("AmplitudeImageFrame"));
        horizontalLayout = new QHBoxLayout(AmplitudeImageFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout->addWidget(AmplitudeImageFrame);

        ConfidenceMapFrame = new QGroupBox(layoutWidget);
        ConfidenceMapFrame->setObjectName(QString::fromUtf8("ConfidenceMapFrame"));
        verticalLayout_2 = new QVBoxLayout(ConfidenceMapFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        verticalLayout->addWidget(ConfidenceMapFrame);

        splitter->addWidget(layoutWidget);
        DepthImageFrame = new QGroupBox(splitter);
        DepthImageFrame->setObjectName(QString::fromUtf8("DepthImageFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DepthImageFrame->sizePolicy().hasHeightForWidth());
        DepthImageFrame->setSizePolicy(sizePolicy);
        verticalLayout_31 = new QVBoxLayout(DepthImageFrame);
        verticalLayout_31->setObjectName(QString::fromUtf8("verticalLayout_31"));
        DepthImageFrame3d = new QFrame(DepthImageFrame);
        DepthImageFrame3d->setObjectName(QString::fromUtf8("DepthImageFrame3d"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(DepthImageFrame3d->sizePolicy().hasHeightForWidth());
        DepthImageFrame3d->setSizePolicy(sizePolicy1);
        DepthImageFrame3d->setFrameShape(QFrame::NoFrame);
        DepthImageFrame3d->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(DepthImageFrame3d);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));

        verticalLayout_31->addWidget(DepthImageFrame3d);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(DepthImageFrame);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_5 = new QLabel(DepthImageFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);


        horizontalLayout_8->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        MaximalDistanceCropSlider = new QSlider(DepthImageFrame);
        MaximalDistanceCropSlider->setObjectName(QString::fromUtf8("MaximalDistanceCropSlider"));
        MaximalDistanceCropSlider->setMaximum(100);
        MaximalDistanceCropSlider->setSingleStep(1);
        MaximalDistanceCropSlider->setValue(40);
        MaximalDistanceCropSlider->setOrientation(Qt::Horizontal);
        MaximalDistanceCropSlider->setTickPosition(QSlider::TicksAbove);

        verticalLayout_4->addWidget(MaximalDistanceCropSlider);

        MinimalDistanceCropSlider = new QSlider(DepthImageFrame);
        MinimalDistanceCropSlider->setObjectName(QString::fromUtf8("MinimalDistanceCropSlider"));
        MinimalDistanceCropSlider->setMaximum(100);
        MinimalDistanceCropSlider->setSingleStep(1);
        MinimalDistanceCropSlider->setValue(10);
        MinimalDistanceCropSlider->setOrientation(Qt::Horizontal);
        MinimalDistanceCropSlider->setTickPosition(QSlider::TicksAbove);

        verticalLayout_4->addWidget(MinimalDistanceCropSlider);


        horizontalLayout_8->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        MaximalDistanceCropLabel = new QLabel(DepthImageFrame);
        MaximalDistanceCropLabel->setObjectName(QString::fromUtf8("MaximalDistanceCropLabel"));

        verticalLayout_5->addWidget(MaximalDistanceCropLabel);

        MinimalDistanceCropLabel = new QLabel(DepthImageFrame);
        MinimalDistanceCropLabel->setObjectName(QString::fromUtf8("MinimalDistanceCropLabel"));

        verticalLayout_5->addWidget(MinimalDistanceCropLabel);


        horizontalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_3 = new QLabel(DepthImageFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_10->addWidget(label_3);

        label_6 = new QLabel(DepthImageFrame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_10->addWidget(label_6);


        horizontalLayout_8->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        ResolutionSlider = new QSlider(DepthImageFrame);
        ResolutionSlider->setObjectName(QString::fromUtf8("ResolutionSlider"));
        ResolutionSlider->setMinimum(1);
        ResolutionSlider->setMaximum(8);
        ResolutionSlider->setPageStep(1);
        ResolutionSlider->setValue(2);
        ResolutionSlider->setOrientation(Qt::Horizontal);
        ResolutionSlider->setTickPosition(QSlider::TicksAbove);

        verticalLayout_11->addWidget(ResolutionSlider);

        CoherenceThresholdSlider = new QSlider(DepthImageFrame);
        CoherenceThresholdSlider->setObjectName(QString::fromUtf8("CoherenceThresholdSlider"));
        CoherenceThresholdSlider->setMinimum(0);
        CoherenceThresholdSlider->setMaximum(100);
        CoherenceThresholdSlider->setPageStep(10);
        CoherenceThresholdSlider->setValue(90);
        CoherenceThresholdSlider->setOrientation(Qt::Horizontal);
        CoherenceThresholdSlider->setTickPosition(QSlider::TicksAbove);

        verticalLayout_11->addWidget(CoherenceThresholdSlider);


        horizontalLayout_8->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        ResolutionLabel = new QLabel(DepthImageFrame);
        ResolutionLabel->setObjectName(QString::fromUtf8("ResolutionLabel"));

        verticalLayout_12->addWidget(ResolutionLabel);

        CoherenceThresholdLabel = new QLabel(DepthImageFrame);
        CoherenceThresholdLabel->setObjectName(QString::fromUtf8("CoherenceThresholdLabel"));

        verticalLayout_12->addWidget(CoherenceThresholdLabel);


        horizontalLayout_8->addLayout(verticalLayout_12);


        verticalLayout_31->addLayout(horizontalLayout_8);

        splitter->addWidget(DepthImageFrame);

        horizontalLayout_4->addWidget(splitter);


        retranslateUi(CSwissRangerAcquisitionDataViewComp);

        QMetaObject::connectSlotsByName(CSwissRangerAcquisitionDataViewComp);
    } // setupUi

    void retranslateUi(QWidget *CSwissRangerAcquisitionDataViewComp)
    {
        CSwissRangerAcquisitionDataViewComp->setWindowTitle(QApplication::translate("CSwissRangerAcquisitionDataViewComp", "SwissRanger Image", 0, QApplication::UnicodeUTF8));
        DepthImageFrame2d->setTitle(QApplication::translate("CSwissRangerAcquisitionDataViewComp", "Distance", 0, QApplication::UnicodeUTF8));
        AmplitudeImageFrame->setTitle(QApplication::translate("CSwissRangerAcquisitionDataViewComp", "Amplitude", 0, QApplication::UnicodeUTF8));
        ConfidenceMapFrame->setTitle(QApplication::translate("CSwissRangerAcquisitionDataViewComp", "Confidence Map", 0, QApplication::UnicodeUTF8));
        DepthImageFrame->setTitle(QApplication::translate("CSwissRangerAcquisitionDataViewComp", "Distance (3D)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CSwissRangerAcquisitionDataViewComp", "Maximal Distance Crop", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CSwissRangerAcquisitionDataViewComp", "Minimal Distance Crop", 0, QApplication::UnicodeUTF8));
        MaximalDistanceCropLabel->setText(QString());
        MinimalDistanceCropLabel->setText(QString());
        label_3->setText(QApplication::translate("CSwissRangerAcquisitionDataViewComp", "Resolution", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CSwissRangerAcquisitionDataViewComp", "Coherence Threshold", 0, QApplication::UnicodeUTF8));
        ResolutionLabel->setText(QString());
        CoherenceThresholdLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CSwissRangerAcquisitionDataViewComp: public Ui_CSwissRangerAcquisitionDataViewComp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSWISSRANGERACQUISITIONDATAVIEWCOMP_H
