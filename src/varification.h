#ifndef VARIFICATION_H
#define VARIFICATION_H

#include <QDialog>
#include "command.h"
#include "login.h"
namespace Ui {
class varification;
}

class varification : public QDialog
{
    Q_OBJECT

public:
    explicit varification(QWidget *parent = nullptr);
    ~varification();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::varification *ui;
};

#endif // VARIFICATION_H
