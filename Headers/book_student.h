#ifndef BOOK_STUDENT_H
#define BOOK_STUDENT_H
#include<QTableView>
#include<QPushButton>
#include <QDialog>
#include"reserve.h"
namespace Ui {
class book_student;
}

class book_student : public QDialog
{
    Q_OBJECT

public:
    explicit book_student(QWidget *parent = nullptr);
    ~book_student();
    QPushButton *Signout;
    QPushButton *Borrowed;
    QPushButton *reserve;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::book_student *ui;
    QTableView *table;
    Reserve *rsw;
};

#endif // BOOK_STUDENT_H
