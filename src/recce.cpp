#include "recce.h"
#include "ui_recce.h"
#include <QMessageBox>

RECCE::RECCE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RECCE)
{
    ui->setupUi(this);
    QPixmap pix("D:/git/enemyatkdefpos/Pic/recce.jpg");
    ui->labelback->setPixmap(pix);
    int bigNo, smallNo;

    bigNo = 1000;
    smallNo = 0;

    int randomValue = qrand() % ((bigNo +1) - smallNo)+ smallNo;

    ui->lineEditID->setText("RF" + QString::number(randomValue));
}

RECCE::~RECCE()
{
    delete ui;
}

void RECCE::on_logoutbutton_clicked()
{
    this->hide();
    Login back;
    back.setModal(true);
    back.exec();
}

void RECCE::on_pushButton_clicked()
{
    Login conn;
    if(!conn.connOpen())
    {
        qDebug()<<"Failed to open database";
        return;
    }

    QString ID,
            en_location,
            en_strength,
            weapon1,
            weapon2,
            weapon3,
            weapon4,
            weapon5,
            weapon6,
            weapon7,
            weapon1_type,
            weapon2_type,
            weapon3_type,
            weapon4_type,
            weapon5_type,
            weapon6_type,
            weapon7_type,
            weapon1_num,
            weapon2_num,
            weapon3_num,
            weapon4_num,
            weapon5_num,
            weapon6_num,
            weapon7_num,
            weapon_location1,
            weapon_location2,
            weapon_location3,
            weapon_location4,
            weapon_location5,
            weapon_location6,
            weapon_location7,
            obstacle1,
            obstacle2,
            obstacle3,
            obstacle4,
            obstacle5,
            obstacle6,
            obstacle1_type,
            obstacle2_type,
            obstacle3_type,
            obstacle4_type,
            obstacle5_type,
            obstacle6_type,
            obstacle_location1,
            obstacle_location2,
            obstacle_location3,
            obstacle_location4,
            obstacle_location5,
            obstacle_location6,
            solution1,
            solution2,
            solution3,
            solution4,
            solution5,
            solution6,
            solution7,
            solution8,
            solution9,
            solution10,
            solution11,
            solution12,
            solution13,
            road,
            road_wide,
            road_type,
            cannopy,
            exit_route,
            task;
    if (ui->radioButton->isCheckable()){
        task = "DESTROY";
    }
    else if (ui->radioButton_2->isCheckable()){
        task = "NEUTRALIZE";
    }
    else{
        task = "CLEAR";
    }
    ID = ui -> lineEditID ->text();
    en_location = ui -> lineEditlocation -> text();
    en_strength = ui ->lineEditstrength -> text();

    if (en_strength >= 0 && en_strength <=30){
        en_strength = "platun";
    } else if (en_strength> 30 && en_strength <=102){
        en_strength = "company";
    }
    else{
        en_strength = "battalion";
    }

    if(ui->checkBoxGPMG->isChecked() ){
        //set in database weapon_category rifle
        weapon1= "GPMG";
        weapon1_type = "rifle";
        weapon_location1 = ui ->lineEditlocationgpmg ->text();
        weapon1_num = ui->lineEditweaponnumber1->text();
        if(weapon1_num <= 10){
           //solution is to low bomb
           solution1 = "low";
           //bomb location
        }
        else if (weapon1_num >=11 && weapon1_num <=25 ){
            //solution is to medium bomb
            solution1 = "Medium";
            //bomb location
        }
        else{
            //solution is to massive bomb
            solution1 = "massive";
            //bomb location
        }

    }else{
        weapon1 = "nun";
        weapon1_num ="nun";
        weapon1_type = "nun";
        weapon_location1= "nun";
        solution1 = "nun";
    }
    if(ui->checkBoxAR15->isChecked()){
        //set in database weapon_category rifle
        weapon2= "AR15";
        weapon2_type = "rifle";
        weapon_location2 = ui ->lineEditlocationar15 ->text();
        weapon2_num = ui->lineEditweaponnumber2->text();
        if(weapon2_num <= 10){
           //solution is to low bomb
           solution2 = "low";
           //bomb location
        }
        else if (weapon2_num >=11 && weapon2_num <=25 ){
            //solution is to medium bomb
            solution2 = "Medium";
            //bomb location
        }
        else{
            //solution is to massive bomb
            solution2 = "massive";
            //bomb location
        }
    }else{
        weapon2 = "nun";
        weapon2_num ="nun";
        weapon2_type = "nun";
        weapon_location2= "nun";
        solution2 = "nun";
    }
    if (ui->checkBoxHMG->isChecked()){
        //set in database weapon_category rifle
        weapon3= "HMG";
        weapon3_type = "rifle";
        weapon_location3 = ui ->lineEditlocationhmg ->text();
        weapon3_num = ui->lineEditweaponnumber3->text();
        if(weapon3_num <= 10){
           //solution is to low bomb
           solution3 = "low";
           //bomb location
        }
        else if (weapon3_num >=11 && weapon3_num <=25 ){
            //solution is to medium bomb
            solution3 = "Medium";
            //bomb location
        }
        else{
            //solution is to massive bomb
            solution3 = "massive";
            //bomb location
        }
    }else{
        weapon3 = "nun";
        weapon3_num = "nun";
        weapon3_type = "nun";
        weapon_location3= "nun";
        solution3 = "nun";
    }
    if(ui->checkBoxrpg->isChecked()){
        //weapon category grenade
        weapon4= "IP Motar";
        weapon4_type = "grenade";
        weapon_location4 = ui ->lineEditlocationrpg ->text();
        weapon4_num = ui->lineEditweaponnumber4->text();
        if(weapon4_num <= 10){
           //solution is to low bomb
           solution4 = "low";
           //bomb location
        }
        else if (weapon4_num >=11 && weapon4_num <=25 ){
            //solution is to medium bomb
            solution4 = "Medium";
            //bomb location
        }
        else{
            //solution is to massive bomb
            solution4 = "massive";
            //bomb location
        }
    }else{
        weapon4 = "nun";
        weapon4_num = "nun";
        weapon4_type = "nun";
        weapon_location4= "nun";
        solution4 = "nun";
    }
    if(ui->checkBoxmotar->isChecked()){
        //weapon category grenade
        weapon5= "IP Motar";
        weapon5_type = "grenade";
        weapon_location5 = ui ->lineEditlocationmotar ->text();
        weapon5_num = ui->lineEditweaponnumber5->text();
        if(weapon5_num <= 10){
           //solution is to low bomb
           solution5 = "low";
           //bomb location
        }
        else if (weapon5_num >=11 && weapon5_num <=25 ){
            //solution is to medium bomb
            solution5 = "Medium";
            //bomb location
        }
        else{
            //solution is to massive bomb
            solution5 = "massive";
            //bomb location
        }
    }else{
        weapon5 = "nun";
        weapon5_num = "nun";
        weapon5_type = "nun";
        weapon_location5= "nun";
        solution5 = "nun";
    }
    if(ui->checkBoxM202->isChecked()){
        //weapon category anti tank
        weapon6= "M136 AT4";
        weapon6_type = "anti tank";
        weapon_location6 = ui ->lineEditlocationm202 ->text();
        weapon6_num = ui->lineEditweaponnumber6->text();
        if(weapon6_num <= 10){
           //solution is to low bomb
           solution6 = "low";
           //bomb location
        }
        else if (weapon6_num >=11 && weapon6_num <=25 ){
            //solution is to medium bomb
            solution6 = "Medium";
            //bomb location
        }
        else{
            //solution is to massive bomb
            solution6 = "massive";
            //bomb location
        }
    }else{
        weapon6 = "nun";
        weapon6_num = "nun";
        weapon6_type = "nun";
        weapon_location6= "nun";
        solution6 = "nun";
    }

    QString direction7;

    if(ui->checkBoxm136->isChecked()){
        //weapon category anti tank
        weapon7= "M136 AT4";
        weapon7_type = "anti tank";
        weapon_location7 = ui ->lineEditlocationm136 ->text();
        weapon7_num = ui->lineEditweaponnumber7->text();
        if(weapon7_num <= 10){
           //solution is to low bomb
           solution7 = "low";
           direction7 = weapon_location7;
           //bomb location
        }
        else if (weapon7_num >=11 && weapon7_num <=25 ){
            //solution is to medium bomb
            solution7 = "Medium";
            direction7 = weapon_location7;
            //bomb location
        }
        else{
            //solution is to massive bomb
            solution7 = "massive";
            direction7 = weapon_location7;
            //bomb location
        }
    }else{
        weapon7 = "nun";
        weapon7_num = "nun";
        weapon7_type = "nun";
        weapon_location7= "nun";
        solution7 = "nun";
    }

    if(ui->checkBoxbooby->isChecked()){
        //set in database weapon_category rifle
        obstacle1="boobby traps";
        obstacle1_type = "man made";
        obstacle_location1 = ui-> lineEditlocationbooby->text();
        solution8 = "bomb";
        //bomb location
    }else{
        obstacle1 = "nun";
        obstacle1_type = "nun";
        obstacle_location1= "nun";
        solution8 = "nun";
    }
    if (ui->checkBoxwire->isChecked()){
        //set in database obstacle_category
        obstacle2="Corsertina wire";
        obstacle2_type = "man made";
        obstacle_location2 = ui-> lineEditlocationwire->text();
        solution9 = "bomb";
        //bomb location
    }else{
        obstacle2 = "nun";
        obstacle2_type = "nun";
        obstacle_location2= "nun";
        solution9 = "nun";
    }
    if(ui->checkBoxhill->isChecked()){
        //set in database obstacle_category
        obstacle3 = "hill";
        obstacle3_type = "natural";
        obstacle_location3 = ui-> lineEditlocationhill->text();
        solution10 = "avoid";
        //avoid location
    }else{
        obstacle3 = "nun";
        obstacle3_type = "nun";
        obstacle_location3= "nun";
        solution10 = "nun";
    }
    if(ui->checkBoxtree->isChecked()){
        //set in database weapon_category rifle
        obstacle4= "tree";
        obstacle4_type = "natural";
        obstacle_location4 = ui-> lineEditlocationtree->text();
        solution11 = "avoid";
        //avoid location
    }else{
        obstacle4 = "nun";
        obstacle4_type = "nun";
        obstacle_location4= "nun";
        solution11 = "nun";
    }
    if(ui->checkBoxlog->isChecked()){
        //set in database weapon_category rifle
        obstacle5 = "logs";
        obstacle5_type = "natural";
        obstacle_location5 = ui-> lineEditlocationlog->text();
        solution12 = "avoid";
        //avoid location
    }else{
        obstacle5 = "nun";
        obstacle5_type = "nun";
        obstacle_location5= "nun";
        solution12 = "nun";
    }
    if (ui->checkBoxswamp->isChecked()){
        //set in database weapon_category rifle
        obstacle6 = "swamp";
        obstacle6_type = "natural";
        obstacle_location6 = ui-> lineEditlocationswamp->text();
        solution13 = "avoid";
        //avoid location
    }else{
        obstacle6 = "nun";
        obstacle6_type = "nun";
        obstacle_location6= "nun";
        solution13 = "nun";
    }
    if (ui->checkBoxroad->isChecked() ){
        road = "yes";
        road_wide = ui -> lineEditroad -> text();

        if (road_wide <= 100){
            road_type = "narrow";
        }else{
            road_type ="wide";
        }
        if(ui->checkBoxcannopy->isChecked()){
             exit_route = "yes";
        }else{
            exit_route = "yes";
        }
    }else{
        if(ui->checkBoxcannopy->isChecked()){
            exit_route = "yes";
        }else{
            exit_route = "no";
        }
    }

    QSqlQuery qry;
    qry.prepare("INSERT INTO recce(ID,en_location,en_strength,weapon1,weapon2,weapon3,weapon4,weapon5,weapon6,weapon7,weapon1_type, weapon2_type,weapon3_type,weapon4_type,weapon5_type,weapon6_type,weapon7_type,weapon1_num,weapon2_num,weapon3_num,weapon4_num,weapon5_num,weapon6_num,weapon7_num,weapon_location1,weapon_location2,weapon_location3,weapon_location4,weapon_location5,weapon_location6,weapon_location7,obstacle1,obstacle2,obstacle3,obstacle4,obstacle5,obstacle6,obstacle1_type,obstacle2_type,obstacle3_type,obstacle4_type,obstacle5_type,obstacle6_type,obstacle_location1,obstacle_location2,obstacle_location3,obstacle_location4,obstacle_location5,obstacle_location6,solution1,solution2,solution3,solution4,solution5,solution6,solution7,solution8,solution9,solution10,solution11,solution12,solution13,road,road_wide,road_type,cannopy,exit_route,task,process) "
             "values ('"+ID+"','"+en_location+"','"+en_strength+"','"+weapon1+"','"+weapon2+"','"+weapon3+"','"+weapon4+"','"+weapon5+"','"+weapon6+"','"+weapon7+"','"+weapon1_type+"','"+weapon2_type+"','"+weapon3_type+"','"+weapon4_type+"','"+weapon5_type+"','"+weapon6_type+"','"+weapon7_type+"','"+weapon1_num+"','"+weapon2_num+"','"+weapon3_num+"','"+weapon4_num+"','"+weapon5_num+"','"+weapon6_num+"','"+weapon7_num+"','"+weapon_location1+"','"+weapon_location2+"','"+weapon_location3+"','"+weapon_location4+"','"+weapon_location5+"','"+weapon_location6+"','"+weapon_location7+"','"+obstacle1+"','"+obstacle2+"','"+obstacle3+"','"+obstacle4+"','"+obstacle5+"','"+obstacle6+"','"+obstacle1_type+"','"+obstacle2_type+"','"+obstacle3_type+"','"+obstacle4_type+"','"+obstacle5_type+"','"+obstacle6_type+"','"+obstacle_location1+"','"+obstacle_location2+"','"+obstacle_location3+"','"+obstacle_location4+"','"+obstacle_location5+"','"+obstacle_location6+"','"+solution1+"','"+solution2+"','"+solution3+"','"+solution4+"','"+solution5+"','"+solution6+"','"+solution7+"','"+solution8+"','"+solution9+"','"+solution10+"','"+solution11+"','"+solution12+"','"+solution13+"','"+road+"','"+road_wide+"','"+road_type+"','"+cannopy+"','"+exit_route+"','"+task+"', 'processing')");
    if(qry.exec()){
        QMessageBox msgBox;
        msgBox.setText("Recce form submitted!");
        msgBox.exec();
    }else {
        QMessageBox msgBox;
        msgBox.setText("Failed to upload");
        msgBox.exec();
    }
}
