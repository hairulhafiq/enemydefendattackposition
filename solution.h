#ifndef SOLUTION_H
#define SOLUTION_H

#include <QDialog>
#include "login.h"

namespace Ui {
class SOLUTION;
}

class SOLUTION : public QDialog
{
    Q_OBJECT

public:
    explicit SOLUTION(QWidget *parent = nullptr);
    ~SOLUTION();

private slots:
    void on_logoutbutton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SOLUTION *ui;
};

#endif // SOLUTION_H
