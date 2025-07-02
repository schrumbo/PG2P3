#include "mainwindow.h"
#include "drachenart.h"
#include "drachenflug.h"
#include "nachtlager.h"
#include "SuchergebnisDialog.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QFileDialog>
#include "QDateEdit"
#include "QDialogButtonBox"

// Konstruktor
MainWindow::MainWindow(Filmstudio* f, QWidget* parent) : QMainWindow(parent), studio(f), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fillDrachenListe();

/*
    // Signal-Slot-Verbindungen nicht notwendig, wenn Bennenung regelkonform (on_<Buttonname>_clicked), diese
    // ... werden automatisch intern über das Signal-Slot-System von Qt (per MOC = Meta-Object Compiler) aufgelöst
    connect(ui->drachenListWidget, &QListWidget::itemClicked, this, &MainWindow::on_drachenListWidget_itemClicked);
    connect(ui->flugListWidget, &QListWidget::itemClicked, this, &MainWindow::on_flugListWidget_itemClicked);

    // Signal-Slot-Verbindungen sind auch nicht bei Buttons notwendig, wenn Bennenung regelkonform --> MOC
    connect(ui->addDracheButton, &QPushButton::clicked, this, &MainWindow::on_addDracheButton_clicked);
    connect(ui->addDrachenflugButton, &QPushButton::clicked, this, &MainWindow::on_addDrachenflugButton_clicked);
    connect(ui->addPassengerButton, &QPushButton::clicked, this, &MainWindow::on_addPassengerButton_clicked);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);
*/
}

// Destruktor
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillDrachenListe() {
    ui->drachenListWidget->clear();
    for (Drache* d : studio->getDrachenListe()) {
        ui->drachenListWidget->addItem(QString::fromStdString(d->getDrachenName()));
    }
}

void MainWindow::showDrachenDetails(Drache* drache) {
    std::stringstream ss;
    ss << "Name: " << drache->getDrachenName() << "\n"
       << "Player: " << drache->getMeinPlayer() << "\n"
       << "Art: " << drache->getDrachenArt() << "\n"
       << "Geschwindigkeit: " << drache->getGeschwindigkeit() << "\n"
       << "Ausdauer: " << drache->getAusdauer() << "\n"
       << "Erholung: " << drache->getErholung() << "\n"
       << "Preis: " << drache->getDrachenPreis();
    ui->detailTextEdit->setPlainText(QString::fromStdString(ss.str()));
}

void MainWindow::showReiseplaene(Drache* drache) {
    ui->reisePlanListWidget->clear();
    for (Reiseplan* plan : drache->getReiseplaene()) {
        ui->reisePlanListWidget->addItem(QString::fromStdString(plan->getName()));
    }
}

void MainWindow::showDrachenreisen(Reiseplan* plan) {
    ui->reiseListWidget->clear();
    for (Drachenreise* abschnitt : plan->getReiseabschnitte()) {
        ui->reiseListWidget->addItem(QString::number(abschnitt->getReiseNummer()));
    }
}


void MainWindow::showDrachenreiseDetails(Drachenreise* reise) {
    ui->reiseDetailsListWidget->clear();
    QStringList reiseDetails;

    reiseDetails << QString("Reisenummer: %1").arg(reise->getReiseNummer());
    reiseDetails << QString("Abfahrt: %1").arg(QString::fromStdString(reise->getAbfahrt()));
    reiseDetails << QString("Ankunft: %1").arg(QString::fromStdString(reise->getAnkunft()));

    // Spezifische Attribute je nach Typ
    if (Drachenflug* flug = dynamic_cast<Drachenflug*>(reise)) {
        reiseDetails << QString("Flugnummer: %1").arg(flug->getFlugNummer());
        reiseDetails << QString("Ziel: %1").arg(QString::fromStdString(flug->getZiel()));
        reiseDetails << QString("Entfernung: %1 km").arg(flug->getEntfernung());
    }
    else if (Nachtlager* lager = dynamic_cast<Nachtlager*>(reise)) {
        reiseDetails << QString("Lager-ID: %1").arg(lager->getLagerID());
        reiseDetails << QString("Ort: %1").arg(QString::fromStdString(lager->getLagerOrt()));
        reiseDetails << QString("Unterkunft: %1").arg(QString::fromStdString(lager->getUnterkunftsTyp()));
        reiseDetails << QString("Ruhelevel: %1").arg(lager->getRuheLevel());
        reiseDetails << QString("Preis: %1 €").arg(lager->getPreis());
    }

    reiseDetails << "Passagiere:";
    for (const QString& detail : reiseDetails) {
        ui->reiseDetailsListWidget->addItem(detail);
    }

    if (reise->getReiseplan()) {
        for (const std::string& name : reise->getReiseplan()->getPassagiere()) {
            ui->reiseDetailsListWidget->addItem(QString::fromStdString(name));
        }
    }
}

