#include <iostream>
#include <string>
#include <vector>
#include "Worker.h"
#include "FormalWorker.h"
#include "TempWorker.h"
using namespace std;

const int MAX_SIZE = 100;                                     // 职工的最大人数

void myMenu();                                                // 提示菜单
void input(vector<Worker*>& pWorker, int num);                // 输入职工信息          (一定要记得加引用&符号)
void output(vector<Worker*>& pWorker, int num);               // 输出职工信息 
void queryWorkerByName(vector<Worker*>& pWorker, int num);    // 根据姓名来查找职工信息
void modifyWorkerByName(vector<Worker*>& pWorker, int num);   // 根据姓名来修改职工信息
void deleteWorkerByName(vector<Worker*>& pWorker, int num);   // 根据姓名来删除职工信息 (可恢复)
void clearWorkerByName(vector<Worker*>& pWorker, int& num);   // 根据姓名来删除职工信息 (不可恢复)
void recoverWorkerByName(vector<Worker*>& pWorker, int num);  // 根据姓名来恢复一个职工信息
void deleteAllWorker(vector<Worker*>& pWorker, int num);      // 用循环来删除指针数组
void showWorkerNum(vector<Worker*>& pWorker, int num);        // 显示各种职工的人数
void showWorkerSalary(vector<Worker*>& pWorker, int num);     // 显示职工总的实发工资、平均实发工资

int main()
{
    int num;
    cout << "请输入职工的人数: ";
    cin >> num;

    vector<Worker*> pWorker(num);   // 相当于Worker* pWorker[num];
    pWorker.resize(num, NULL);      // 将pWorker的现有元素个数调至num个, 多则删, 少则补, 其值为0

    input(pWorker, num);

    myMenu();

    int choice;
    while (true)
    {
        cout << "\n\n------------------------------------------------";
        cout << "\n请输入您的选择(0-10): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            input(pWorker, num);
            break;
        case 2:
            deleteWorkerByName(pWorker, num);
            break;
        case 3:
            modifyWorkerByName(pWorker, num);
            break;
        case 4:
            queryWorkerByName(pWorker, num);
            break;
        case 5:
            clearWorkerByName(pWorker, num);
            break;
        case 6:
            recoverWorkerByName(pWorker, num);
            break;
        case 7:
            output(pWorker, num);
            break;
        case 8:
            myMenu();
            break;
        case 9:
            showWorkerNum(pWorker, num);
            break;
        case 10:
            showWorkerSalary(pWorker, num);
            break;
        case 0:
            deleteAllWorker(pWorker, num);
            cout << "成功退出系统。byebye" << endl;
            return 0; // 退出程序
        default:
            cout << "您的输入有误, 请重新输入0-10之间的数。" << endl;
            break;
        }
    }

    return 0;
}

/* 提示菜单 */
void myMenu()
{
    cout << endl << endl;
    cout << "----------------------菜  单-------------------------------" << endl;
    cout << "     1 增加职工记录           　 2 删除职工记录 (可恢复)      " << endl;
    cout << "     3 修改职工记录            　4 查找职工记录              " << endl;
    cout << "     5 删除职工记录 (不可恢复) 　6 恢复职工数据               " << endl;
    cout << "     7 显示职工记录           　 8 显示菜单                  " << endl;
    cout << "     9 统计职工人数              10 统计职工工资             " << endl;
    cout << "     0 退出系统                                             " << endl;
    cout << "-----------------------------------------------------------" << endl;
}

/* 输入职工信息 */
void input(vector<Worker*>& pWorker, int num)           // 相当于void input(Worker* pWorker[], int num)    
{
    string name;        // 姓名
    double basicSalary; // 基本工资
    double tax;         // 所得税
    double bonus;       // 奖金
    char choice;

    cout << "请输入职工类型 t是临时工、f是正式职工: \n" << endl;

    for (int i = 0; i < num; i++)
    {
        cin >> choice;
        if (choice == 'f' || choice == 'F')
        {
            cin >> name >> basicSalary >> tax;
            //FormalWorker fWorker(name, basicSalary, tax); 
            //pWorker[i] = &fWorker;    // 不行: 在循环内创建对象, 循环结束后会调用析构函数, 无法统计个数
            pWorker[i] = new FormalWorker(name, basicSalary, tax);
            pWorker[i]->showCount();
            pWorker[i]->showSalary();
        }
        else if (choice == 't' || choice == 'T')
        {
            cin >> name >> basicSalary >> bonus;
            pWorker[i] = new TempWorker(name, basicSalary, bonus);
            pWorker[i]->showCount();
            pWorker[i]->showSalary();
        }
        else
        {
            cout << "您的输入有误!!!" << endl;
            pWorker[i] = new TempWorker();     // 先调用无参构造函数, 防止有部分pWorker[i]未初始化而不好delete
        }
        pWorker[i]->flag = true;   // 表示可以访问
    }
}

