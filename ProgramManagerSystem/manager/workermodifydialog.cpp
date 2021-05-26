#include "workermodifydialog.h"
#include "ui_workermodifydialog.h"

WorkerModifyDialog::WorkerModifyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WorkerModifyDialog)
{
    ui->setupUi(this);
    setWindowTitle("修改信息");
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));
}

WorkerModifyDialog::~WorkerModifyDialog()
{
    delete ui;
}

void WorkerModifyDialog::on_pushButton_Modify_clicked()
{
    //获取信息
    vector<string> v;
    int i;
    string ID = ui->lineEdit_ID->text().trimmed().toStdString();
    i = 0;
   for (auto c : ID) {
       i *= 10;
        i += c - '0';
   }
    string name = ui->lineEdit_name->text().trimmed().toStdString();
    v.push_back(name);
    string salary = ui->lineEdit_salary->text().trimmed().toStdString();
    v.push_back(salary);
    string department = ui->lineEdit_departmen->text().trimmed().toStdString();
    v.push_back(department);
    string position = ui->lineEdit_position->text().trimmed().toStdString();
    v.push_back(position);
    string address = ui->lineEdit_address->text().trimmed().toStdString();
    v.push_back(address);
    //修改信息
    Resources::m_worker[i - 1]->ModifyOwnInf(v);

    QMessageBox box(QMessageBox::Information,"消息","修改成功！");
    box.setStandardButtons (QMessageBox::Ok);
    box.setButtonText (QMessageBox::Ok,QString("确 定"));
    box.exec ();

}
