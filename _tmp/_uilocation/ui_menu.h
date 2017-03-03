/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *players;
    QRadioButton *ai;
    QGroupBox *timer;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_8;
    QSlider *horizontalSlider_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QGroupBox *aiLevel;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *label_5;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Menu->sizePolicy().hasHeightForWidth());
        Menu->setSizePolicy(sizePolicy);
        Menu->setMaximumSize(QSize(400, 300));
        verticalLayout_2 = new QVBoxLayout(Menu);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Menu);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 20));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(Menu);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        players = new QRadioButton(groupBox);
        players->setObjectName(QStringLiteral("players"));
        players->setLayoutDirection(Qt::LeftToRight);
        players->setChecked(true);

        verticalLayout_3->addWidget(players);

        ai = new QRadioButton(groupBox);
        ai->setObjectName(QStringLiteral("ai"));

        verticalLayout_3->addWidget(ai);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout->addWidget(groupBox);

        timer = new QGroupBox(Menu);
        timer->setObjectName(QStringLiteral("timer"));
        timer->setEnabled(true);
        timer->setMaximumSize(QSize(16777215, 80));
        verticalLayout_7 = new QVBoxLayout(timer);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalSlider_2 = new QSlider(timer);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(5);
        horizontalSlider_2->setMaximum(30);
        horizontalSlider_2->setValue(10);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(horizontalSlider_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(timer);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(16777215, 20));

        horizontalLayout_2->addWidget(label_6);

        label_7 = new QLabel(timer);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(16777215, 20));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_7);


        verticalLayout_8->addLayout(horizontalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_8);


        verticalLayout->addWidget(timer);

        aiLevel = new QGroupBox(Menu);
        aiLevel->setObjectName(QStringLiteral("aiLevel"));
        aiLevel->setEnabled(false);
        aiLevel->setMaximumSize(QSize(16777215, 80));
        verticalLayout_6 = new QVBoxLayout(aiLevel);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalSlider = new QSlider(aiLevel);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(10);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(aiLevel);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(16777215, 20));

        horizontalLayout->addWidget(label_4);

        label_5 = new QLabel(aiLevel);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(16777215, 20));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_5);


        verticalLayout_5->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout->addWidget(aiLevel);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(Menu);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(Menu);
        QObject::connect(buttonBox, SIGNAL(accepted()), Menu, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Menu, SLOT(reject()));

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QDialog *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Dialog", 0));
#ifndef QT_NO_TOOLTIP
        Menu->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Menu", "Welcome to the Gomoku !", 0));
        groupBox->setTitle(QApplication::translate("Menu", "Choose your game type:", 0));
        players->setText(QApplication::translate("Menu", "2 Players", 0));
        ai->setText(QApplication::translate("Menu", "Player and AI", 0));
        timer->setTitle(QApplication::translate("Menu", "Timer", 0));
#ifndef QT_NO_TOOLTIP
        horizontalSlider_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("Menu", "5", 0));
        label_7->setText(QApplication::translate("Menu", "30", 0));
        aiLevel->setTitle(QApplication::translate("Menu", "IA Level", 0));
#ifndef QT_NO_TOOLTIP
        horizontalSlider->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("Menu", "0", 0));
        label_5->setText(QApplication::translate("Menu", "10", 0));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
