#include "command.h"
#include "ui_command.h"
#include <QMessageBox>

COMMAND::COMMAND(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::COMMAND)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Hairul Hafiq/Documents/enemyatkdefpos/Pic/command.jpg");
    ui->labelback->setPixmap(pix);
    Login conn;

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery *qry2 = new QSqlQuery(conn.csmsDB);
    qry2->prepare("SELECT fullname from users where privilage = 1 ");
    qry2->exec();
    modal->setQuery(*qry2);
    ui->comboBox->setModel(modal);

    QSqlQueryModel * modal1 = new QSqlQueryModel();
    QSqlQuery *q = new QSqlQuery(conn.csmsDB);
    q->prepare("SELECT fullname from users where privilage = 2 ");
    q->exec();
    modal1->setQuery(*q);
    ui->comboBox_2->setModel(modal1);
}

COMMAND::~COMMAND()
{
    delete ui;
}

void COMMAND::on_logoutbutton_clicked()
{
    this->hide();
    Login back;
    back.setModal(true);
    back.exec();
}

void COMMAND::on_pushButton_clicked()
{
    Login conn;
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open database";
        return;
    }


    if (ui->radioButton->isCheckable()){

                QMessageBox msgBox;
                msgBox.setText("Task have been submitted for recce process!");
                msgBox.exec();
                ui->radioButton->setEnabled(false);
                ui->radioButton_2->setEnabled(false);
                ui->radioButton_3->setEnabled(false);
                ui->comboBox->setEnabled(false);

    }
    else if (ui->radioButton_2->isCheckable()){
                QMessageBox msgBox;
                msgBox.setText("Task have been submitted for recce process!");
                msgBox.exec();
                ui->radioButton->setEnabled(false);
                ui->radioButton_2->setEnabled(false);
                ui->radioButton_3->setEnabled(false);
                ui->comboBox->setEnabled(false);

    }
    else{
        QMessageBox msgBox;
                msgBox.setText("Task have been submitted for recce process!");
                msgBox.exec();
                ui->radioButton->setEnabled(false);
                ui->radioButton_2->setEnabled(false);
                ui->radioButton_3->setEnabled(false);
                ui->comboBox->setEnabled(false);
    }


}

void COMMAND::on_pushButton_2_clicked()
{
    this->hide();
    varification front;
    front.setModal(true);
    front.exec();
}