void MainWindow::on_drachenListWidget_itemClicked(QListWidgetItem* item) {
    std::string name = item->text().toStdString();
    Drache* drache = studio->sucheDrache(name);
    if (drache) {
        showDrachenDetails(drache);
        showReiseplaene(drache);
        ui->reiseListWidget->clear();
        ui->reiseDetailsListWidget->clear();
    }
}

void MainWindow::on_reisePlanListWidget_itemClicked(QListWidgetItem* item) {
    QListWidgetItem* dracheItem = ui->drachenListWidget->currentItem();
    if (!dracheItem || !item) return;

    Drache* drache = studio->sucheDrache(dracheItem->text().toStdString());
    if (!drache) return;

    Reiseplan* plan = drache->findeReiseplan(item->text().toStdString());
    if (!plan) return;

    showDrachenreisen(plan);
    ui->reiseDetailsListWidget->clear();
}

void MainWindow::on_reiseListWidget_itemClicked(QListWidgetItem* item) {
    QListWidgetItem* dracheItem = ui->drachenListWidget->currentItem();
    QListWidgetItem* planItem = ui->reisePlanListWidget->currentItem();
    if (!dracheItem || !planItem || !item) return;

    Drache* drache = studio->sucheDrache(dracheItem->text().toStdString());
    Reiseplan* plan = drache->findeReiseplan(planItem->text().toStdString());
    if (!plan) return;

    int nummer = item->text().toInt();
    for (Drachenreise* r : plan->getReiseabschnitte()) {
        if (r->getReiseNummer() == nummer) {
            showDrachenreiseDetails(r);
            break;
        }
    }
}

void MainWindow::on_addDracheButton_clicked() {
    // 1. Name abfragen
    QString name = QInputDialog::getText(this, "Neuer Drache", "Name des Drachen:");
    if (name.isEmpty()) return;

    // 2. Player abfragen
    QString player = QInputDialog::getText(this, "Spielername", "Name des Spielers:");
    if (player.isEmpty()) return;

    // 3. Art auswählen
    QStringList arten = {"Nachtschatten", "Tagschatten", "ToedlicherNadder", "Skrill"};
    QString art = QInputDialog::getItem(this, "Art auswählen", "Drachenart:", arten, 0, false);

    // ***** 4. Drache erzeugen: Aufgabe 8: Konstruktor mit zwei Parametern anpassen *****
    Drache* neuerDrache = nullptr;
    if (art == "Nachtschatten") neuerDrache = new Nachtschatten(name.toStdString(), player.toStdString());
    else if (art == "Tagschatten") neuerDrache = new Tagschatten(name.toStdString(), player.toStdString());
    else if (art == "ToedlicherNadder") neuerDrache = new ToedlicherNadder(name.toStdString(), player.toStdString());
    else if (art == "Skrill") neuerDrache = new Skrill(name.toStdString(), player.toStdString());

    // 5. Aufgabe 8: diese setter-Aufrufe sollen hier ersetzt werden
    //neuerDrache->setDrachenName(name.toStdString());
    //neuerDrache->setMeinPlayer(player.toStdString());

    // 6. Drache hinzufügen
    studio->addDrache(neuerDrache);
    fillDrachenListe();
}

