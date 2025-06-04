#ifndef SUCHERGEBNISDIALOG_H
#define SUCHERGEBNISDIALOG_H

#include <QDialog>

namespace Ui {
class SuchergebnisDialog;
}

class SuchergebnisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SuchergebnisDialog(QWidget *parent = nullptr);
    ~SuchergebnisDialog();

private:
    Ui::SuchergebnisDialog *ui;
};

#endif // SUCHERGEBNISDIALOG_H
