#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QStringList>
#include "filmstudio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    //MainWindow(QWidget* parent = nullptr);
    MainWindow(Filmstudio* f, QWidget* parent = nullptr);
    ~MainWindow();


    //Hilfsfunktionen
    void clearWidgets();
    QString frageDatum(const QString& titel, const QString& label, const QDate& defaultDate);
private slots:


    // ***** Slots für ListWidgets benötigt *****
    void on_drachenListWidget_itemClicked(QListWidgetItem* item);
    void on_reisePlanListWidget_itemClicked(QListWidgetItem *item); // ***** Neu!!! *****
    void on_reiseListWidget_itemClicked(QListWidgetItem *item);

    // ***** Slots für Buttons benötigt *****
    void on_addDracheButton_clicked();
    void on_addReiseplanButton_clicked();                           // ***** Neu!!! *****
    void on_addDrachenreiseButton_clicked();
    void on_addPassengerButton_clicked();
    void on_saveButton_clicked();


    void on_actionBeenden_triggered();

    void on_actionSpeichern_triggered();

    void on_actionEinlesen_triggered();

    void on_actionDrache_L_schen_triggered();

    void on_actionReiseplan_L_schen_triggered();

    void on_actionDrachenreise_L_schen_triggered();

    void on_actionPassagier_L_schen_triggered();

    void on_actionPassagierSuchen_triggered();

private:
    Ui::MainWindow* ui;
    Filmstudio* studio;

    void fillDrachenListe();
    void showDrachenDetails(Drache* drache);
    void showReiseplaene(Drache* drache);                           // ***** Neu!!! *****
    void showDrachenreisen(Reiseplan* plan);                        // ***** Geändert!!! *****
    void showDrachenreiseDetails(Drachenreise* reise);
};

#endif // MAINWINDOW_H
