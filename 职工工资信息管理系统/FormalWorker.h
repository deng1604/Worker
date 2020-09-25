#pragma once        
#include "Worker.h"

class FormalWorker : public Worker
{
private:
    double tax;                 // 所得税
    double realSalary;          // 实发工资
    static int formalCount;     // 静态数据类型: 正式职工总人数   (只是声明, 另外还需要在cpp文件中定义 !!!)
    static double totalSalary;  // 静态数据类型: 正式职工总工资、平均工资
public:
    FormalWorker();
    FormalWorker(string name, double basicSalary, double tax);
    virtual ~FormalWorker();

    double getTax();
    double getRealSalary();

    void show();                // 输出正式职工的姓名、基本工资、所得税、实发工资
    static void showCount();    // 输出正式职工的总数
    static void showSalary();   // 输出正式职工的总工资、平均工资
};

/* 重载左移运算符 (用于输出一个对象的信息) */
ostream& operator<<(ostream& cout, FormalWorker& f);