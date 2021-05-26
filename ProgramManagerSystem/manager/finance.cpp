#include "finance.h"
#include "ui_finance.h"

int list1, list2;
double sum1, sum2;
finance::finance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finance)
{
    ui->setupUi(this);
    setWindowTitle("财务管理");

    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));

    //设置tableview的参数
    model->setColumnCount(4);
    model->setHeaderData(0,Qt::Horizontal,QString::fromStdString("固定支出"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromStdString("金额"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromStdString("流动指出"));
    model->setHeaderData(3,Qt::Horizontal,QString::fromStdString("金额"));

    //关联model
    ui->tableView->setModel(model);
    //设置宽度
    for(int i = 0;i < 3;i++)
    {
        ui->tableView->setColumnWidth(i,70);
    }
    ui->tableView->setColumnWidth(4,110);
    sum1 = 0;
    sum2 = 0;
    list1 =0;
    list2 = 0;
    for(int i = 0;i < (int)Resources::m_worker.size();i++)
    {
        sum1 += Resources::m_worker[i]->salary;
    }
    model->setItem(list1,0,new QStandardItem(QString::fromStdString("工资")));
    model->setItem(list1,1,new QStandardItem(QString::number(sum1)));
    list1++;

    ui->lineEdit_sum->setText(QString::number(sum1));
    ui->lineEdit_liquid->setText(QString::number(sum2));

}

finance::~finance()
{
    delete ui;
}

void finance::on_pushButton_add_clicked()
{
    double tem = 0;
    string name = ui->lineEdit_name->text().trimmed().toStdString();
    string money = ui->lineEdit_numer->text().trimmed().toStdString();

    if(!ui->radioButton_station->isChecked() && !ui->radioButton_positive->isChecked())
    {
        QMessageBox::critical(this ,
        "错误" , "请选择支出种类！",
        QMessageBox::Ok, 0, 0);
        return;
    }else if(ui->lineEdit_name->text().trimmed().isEmpty() || ui->lineEdit_numer->text().trimmed().isEmpty())
    {
        QMessageBox::critical(this ,
        "错误" , "请填写款项与金额！",
        QMessageBox::Ok, 0, 0);
        return;
    }else if(ui->radioButton_station->isChecked())
    {
        tem = 0;
        for (auto c : money) {
            tem *= 10;
             tem += c - '0';
        }
        sum1 += tem;
        model->setItem(list1,0,new QStandardItem(QString::fromStdString(name)));
        model->setItem(list1,1,new QStandardItem(QString::number(tem)));
        list1++;
        ui->lineEdit_sum->setText(QString::number(sum1));
    }

    if(ui->radioButton_positive->isChecked())
    {
        tem = 0;
        for (auto c : money) {
            tem *= 10;
             tem += c - '0';
        }
        sum2 += tem;
        model->setItem(list2,2,new QStandardItem(QString::fromStdString(name)));
        model->setItem(list2,3,new QStandardItem(QString::number(tem)));
        list2++;
        ui->lineEdit_sum->setText(QString::number(sum2));
    }


}
