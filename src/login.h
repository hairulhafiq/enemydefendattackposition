#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include "command.h"
#include "recce.h"
#include "solution.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

    QSqlDatabase csmsDB;
    void connClose()
        {
            csmsDB.close();
            csmsDB.removeDatabase(QSqlDatabase::defaultConnection);
        }

        bool connOpen()
        {
            csmsDB = QSqlDatabase::addDatabase("QSQLITE");
            csmsDB.setDatabaseName("D:/git/enemydefendattackposition/src/enemy");   //depends on your directory


            if(!csmsDB.open()){
               qDebug()<<("Failed to connect to Database");
                return false;
            }
            else{
                qDebug()<<("Connected!!");
                return true;
            }
        }
private slots:
        void on_loginbutton_clicked();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
