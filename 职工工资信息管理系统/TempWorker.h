#pragma once
#include "Worker.h"

class TempWorker : public Worker
{
private:
    double bonus;               // ����
    double realSalary;          // ʵ������
    static int tempCount;       // ��̬��������: ��ʱ�������� (ֻ������, ���⻹��Ҫ��cpp�ļ��ж��� !!!)
    static double totalSalary;  // ��̬��������: ��ʱ���ܹ���
public:
    TempWorker();
    TempWorker(string name, double basicSalary, double bonus);
    virtual ~TempWorker();

    double getBonus();
    double getRealSalary();    // �����ʱ����ʵ������

    void show();               // �����ʱ�����������������ʡ�����˰��ʵ������
    static void showCount();   // �����ʱ��������
    static void showSalary();  // �����ʱ�����ܹ��ʡ�ƽ������
}; 

/* ������������� (�������һ���������Ϣ) */
ostream& operator<<(ostream& cout, TempWorker& t);
