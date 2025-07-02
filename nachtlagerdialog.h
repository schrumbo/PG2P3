#ifndef NACHTLAGERDIALOG_H
#define NACHTLAGERDIALOG_H

#include <QDialog>
#include "nachtlager.h"

namespace Ui {
class NachtlagerDialog;
}

class NachtlagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NachtlagerDialog(Nachtlager* lager, QWidget *parent = nullptr);
    ~NachtlagerDialog();

private:
    Ui::NachtlagerDialog *ui;
    Nachtlager* pLager;

    void ladeDaten();
    void speichereDaten();

private slots:
    void accept() override;  // Wird bei OK gedrückt aufgerufen
};

#endif // NACHTLAGERDIALOG_H
