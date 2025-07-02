#include "nachtlagerdialog.h"
#include "ui_nachtlagerdialog.h"

NachtlagerDialog::NachtlagerDialog(Nachtlager* lager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NachtlagerDialog),
    pLager(lager)
{
    ui->setupUi(this);

    ladeDaten();



    // Verbinde OK/Cancel
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &NachtlagerDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &NachtlagerDialog::reject);
}

NachtlagerDialog::~NachtlagerDialog()
{
    delete ui;
}


void NachtlagerDialog::ladeDaten()
{
    if (!pLager) return;

    // Felder mit bestehenden Werten füllen
    ui->lineEditOrt->setText(QString::fromStdString(pLager->getLagerOrt()));
    ui->lineEditAbfahrt->setText(QString::fromStdString(pLager->getAbfahrt()));
    ui->lineEditAnkunft->setText(QString::fromStdString(pLager->getAnkunft()));
    ui->doubleSpinBoxPreis->setValue(pLager->getPreis());
    ui->doubleSpinBoxRuhelevel->setValue(pLager->getRuheLevel());

    // Unterkunftstyp vorauswählen
    QString unterkunft = QString::fromStdString(pLager->getUnterkunftsTyp());
    int index = ui->comboBoxUnterkunft->findText(unterkunft);
    if (index >= 0)
        ui->comboBoxUnterkunft->setCurrentIndex(index);

}


void NachtlagerDialog::speichereDaten()
{
    if (!pLager) return;

    // Änderungen ins Originalobjekt zurückschreiben
    pLager->setLagerOrt(ui->lineEditOrt->text().toStdString());
    pLager->setAbfahrt(ui->lineEditAbfahrt->text().toStdString());
    pLager->setAnkunft(ui->lineEditAnkunft->text().toStdString());
    pLager->setPreis(ui->doubleSpinBoxPreis->value());
    pLager->setRuheLevel(ui->doubleSpinBoxRuhelevel->value());
    pLager->setUnterkunftsTyp(ui->comboBoxUnterkunft->currentText().toStdString());
}


// Diese Methode wird im accept()-Slot aufgerufen
void NachtlagerDialog::accept()
{
    speichereDaten();
    QDialog::accept();
}
