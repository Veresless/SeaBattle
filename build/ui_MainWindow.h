/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMake_Host;
    QAction *actionFound;
    QAction *actionEnter_IP;
    QAction *actionSave;
    QAction *actionLoad;
    QWidget *centralWidget;
    QVBoxLayout *Central;
    QLabel *Info;
    QHBoxLayout *horizontalLayout;
    QWidget *PlayerWidget;
    QGridLayout *Player;
    QWidget *EnemyWidget;
    QGridLayout *Enemy;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuConnect_to_Host;
    QMenu *menuFile;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(768, 443);
        actionMake_Host = new QAction(MainWindow);
        actionMake_Host->setObjectName(QStringLiteral("actionMake_Host"));
        actionFound = new QAction(MainWindow);
        actionFound->setObjectName(QStringLiteral("actionFound"));
        actionEnter_IP = new QAction(MainWindow);
        actionEnter_IP->setObjectName(QStringLiteral("actionEnter_IP"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Central = new QVBoxLayout(centralWidget);
        Central->setSpacing(6);
        Central->setContentsMargins(11, 11, 11, 11);
        Central->setObjectName(QStringLiteral("Central"));
        Info = new QLabel(centralWidget);
        Info->setObjectName(QStringLiteral("Info"));
        Info->setLayoutDirection(Qt::LeftToRight);
        Info->setFrameShape(QFrame::NoFrame);
        Info->setMidLineWidth(-2);
        Info->setAlignment(Qt::AlignCenter);

        Central->addWidget(Info);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        PlayerWidget = new QWidget(centralWidget);
        PlayerWidget->setObjectName(QStringLiteral("PlayerWidget"));
        PlayerWidget->setMinimumSize(QSize(300, 300));
        PlayerWidget->setMaximumSize(QSize(300, 300));
        Player = new QGridLayout(PlayerWidget);
        Player->setSpacing(0);
        Player->setContentsMargins(11, 11, 11, 11);
        Player->setObjectName(QStringLiteral("Player"));
        Player->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(PlayerWidget);

        EnemyWidget = new QWidget(centralWidget);
        EnemyWidget->setObjectName(QStringLiteral("EnemyWidget"));
        EnemyWidget->setMinimumSize(QSize(300, 300));
        EnemyWidget->setMaximumSize(QSize(300, 300));
        Enemy = new QGridLayout(EnemyWidget);
        Enemy->setSpacing(0);
        Enemy->setContentsMargins(11, 11, 11, 11);
        Enemy->setObjectName(QStringLiteral("Enemy"));
        Enemy->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(EnemyWidget);


        Central->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        Central->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 768, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuConnect_to_Host = new QMenu(menuMenu);
        menuConnect_to_Host->setObjectName(QStringLiteral("menuConnect_to_Host"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionMake_Host);
        menuMenu->addAction(menuConnect_to_Host->menuAction());
        menuConnect_to_Host->addAction(actionFound);
        menuConnect_to_Host->addAction(actionEnter_IP);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        mainToolBar->addAction(actionMake_Host);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionLoad);
        mainToolBar->addAction(actionFound);
        mainToolBar->addAction(actionEnter_IP);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionMake_Host->setText(QApplication::translate("MainWindow", "Make Host", Q_NULLPTR));
        actionFound->setText(QApplication::translate("MainWindow", "Found", Q_NULLPTR));
        actionEnter_IP->setText(QApplication::translate("MainWindow", "Enter IP", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        Info->setText(QString());
        menuMenu->setTitle(QApplication::translate("MainWindow", "Game", Q_NULLPTR));
        menuConnect_to_Host->setTitle(QApplication::translate("MainWindow", "Connect to Host", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
