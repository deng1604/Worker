#include <iostream>
#include "Worker.h"
using namespace std;

Worker::Worker()
{
    this->name = "������";
    this->basicSalary = 0;
}

Worker::Worker(string name, double basicSalary)
{
    this->name = name;
    this->basicSalary = basicSalary;
}

Worker::~Worker() {
}

double Worker::getBasicSalary()
{
    return basicSalary;
}

string Worker::getName()
{
    return name;
}

void Worker::setName(string name)
{
    this->name = name;
}

//void Worker::setBasicSalary(double basicSalary)
//{
//    this->basicSalary = basicSalary;
//}

/* ������: �����Ӧְ�������� */
void Worker::show() {
}

/* ������: �����Ӧְ�������� */ 
void Worker::showCount() {
}

/* ������: �����Ӧְ�����ܹ��ʡ�ƽ������ */
void Worker::showSalary(){
}

/* ������������� (�������һ���������Ϣ) */
ostream& operator<<(ostream& cout, Worker& w)
{
    cout << w.getName() << "\t" << w.getBasicSalary() << endl;
    return cout;
}