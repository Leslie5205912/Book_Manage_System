#ifndef ADIMI_INSERT_H
#define ADIMI_INSERT_H

#include <QDialog>

namespace Ui {
class Adimi_Insert;
}

class Adimi_Insert : public QDialog
{
    Q_OBJECT

public:
    explicit Adimi_Insert(QWidget *parent = nullptr);
    ~Adimi_Insert();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Adimi_Insert *ui;
};

#endif // ADIMI_INSERT_H
