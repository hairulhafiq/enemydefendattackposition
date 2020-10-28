#include "secondpage.h"
#include "ui_secondpage.h"

secondpage::secondpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondpage)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Hairul Hafiq/Documents/enemyatkdefpos/Pic/verify.jpg");
    ui->labelback->setPixmap(pix);
}

secondpage::~secondpage()
{
    delete ui;
}
