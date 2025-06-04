/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionBeenden;
    QAction *actionSpeichern;
    QAction *actionEinlesen;
    QAction *actionDrache_L_schen;
    QAction *actionReiseplan_L_schen;
    QAction *actionDrachenreise_L_schen;
    QAction *actionPassagier_L_schen;
    QAction *actionPassagierSuchen;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *drachenListWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_drachenDetails;
    QPlainTextEdit *detailTextEdit;
    QLabel *label_Plaene;
    QListWidget *reisePlanListWidget;
    QLabel *label_reisen;
    QListWidget *reiseListWidget;
    QLabel *label_drachenflugDetails;
    QListWidget *reiseDetailsListWidget;
    QHBoxLayout *buttonLayout;
    QPushButton *addDracheButton;
    QPushButton *addReiseplanButton;
    QPushButton *addDrachenreiseButton;
    QPushButton *addPassengerButton;
    QPushButton *saveButton;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuL_schen;
    QMenu *menuSuchen;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(986, 675);
        QFont font;
        font.setFamilies({QString::fromUtf8("Ubuntu")});
        MainWindow->setFont(font);
        actionBeenden = new QAction(MainWindow);
        actionBeenden->setObjectName("actionBeenden");
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/icons/beenden.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionBeenden->setIcon(icon);
        actionBeenden->setFont(font);
        actionSpeichern = new QAction(MainWindow);
        actionSpeichern->setObjectName("actionSpeichern");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/icons/speichern.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSpeichern->setIcon(icon1);
        actionEinlesen = new QAction(MainWindow);
        actionEinlesen->setObjectName("actionEinlesen");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icons/icons/einlesen.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionEinlesen->setIcon(icon2);
        actionDrache_L_schen = new QAction(MainWindow);
        actionDrache_L_schen->setObjectName("actionDrache_L_schen");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icons/icons/drache.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionDrache_L_schen->setIcon(icon3);
        actionReiseplan_L_schen = new QAction(MainWindow);
        actionReiseplan_L_schen->setObjectName("actionReiseplan_L_schen");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("icons/icons/reiseplan.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionReiseplan_L_schen->setIcon(icon4);
        actionDrachenreise_L_schen = new QAction(MainWindow);
        actionDrachenreise_L_schen->setObjectName("actionDrachenreise_L_schen");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("icons/icons/drachenreise.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionDrachenreise_L_schen->setIcon(icon5);
        actionPassagier_L_schen = new QAction(MainWindow);
        actionPassagier_L_schen->setObjectName("actionPassagier_L_schen");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("icons/icons/passagier.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPassagier_L_schen->setIcon(icon6);
        actionPassagierSuchen = new QAction(MainWindow);
        actionPassagierSuchen->setObjectName("actionPassagierSuchen");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("icons/icons/suchen.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionPassagierSuchen->setIcon(icon7);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        drachenListWidget = new QListWidget(centralwidget);
        drachenListWidget->setObjectName("drachenListWidget");

        horizontalLayout->addWidget(drachenListWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_drachenDetails = new QLabel(centralwidget);
        label_drachenDetails->setObjectName("label_drachenDetails");

        verticalLayout->addWidget(label_drachenDetails);

        detailTextEdit = new QPlainTextEdit(centralwidget);
        detailTextEdit->setObjectName("detailTextEdit");
        detailTextEdit->setReadOnly(true);

        verticalLayout->addWidget(detailTextEdit);

        label_Plaene = new QLabel(centralwidget);
        label_Plaene->setObjectName("label_Plaene");

        verticalLayout->addWidget(label_Plaene);

        reisePlanListWidget = new QListWidget(centralwidget);
        reisePlanListWidget->setObjectName("reisePlanListWidget");

        verticalLayout->addWidget(reisePlanListWidget);

        label_reisen = new QLabel(centralwidget);
        label_reisen->setObjectName("label_reisen");

        verticalLayout->addWidget(label_reisen);

        reiseListWidget = new QListWidget(centralwidget);
        reiseListWidget->setObjectName("reiseListWidget");

        verticalLayout->addWidget(reiseListWidget);

        label_drachenflugDetails = new QLabel(centralwidget);
        label_drachenflugDetails->setObjectName("label_drachenflugDetails");

        verticalLayout->addWidget(label_drachenflugDetails);

        reiseDetailsListWidget = new QListWidget(centralwidget);
        reiseDetailsListWidget->setObjectName("reiseDetailsListWidget");

        verticalLayout->addWidget(reiseDetailsListWidget);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        addDracheButton = new QPushButton(centralwidget);
        addDracheButton->setObjectName("addDracheButton");

        buttonLayout->addWidget(addDracheButton);

        addReiseplanButton = new QPushButton(centralwidget);
        addReiseplanButton->setObjectName("addReiseplanButton");

        buttonLayout->addWidget(addReiseplanButton);

        addDrachenreiseButton = new QPushButton(centralwidget);
        addDrachenreiseButton->setObjectName("addDrachenreiseButton");

        buttonLayout->addWidget(addDrachenreiseButton);

        addPassengerButton = new QPushButton(centralwidget);
        addPassengerButton->setObjectName("addPassengerButton");

        buttonLayout->addWidget(addPassengerButton);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        buttonLayout->addWidget(saveButton);


        verticalLayout->addLayout(buttonLayout);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setEnabled(true);
        menubar->setGeometry(QRect(0, 0, 986, 18));
        menubar->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        menubar->setDefaultUp(false);
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName("menuDatei");
        menuL_schen = new QMenu(menubar);
        menuL_schen->setObjectName("menuL_schen");
        menuSuchen = new QMenu(menubar);
        menuSuchen->setObjectName("menuSuchen");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::ToolBarArea::LeftToolBarArea, toolBar);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menuL_schen->menuAction());
        menubar->addAction(menuSuchen->menuAction());
        menuDatei->addAction(actionEinlesen);
        menuDatei->addAction(actionSpeichern);
        menuDatei->addAction(actionBeenden);
        menuL_schen->addAction(actionDrache_L_schen);
        menuL_schen->addAction(actionReiseplan_L_schen);
        menuL_schen->addAction(actionDrachenreise_L_schen);
        menuL_schen->addAction(actionPassagier_L_schen);
        menuSuchen->addAction(actionPassagierSuchen);
        toolBar->addAction(actionBeenden);
        toolBar->addAction(actionSpeichern);
        toolBar->addAction(actionEinlesen);
        toolBar->addAction(actionDrache_L_schen);
        toolBar->addAction(actionReiseplan_L_schen);
        toolBar->addAction(actionDrachenreise_L_schen);
        toolBar->addAction(actionPassagier_L_schen);
        toolBar->addAction(actionPassagierSuchen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Drachenflug-Manager", nullptr));
        actionBeenden->setText(QCoreApplication::translate("MainWindow", "Beenden", nullptr));
        actionSpeichern->setText(QCoreApplication::translate("MainWindow", "Speichern", nullptr));
        actionEinlesen->setText(QCoreApplication::translate("MainWindow", "Einlesen", nullptr));
        actionDrache_L_schen->setText(QCoreApplication::translate("MainWindow", "Drache L\303\266schen", nullptr));
        actionReiseplan_L_schen->setText(QCoreApplication::translate("MainWindow", "Reiseplan L\303\266schen", nullptr));
        actionDrachenreise_L_schen->setText(QCoreApplication::translate("MainWindow", "Drachenreise L\303\266schen", nullptr));
        actionPassagier_L_schen->setText(QCoreApplication::translate("MainWindow", "Passagier L\303\266schen", nullptr));
        actionPassagierSuchen->setText(QCoreApplication::translate("MainWindow", "Passagier Suchen", nullptr));
        label_drachenDetails->setText(QCoreApplication::translate("MainWindow", "Details zum Drachen:", nullptr));
        label_Plaene->setText(QCoreApplication::translate("MainWindow", "Reisepl\303\244ne", nullptr));
        label_reisen->setText(QCoreApplication::translate("MainWindow", "Drachenreisen:", nullptr));
        label_drachenflugDetails->setText(QCoreApplication::translate("MainWindow", "Details zur Drachenreise:", nullptr));
        addDracheButton->setText(QCoreApplication::translate("MainWindow", "Drache hinzuf\303\274gen", nullptr));
        addReiseplanButton->setText(QCoreApplication::translate("MainWindow", "Reiseplan hinzuf\303\274gen", nullptr));
        addDrachenreiseButton->setText(QCoreApplication::translate("MainWindow", "Reise hinzuf\303\274gen", nullptr));
        addPassengerButton->setText(QCoreApplication::translate("MainWindow", "Passagier buchen", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Speichern", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("MainWindow", "Datei", nullptr));
        menuL_schen->setTitle(QCoreApplication::translate("MainWindow", "L\303\266schen", nullptr));
        menuSuchen->setTitle(QCoreApplication::translate("MainWindow", "Suchen", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
