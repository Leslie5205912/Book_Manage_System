#ifndef STU_DELETE_H
#define STU_DELETE_H

#include <QDialog>

namespace Ui {
class Stu_Delete;
}

class Stu_Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Stu_Delete(QWidget *parent = nullptr);
    ~Stu_Delete();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Stu_Delete *ui;
};

#endif // STU_DELETE_H
