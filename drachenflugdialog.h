
#ifndef DRACHENFLUGDIALOG_H
#define DRACHENFLUGDIALOG_H

#include <QDialog>
#include "drachenflug.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class DrachenflugDialog;
}
QT_END_NAMESPACE

class DrachenflugDialog : public QDialog
{
    Q_OBJECT

public:
    DrachenflugDialog(Drachenflug* flug, QWidget *parent = nullptr);
    ~DrachenflugDialog();

private slots:
    void accept() override;

private:
    Ui::DrachenflugDialog *ui;
    Drachenflug* pFlug;

    void ladeDaten();
    void speichereDaten();
};

#endif // DRACHENFLUGDIALOG_H
