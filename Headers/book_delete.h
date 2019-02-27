#ifndef BOOK_DELETE_H
#define BOOK_DELETE_H

#include <QDialog>
#include<QLineEdit>
namespace Ui {
class Book_Delete;
}

class Book_Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Book_Delete(QWidget *parent = nullptr);
    ~Book_Delete();

    QLineEdit *line;
private slots:
    void on_pushButton_clicked();

private:
    Ui::Book_Delete *ui;

};

#endif // BOOK_DELETE_H
