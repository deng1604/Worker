#include <iostream>
#include "TempWorker.h"
using namespace std;

/* 临时工的人数赋初值为0 (定义) */
int TempWorker::tempCount = 0;

/* 临时工的总工资赋初值为0 (定义) */
double TempWorker::totalSalary = 0;

TempWorker::TempWorker()
{
    this->bonus = 0;
    this->realSalary = getBasicSalary();
    tempCount++;               // 临时工个数加1
    totalSalary += 0;
}

/* 注意: 子类的有参构造函数中, 一定要给父类的属性赋值 */
TempWorker::TempWorker(string name, double basicSalary, double bonus) : Worker(name, basicSalary)
{
    this->bonus = bonus;
    this->realSalary = getBasicSalary() + bonus;
    tempCount++;
    totalSalary += realSalary;
}

TempWorker::~TempWorker()
{
    tempCount--;               // 临时工个数减1
    totalSalary -= realSalary;
}

/* 获得临时职工的实发工资 */
double TempWorker::getBonus()
{
    return bonus;
}

/* 获得临时职工的实发工资 */
double TempWorker::getRealSalary()
{
    return realSalary;
}

/* 输出临时职工的姓名、基本工资、所得税、实发工资 */
void TempWorker::show()
{
    cout << getName() << "\t" << getBasicSalary() << "\t" << getBonus() << "\t" << getRealSalary() << endl;
}

/* 输出临时工的总数 */
void TempWorker::showCount()
{
    cout << "临时职工的总人数为: " << tempCount << endl;
}

/* 输出临时工的总工资、平均工资 */
void TempWorker::showSalary()
{
    cout << "临时职工的总工资为: " << totalSalary << endl;
    cout << "临时职工的平均工资为: " << totalSalary / tempCount << endl << endl;
}

/* 重载左移运算符 (用于输出一个对象的信息) */
ostream& operator<<(ostream& cout, TempWorker& t)
{
    cout << t.getName()  << "\t" << t.getBasicSalary() << "\t"
         << t.getBonus() << "\t" << t.getRealSalary() << endl;
    return cout;
}