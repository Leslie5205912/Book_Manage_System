#include "mainwindow.h"
#include <QApplication>
#include<QSqlDatabase>
#include "book_student.h"
#include<QMessageBox>
#include<QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTextCodec>
bool creatConnect();
QString MainWindow::u;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    creatConnect();
    MainWindow w;
    w.show();
    return a.exec();
}
bool creatConnect()
{
    QSqlDatabase db= QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("library");
    db.setUserName("root");
    db.setPassword("123456");

    bool ok = db.open();//建立数据库连接
    if(!ok)
    {
        QMessageBox::critical(0,QObject::tr("连接数据库失败！！！"),db.lastError().text());
        return false;
    }
    else
    {
        QMessageBox::information(0,QObject::tr("Tips"),QObject::tr("连接数据库成功！！！"));
        return true;
    }
}
