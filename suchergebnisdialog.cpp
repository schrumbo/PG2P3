#include "suchergebnisdialog.h"
#include "ui_suchergebnisdialog.h"
#include<QMessageBox>
#include "drachenflug.h"
#include "nachtlager.h"
#include "nachtlagerdialog.h"
#include "drachenflugdialog.h"



SuchergebnisDialog::SuchergebnisDialog(Filmstudio* studio, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SuchergebnisDialog)
    , studio(studio)
{
    ui->setupUi(this);

    // Tabellen initialisieren
    QStringList headerPlayer = {"PlanNr.", "PlanName", "ReiseBeginn", "ReiseEnde", "Preis"};
    QStringList headerPassagier = {"PlanNr.", "PlanName", "ReiseBeginn", "ReiseEnde", "Preis"};

    // Setzt die Anzahl der Spalten beider Tabellen (Player & Passagier) auf 4
    ui->tableWidgetPlayer->setColumnCount(5);
    ui->tableWidgetPassagier->setColumnCount(5);

    // Setzt die Breiten der einzelnen Spalten
    ui->tableWidgetPlayer->setColumnWidth(0, 50);   // Spalte "PlanNr."
    ui->tableWidgetPlayer->setColumnWidth(1, 150);  // Spalte "PlanName"
    ui->tableWidgetPlayer->setColumnWidth(2, 80);  // Spalte "Beginn"
    ui->tableWidgetPlayer->setColumnWidth(3, 80);  // Spalte "Ende"
    ui->tableWidgetPlayer->setColumnWidth(4, 80);   // Spalte "Preis"
    ui->tableWidgetPassagier->setColumnWidth(0, 50);   // Spalte "PlanNr."
    ui->tableWidgetPassagier->setColumnWidth(1, 150);  // Spalte "PlanName"
    ui->tableWidgetPassagier->setColumnWidth(2, 80);  // Spalte "Beginn"
    ui->tableWidgetPassagier->setColumnWidth(3, 80);  // Spalte "Ende"
    ui->tableWidgetPassagier->setColumnWidth(4, 80);   // Spalte "Preis"
    this->setMinimumWidth(565);  // Minimalbreite festlegen
    this->setMaximumWidth(565);  // Minimalbreite festlegen

    // Setzt die Beschriftungen der Spaltenköpfe (z.B. PlanNr., Name, Beginn, Ende)
    ui->tableWidgetPlayer->setHorizontalHeaderLabels(headerPlayer);
    ui->tableWidgetPassagier->setHorizontalHeaderLabels(headerPassagier);

    // Sorgt dafür, dass die letzte Spalte automatisch den verbleibenden Platz nutzt
    ui->tableWidgetPlayer->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetPassagier->horizontalHeader()->setStretchLastSection(true);

    // Verhindert, dass Zellen direkt bearbeitet werden können (rein zur Anzeige)
    ui->tableWidgetPlayer->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetPassagier->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Macht die Auswahl zeilenweise – beim Klicken wird die ganze Zeile markiert
    ui->tableWidgetPlayer->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetPassagier->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Erlaubt nur eine einzige Auswahl gleichzeitig – keine Mehrfachauswahl
    ui->tableWidgetPlayer->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetPassagier->setSelectionMode(QAbstractItemView::SingleSelection);

    // Blendet die linke vertikale Kopfspalte (Zeilennummerierung) aus
    ui->tableWidgetPlayer->verticalHeader()->setVisible(false);
    ui->tableWidgetPassagier->verticalHeader()->setVisible(false);

    // LINE EDIT NUN NICHT MEHR READ ONLY (11,b)
    ui->lineEditPassagierName->setReadOnly(false);

    // Hintergrundfarbe der Headerzeile ändern
    QHeaderView* headerTablePlayer = ui->tableWidgetPlayer->horizontalHeader();
    headerTablePlayer->setStyleSheet("QHeaderView::section { background-color: lightblue; color: black; }");

    QHeaderView* headerTablePassagier = ui->tableWidgetPassagier->horizontalHeader();
    headerTablePassagier->setStyleSheet("QHeaderView::section { background-color: rgb(200, 245, 220); color: black; }");
    initReiseabschnitte();


}


SuchergebnisDialog::~SuchergebnisDialog()
{
    delete ui;
}

