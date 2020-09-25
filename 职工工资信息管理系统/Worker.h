#pragma once         // 防止头文件重复包含
#include <string>
using namespace std;

class Worker
{
private:
    string name;         // 姓名
    double basicSalary;  // 基本职务工资
public:
    bool flag;           // 0表示不可访问, 1表示可访问

    Worker();
    Worker(string name, double basicSalary);
    virtual ~Worker();

    double getBasicSalary();
    string getName();
    void setName(string name);
    //void setBasicSalary(double basicSalary);

    virtual void show();
    virtual void showCount();    // 这里不能加上static, 因为: 仅非静态成员函数是可以虚拟的
    virtual void showSalary();   // 这里不能加上static, 因为: 仅非静态成员函数是可以虚拟的
};

/* 重载左移运算符 (用于输出一个对象的信息) */
ostream& operator<<(ostream& cout, Worker& w);