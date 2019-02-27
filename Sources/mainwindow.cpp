#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<book_student.h>
#include<QTableWidget>
#include<QSqlQuery>
#include<QSqlRecord>
#include<QDebug>
#include<QMessageBox>
#include<QStandardItemModel>
#include<QTableView>
#include<QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("图书管理系统主窗口");
    ui->PAlineEdit->setEchoMode(QLineEdit::Password);

    MainWindow::student=new book_student(this);
    MainWindow::administrator=new book_administrator(this);
    MainWindow::superadministrator=new book_super_administrator(this);
    MainWindow::brw=new Book_Borrow(this);
    //MainWindow::rsw=new Reserve;


    ui->book_search->setPlaceholderText("请输入书名");
    ui->tableWidget->setRowCount(100);     //设置行数为10
    ui->tableWidget->setColumnCount(4);   //设置列数为5
    ui->tableWidget->setColumnWidth(1,200);
    ui->tableWidget->setColumnWidth(2,200);
    QStringList header;
    header<<"Book_No"<<"Book_Name"<<"Book_Author"<<"Book_number";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    QSqlQuery query;
    query.exec("select * from book");
    int k=-1;
    while(query.next()){
        ++k;
        for(int i=0;i<4;++i)ui->tableWidget->setItem(k,i,new QTableWidgetItem(query.value(i).toString()));

    }
    //The Sign out
   /* connect(student->Signout,SIGNAL(clicked()),this,SLOT(reshow()));
    connect(administrator->Signout,SIGNAL(clicked()),this,SLOT(reshow()));
    connect(superadministrator->Signout,SIGNAL(clicked()),this,SLOT(reshow()));*/

    //Student's borrow
    connect(student->Borrowed,SIGNAL(clicked()),this,SLOT(create()));


    //admini's book manage
    //connect(administrator->)

    //connect(brw,SIGNAL(sendData(QString)),this,SLOT(receiveData(QString)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username=ui->IDlineEdit->text();
    QString userpassword=ui->PAlineEdit->text();
    QSqlQuery query;
    MainWindow::u=username;
    if(ui->radioButton->isChecked()){//student
        query.prepare("select PASSWORD from student where ID=:ll");
        query.bindValue(":ll",username);
        query.exec();
        query.first();
        QString password=query.value(0).toString();
        if(password==userpassword){
            student->exec();
            ui->IDlineEdit->clear();
            ui->PAlineEdit->clear();
        }else{
            QMessageBox::warning(this,"错误","用户名或密码错误！","确定");
        }
    }
    else if(ui->radioButton_2->isChecked()){//administrator
        query.prepare("select PASSWORD from administrator where ID=:ll");
        query.bindValue(":ll",username);
        query.exec();
        query.first();
        QString password=query.value(0).toString();
        if(password==userpassword){
            administrator->exec();
            ui->IDlineEdit->clear();
            ui->PAlineEdit->clear();
        }else{
           QMessageBox::warning(this,"错误","用户名或密码错误！","确定");
        }
    }
    else if(ui->radioButton_3->isChecked()){//superadministrator
        query.prepare("select PASSWORD from superadministrator where ID=:ll");
        query.bindValue(":ll",username);
        query.exec();
        query.first();
        QString password=query.value(0).toString();
        if(password==userpassword){
            superadministrator->exec();
            ui->IDlineEdit->clear();
            ui->PAlineEdit->clear();
        }else{
            QMessageBox::warning(this,"错误","用户名或密码错误！","确定");
        }
    }
}
void MainWindow::on_search_button_clicked()
{
    QString book_name=ui->book_search->text();
    QSqlQuery query;
    /*if(book_name.length()==0){QMessageBox::warning(this,"错误","请输入书名！","确定");return;}*/
    ui->tableWidget->clearContents();
    query.prepare("select * from book where bname like :ll");
    query.bindValue(":ll","%"+book_name+"%");//模糊查询
    query.exec();
    int k=-1;
    while(query.next()){
        ++k;
        for(int i=0;i<4;++i)ui->tableWidget->setItem(k,i,new QTableWidgetItem(query.value(i).toString()));
    }
    ui->book_search->clear();
}
void MainWindow::reshow(){
    this->show();
}
void MainWindow::create(){
    QSqlQuery query;
    QStandardItemModel *model=new QStandardItemModel();
    //brw->table=new QTableView();
    model->setColumnCount(1);
    model->setHeaderData(0,Qt::Horizontal,"book_name");
    query.prepare("select bname from book where bno in (select bno from book_borrow where ID=:ll)");
    query.bindValue(":ll",MainWindow::u);
    query.exec();
    int k=-1;
    while(query.next()){
        ++k;
        model->setItem(k,new QStandardItem(query.value(0).toString()));
    }
    brw->table->setModel(model);
    brw->table->setColumnWidth(0,200);
    brw->setWindowTitle("您已借");
    brw->exec();
}
/*void MainWindow::receiveData(QString data){
    ui->lineEdit->setText(data);
}
*/
