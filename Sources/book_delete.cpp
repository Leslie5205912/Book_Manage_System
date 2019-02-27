#include "book_delete.h"
#include "ui_book_delete.h"
#include<QSqlQuery>
#include<QMessageBox>
Book_Delete::Book_Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Book_Delete)
{
    ui->setupUi(this);
    this->line=ui->lineEdit;
}

Book_Delete::~Book_Delete()
{
    delete ui;
}

void Book_Delete::on_pushButton_clicked()
{
    if(!ui->lineEdit->text().length()){
        QMessageBox::warning(this,"错误！","请输入Book_No!");
        return;
    }
    QSqlQuery query;
    query.prepare("delete from book where bno=:ll");
    query.bindValue(":ll",ui->lineEdit->text());
    query.exec();
    QMessageBox::information(this,"恭喜！","书籍信息及相关信息删除成功！");
}
