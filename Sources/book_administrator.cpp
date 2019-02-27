#include "book_administrator.h"
#include "ui_book_administrator.h"
#include<QTableView>
#include<QStandardItemModel>
#include<QSqlQuery>
#include<QDebug>
book_administrator::book_administrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::book_administrator)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员");
    this->Signout=ui->pushButton;
    this->book_rsw=ui->pushButton_3;//预约情况
    this->book_brw=ui->pushButton_2;//借还情况
    book_administrator::brw=new Book_Borrow();
    book_administrator::jiehuan=new Book_Borrow();
    book_administrator::chose=new Choose();
}

book_administrator::~book_administrator()
{
    delete ui;
}

void book_administrator::on_pushButton_clicked()//Sign Out
{
    this->close();
}

void book_administrator::on_pushButton_3_clicked()//学生预约
{
   //book_administrator::brw->table=new QTableView;
    QStandardItemModel *model=new QStandardItemModel();
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,"Book_No");
    model->setHeaderData(1,Qt::Horizontal,"Student_ID");
    
    QSqlQuery query;
    query.exec("select * from reserve");
    int k=-1;
    while(query.next()){
        ++k;
        for(int i=0;i<2;++i)model->setItem(k,i,new QStandardItem(query.value(i).toString()));
    }
    book_administrator::brw->table->setModel(model);
    book_administrator::brw->setWindowTitle("学生预约情况");
    book_administrator::brw->exec();
}

void book_administrator::on_pushButton_4_clicked()//学生借还
{
    QStandardItemModel *model=new QStandardItemModel();
    model->setColumnCount(2);
    model->setHeaderData(0,Qt::Horizontal,"ID");
    model->setHeaderData(1,Qt::Horizontal,"Book_No");
    QSqlQuery query;
    query.exec("select * from book_borrow");
    int k=-1;
    while(query.next()){
        ++k;
        for(int i=0;i<2;++i)model->setItem(k,i,new QStandardItem(query.value(i).toString()));
    }
    book_administrator::jiehuan->table->setModel(model);
    book_administrator::jiehuan->setWindowTitle("学生借还情况");
    book_administrator::jiehuan->exec();
}

void book_administrator::on_pushButton_2_clicked()
{
    chose->setWindowTitle("请选择您要进行的操作");
    chose->exec();
}
