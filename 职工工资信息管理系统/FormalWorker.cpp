#include <iostream>
#include "FormalWorker.h"
using namespace std;

/* 临时工的人数赋初值为0 (定义) !!! */
int FormalWorker::formalCount = 0;

/* 临时工的总工资赋初值为0 (定义) */
double FormalWorker::totalSalary = 0;

FormalWorker::FormalWorker()
{
    this->tax = 0;
    this->realSalary = getBasicSalary();
    formalCount++;
    totalSalary += 0;
}

/* 注意: 子类的有参构造函数中, 一定要给父类的属性赋值 */
FormalWorker::FormalWorker(string name, double basicSalary, double tax) : Worker(name, basicSalary)
{
    this->tax = tax;
    this->realSalary = getBasicSalary() - tax;
    formalCount++;
    totalSalary += realSalary;
}

FormalWorker::~FormalWorker()
{
    formalCount--;
    totalSalary -= realSalary;
}

double FormalWorker::getRealSalary()
{
    return realSalary;
}

double FormalWorker::getTax()
{
    return tax;
}

/* 输出正式职工的姓名、基本工资、所得税、实发工资 */
void FormalWorker::show()
{
    cout << getName() << "\t" << getBasicSalary() << "\t" << getTax() << "\t" << getRealSalary() << endl;
}

/* 输出正式职工的总数 */
void FormalWorker::showCount()
{
    cout << "正式职工的总人数为: " << formalCount << endl;
}

/* 输出正式职工的总工资、平均工资 */
void FormalWorker::showSalary()
{
    cout << "正式职工的总工资为: " << totalSalary << endl;
    cout << "正式职工的平均工资为: " << totalSalary / formalCount << endl << endl;
}

/* 重载左移运算符 (用于输出一个对象的信息) */
ostream& operator<<(ostream& cout, FormalWorker& f)
{
    cout << f.getName() << "\t" << f.getBasicSalary() << "\t"
         << f.getTax()  << "\t" << f.getRealSalary()  << endl;
    return cout;
}