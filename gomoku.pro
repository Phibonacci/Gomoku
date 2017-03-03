#--------#
# Gomoku #
#--------#

#################
# CONFIGURATION #
#################

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt c++11
TARGET = gomoku
TEMPLATE = app

# TMP OUTPUT DIRECTORY

OBJECTS_DIR = _tmp/_objlocation/
UI_DIR = _tmp/_uilocation/
MOC_DIR = _tmp/_moclocation/
RCC_DIR = _tmp/

# Custom configuration for the Gomoku project #
QMAKE_CXXFLAGS *= -std=c++11
QMAKE_CXXFLAGS_RELEASE -= -O1
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE *= -O3

############
# GAMEPLAY #
############

INCLUDEPATH += RGamePlay
SOURCES += \
    RGamePlay/GamePlay.cpp \
    RGamePlay/RGameArbitre_captureLine.cpp \
    RGamePlay/RGameArbitre_checkWin.cpp \
    RGamePlay/RGameArbitre.cpp \
    RGamePlay/RGameArbitre_getLine.cpp \
    RGamePlay/RGameArbitre_tryPiece.cpp \
    RGamePlay/RGameBoard.cpp \
    RGamePlay/RLine.cpp \
    RGamePlay/RPiece.cpp
HEADERS += \
    RGamePlay/GamePlay.hh \
    RGamePlay/RGameArbitre.hh \
    RGamePlay/RGameBoard.hh \
    RGamePlay/RGamePlay.hh \
    RGamePlay/RLine.hh \
    RGamePlay/RPattern.hh \
    RGamePlay/RPiece.hh \
    RGamePlay/RPieceInformation.hh \
    RGamePlay/RPlayerInfo.hh

#############
# INTERFACE #
#############

INCLUDEPATH += Interface
SOURCES += \
    Interface/configstylesheet.cpp \
    Interface/Context.cpp \
    Interface/gameview.cpp \
    Interface/guistrstyle.cpp \
    Interface/info.cpp \
    Interface/main.cpp \
    Interface/mainwindow.cpp \
    Interface/menu.cpp \
    Interface/rgbdial.cpp \
    Interface/Time.cpp
HEADERS += \
    Interface/configstylesheet.h \
    Interface/gameview.h \
    Interface/guistrstyle.h \
    Interface/mainwindow.h \
    Interface/menu.h \
    Interface/rgbdial.h \
    Interface/Context.hh \
    Interface/IGamePlay.hh \
    Interface/info.hh \
    Interface/IPieceInfo.hh \
    Interface/IPlayerInfo.hh \
    Interface/Time.hh
FORMS += \
    Resource/mainwindow.ui \
    Resource/menu.ui \
    Resource/rgbdial.ui \
    Resource/configstylesheet.ui \
    Resource/info.ui
RESOURCES += \
    Resource/GomokuRes.qrc

#########
# LOGIC #
#########

INCLUDEPATH += Logic
SOURCES += \
    Logic/Game.cpp \
    Logic/Player.cpp \
    Logic/RobotThread.cpp \
    Logic/AiThread.cpp

HEADERS += \
    Logic/Game.hh \
    Logic/Player.hh \
    Logic/Coord.hh \
    Logic/IThread.hh \
    Logic/RobotThread.hh \
    Logic/AiThread.hh \
    Logic/Logic.hh

######
# IA #
######

INCLUDEPATH += ia
SOURCES += \
    ia/ARobot.cpp \
    ia/Priority.cpp \
    ia/Phia.cpp \
    ia/Choice.cpp \
    ia/State.cpp \
    ia/Condition.cpp \
    ia/HelpRobot.cpp \
    ia/Node.cpp \
    ia/Transition.cpp \
    ia/MinRobot.cpp \
    ia/MinNode.cpp \
    ia/MinTransition.cpp
HEADERS += \
    ia/ARobot.hh \
    ia/Priority.hh \
    ia/IRobot.hh \
    ia/Phia.hpp \
    ia/Choice.hpp \
    ia/State.hpp \
    ia/Condition.hpp \
    ia/HelpRobot.hh \
    ia/Node.hh \
    ia/Transition.hh \
    ia/MinRobot.hh \
    ia/MinNode.hh \
    ia/MinTransition.hh
