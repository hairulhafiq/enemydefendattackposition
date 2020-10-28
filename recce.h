#ifndef RECCE_H
#define RECCE_H

#include <QDialog>
#include "login.h"

namespace Ui {
class RECCE;
}

class RECCE : public QDialog
{
    Q_OBJECT

public:
    explicit RECCE(QWidget *parent = nullptr);
    ~RECCE();

private slots:
    void on_logoutbutton_clicked();

    void on_pushButton_clicked();

private:
    Ui::RECCE *ui;
};

#endif // RECCE_H
