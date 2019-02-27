#include "adimi_insert.h"
#include "ui_adimi_insert.h"
#include<QSqlQuery>
#include<QMessageBox>
Adimi_Insert::Adimi_Insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adimi_Insert)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员添加");
}

Adimi_Insert::~Adimi_Insert()
{
    delete ui;
}

void Adimi_Insert::on_pushButton_clicked()
{
    if(!(ui->lineEdit->text().length()&&ui->lineEdit_2->text().length())){
        QMessageBox::warning(this,"错误！","请填入信息！");
        return;
    }
    QSqlQuery query;
    query.prepare("insert into administrator values(:kk,:ll)");
    query.bindValue(":kk",ui->lineEdit->text());
    query.bindValue(":ll",ui->lineEdit_2->text());
    query.exec();
    QMessageBox::information(this,"恭喜！","插入成功！");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}
