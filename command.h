#ifndef COMMAND_H
#define COMMAND_H

#include <QDialog>
#include "login.h"
#include <QtSql>
#include <QFileInfo>
#include "varification.h"

namespace Ui {
class COMMAND;
}

class COMMAND : public QDialog
{
    Q_OBJECT

public:
    explicit COMMAND(QWidget *parent = nullptr);
    ~COMMAND();


private slots:
    void on_logoutbutton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::COMMAND *ui;
};

#endif // COMMAND_H
