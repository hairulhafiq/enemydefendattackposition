#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Hairul Hafiq/Documents/enemyatkdefpos/Pic/back.jpg");
    ui->labelback->setPixmap(pix);

    if(!connOpen())
          ui->labelStatus_2->setText("Failed to connect to Database");

        else
          ui->labelStatus_2->setText("Database is connected!!");

}

Login::~Login()
{
    delete ui;
}


void Login::on_loginbutton_clicked()
{
    QString username, password;
    username = ui->lineEditUsername->text();
    password = ui->lineEditPassword->text();

    QSqlQuery qry1,qry2,qry3,qry4,qry5;
        qry1.prepare("select * from users where usrname ='"+username+"'and password ='"+password+"'and privilage = '0'");
        qry2.prepare("select * from users where usrname ='"+username+"'and password ='"+password+"'and privilage = '1'");
        qry3.prepare("select * from users where usrname ='"+username+"'and password ='"+password+"'and privilage = '2'");

        if(qry1.exec())
        {
            int count = 0;
            while(qry1.next())
            {
                count++;
            }

            if(count ==1)
            {
               ui->labelStatus_2->setText("username and password is correct");
               connClose();
               this ->hide();
               COMMAND options;
               options.setModal(true);
               options.exec();
            }
            else if(count >1)
                ui->labelStatus_2->setText("duplicate username and password");

            else if(count <1)
                ui->labelStatus_2->setText("username and password is not correct");

        }

        if(qry2.exec())
        {
            int count = 0;
            while(qry2.next())
            {
                count++;
            }

            if(count ==1)
            {
                    connClose();
                    this ->hide();
                    RECCE options;
                    options.setModal(true);
                    options.exec();

            }
            else if(count >1)
                ui->labelStatus_2->setText ("duplicate username and password");

            else if(count <1)
                ui->labelStatus_2->setText ("username and password is not correct");
        }

        if(qry3.exec())
        {
            int count = 0;
            while(qry3.next())
            {
                count++;
            }

            if(count ==1)
            {
               ui->labelStatus_2->setText("username and password is correct");
               connClose();
               this ->hide();
               SOLUTION options;
               options.setModal(true);
               options.exec();
            }
            else if(count >1)
                ui->labelStatus_2->setText ("duplicate username and password");

            else if(count <1)
                ui->labelStatus_2->setText ("username and password is not correct");
        }
        ui ->lineEditUsername ->clear();
        ui ->lineEditPassword->clear();
}
