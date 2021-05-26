#ifndef MANAGERDIALOG_H
#define MANAGERDIALOG_H

#include <QDialog>
#include "stdafx.h"
#include "workermodifydialog.h"
#include "addworker.h"
#include "modifypassword.h"
#include "databackup.h"
#include "displayworker.h"
#include "displaybydepartment.h"
#include "analys.h"
#include "datarecovery.h"
#include "finance.h"

namespace Ui {
class ManagerDialog;
}

class ManagerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerDialog(QWidget *parent = 0);
    ~ManagerDialog();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_Modify_clicked();

    void on_pushButton_addworker_clicked();

    void on_pushButton_changepassword_clicked();

    void on_pushButton_savedate_clicked();

    void on_pushButton_displayworker_clicked();

    void on_pushButton_displaybydepartment_clicked();

    void on_pushButton_analys_clicked();

    void on_pushButton_recover_clicked();

    void on_pushButton_finance_clicked();

private:
    Ui::ManagerDialog *ui;
};

#endif // MANAGERDIALOG_H