void MainWindow::on_addReiseplanButton_clicked() {
    QListWidgetItem* selectedItem = ui->drachenListWidget->currentItem();
    if (!selectedItem) return;

    Drache* drache = studio->sucheDrache(selectedItem->text().toStdString());
    if (!drache) return;

    drache->addReiseplan(new Reiseplan());
    showReiseplaene(drache);
}

void MainWindow::on_addDrachenreiseButton_clicked() {
    QListWidgetItem* dracheItem = ui->drachenListWidget->currentItem();
    QListWidgetItem* planItem = ui->reisePlanListWidget->currentItem();
    if (!dracheItem || !planItem){
        QMessageBox::warning(this, "Fehler", "Bitte vorher einen Drachen auswählen");
        return;
    }

    Drache* drache = studio->sucheDrache(dracheItem->text().toStdString());
    Reiseplan* plan = drache->findeReiseplan(planItem->text().toStdString());
    if (!plan) return;

    QString abfahrt = frageDatum("Abfahrt", "Bitte Abfahrtsdatum wählen: ", QDate::currentDate());
    QString ankunft = frageDatum("Ankunft", "Bitte Ankunftsdatum wählen: ", QDate::currentDate());
    if (abfahrt.isEmpty() || ankunft.isEmpty()) return;

    QStringList arten = {"Drachenflug", "Nachtlager"};
    QString art = QInputDialog::getItem(this, "Typ auswählen", "Reisetyp:", arten, 0, false);

    Drachenreise* reise = nullptr;
    if (art == "Drachenflug") {
        QString ziel = QInputDialog::getText(this, "Flug", "Ziel:");
        double entfernung = QInputDialog::getDouble(this, "Flug", "Entfernung (km):", 100.0, 0.0);
        reise = new Drachenflug(abfahrt.toStdString(), ankunft.toStdString(), ziel.toStdString(), entfernung);
    } else {
        QString ort = QInputDialog::getText(this, "Nachtlager", "Ort:");
        QStringList typen = {"Bergplateau", "Höhle", "Baumkrone"};
        QString typ = QInputDialog::getItem(this, "Typ", "Unterkunftstyp:", typen, 0, false);
        int ruhe = QInputDialog::getInt(this, "Nachtlager", "Ruhelevel:", 5, 1, 10);
        double preis = QInputDialog::getDouble(this, "Nachtlager", "Preis:", 100.0, 0.0);
        reise = new Nachtlager(abfahrt.toStdString(), ankunft.toStdString(), preis, ort.toStdString(), typ.toStdString(), ruhe);
    }

    if (reise) {
        plan->addReise(reise);
        showDrachenreisen(plan);
    }
}


void MainWindow::on_addPassengerButton_clicked() {
    QListWidgetItem* flugItem = ui->reiseListWidget->currentItem();

    if (!flugItem) {
        QMessageBox::warning(this, "Keine Drachenreise ausgewählt",
                             "Bitte zuerst eine Drachenreise auswählen");
        return;
    }

    QString name = QInputDialog::getText(this, "Passagier hinzufügen", "Name des Passagiers:");
    if (name.isEmpty()) return;

    int reiseNummer = flugItem->text().toInt();
    Drachenreise* reise = studio->getDrachenreise(reiseNummer);
    if (!reise) return;

    // Zugriff auf Reiseplan:
    if (reise->getReiseplan()) {
        reise->getReiseplan()->addPassagier(name.toStdString());
        showDrachenreiseDetails(reise);
    }
}

void MainWindow::on_saveButton_clicked() {
    QString fileName = QFileDialog::getSaveFileName(this, "Daten speichern", "", "JSON Dateien (*.json)");
    if (!fileName.isEmpty()) {
        studio->speichernJSON(fileName.toStdString());
        QMessageBox::information(this, "Gespeichert", "Die Daten wurden erfolgreich gespeichert.");
    }
    else
        QMessageBox::warning(this, "Speichern abgebrochen", "Dateiname wurde nicht angegeben.");
}

