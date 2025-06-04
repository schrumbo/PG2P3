#include "suchergebnisdialog.h"
#include "ui_suchergebnisdialog.h"

SuchergebnisDialog::SuchergebnisDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SuchergebnisDialog)
{
    ui->setupUi(this);
}

SuchergebnisDialog::~SuchergebnisDialog()
{
    delete ui;
}
