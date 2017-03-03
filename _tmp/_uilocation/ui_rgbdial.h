/********************************************************************************
** Form generated from reading UI file 'rgbdial.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RGBDIAL_H
#define UI_RGBDIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_rgbDial
{
public:
    QFormLayout *formLayout;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *_red;
    QLabel *label_2;
    QLineEdit *_redVal;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSlider *_green;
    QLabel *label_4;
    QLineEdit *_greenVal;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSlider *_blue;
    QLabel *label_6;
    QLineEdit *_blueVal;

    void setupUi(QDialog *rgbDial)
    {
        if (rgbDial->objectName().isEmpty())
            rgbDial->setObjectName(QStringLiteral("rgbDial"));
        rgbDial->resize(397, 206);
        formLayout = new QFormLayout(rgbDial);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_7 = new QLabel(rgbDial);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(rgbDial);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(20, 20));
        label->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(label);

        _red = new QSlider(rgbDial);
        _red->setObjectName(QStringLiteral("_red"));
        _red->setMinimumSize(QSize(50, 0));
        _red->setMaximumSize(QSize(200, 16777215));
        _red->setMaximum(255);
        _red->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(_red);

        label_2 = new QLabel(rgbDial);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(20, 20));
        label_2->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(label_2);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        _redVal = new QLineEdit(rgbDial);
        _redVal->setObjectName(QStringLiteral("_redVal"));
        _redVal->setMaximumSize(QSize(25, 15));

        formLayout->setWidget(1, QFormLayout::LabelRole, _redVal);

        label_8 = new QLabel(rgbDial);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(rgbDial);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(20, 20));
        label_3->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(label_3);

        _green = new QSlider(rgbDial);
        _green->setObjectName(QStringLiteral("_green"));
        _green->setMinimumSize(QSize(50, 0));
        _green->setMaximumSize(QSize(200, 16777215));
        _green->setMaximum(255);
        _green->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(_green);

        label_4 = new QLabel(rgbDial);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(20, 20));
        label_4->setMaximumSize(QSize(20, 20));

        horizontalLayout_2->addWidget(label_4);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);

        _greenVal = new QLineEdit(rgbDial);
        _greenVal->setObjectName(QStringLiteral("_greenVal"));
        _greenVal->setMaximumSize(QSize(25, 15));

        formLayout->setWidget(3, QFormLayout::LabelRole, _greenVal);

        label_9 = new QLabel(rgbDial);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(rgbDial);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(20, 20));
        label_5->setMaximumSize(QSize(20, 20));

        horizontalLayout_3->addWidget(label_5);

        _blue = new QSlider(rgbDial);
        _blue->setObjectName(QStringLiteral("_blue"));
        _blue->setMinimumSize(QSize(50, 0));
        _blue->setMaximumSize(QSize(200, 16777215));
        _blue->setMaximum(255);
        _blue->setOrientation(Qt::Horizontal);
        _blue->setInvertedAppearance(false);
        _blue->setInvertedControls(false);
        _blue->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(_blue);

        label_6 = new QLabel(rgbDial);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(20, 20));
        label_6->setMaximumSize(QSize(20, 20));

        horizontalLayout_3->addWidget(label_6);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_3);

        _blueVal = new QLineEdit(rgbDial);
        _blueVal->setObjectName(QStringLiteral("_blueVal"));
        _blueVal->setMaximumSize(QSize(25, 15));

        formLayout->setWidget(5, QFormLayout::LabelRole, _blueVal);


        retranslateUi(rgbDial);

        QMetaObject::connectSlotsByName(rgbDial);
    } // setupUi

    void retranslateUi(QDialog *rgbDial)
    {
        rgbDial->setWindowTitle(QApplication::translate("rgbDial", "Dialog", 0));
        label_7->setText(QApplication::translate("rgbDial", "Red", 0));
        label->setText(QApplication::translate("rgbDial", "0", 0));
        label_2->setText(QApplication::translate("rgbDial", "255", 0));
        label_8->setText(QApplication::translate("rgbDial", "Green", 0));
        label_3->setText(QApplication::translate("rgbDial", "0", 0));
        label_4->setText(QApplication::translate("rgbDial", "255", 0));
        label_9->setText(QApplication::translate("rgbDial", "Blue", 0));
        label_5->setText(QApplication::translate("rgbDial", "0", 0));
        label_6->setText(QApplication::translate("rgbDial", "255", 0));
    } // retranslateUi

};

namespace Ui {
    class rgbDial: public Ui_rgbDial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RGBDIAL_H
