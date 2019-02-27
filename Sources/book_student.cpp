#include "book_student.h"
#include "ui_book_student.h"
#include<QMessageBox>
#include"mainwindow.h"
#include<QTableView>
#include<QStandardItemModel>
#include<QDebug>
#include<QString>
book_student::book_student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_student)
{
    ui->setupUi(this);
    book_student::rsw=new Reserve(this);
    this->setWindowTitle("学生");
    this->Signout=ui->pushButton;
    this->Borrowed=ui->pushButton_3;
    this->reserve=ui->pushButton_2;
}

book_student::~book_student()
{
    delete ui;
}
void book_student::on_pushButton_clicked()//sign out
{
    this->close();
}

void book_student::on_pushButton_3_clicked()//borrowed
{

}

void book_student::on_pushButton_2_clicked()//reserve
{
    rsw->exec();
}
