#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"book_student.h"
#include"book_administrator.h"
#include"book_super_administrator.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include"book_Borrow.h"
#include"reserve.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static QString u;
private slots:
    void on_pushButton_clicked();
    void on_search_button_clicked();
    void reshow();
    void create();
   // void receiveData(QString data);
private:
    Ui::MainWindow *ui;
    book_student *student;
    book_administrator *administrator;
    book_super_administrator *superadministrator;
    Book_Borrow *brw;
    Reserve *rsw;
};

#endif // MAINWINDOW_H
