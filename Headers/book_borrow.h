#ifndef BOOK_BORROW_H
#define BOOK_BORROW_H

#include <QDialog>
#include<QTableView>
#include<QString>
namespace Ui {
class Book_Borrow;
}

class Book_Borrow : public QDialog
{
    Q_OBJECT

public:
    explicit Book_Borrow(QWidget *parent = nullptr);
    ~Book_Borrow();

    QTableView *table;
private slots:
    //void on_pushButton_clicked();

private:
    Ui::Book_Borrow *ui;

signals:
    void sendData(QString);
private slots:
    //void buttonBox_accepted();
};

#endif // BOOK_BORROW_H
