#include <iostream>
#include "TempWorker.h"
using namespace std;

/* ��ʱ������������ֵΪ0 (����) */
int TempWorker::tempCount = 0;

/* ��ʱ�����ܹ��ʸ���ֵΪ0 (����) */
double TempWorker::totalSalary = 0;

TempWorker::TempWorker()
{
    this->bonus = 0;
    this->realSalary = getBasicSalary();
    tempCount++;               // ��ʱ��������1
    totalSalary += 0;
}

/* ע��: ������вι��캯����, һ��Ҫ����������Ը�ֵ */
TempWorker::TempWorker(string name, double basicSalary, double bonus) : Worker(name, basicSalary)
{
    this->bonus = bonus;
    this->realSalary = getBasicSalary() + bonus;
    tempCount++;
    totalSalary += realSalary;
}

TempWorker::~TempWorker()
{
    tempCount--;               // ��ʱ��������1
    totalSalary -= realSalary;
}

/* �����ʱְ����ʵ������ */
double TempWorker::getBonus()
{
    return bonus;
}

/* �����ʱְ����ʵ������ */
double TempWorker::getRealSalary()
{
    return realSalary;
}

/* �����ʱְ�����������������ʡ�����˰��ʵ������ */
void TempWorker::show()
{
    cout << getName() << "\t" << getBasicSalary() << "\t" << getBonus() << "\t" << getRealSalary() << endl;
}

/* �����ʱ�������� */
void TempWorker::showCount()
{
    cout << "��ʱְ����������Ϊ: " << tempCount << endl;
}

/* �����ʱ�����ܹ��ʡ�ƽ������ */
void TempWorker::showSalary()
{
    cout << "��ʱְ�����ܹ���Ϊ: " << totalSalary << endl;
    cout << "��ʱְ����ƽ������Ϊ: " << totalSalary / tempCount << endl << endl;
}

/* ������������� (�������һ���������Ϣ) */
ostream& operator<<(ostream& cout, TempWorker& t)
{
    cout << t.getName()  << "\t" << t.getBasicSalary() << "\t"
         << t.getBonus() << "\t" << t.getRealSalary() << endl;
    return cout;
}