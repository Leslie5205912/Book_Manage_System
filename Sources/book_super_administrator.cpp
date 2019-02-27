#include "book_super_administrator.h"
#include "ui_book_super_administrator.h"

book_super_administrator::book_super_administrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_super_administrator)
{
    ui->setupUi(this);
    this->setWindowTitle("超级管理员");
    this->Signout=ui->pushButton;
    book_super_administrator::ade=new Admini_Delete();
    book_super_administrator::ait=new Adimi_Insert();
    book_super_administrator::sde=new Stu_Delete();
    book_super_administrator::sit=new Stu_Insert();
}

book_super_administrator::~book_super_administrator()
{
    delete ui;
}

void book_super_administrator::on_pushButton_clicked()//Sign Out
{
    this->close();
}

void book_super_administrator::on_pushButton_2_clicked()//管理员删除
{

    ade->exec();
}

void book_super_administrator::on_pushButton_3_clicked()//管理员添加
{
    ait->exec();
}

void book_super_administrator::on_pushButton_4_clicked()//学生删除
{
    sde->exec();
}

void book_super_administrator::on_pushButton_5_clicked()//学生添加
{
    sit->exec();
}
