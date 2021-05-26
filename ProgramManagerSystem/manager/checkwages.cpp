#include "checkwages.h"
#include "ui_checkwages.h"

CheckWages::CheckWages(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckWages)
{
    ui->setupUi(this);
    setWindowTitle("查询工资");
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));

    //将框中的信息设置展示出来
    if(Resources::whichworker != -1)
    {
        ui->lineEdit_ID->setText(QString::fromStdString(Resources::m_worker[Resources::whichworker]->ID));
        ui->lineEdit_name->setText(QString::fromStdString(Resources::m_worker[Resources::whichworker]->m_name));
        ui->lineEdit_department->setText(QString::fromStdString(Resources::m_worker[Resources::whichworker]->m_department));
        ui->lineEdit_position->setText(QString::fromStdString(Resources::m_worker[Resources::whichworker]->m_position));

        if(Resources::m_worker[Resources::whichworker]->ConfirmInf() == 1)
        {
            QMessageBox box(QMessageBox::Information,"提示","员工职位信息有误，工资信息错误。\n建议修改信息");
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString("确 定"));
            box.exec ();
        }
        if(Resources::m_worker[Resources::whichworker]->ConfirmInf() == 2)
        {
            QMessageBox box(QMessageBox::Information,"提示","员工部门信息有误，工资信息错误。\n建议修改信息");
            box.setStandardButtons (QMessageBox::Ok);
            box.setButtonText (QMessageBox::Ok,QString("确 定"));
            box.exec ();
        }
    }


}

CheckWages::~CheckWages()
{
    delete ui;
}

void CheckWages::on_pushButton_find_clicked()
{
    //根据输入框中的信息更新工资信息
    string findname = ui->lineEdit_findname->text().trimmed().toStdString();
    int findwho = -1;
    for(int i = 0;i < (int)Resources::m_worker.size();i++)
    {
        if(Resources::m_worker[i]->m_name == findname)
        {
            findwho = i;
        }
    }
    if(findwho != -1)
    {
        QMessageBox box(QMessageBox::Information,"消息","查询成功！");
        box.setStandardButtons (QMessageBox::Ok);
        box.setButtonText (QMessageBox::Ok,QString("确 定"));
        box.exec ();
        ui->lineEdit_ID->setText(QString::fromStdString(Resources::m_worker[findwho]->ID));
        ui->lineEdit_name->setText(QString::fromStdString(Resources::m_worker[findwho]->m_name));
        ui->lineEdit_department->setText(QString::fromStdString(Resources::m_worker[findwho]->m_department));
        ui->lineEdit_position->setText(QString::fromStdString(Resources::m_worker[findwho]->m_position));
        ui->lineEdit_address->setText(QString::fromStdString(Resources::m_worker[findwho]->m_adress));

    }
    else
        QMessageBox::critical(this ,
        "错误" , "没有该员工！",
        QMessageBox::Ok, 0, 0);
}