void SuchergebnisDialog::addPlayerEntry(int nummer, QString name, QString beginn, QString ende, double preis){

    auto table = ui->tableWidgetPlayer;
    int row = table->rowCount();

    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem(QString::number(nummer)));
    table->setItem(row, 1, new QTableWidgetItem(name));
    table->setItem(row, 2, new QTableWidgetItem(beginn));
    table->setItem(row, 3, new QTableWidgetItem(ende));
    table->setItem(row, 4, new QTableWidgetItem(QString::number(preis)));
}

void SuchergebnisDialog::addPassagierEntry(int nummer, QString name, QString beginn, QString ende, double preis){
    auto table = ui->tableWidgetPassagier;
    int row = table->rowCount();

    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem(QString::number(nummer)));
    table->setItem(row, 1, new QTableWidgetItem(name));
    table->setItem(row, 2, new QTableWidgetItem(beginn));
    table->setItem(row, 3, new QTableWidgetItem(ende));
    table->setItem(row, 4, new QTableWidgetItem(QString::number(preis)));
}

void SuchergebnisDialog::setPassagierName(QString name){
    ui->lineEditPassagierName->setText(name);
}

void SuchergebnisDialog::starteSuche(QString name) {
    ui->lineEditPassagierName->setText(name);

    ui->tableWidgetPlayer->setRowCount(0);
    ui->tableWidgetPassagier->setRowCount(0);


    std::vector<ReiseInfo> alsPlayer = studio->findeReiseplaeneAlsPlayer(name.toStdString());
    std::vector<ReiseInfo> alsPassagier = studio->findeReiseplaeneAlsPassagier(name.toStdString());

    for(const auto& info : alsPlayer) {
        addPlayerEntry(
            info.nummer,
            QString::fromStdString(info.name),
            QString::fromStdString(info.beginn),
            QString::fromStdString(info.ende),
            info.preis
            );
    }

    for(const auto& info : alsPassagier) {
        addPassagierEntry(
            info.nummer,
            QString::fromStdString(info.name),
            QString::fromStdString(info.beginn),
            QString::fromStdString(info.ende),
            info.preis
            );
    }
}

void SuchergebnisDialog::on_pushButtonSuche_clicked()
{
    QString name = ui->lineEditPassagierName->text().trimmed();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Warnung", "Bitte geben Sie einen Namen ein.");
        return;
    }

    starteSuche(name);
}


void SuchergebnisDialog::initReiseabschnitte(){

    ui->tableWidgetReiseabschnitte->setColumnCount(5);

    QStringList headerLabels;
    headerLabels << "Typ" << "Ziel/Lagerort" << "Abfahrt" << "Ankunft" << "Preis";
    ui->tableWidgetReiseabschnitte->setHorizontalHeaderLabels(headerLabels);

    ui->tableWidgetReiseabschnitte->setColumnWidth(0, 50);
    ui->tableWidgetReiseabschnitte->setColumnWidth(1, 150);
    ui->tableWidgetReiseabschnitte->setColumnWidth(2, 80);
    ui->tableWidgetReiseabschnitte->setColumnWidth(3, 80);
    ui->tableWidgetReiseabschnitte->setColumnWidth(4, 80);

    ui->tableWidgetReiseabschnitte->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetReiseabschnitte->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetReiseabschnitte->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetReiseabschnitte->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetReiseabschnitte->verticalHeader()->setVisible(false);

    QHeaderView* headerTableReiseabschnitte = ui->tableWidgetReiseabschnitte->horizontalHeader();
    headerTableReiseabschnitte->setStyleSheet("QHeaderView::section { background-color: lightcoral; color: black; }");

    ui->tableWidgetReiseabschnitte->setSortingEnabled(false);
}

