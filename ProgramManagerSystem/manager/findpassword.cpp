#include "findpassword.h"
#include "ui_findpassword.h"

FindPassword::FindPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindPassword)
{
    ui->setupUi(this);
    setWindowTitle("找回密码");
    QObject::connect(ui->pushButton_back,SIGNAL(clicked(bool)),this,SLOT(close()));
}

FindPassword::~FindPassword()
{
    delete ui;
}

void FindPassword::on_pushButton_find_clicked()
{

    if(!ui->lineEdit->text().trimmed().isEmpty())
    {
        string accout = ui->lineEdit->text().toStdString();

            for(int i = 0;i < (int)Resources::m_manager.size();i++)
            {
                if(Resources::m_manager[i]->m_accout == accout)
                {
                    //ui->label_password->setText( QString::fromStdString(Resources::m_manager[i]->m_password));
                    QString s = QString("你的密码为：%1").arg(QString::fromStdString(Resources::m_manager[i]->m_password));
                    QMessageBox box(QMessageBox::Information,"提示",s);
                    box.setStandardButtons (QMessageBox::Ok);
                    box.setButtonText (QMessageBox::Ok,QString("确 定"));
                    box.exec ();
                    return;
                }
            }

        QMessageBox::critical(this ,
        "错误" , "没有该账户！",
        QMessageBox::Ok, 0, 0);
    }
    else
        QMessageBox::critical(this ,
        "错误" , "请输入账号",
        QMessageBox::Ok, 0, 0);
}
