#ifndef STU_INSERT_H
#define STU_INSERT_H

#include <QDialog>

namespace Ui {
class Stu_Insert;
}

class Stu_Insert : public QDialog
{
    Q_OBJECT

public:
    explicit Stu_Insert(QWidget *parent = nullptr);
    ~Stu_Insert();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Stu_Insert *ui;
};

#endif // STU_INSERT_H
