#include "choose.h"
#include "ui_choose.h"
#include<QMessageBox>
Choose::Choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choose)
{
    ui->setupUi(this);
    Choose::ist=new Insert();
    Choose::dlt=new Book_Delete();
}

Choose::~Choose()
{
    delete ui;
}

void Choose::on_pushButton_clicked()
{
    ist->setWindowTitle("请填入相关信息");
    ist->exec();
}

void Choose::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"注意！","删除书籍同时会删除学生的预约和借阅信息！");
    dlt->setWindowTitle("请输入要删除的图书编号");
    dlt->line->setPlaceholderText("请输入Book_No");
    dlt->exec();
}
