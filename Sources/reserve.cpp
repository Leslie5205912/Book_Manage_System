#include "reserve.h"
#include "ui_reserve.h"
#include<QString>
#include<QSqlQuery>
#include<QMessageBox>
#include<mainwindow.h>
Reserve::Reserve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reserve)
{
    ui->setupUi(this);
    this->setWindowTitle("预约书籍");
    ui->book_search->setPlaceholderText("请输入书名");
    ui->resline->setPlaceholderText("请输入Book_No");
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
}

Reserve::~Reserve()
{
    delete ui;
}

void Reserve::on_pushButton_clicked()
{
    QString book_name=ui->book_search->text();
    QSqlQuery query;
    if(book_name.length()==0){QMessageBox::warning(this,"错误","请输入书名！","确定");return;}
    ui->tableWidget->clearContents();
    query.prepare("select * from book where bname like :ll");
    query.bindValue(":ll","%"+book_name+"%");//模糊查询
    query.exec();
    int k=-1;
    while(query.next()){
        ++k;
        for(int i=0;i<4;++i)ui->tableWidget->setItem(k,i,new QTableWidgetItem(query.value(i).toString()));
    }
}

void Reserve::on_pushButton_2_clicked()
{
    QString book_No=ui->resline->text();
    QSqlQuery query;
    if(book_No.length()==0){QMessageBox::warning(this,"错误","请输入Book_No！","确定");return;}
    query.prepare("select bnum from book where bno=:ll");
    query.bindValue(":ll",book_No);
    query.exec();
    query.first();
    int val=query.value(0).toInt();
    if(val){
        QMessageBox::information(this,QString("恭喜！"),QString("您已预约成功，请在24小时之内入图书馆借阅！"));
        query.prepare("update book set bnum =bnum-1 where bno=:ll");
        query.bindValue(":ll",book_No);
        query.exec();
        query.prepare("insert into reserve values (:ll,:kk)");
        query.bindValue(":kk",MainWindow::u);
        query.bindValue(":ll",book_No);
        query.exec();
    }else{
        QMessageBox::warning(this,QString("Sorry!"),QString("本书不存在或库存为空"));
    }
}
