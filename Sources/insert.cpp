#include "insert.h"
#include "ui_insert.h"
#include<QMessageBox>
#include<QSqlQuery>
Insert::Insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Insert)
{
    ui->setupUi(this);
}

Insert::~Insert()
{
    delete ui;
}

void Insert::on_pushButton_clicked()
{
    if(!(ui->Book_ID->text().length()&&ui->Book_Name->text().length()&&ui->Book_Author->text().length()&&ui->Book_number->text().length())){
        QMessageBox::warning(this,"错误！","请勿空输入！");
        return;
    }
    QSqlQuery query;
    query.prepare("insert into book values(:hh,:jj,:kk,:ll)");
    query.bindValue(":hh",ui->Book_ID->text());
    query.bindValue(":jj",ui->Book_Name->text());
    query.bindValue(":kk",ui->Book_Author->text());
    query.bindValue(":ll",ui->Book_number->text().toInt());
    query.exec();
    QMessageBox::information(this,"恭喜！","插入书籍信息成功！");
}
