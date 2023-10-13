/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionNew_File;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionSend_File;
    QAction *actionRevert;
    QAction *actionClose;
    QAction *actionProperties;
    QAction *actionPrint;
    QAction *actionView_all_recent_files;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionRemove;
    QAction *actionDelete;
    QAction *actionSelect_All;
    QAction *actionAdvance;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuInsert;
    QMenu *menuTools;
    QMenu *menuOptions;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionNew_File = new QAction(MainWindow);
        actionNew_File->setObjectName("actionNew_File");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName("actionSave_as");
        actionSend_File = new QAction(MainWindow);
        actionSend_File->setObjectName("actionSend_File");
        actionRevert = new QAction(MainWindow);
        actionRevert->setObjectName("actionRevert");
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName("actionClose");
        actionProperties = new QAction(MainWindow);
        actionProperties->setObjectName("actionProperties");
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName("actionPrint");
        actionView_all_recent_files = new QAction(MainWindow);
        actionView_all_recent_files->setObjectName("actionView_all_recent_files");
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName("actionRedo");
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName("actionRemove");
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        actionSelect_All = new QAction(MainWindow);
        actionSelect_All->setObjectName("actionSelect_All");
        actionAdvance = new QAction(MainWindow);
        actionAdvance->setObjectName("actionAdvance");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuInsert = new QMenu(menubar);
        menuInsert->setObjectName("menuInsert");
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuInsert->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionNew_File);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionSend_File);
        menuFile->addSeparator();
        menuFile->addAction(actionRevert);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionProperties);
        menuFile->addAction(actionPrint);
        menuFile->addAction(actionView_all_recent_files);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionRemove);
        menuEdit->addAction(actionDelete);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_All);
        menuEdit->addSeparator();
        menuEdit->addAction(actionAdvance);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_File->setText(QCoreApplication::translate("MainWindow", "New File", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
        actionSend_File->setText(QCoreApplication::translate("MainWindow", "Send File", nullptr));
        actionRevert->setText(QCoreApplication::translate("MainWindow", "Revert", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionProperties->setText(QCoreApplication::translate("MainWindow", "Properties", nullptr));
        actionPrint->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        actionView_all_recent_files->setText(QCoreApplication::translate("MainWindow", "View all recent files", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
        actionRemove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        actionSelect_All->setText(QCoreApplication::translate("MainWindow", "Select All", nullptr));
        actionAdvance->setText(QCoreApplication::translate("MainWindow", "Advance", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuInsert->setTitle(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
