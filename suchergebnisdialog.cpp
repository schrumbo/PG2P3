#include "suchergebnisdialog.h"
#include "ui_suchergebnisdialog.h"

SuchergebnisDialog::SuchergebnisDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SuchergebnisDialog)
{
    ui->setupUi(this);

    // Tabellen initialisieren
    QStringList headerPlayer = {"PlanNr.", "PlanName", "ReiseBeginn", "ReiseEnde"};
    QStringList headerPassagier = {"PlanNr.", "PlanName", "ReiseBeginn", "ReiseEnde"};

    // Setzt die Anzahl der Spalten beider Tabellen (Player & Passagier) auf 4
    ui->tableWidgetPlayer->setColumnCount(4);
    ui->tableWidgetPassagier->setColumnCount(4);

    // Setzt die Breiten der einzelnen Spalten
    ui->tableWidgetPlayer->setColumnWidth(0, 50);   // Spalte "PlanNr."
    ui->tableWidgetPlayer->setColumnWidth(1, 150);  // Spalte "PlanName"
    ui->tableWidgetPlayer->setColumnWidth(2, 120);  // Spalte "Beginn"
    ui->tableWidgetPlayer->setColumnWidth(3, 120);  // Spalte "Ende"
    ui->tableWidgetPassagier->setColumnWidth(0, 50);   // Spalte "PlanNr."
    ui->tableWidgetPassagier->setColumnWidth(1, 150);  // Spalte "PlanName"
    ui->tableWidgetPassagier->setColumnWidth(2, 120);  // Spalte "Beginn"
    ui->tableWidgetPassagier->setColumnWidth(3, 120);  // Spalte "Ende"
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

    // setzt lineEdit als nicht editierbar
    ui->lineEditPassagierName->setReadOnly(true);

    // Hintergrundfarbe der Headerzeile ändern
    QHeaderView* headerTablePlayer = ui->tableWidgetPlayer->horizontalHeader();
    headerTablePlayer->setStyleSheet("QHeaderView::section { background-color: lightblue; color: black; }");

    QHeaderView* headerTablePassagier = ui->tableWidgetPassagier->horizontalHeader();
    headerTablePassagier->setStyleSheet("QHeaderView::section { background-color: rgb(200, 245, 220); color: black; }");
}

SuchergebnisDialog::~SuchergebnisDialog()
{
    delete ui;
}



void SuchergebnisDialog::addPlayerEntry(int nummer, QString name, QString beginn, QString ende){
    auto table = ui->tableWidgetPlayer;
    int row = table->rowCount();

    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem(QString::number(nummer)));
    table->setItem(row, 1, new QTableWidgetItem(name));
    table->setItem(row, 2, new QTableWidgetItem(beginn));
    table->setItem(row, 3, new QTableWidgetItem(ende));

}

void SuchergebnisDialog::addPassagierEntry(int nummer, QString name, QString beginn, QString ende){
    auto table = ui->tableWidgetPassagier;
    int row = table->rowCount();

    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem(QString::number(nummer)));
    table->setItem(row, 1, new QTableWidgetItem(name));
    table->setItem(row, 2, new QTableWidgetItem(beginn));
    table->setItem(row, 3, new QTableWidgetItem(ende));

}


void SuchergebnisDialog::setPassagierName(QString name){
    ui->lineEditPassagierName->setText(name);
}
