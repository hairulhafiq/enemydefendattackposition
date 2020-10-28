#include "solution.h"
#include "ui_solution.h"
#include <QMessageBox>

SOLUTION::SOLUTION(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SOLUTION)
{
    Login conn;
    ui->setupUi(this);
    QPixmap pix("D:/git/enemyatkdefpos/Pic/solution.jpg");
    ui->labelback->setPixmap(pix);

    QSqlQueryModel * modal1 = new QSqlQueryModel();
    QSqlQuery *q = new QSqlQuery(conn.csmsDB);
    q->prepare("SELECT ID from recce");
    q->exec();
    modal1->setQuery(*q);
    ui->comboBox->setModel(modal1);
}

SOLUTION::~SOLUTION()
{
    delete ui;
}

void SOLUTION::on_logoutbutton_clicked()
{
    this->hide();
    Login back;
    back.setModal(true);
    back.exec();
}

void SOLUTION::on_pushButton_clicked()
{
    Login conn;

    QSqlQuery qry,qry1,qry2,qry3,qry4,qry5,qry6,qry7;
    QString id,location,strength,exit,task,type,start,tactic,solution;
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

    if(task == "DESTROY"){
        solution = "Destroy everything in territory";
    }
    else if (task == "NEUTRALIZE"){
        solution = "Dissable everything in territory";
    }
    else if (task == "CLEAR"){
        solution = "Expel everything in enemy territory";
    }

    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery *qry8 = new QSqlQuery(conn.csmsDB);
    qry8->prepare("SELECT weapon1,weapon1_num,weapon2,weapon2_num,weapon3,weapon3_num,weapon4,weapon4_num,weapon5,weapon5_num,weapon6,weapon6_num,weapon7,weapon7_num from recce where ID = '"+id+"'");
    qry8->exec();
    modal->setQuery(*qry8);
    ui->tableView_3->setModel(modal);

    QSqlQueryModel * modal1 = new QSqlQueryModel();
    QSqlQuery *q = new QSqlQuery(conn.csmsDB);
    q->prepare("SELECT obstacle1,obstacle_location1,obstacle2,obstacle_location2,obstacle3,obstacle_location3,obstacle4,obstacle_location4,obstacle5,obstacle_location5,obstacle6,obstacle_location6 from recce where ID = '"+id+"'");
    q->exec();
    modal1->setQuery(*q);
    ui->tableView_4->setModel(modal1);

  ui->lineEditlocation_2 -> setText("north 100 degree");
  ui->lineEditstrength_2->setText("company");
  ui->lineEditexit_2->setText("yes");
  ui->lineEdittask_2->setText("DESTROY");
  ui->lineEditstart_2->setText("sitting weapon and obstacle.");
  ui->lineEdittype_2->setText("class2");
  ui->lineEdittactic_2->setText("delibrate attack");
}


void SOLUTION::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("DELIBRATE ATTACK because the order from high command is to DESTROY enemy with the strength of a COMPANY. ");
    msgBox.exec();
}
