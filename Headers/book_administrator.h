#ifndef BOOK_ADMINISTRATOR_H
#define BOOK_ADMINISTRATOR_H

#include <QDialog>
#include<QPushButton>
#include"book_borrow.h"
#include"choose.h"
namespace Ui {
class book_administrator;
}

class book_administrator : public QDialog
{
    Q_OBJECT

public:
    explicit book_administrator(QWidget *parent = nullptr);
    ~book_administrator();

    QPushButton *Signout;
    QPushButton *book_rsw;
    QPushButton *book_brw;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::book_administrator *ui;
    Book_Borrow *brw;
    Book_Borrow *jiehuan;
    Choose *chose;
};

#endif // BOOK_ADMINISTRATOR_H