/* 输出职工信息 */
void output(vector<Worker*>& pWorker, int num)
{
    cout << endl << endl;
    cout << "姓名  基本工资 税/奖金 实发工资" << endl;
    for (int i = 0; i < num; i++)
    {
        if (pWorker[i]->flag)                            // ------------------------------------------------
        {
            //pWorker[i]->show();                        // (可以正常运行)    
            FormalWorker* p1 = dynamic_cast<FormalWorker*>(pWorker[i]);
            TempWorker* p2 = dynamic_cast<TempWorker*>(pWorker[i]);
            if (p1 != NULL && p2 == NULL)                // 转换成功, 是FormalWorker对象(正式职工)
            {
                //cout << *(FormalWorker)pWorker[i];     // 咦, 不需要强制类型转换吗?    哦, 我好像知道了❗
                cout << *p1;
            }
            else if (p1 == NULL && p2 != NULL)           // 转换成功, 是TempWorker对象  (临时工)
            {
                cout << *p2;
            }
            else
            {
                cout << "OUTPUT ERROR!!!" << endl;
                exit(1);
            }
        }
    }
}

/* 根据姓名来查找职工信息 */
void queryWorkerByName(vector<Worker*>& pWorker, int num)
{
    string queryName;
    cout << "\n请输入要查询的职工的姓名: " << endl;
    cin >> queryName;

    for (int i = 0; i < num; i++)
    {
        if (pWorker[i]->getName() == queryName && pWorker[i]->flag)
        {
            cout << "姓名为: " << queryName << ", 基本工资是: " << pWorker[i]->getBasicSalary() << endl;
            return; // 查找成功
        }
    }

    cout << "查找失败 !!!" << endl;
}

/* 根据姓名来修改职工信息: (备注, 这里只修改了姓名, 其余的属性不好修改啊 (⊙﹏⊙) */
void modifyWorkerByName(vector<Worker*>& pWorker, int num)
{
    string queryName, newName;
    cout << "\n请输入要修改的职工的姓名: " << endl;
    cin >> queryName;

    for (int i = 0; i < num; i++)
    {
        if (pWorker[i]->getName() == queryName && pWorker[i]->flag)              // 查找成功
        {
            cout << "请输入要修改新名字: " << endl;
            cin >> newName;
            pWorker[i]->setName(newName);
            return; // 查找成功, 返回
        }
    }

    cout << "查找失败, 姓名无法修改!" << endl;
}

/* 根据姓名来删除职工信息 (可恢复) */
void deleteWorkerByName(vector<Worker*>& pWorker, int num)
{
    string queryName;
    cout << "\n请输入要删除的职工的姓名(可恢复): " << endl;
    cin >> queryName;

    for (int i = 0; i < num; i++)
    {
        if (pWorker[i]->getName() == queryName)  // 查找成功
        {
            pWorker[i]->flag = false;            // 设置为不可访问
            return;                              // 查找成功, 返回
        }
    }

    cout << "查无此人, 无法删除!" << endl;
}

/* 根据姓名来删除职工信息 (不可恢复) */
void clearWorkerByName(vector<Worker*>& pWorker, int& num)
{
    string queryName;
    cout << "\n请输入要删除的职工的姓名(不可恢复): " << endl;
    cin >> queryName;

    for (int i = 0; i < num; i++)
    {
        if (pWorker[i]->getName() == queryName)    // 查找成功
        {
            delete pWorker[i];                     // 先释放该元素空间 (原因:必须要在erase之前将其delete掉)
            pWorker.erase(pWorker.begin() + i);    // 删除pWorker[i]元素
            num--;
            return;                                // 查找成功, 返回
        }
    }

    cout << "查无此人, 无法删除!" << endl;
}

/* 根据姓名来恢复一个职工信息 */
void recoverWorkerByName(vector<Worker*>& pWorker, int num)
{
    string queryName;
    cout << "\n请输入要恢复的职工的姓名: " << endl;
    cin >> queryName;

    for (int i = 0; i < num; i++)
    {
        if (pWorker[i]->getName() == queryName && pWorker[i]->flag == false)
        {
            pWorker[i]->flag = true;
            cout << "恢复成功: " << endl;
            return;            // 查找成功, 返回
        }
    }

    cout << "查无此人, 恢复失败!" << endl;
}

