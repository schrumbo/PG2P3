
#include "drachenflugdialog.h"
#include "ui_drachenflugdialog.h"
#include <QDate>

DrachenflugDialog::DrachenflugDialog(Drachenflug* flug, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrachenflugDialog),
    pFlug(flug)
{
    ui->setupUi(this);
    ladeDaten();

    // Verbinde OK/Cancel
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &DrachenflugDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &DrachenflugDialog::reject);
}

DrachenflugDialog::~DrachenflugDialog()
{
    delete ui;
}

void DrachenflugDialog::ladeDaten()
{
    if (!pFlug) return;

    // Felder mit bestehenden Werten füllen
    ui->lineEditZiel->setText(QString::fromStdString(pFlug->getZiel()));
    ui->doubleSpinBoxPreis->setValue(pFlug->getPreis());
    ui->doubleSpinBoxEntfernung->setValue(pFlug->getEntfernung());

    // Datum parsen und setzen (falls Format "YYYY-MM-DD" verwendet wird)
    // Annahme: getAbfahrt() und getAnkunft() liefern Strings im Format "YYYY-MM-DD"
    QString abfahrtStr = QString::fromStdString(pFlug->getAbfahrt());
    QString ankunftStr = QString::fromStdString(pFlug->getAnkunft());

    ui->lineEditAbfahrt->setText(abfahrtStr);
    ui->lineEditAnkunft->setText(ankunftStr);

}

void DrachenflugDialog::speichereDaten()
{
    if (!pFlug) return;

    // Änderungen ins Originalobjekt zurückschreiben
    pFlug->setZiel(ui->lineEditZiel->text().toStdString());
    //pFlug->setPreis(ui->doubleSpinBoxPreis->value());
    pFlug->setEntfernung(ui->doubleSpinBoxEntfernung->value());

    // Datum zurück in String-Format konvertieren
    QString abfahrtStr = ui->lineEditAbfahrt->displayText();
    QString ankunftStr = ui->lineEditAnkunft->displayText();

    //pFlug->setAbfahrt(abfahrtStr.toStdString());
    //pFlug->setAnkunft(ankunftStr.toStdString());
}

// Diese Methode wird im accept()-Slot aufgerufen
void DrachenflugDialog::accept()
{
    speichereDaten();
    QDialog::accept();
}
