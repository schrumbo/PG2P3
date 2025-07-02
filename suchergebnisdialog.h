#ifndef SUCHERGEBNISDIALOG_H
#define SUCHERGEBNISDIALOG_H

#include <QDialog>
#include "filmstudio.h" // Include the Filmstudio class
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class SuchergebnisDialog; }
QT_END_NAMESPACE

class SuchergebnisDialog : public QDialog
{
    Q_OBJECT

public:
    SuchergebnisDialog(Filmstudio* studio, QWidget *parent = nullptr); // Modified constructor
    ~SuchergebnisDialog();

    void addPlayerEntry(int nummer, QString name, QString beginn, QString ende, double preis);
    void addPassagierEntry(int nummer, QString name, QString beginn, QString ende, double preis);
    void setPassagierName(QString name);
    void initReiseabschnitte();
    void starteSuche(QString name);
    void zeigeReiseabschnitte(int planNr);

private slots:
    void on_pushButtonSuche_clicked();

    void on_tableWidgetPlayer_itemDoubleClicked(QTableWidgetItem *item);

    void on_tableWidgetPassagier_itemDoubleClicked(QTableWidgetItem *item);

    void on_tableWidgetReiseabschnitte_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::SuchergebnisDialog *ui;
    Filmstudio* studio;
    Reiseplan* aktuellerReiseplan = nullptr;
};

#endif // SUCHERGEBNISDIALOG_H
