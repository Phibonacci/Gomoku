/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "gameview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStyle;
    QAction *actionExit;
    QAction *actionDark_Style;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    GameView *gameView;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *doubleThreeCheckBox;
    QCheckBox *breakableFiveCheckBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *_blackScore;
    QLabel *_whiteScore;
    QTextEdit *logText;
    QHBoxLayout *horizontalLayout;
    QPushButton *restartButton;
    QPushButton *undoButton;
    QMenuBar *menuBar;
    QMenu *menuEdit;
    QMenu *menuQuit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1081, 847);
        actionStyle = new QAction(MainWindow);
        actionStyle->setObjectName(QStringLiteral("actionStyle"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionDark_Style = new QAction(MainWindow);
        actionDark_Style->setObjectName(QStringLiteral("actionDark_Style"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        gameView = new GameView(centralWidget);
        gameView->setObjectName(QStringLiteral("gameView"));
        gameView->setMinimumSize(QSize(760, 760));
        gameView->setMaximumSize(QSize(760, 760));
        gameView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_2->addWidget(gameView);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        doubleThreeCheckBox = new QCheckBox(centralWidget);
        doubleThreeCheckBox->setObjectName(QStringLiteral("doubleThreeCheckBox"));
        doubleThreeCheckBox->setChecked(true);

        verticalLayout_2->addWidget(doubleThreeCheckBox);

        breakableFiveCheckBox = new QCheckBox(centralWidget);
        breakableFiveCheckBox->setObjectName(QStringLiteral("breakableFiveCheckBox"));
        breakableFiveCheckBox->setChecked(true);

        verticalLayout_2->addWidget(breakableFiveCheckBox);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(40, 16777215));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(45, 16777215));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        _blackScore = new QLabel(centralWidget);
        _blackScore->setObjectName(QStringLiteral("_blackScore"));
        _blackScore->setMaximumSize(QSize(20, 16777215));
        _blackScore->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(_blackScore, 1, 0, 1, 1);

        _whiteScore = new QLabel(centralWidget);
        _whiteScore->setObjectName(QStringLiteral("_whiteScore"));
        _whiteScore->setMaximumSize(QSize(20, 16777215));
        _whiteScore->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(_whiteScore, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        logText = new QTextEdit(centralWidget);
        logText->setObjectName(QStringLiteral("logText"));
        logText->setMaximumSize(QSize(400, 16777215));
        logText->setReadOnly(true);

        verticalLayout_2->addWidget(logText);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(1, 75);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        restartButton = new QPushButton(centralWidget);
        restartButton->setObjectName(QStringLiteral("restartButton"));

        horizontalLayout->addWidget(restartButton);

        undoButton = new QPushButton(centralWidget);
        undoButton->setObjectName(QStringLiteral("undoButton"));

        horizontalLayout->addWidget(undoButton);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1081, 19));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuQuit = new QMenu(menuBar);
        menuQuit->setObjectName(QStringLiteral("menuQuit"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuQuit->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuEdit->addAction(actionStyle);
        menuEdit->addAction(actionDark_Style);
        menuQuit->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gomoku", 0));
        actionStyle->setText(QApplication::translate("MainWindow", "Custom Style", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        actionDark_Style->setText(QApplication::translate("MainWindow", "Dark Style", 0));
        doubleThreeCheckBox->setText(QApplication::translate("MainWindow", "Double Three", 0));
        breakableFiveCheckBox->setText(QApplication::translate("MainWindow", "Breakable Five", 0));
        label->setText(QApplication::translate("MainWindow", "Black:", 0));
        label_2->setText(QApplication::translate("MainWindow", "White:", 0));
        _blackScore->setText(QApplication::translate("MainWindow", "0", 0));
        _whiteScore->setText(QApplication::translate("MainWindow", "0", 0));
        restartButton->setText(QApplication::translate("MainWindow", "Restart (r)", 0));
        restartButton->setShortcut(QApplication::translate("MainWindow", "R", 0));
        undoButton->setText(QApplication::translate("MainWindow", "Undo (u)", 0));
        undoButton->setShortcut(QApplication::translate("MainWindow", "U", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuQuit->setTitle(QApplication::translate("MainWindow", "Gomoku", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
