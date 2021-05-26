
#include "worker.h"

worker::worker(vector<string> v)
{
    m_accout = v[1];
    m_salary = v[2];

    ID = v[0];
    m_name = v[3];
    m_department = v[4];
    m_position = v[5];
    m_adress = v[6];


    UpDateWages();
}


worker::~worker()
{
}



void worker::ModifyOwnInf(vector<string> v)
{
    if(v[0] != "") m_name = v[0];
    if(v[1] != "") m_salary = v[0];
    if(v[2] != "") m_department = v[1];
    if(v[3] != "") m_position = v[2];
    if(v[4] != "") m_adress = v[3];

    UpDateWages();

}

void worker::UpDateWages()
{
    salary = 0;
   for (auto c : m_salary) {
       salary *= 10;
        salary += c - '0';
   }
}

void worker::ModifyByManager(vector<string> v)
{

    ID = v[0];
    m_name = v[1];
    m_department = v[2];
    m_position = v[3];
    m_adress = v[4];


    UpDateWages();
}
