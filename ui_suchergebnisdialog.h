/********************************************************************************
** Form generated from reading UI file 'suchergebnisdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCHERGEBNISDIALOG_H
#define UI_SUCHERGEBNISDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SuchergebnisDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *searchLayout;
    QLabel *label;
    QLineEdit *lineEditPassagierName;
    QPushButton *pushButtonSuche;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBoxPlayer;
    QVBoxLayout *verticalLayoutPlayer;
    QTableWidget *tableWidgetPlayer;
    QGroupBox *groupBoxPassagier;
    QVBoxLayout *verticalLayoutPassagier;
    QTableWidget *tableWidgetPassagier;
    QTableWidget *tableWidgetReiseabschnitte;

    void setupUi(QDialog *SuchergebnisDialog)
    {
        if (SuchergebnisDialog->objectName().isEmpty())
            SuchergebnisDialog->setObjectName("SuchergebnisDialog");
        SuchergebnisDialog->resize(528, 659);
        horizontalLayout = new QHBoxLayout(SuchergebnisDialog);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        searchLayout = new QHBoxLayout();
        searchLayout->setObjectName("searchLayout");
        label = new QLabel(SuchergebnisDialog);
        label->setObjectName("label");

        searchLayout->addWidget(label);

        lineEditPassagierName = new QLineEdit(SuchergebnisDialog);
        lineEditPassagierName->setObjectName("lineEditPassagierName");

        searchLayout->addWidget(lineEditPassagierName);

        pushButtonSuche = new QPushButton(SuchergebnisDialog);
        pushButtonSuche->setObjectName("pushButtonSuche");
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/suchen.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButtonSuche->setIcon(icon);

        searchLayout->addWidget(pushButtonSuche);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        searchLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(searchLayout);

        groupBoxPlayer = new QGroupBox(SuchergebnisDialog);
        groupBoxPlayer->setObjectName("groupBoxPlayer");
        verticalLayoutPlayer = new QVBoxLayout(groupBoxPlayer);
        verticalLayoutPlayer->setObjectName("verticalLayoutPlayer");
        tableWidgetPlayer = new QTableWidget(groupBoxPlayer);
        if (tableWidgetPlayer->columnCount() < 5)
            tableWidgetPlayer->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetPlayer->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetPlayer->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetPlayer->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetPlayer->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetPlayer->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetPlayer->setObjectName("tableWidgetPlayer");

        verticalLayoutPlayer->addWidget(tableWidgetPlayer);


        verticalLayout->addWidget(groupBoxPlayer);

        groupBoxPassagier = new QGroupBox(SuchergebnisDialog);
        groupBoxPassagier->setObjectName("groupBoxPassagier");
        verticalLayoutPassagier = new QVBoxLayout(groupBoxPassagier);
        verticalLayoutPassagier->setObjectName("verticalLayoutPassagier");
        tableWidgetPassagier = new QTableWidget(groupBoxPassagier);
        if (tableWidgetPassagier->columnCount() < 5)
            tableWidgetPassagier->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetPassagier->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetPassagier->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetPassagier->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetPassagier->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetPassagier->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        tableWidgetPassagier->setObjectName("tableWidgetPassagier");

        verticalLayoutPassagier->addWidget(tableWidgetPassagier);


        verticalLayout->addWidget(groupBoxPassagier);

        tableWidgetReiseabschnitte = new QTableWidget(SuchergebnisDialog);
        if (tableWidgetReiseabschnitte->columnCount() < 5)
            tableWidgetReiseabschnitte->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetReiseabschnitte->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetReiseabschnitte->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetReiseabschnitte->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetReiseabschnitte->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetReiseabschnitte->setHorizontalHeaderItem(4, __qtablewidgetitem14);
        tableWidgetReiseabschnitte->setObjectName("tableWidgetReiseabschnitte");

        verticalLayout->addWidget(tableWidgetReiseabschnitte);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(SuchergebnisDialog);

        QMetaObject::connectSlotsByName(SuchergebnisDialog);
    } // setupUi

    void retranslateUi(QDialog *SuchergebnisDialog)
    {
        SuchergebnisDialog->setWindowTitle(QCoreApplication::translate("SuchergebnisDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SuchergebnisDialog", "Name des Passagiers:", nullptr));
        pushButtonSuche->setText(QString());
        groupBoxPlayer->setTitle(QCoreApplication::translate("SuchergebnisDialog", "Reisepl\303\244ne als Player", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetPlayer->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SuchergebnisDialog", "PlanNr.", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetPlayer->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SuchergebnisDialog", "PlanName", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetPlayer->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SuchergebnisDialog", "ReiseBeginn", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetPlayer->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SuchergebnisDialog", "ReiseEnde", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetPlayer->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SuchergebnisDialog", "Preis", nullptr));
        groupBoxPassagier->setTitle(QCoreApplication::translate("SuchergebnisDialog", "Reisepl\303\244ne als Passagier", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetPassagier->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("SuchergebnisDialog", "PlanNr.", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetPassagier->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("SuchergebnisDialog", "PlanName", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetPassagier->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("SuchergebnisDialog", "ReiseBeginn", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetPassagier->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("SuchergebnisDialog", "ReiseEnde", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetPassagier->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("SuchergebnisDialog", "Preis", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetReiseabschnitte->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("SuchergebnisDialog", "Typ", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetReiseabschnitte->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("SuchergebnisDialog", "Ziel/Lagerort", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetReiseabschnitte->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("SuchergebnisDialog", "Abfahrt", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetReiseabschnitte->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("SuchergebnisDialog", "Ankunft", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetReiseabschnitte->horizontalHeaderItem(4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("SuchergebnisDialog", "Preis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuchergebnisDialog: public Ui_SuchergebnisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCHERGEBNISDIALOG_H
