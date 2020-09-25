#include <iostream>
#include "FormalWorker.h"
using namespace std;

/* ��ʱ������������ֵΪ0 (����) !!! */
int FormalWorker::formalCount = 0;

/* ��ʱ�����ܹ��ʸ���ֵΪ0 (����) */
double FormalWorker::totalSalary = 0;

FormalWorker::FormalWorker()
{
    this->tax = 0;
    this->realSalary = getBasicSalary();
    formalCount++;
    totalSalary += 0;
}

/* ע��: ������вι��캯����, һ��Ҫ����������Ը�ֵ */
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

/* �����ʽְ�����������������ʡ�����˰��ʵ������ */
void FormalWorker::show()
{
    cout << getName() << "\t" << getBasicSalary() << "\t" << getTax() << "\t" << getRealSalary() << endl;
}

/* �����ʽְ�������� */
void FormalWorker::showCount()
{
    cout << "��ʽְ����������Ϊ: " << formalCount << endl;
}

/* �����ʽְ�����ܹ��ʡ�ƽ������ */
void FormalWorker::showSalary()
{
    cout << "��ʽְ�����ܹ���Ϊ: " << totalSalary << endl;
    cout << "��ʽְ����ƽ������Ϊ: " << totalSalary / formalCount << endl << endl;
}

/* ������������� (�������һ���������Ϣ) */
ostream& operator<<(ostream& cout, FormalWorker& f)
{
    cout << f.getName() << "\t" << f.getBasicSalary() << "\t"
         << f.getTax()  << "\t" << f.getRealSalary()  << endl;
    return cout;
}