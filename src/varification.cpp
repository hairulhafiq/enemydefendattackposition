#include "varification.h"
#include "ui_varification.h"
#include "QMessageBox"

varification::varification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::varification)
{
    ui->setupUi(this);
    QPixmap pix("D:/git/enemyatkdefpos/Pic/verify.jpg");   //depends on your directory
    ui->labelback->setPixmap(pix);
    Login conn;
    QSqlQueryModel * modal1 = new QSqlQueryModel();
    QSqlQuery *q = new QSqlQuery(conn.csmsDB);
    q->prepare("SELECT ID from recce");
    q->exec();
    modal1->setQuery(*q);
    ui->comboBox->setModel(modal1);
}

varification::~varification()
{
    delete ui;
}

void varification::on_pushButton_2_clicked()
{
    Login conn;
    QString id;
    id = ui->comboBox->currentText();
    QSqlQuery qry1;
    qry1.prepare("update recce set process = 'verify' where ID = '"+id+"'");

    if(qry1.exec()){
        QMessageBox msgBox;
        msgBox.setText("Recce has been verified!");
        msgBox.exec();
    }else {
        QMessageBox msgBox;
        msgBox.setText("Failed to upload");
        msgBox.exec();
    }
}

void varification::on_pushButton_3_clicked()
{
    this ->hide();
    COMMAND options;
    options.setModal(true);
    options.exec();
}

void varification::on_pushButton_clicked()
{
    Login conn;

    QSqlQuery qry,qry1,qry2,qry3,qry4,qry5,qry6,qry7;
    QString id,location,strength,exit,task,type,start,tactic;
    id = ui->comboBox->currentText();
    location = qry.exec("select en_location from recce where ID = '"+id+"'");
    strength = qry2.exec("select en_strength from recce where ID = '"+id+"'");
    exit = qry3.exec("select exit_route from recce where ID = '"+id+"'");
    task = qry4.exec("select task from recce where ID = '"+id+"'");

    if (strength == "battalion"){
        type = "class3";
        start = "siting weapon, obstacle and exit route.";
        if(task == "DESTROY"){
            tactic = "delibrate attack";
        }
        else if (task == "NEUTRALIZE"){
            tactic = "delibrate attack";
        }
        else if (task == "CLEAR"){
            tactic = "delibrate attack";
        }
    }
    else if(strength == "company"){
        type = "class2";
        start = "sitting weapon and obstacle.";
        if(task == "DESTROY"){
            tactic = "delibrate attack";
        }
        else if (task == "NEUTRALIZE"){
            tactic = "delibrate attack";
        }
        else if (task == "CLEAR"){
            tactic = "quick attack";
        }
    }
    else if(strength == "platun"){
        type = "class1";
        start = "sitting weapon.";
        if(task == "DESTROY"){
            tactic = "delibrate attack";
        }
        else if (task == "NEUTRALIZE"){
            tactic = "quick attack";
        }
        else if (task == "CLEAR"){
            tactic = "quick attack";
        }
    }
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery *qry8 = new QSqlQuery(conn.csmsDB);
    qry8->prepare("SELECT weapon1,weapon1_num,weapon2,weapon2_num,weapon3,weapon3_num,weapon4,weapon4_num,weapon5,weapon5_num,weapon6,weapon6_num,weapon7,weapon7_num from recce where ID = '"+id+"'");
    qry8->exec();
    modal->setQuery(*qry8);
    ui->tableView->setModel(modal);

    QSqlQueryModel * modal1 = new QSqlQueryModel();
    QSqlQuery *q = new QSqlQuery(conn.csmsDB);
    q->prepare("SELECT obstacle1,obstacle_location1,obstacle2,obstacle_location2,obstacle3,obstacle_location3,obstacle4,obstacle_location4,obstacle5,obstacle_location5,obstacle6,obstacle_location6 from recce where ID = '"+id+"'");
    q->exec();
    modal1->setQuery(*q);
    ui->tableView_2->setModel(modal1);

  ui->lineEditlocation -> setText("north 100 degree");
  ui->lineEditstrength->setText("company");
  ui->lineEditexit->setText("yes");
  ui->lineEdittask->setText("DESTROY");
  ui->lineEditstart->setText("sitting weapon and obstacle.");
  ui->lineEdittype->setText("class2");
  ui->lineEdittactic->setText("delibrate attack");
}
