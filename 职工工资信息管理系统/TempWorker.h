#pragma once
#include "Worker.h"

class TempWorker : public Worker
{
private:
    double bonus;               // 奖金
    double realSalary;          // 实发工资
    static int tempCount;       // 静态数据类型: 临时工总人数 (只是声明, 另外还需要在cpp文件中定义 !!!)
    static double totalSalary;  // 静态数据类型: 临时工总工资
public:
    TempWorker();
    TempWorker(string name, double basicSalary, double bonus);
    virtual ~TempWorker();

    double getBonus();
    double getRealSalary();    // 获得临时工的实发工资

    void show();               // 输出临时工的姓名、基本工资、所得税、实发工资
    static void showCount();   // 输出临时工的总数
    static void showSalary();  // 输出临时工的总工资、平均工资
}; 

/* 重载左移运算符 (用于输出一个对象的信息) */
ostream& operator<<(ostream& cout, TempWorker& t);
