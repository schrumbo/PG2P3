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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
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
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(986, 675);
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
        menubar->setGeometry(QRect(0, 0, 986, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Drachenflug-Manager", nullptr));
        label_drachenDetails->setText(QCoreApplication::translate("MainWindow", "Details zum Drachen:", nullptr));
        label_Plaene->setText(QCoreApplication::translate("MainWindow", "Reisepl\303\244ne", nullptr));
        label_reisen->setText(QCoreApplication::translate("MainWindow", "Drachenreisen:", nullptr));
        label_drachenflugDetails->setText(QCoreApplication::translate("MainWindow", "Details zur Drachenreise:", nullptr));
        addDracheButton->setText(QCoreApplication::translate("MainWindow", "Drache hinzuf\303\274gen", nullptr));
        addReiseplanButton->setText(QCoreApplication::translate("MainWindow", "Reiseplan hinzuf\303\274gen", nullptr));
        addDrachenreiseButton->setText(QCoreApplication::translate("MainWindow", "Reise hinzuf\303\274gen", nullptr));
        addPassengerButton->setText(QCoreApplication::translate("MainWindow", "Passagier buchen", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Speichern", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