void MainWindow::on_actionBeenden_triggered()
{
    close();
}


void MainWindow::on_actionSpeichern_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Daten speichern", "", "JSON Dateien (*.json)");
    if (!fileName.isEmpty()) {
        studio->speichernJSON(fileName.toStdString());
        QMessageBox::information(this, "Gespeichert", "Die Daten wurden erfolgreich gespeichert.");
    }
    else
        QMessageBox::warning(this, "Speichern abgebrochen", "Dateiname wurde nicht angegeben.");
}


void MainWindow::on_actionEinlesen_triggered()
{
    clearWidgets();

    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("JSON-Datei öffnen"),
        "",
        tr("JSON-Dateien (*.json);;Alle Dateien (*)")
        );

    if (!fileName.isEmpty()) {
        try {
            studio->einlesenJSON(fileName.toStdString());
        } catch (const std::exception &e) {
            QMessageBox::warning(
                this,
                tr("Fehler beim Einlesen"),
                tr("Die Datei konnte nicht gelesen werden:\n%1").arg(e.what())
                );
        }
    }

    fillDrachenListe();
}


void MainWindow::on_actionDrache_L_schen_triggered()
{
    QListWidgetItem* drachenItem = ui->drachenListWidget->currentItem();
    if (!drachenItem) {
        QMessageBox::warning(this, "Kein Drache ausgewählt", "Bitte zuerst einen Drachen auswählen");
        return;
    }

    if(QMessageBox::question(this, "Drache löschen", "Drache wirklich löschen?") != QMessageBox::Yes){
        return;
    }
    bool deleted = studio->loescheDrache(drachenItem->text().toStdString());
    if(!deleted){
        QMessageBox::warning(this, "Fehler", "Löschen fehlgeschlagen");
        return;
    }
    clearWidgets();
    studio->loescheDrache(drachenItem->text().toStdString());
    fillDrachenListe();
    QMessageBox::information(this, "Erfolg", "Drache gelöscht");
    return;
}


void MainWindow::on_actionReiseplan_L_schen_triggered()
{
    QListWidgetItem* drachenItem = ui->drachenListWidget->currentItem();
    QListWidgetItem* reiseplanItem = ui->reisePlanListWidget->currentItem();

    if(!drachenItem){
        QMessageBox::warning(this, "Kein Drache ausgewählt", "Bitte zuerst einen Drachen auswählen");
        return;
    }
    if(!reiseplanItem){
        QMessageBox::warning(this, "Kein Reiseplan ausgewählt", "Bitte zuerst einen Reiseplan auswählen");
        return;
    }

    auto drache = studio->sucheDrache(drachenItem->text().toStdString());

    if(QMessageBox::question(this, "Plan löschen", "Plan wirklich löschen?") != QMessageBox::Yes){
        return;
    }

    bool deleted = drache->loescheReiseplan(reiseplanItem->text().toStdString());

    if(!deleted){
        QMessageBox::warning(this, "Fehler", "Löschen fehlgeschlagen");
        return;
    }

    drache->loescheReiseplan(reiseplanItem->text().toStdString());
    ui->reisePlanListWidget->clear();
    ui->reiseListWidget->clear();
    ui->reiseDetailsListWidget->clear();
    fillDrachenListe();

    QMessageBox::information(this, "Erfolg", "Reiseplan gelöscht");
    return;
}


void MainWindow::on_actionDrachenreise_L_schen_triggered()
{
    QListWidgetItem* drachenItem = ui->drachenListWidget->currentItem();
    QListWidgetItem* reiseplanItem = ui->reisePlanListWidget->currentItem();
    QListWidgetItem* reiseItem = ui->reiseListWidget->currentItem();
    if(!drachenItem || !reiseplanItem || !reiseItem){
        QMessageBox::warning(this, "Keine Reise", "Bitte zuerst eine Reise auswählen");
        return;
    }

    auto drache = studio->sucheDrache(drachenItem->text().toStdString());
    auto reiseplan = drache->findeReiseplan(reiseplanItem->text().toStdString());

    if(QMessageBox::question(this, "Reise", "Reise wirklich löschen?") != QMessageBox::Yes){
        return;
    }
    bool deleted = reiseplan->loescheDrachenreise(reiseItem->text().toInt());

    if(!deleted){
        QMessageBox::warning(this, "Fehler", "Löschen fehlgeschlagen");
        return;
    }

    reiseplan->loescheDrachenreise(reiseItem->text().toInt());

    ui->reiseListWidget->clear();
    ui->reiseDetailsListWidget->clear();
    fillDrachenListe();

    QMessageBox::information(this, "Erfolg", "Reiseplan gelöscht");
    return;
}


