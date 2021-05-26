#ifndef FINANCE_H
#define FINANCE_H

#include <QDialog>
#include "stdafx.h"
#include <QStandardItemModel>

namespace Ui {
class finance;
}

class finance : public QDialog
{
    Q_OBJECT

public:
    explicit finance(QWidget *parent = 0);
    ~finance();

private slots:

    void on_pushButton_add_clicked();
private:
    Ui::finance *ui;
    QStandardItemModel  *model = new QStandardItemModel();
};

#endif // FINANCE_H
