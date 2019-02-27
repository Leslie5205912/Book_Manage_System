#ifndef CHOOSE_H
#define CHOOSE_H

#include <QDialog>
#include<insert.h>
#include<book_delete.h>
namespace Ui {
class Choose;
}

class Choose : public QDialog
{
    Q_OBJECT

public:
    explicit Choose(QWidget *parent = nullptr);
    ~Choose();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Choose *ui;
    Insert *ist;
    Book_Delete *dlt;
};

#endif // CHOOSE_H