void SuchergebnisDialog::zeigeReiseabschnitte(int planNr) {
    ui->tableWidgetReiseabschnitte->setRowCount(0);


    aktuellerReiseplan = studio->findeReiseplan(planNr);

    if (!aktuellerReiseplan) {
        QMessageBox::warning(this, "Fehler", "Reiseplan nicht gefunden!");
        return;
    }

    const auto& reiseabschnitte = aktuellerReiseplan->getReiseabschnitte();

    for (const auto& reise : reiseabschnitte) {
        int row = ui->tableWidgetReiseabschnitte->rowCount();
        ui->tableWidgetReiseabschnitte->insertRow(row);

        QTableWidgetItem* iconItem = new QTableWidgetItem();

        Drachenflug* flug = dynamic_cast<Drachenflug*>(reise);
        Nachtlager* lager = dynamic_cast<Nachtlager*>(reise);

        QString zielOderOrt;

        if (flug) {
            iconItem->setIcon(QIcon(":/icons/drachenflug.svg"));
            zielOderOrt = QString::fromStdString(flug->getZiel());
        } else if (lager) {
            iconItem->setIcon(QIcon(":/icons/nachtlager.svg"));
            zielOderOrt = QString::fromStdString(lager->getLagerOrt());
        }

        ui->tableWidgetReiseabschnitte->setItem(row, 0, iconItem);
        ui->tableWidgetReiseabschnitte->setItem(row, 1, new QTableWidgetItem(zielOderOrt));
        ui->tableWidgetReiseabschnitte->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(reise->getAbfahrt())));
        ui->tableWidgetReiseabschnitte->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(reise->getAnkunft())));
        ui->tableWidgetReiseabschnitte->setItem(row, 4, new QTableWidgetItem(QString::number(reise->getPreis(), 'f', 2)));
    }
}



void SuchergebnisDialog::on_tableWidgetPlayer_itemDoubleClicked(QTableWidgetItem *item)
{
    if (!item) return;

    int row = item->row();

    QTableWidgetItem* planNrItem = ui->tableWidgetPlayer->item(row, 0);
    if (!planNrItem) return;

    bool ok;
    int planNr = planNrItem->text().toInt(&ok);
    if (!ok) return;


    zeigeReiseabschnitte(planNr);
}


void SuchergebnisDialog::on_tableWidgetPassagier_itemDoubleClicked(QTableWidgetItem *item)
{
    if (!item) return;

    int row = item->row();

    QTableWidgetItem* planNrItem = ui->tableWidgetPassagier->item(row, 0);
    if (!planNrItem) return;

    bool ok;
    int planNr = planNrItem->text().toInt(&ok);
    if (!ok) return;

    zeigeReiseabschnitte(planNr);
}


void SuchergebnisDialog::on_tableWidgetReiseabschnitte_itemDoubleClicked(QTableWidgetItem *item)
{
    if (!item) return;

    // Ermitteln der angeklickten Zeile
    int row = item->row();

    // Prüfen ob ein aktueller Reiseplan vorhanden ist
    if (!aktuellerReiseplan) {
        QMessageBox::warning(this, "Fehler", "Kein Reiseplan ausgewählt!");
        return;
    }

    // Reiseabschnitte aus dem aktuellen Reiseplan holen
    const auto& reiseabschnitte = aktuellerReiseplan->getReiseabschnitte();

    // Prüfen ob die Zeile gültig ist
    if (row < 0 || row >= static_cast<int>(reiseabschnitte.size())) {
        QMessageBox::warning(this, "Fehler", "Ungültige Auswahl!");
        return;
    }

    // Das entsprechende Reiseabschnitt-Objekt holen
    Drachenreise* reise = reiseabschnitte[row];
    if (!reise) return;

    // Typ prüfen und entsprechenden Dialog öffnen
    if (reise->getTyp() == "drachenflug") {
        // Cast zu Drachenflug
        Drachenflug* flug = dynamic_cast<Drachenflug*>(reise);
        if (flug) {
            //TODO




            DrachenflugDialog dlg(flug, this);
            if (dlg.exec() == QDialog::Accepted) {
                // Bei OK: Tabelle aktualisieren
                zeigeReiseabschnitte(aktuellerReiseplan->getReiseplanNummer());
                QMessageBox::information(this, "Erfolg", "Drachenflug wurde aktualisiert!");
            }

        }
    }
    else if (reise->getTyp() == "nachtlager") {
        // Cast zu Nachtlager
        Nachtlager* nacht = dynamic_cast<Nachtlager*>(reise);
        if (nacht) {
            NachtlagerDialog dlg(nacht, this);
            if (dlg.exec() == QDialog::Accepted) {
                // Bei OK: Tabelle aktualisieren
                ui->tableWidgetReiseabschnitte->setRowCount(0);

                zeigeReiseabschnitte(aktuellerReiseplan->getReiseplanNummer());
                QMessageBox::information(this, "Erfolg", "Nachtlager wurde aktualisiert!");
            }
        }
    }
}

