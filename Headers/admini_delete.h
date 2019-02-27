#ifndef ADMINI_DELETE_H
#define ADMINI_DELETE_H

#include <QDialog>

namespace Ui {
class Admini_Delete;
}

class Admini_Delete : public QDialog
{
    Q_OBJECT

public:
    explicit Admini_Delete(QWidget *parent = nullptr);
    ~Admini_Delete();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Admini_Delete *ui;
};

#endif // ADMINI_DELETE_H
