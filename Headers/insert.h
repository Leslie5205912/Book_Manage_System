#ifndef INSERT_H
#define INSERT_H

#include <QDialog>

namespace Ui {
class Insert;
}

class Insert : public QDialog
{
    Q_OBJECT

public:
    explicit Insert(QWidget *parent = nullptr);
    ~Insert();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Insert *ui;
};

#endif // INSERT_H
