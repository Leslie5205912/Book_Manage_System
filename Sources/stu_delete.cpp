#include "stu_delete.h"
#include "ui_stu_delete.h"
#include<QSqlQuery>
#include<QMessageBox>
Stu_Delete::Stu_Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stu_Delete)
{
    ui->setupUi(this);
    this->setWindowTitle("学生删除");
}

Stu_Delete::~Stu_Delete()
{
    delete ui;
}

void Stu_Delete::on_pushButton_clicked()
{
    if(!ui->lineEdit->text().length()){
        QMessageBox::warning(this,"错误！","请输入学生编号！");
    }
    QSqlQuery query;
    query.prepare("delete from student where ID=:ll");
    query.bindValue(":ll",ui->lineEdit->text());
    query.exec();
    QMessageBox::information(this,"恭喜！","删除成功！");
    ui->lineEdit->clear();
}
