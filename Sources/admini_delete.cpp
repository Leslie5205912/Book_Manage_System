#include "admini_delete.h"
#include "ui_admini_delete.h"
#include<QSqlQuery>
#include<QMessageBox>
Admini_Delete::Admini_Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admini_Delete)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员删除");
}

Admini_Delete::~Admini_Delete()
{
    delete ui;
}

void Admini_Delete::on_pushButton_clicked()
{
    if(!ui->lineEdit->text().length()){
        QMessageBox::warning(this,"错误！","请输入管理员编号！");
        return;
    }
    QSqlQuery query;
    query.prepare("delete from administrator where ID=:ll");
    query.bindValue(":ll",ui->lineEdit->text());
    query.exec();
    QMessageBox::information(this,"恭喜！","信息删除成功!");
    ui->lineEdit->clear();
}
