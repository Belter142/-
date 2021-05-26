#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("登录");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Register_clicked()
{
    this->hide();
    register1->show();
    register1->exec();
    this->show();
}

void MainWindow::on_pushButton_FindPassword_clicked()
{
    this->hide();
    findpassword1->show();
    findpassword1->exec();
    this->show();
}

void MainWindow::on_pushButton_Login_clicked()
{
    if(ui->LineEdit_accout->text().trimmed().isEmpty())
    {
        QMessageBox::critical(this ,
        "错误" , "请输入账户",
        QMessageBox::Ok, 0, 0);
        return;
    }

    else if(ui->LineEdit_password->text().trimmed().isEmpty())
    {
        QMessageBox::critical(this ,
        "错误" , "请输入密码",
        QMessageBox::Ok, 0, 0);
        return;
    }

    string accout = ui->LineEdit_accout->text().trimmed().toStdString();
    string password = ui->LineEdit_password->text().trimmed().toStdString();


    int flag = 0;
    for(int i = 0;i < (int)Resources::m_manager.size();i++)
    {
        if(Resources::m_manager[i]->m_accout == accout && Resources::m_manager[i]->m_password == password)
        {
            flag = 1;
            Resources::whichmanager = i;
        }
    }
    if(flag)
    {
        ManagerDialog *managerdialog1 = new ManagerDialog(this);
        this->hide();
        managerdialog1->show();
    }
    else
        QMessageBox::critical(this ,
                              "错误" , "账号或者密码错误！",
                              QMessageBox::Ok, 0, 0);

}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}