void MainWindow::on_actionPassagier_L_schen_triggered()
{
    QListWidgetItem* drachenItem = ui->drachenListWidget->currentItem();
    QListWidgetItem* reiseplanItem = ui->reisePlanListWidget->currentItem();
    QListWidgetItem* reiseItem = ui->reiseListWidget->currentItem();
    QListWidgetItem* passagierItem = ui->reiseDetailsListWidget->currentItem();
    if(!drachenItem || !reiseplanItem || !reiseItem || !passagierItem){
        QMessageBox::warning(this, "Keine Passagier", "Bitte zuerst einen Passagier auswählen");
        return;
    }

    auto drache = studio->sucheDrache(drachenItem->text().toStdString());
    auto reiseplan = drache->findeReiseplan(reiseplanItem->text().toStdString());

    if(QMessageBox::question(this, "Passagier", "Passagier wirklich löschen?") != QMessageBox::Yes){
        return;
    }

    bool deleted = reiseplan->loeschePassagier(passagierItem->text().toStdString());

    if(!deleted){
        QMessageBox::warning(this, "Fehler", "Löschen fehlgeschlagen");
        return;
    }

    reiseplan->loeschePassagier(passagierItem->text().toStdString());

    ui->reiseDetailsListWidget->clear();
    QMessageBox::information(this, "Erfolg", "Passagier gelöscht");
    return;


}

//Hilfsmethode (ist arsch)
void MainWindow::clearWidgets(){
    ui->reiseDetailsListWidget->clear();
    ui->reiseListWidget->clear();
    ui->reisePlanListWidget->clear();
    ui->detailTextEdit->clear();
}

QString MainWindow::frageDatum(const QString& titel, const QString& label, const QDate& defaultDate) {
    QDialog dialog(this);
    dialog.setWindowTitle(titel);

    QVBoxLayout layout(&dialog);

    QLabel info(label);
    layout.addWidget(&info);

    QDateEdit dateEdit;
    dateEdit.setCalendarPopup(true);
    dateEdit.setDate(defaultDate);
    layout.addWidget(&dateEdit);

    QDialogButtonBox buttons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    layout.addWidget(&buttons);

    connect(&buttons, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        return dateEdit.date().toString("dd.MM.yyyy"); // Format anpassen
    }

    return ""; // oder QString(), wenn abgebrochen wurde
}




void MainWindow::on_actionPassagierSuchen_triggered()
{
    QString person = QInputDialog::getText(this, "Suche", "Name der gesuchten Person");
    if(person.isEmpty())return;

    std::vector<ReiseInfo> alsPlayer = studio->findeReiseplaeneAlsPlayer(person.toStdString());
    std::vector<ReiseInfo> alsPassagier = studio->findeReiseplaeneAlsPassagier(person.toStdString());

    auto* dialog = new SuchergebnisDialog(studio, this);

    for(const auto& info: alsPlayer){
        dialog->addPlayerEntry(
            info.nummer,
            QString::fromStdString(info.name),
            QString::fromStdString(info.beginn),
            QString::fromStdString(info.ende),
            info.preis
            );
    }

    for(const auto& info: alsPassagier){
        dialog->addPassagierEntry(
            info.nummer,
            QString::fromStdString(info.name),
            QString::fromStdString(info.beginn),
            QString::fromStdString(info.ende),
            info.preis
            );
    }

    dialog->setPassagierName(person);

    dialog->exec();
}

