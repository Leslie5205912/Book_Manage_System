#include "stu_insert.h"
#include "ui_stu_insert.h"
#include<QSqlQuery>
#include<QMessageBox>
Stu_Insert::Stu_Insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stu_Insert)
{
    ui->setupUi(this);
    this->setWindowTitle("学生添加");
}

Stu_Insert::~Stu_Insert()
{
    delete ui;
}

void Stu_Insert::on_pushButton_clicked()
{
    if(!(ui->lineEdit->text().length()&&ui->lineEdit_2->text().length())){
        QMessageBox::warning(this,"错误！","请输入信息！");
        return;
    }
    QSqlQuery query;
    query.prepare("insert into student values(:kk,:ll)");
    query.bindValue(":kk",ui->lineEdit->text());
    query.bindValue(":ll",ui->lineEdit_2->text());
    query.exec();
    QMessageBox::information(this,"恭喜！","插入成功！");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}
