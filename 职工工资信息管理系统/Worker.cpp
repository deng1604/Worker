#include <iostream>
#include "Worker.h"
using namespace std;

Worker::Worker()
{
    this->name = "无名氏";
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

/* 抽象函数: 输出对应职工的属性 */
void Worker::show() {
}

/* 抽象函数: 输出对应职工的人数 */ 
void Worker::showCount() {
}

/* 抽象函数: 输出对应职工的总工资、平均工资 */
void Worker::showSalary(){
}

/* 重载左移运算符 (用于输出一个对象的信息) */
ostream& operator<<(ostream& cout, Worker& w)
{
    cout << w.getName() << "\t" << w.getBasicSalary() << endl;
    return cout;
}