/* 9.显示各种职工人数 */
void showWorkerNum(vector<Worker*>& pWorker, int num)
{
    /*
    TempWorker::showCount();    // 这里必须要将showCount函数定义为静态函数, 即加上static关键字
    FormalWorker::showCount();  // 关键问题: 可恢复删除(未delete)导致静态的人数没有变化 !!!!!!!!!!!!!!!!!
    */

    int formalWorkerNum = 0;
    int tempWorkerNum = 0;
    for (int i = 0; i < num; i++)
    {
        if (pWorker[i]->flag)
        {
            FormalWorker* p1 = dynamic_cast<FormalWorker*>(pWorker[i]);
            TempWorker* p2 = dynamic_cast<TempWorker*>(pWorker[i]);
            if (p1 != NULL && p2 == NULL)                // 转换成功, 是FormalWorker对象(正式职工)
            {
                formalWorkerNum++;
            }
            else if (p1 == NULL && p2 != NULL)           // 转换成功, 是TempWorker对象  (临时工)
            {
                tempWorkerNum++;
            }
            else
            {
                cout << "SHOWWORKERNUM ERROR!!!" << endl;
                exit(1);
            }
        }
    }
    cout << "临时职工的总人数为: " << tempWorkerNum << endl;
    cout << "正式职工的总人数为: " << formalWorkerNum << endl;
}

/* 显示职工总的实发工资、平均实发工资 */
void showWorkerSalary(vector<Worker*>& pWorker, int num)
{
    /*
    TempWorker::showSalary();    // 这里必须要将showCount函数定义为静态函数, 即加上static关键字
    FormalWorker::showSalary();  // 关键问题: 可恢复删除(未delete)导致静态的人数没有变化 !!!!!!!!!!!!!!!!!
    */

    int formalWorkerNum = 0;
    int tempWorkerNum = 0;
    int formalWorkerSalary = 0;
    int tempWorkerSalary = 0;

    for (int i = 0; i < num; i++)
    {
        if (pWorker[i]->flag)
        {
            FormalWorker* p1 = dynamic_cast<FormalWorker*>(pWorker[i]);
            TempWorker* p2 = dynamic_cast<TempWorker*>(pWorker[i]);
            if (p1 != NULL && p2 == NULL)                // 转换成功, 是FormalWorker对象(正式职工)
            {
                formalWorkerNum++;
                formalWorkerSalary += p1->getRealSalary();
            }
            else if (p1 == NULL && p2 != NULL)           // 转换成功, 是TempWorker对象  (临时工)
            {
                tempWorkerNum++;
                tempWorkerSalary += p2->getRealSalary();
            }
            else
            {
                cout << "SHOWWORKERSALARY ERROR!!!" << endl;
                exit(1);
            }
        }
    }
    cout << "临时职工的总实发工资为:  " << tempWorkerSalary << endl;
    cout << "临时职工的平均实发工资为: " << tempWorkerSalary / tempWorkerNum << endl;

    cout << "正式职工的总实发工资为:  " << formalWorkerSalary << endl;
    cout << "正式职工的平均实发工资为: " << formalWorkerSalary / formalWorkerNum << endl;
}

/* 用循环来删除指针数组 (new和delete必须要同时使用) */
void deleteAllWorker(vector<Worker*>& pWorker, int num)
{
    for (int i = 0; i < num; i++)
    {
        delete pWorker[i];
    }
}

/*
测试数据:
10
f 小明 10000 900
F 张三 3000 800
f 李四 4000 700
f 王五 5000 600
F 赵六 6000 500
T AAA 10000 900
t BBB 3000 800
T CCC 4000 700
t DDD 5000 600
t EEE 6000 500
4
王五
7
3
小明
小二
7
8
5
赵六
7
2
BBB
7
6
赵六
6
BBB
7
9
8
2
DD
2
DDD
7
9
10
0
*/

/**
 * 备注:
 * 1.这个程序的静态的统计人数不好写, 主要是因为可恢复删除那里, 删除时未调用析构函数, 导致统计出错
 *   我暂时先: 遍历pWorker数组, 运用dynamic_cast动态类型转换来求出具体人数
 * 
 * 2.那个静态的统计分数和平均分的函数呢? 
 *   该怎么写呀???
 * 
 * 3.复制构造函数有什么用处呢?
 * 
 */