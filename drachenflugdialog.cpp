
#include "drachenflugdialog.h"
#include "ui_drachenflugdialog.h"
#include <QDate>


//TODO: daten müssen gespeichert werden + weitere setter in drachenflug für preis usw hinzufügen!



DrachenflugDialog::DrachenflugDialog(Drachenflug* flug, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrachenflugDialog),
    pFlug(flug)
{
    ui->setupUi(this);
    ladeDaten();

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

    ui->lineEditZiel->setText(QString::fromStdString(pFlug->getZiel()));
    ui->doubleSpinBoxPreis->setValue(pFlug->getPreis());
    ui->doubleSpinBoxEntfernung->setValue(pFlug->getEntfernung());

    QString abfahrtStr = QString::fromStdString(pFlug->getAbfahrt());
    QString ankunftStr = QString::fromStdString(pFlug->getAnkunft());

    ui->lineEditAbfahrt->setText(abfahrtStr);
    ui->lineEditAnkunft->setText(ankunftStr);

}

void DrachenflugDialog::speichereDaten()
{
    if (!pFlug) return;

    pFlug->setZiel(ui->lineEditZiel->text().toStdString());
    pFlug->setEntfernung(ui->doubleSpinBoxEntfernung->value());

    QString abfahrtStr = ui->lineEditAbfahrt->displayText();
    QString ankunftStr = ui->lineEditAnkunft->displayText();

}

void DrachenflugDialog::accept()
{
    speichereDaten();
    QDialog::accept();
}
