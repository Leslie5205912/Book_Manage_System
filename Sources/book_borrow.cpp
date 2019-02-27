#include "book_borrow.h"
#include "ui_book_borrow.h"

Book_Borrow::Book_Borrow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Book_Borrow)
{
    ui->setupUi(this);
    this->table=ui->tableView;
    //connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(buttonBox_accepted()));
}


Book_Borrow::~Book_Borrow()
{
    delete ui;
}
/*void Book_Borrow::on_pushButton_clicked()
{

}
void Book_Borrow::buttonBox_accepted(){
    emit sendData(ui->lineEdit->text());
}*/
