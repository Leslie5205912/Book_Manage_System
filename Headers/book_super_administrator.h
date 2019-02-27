#ifndef BOOK_SUPER_ADMINISTRATOR_H
#define BOOK_SUPER_ADMINISTRATOR_H

#include <QDialog>
#include<QPushButton>
#include<admini_delete.h>
#include<adimi_insert.h>
#include<stu_delete.h>
#include<stu_insert.h>
namespace Ui {
class book_super_administrator;
}

class book_super_administrator : public QDialog
{
    Q_OBJECT

public:
    explicit book_super_administrator(QWidget *parent = nullptr);
    ~book_super_administrator();

    QPushButton *Signout;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::book_super_administrator *ui;
    Admini_Delete *ade;
    Adimi_Insert *ait;
    Stu_Delete *sde;
    Stu_Insert *sit;
};

#endif // BOOK_SUPER_ADMINISTRATOR_H
