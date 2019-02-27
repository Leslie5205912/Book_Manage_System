#ifndef RESERVE_H
#define RESERVE_H

#include <QDialog>

namespace Ui {
class Reserve;
}

class Reserve : public QDialog
{
    Q_OBJECT

public:
    explicit Reserve(QWidget *parent = nullptr);
    ~Reserve();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Reserve *ui;
};

#endif // RESERVE_H
