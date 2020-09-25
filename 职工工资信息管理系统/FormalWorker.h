#pragma once        
#include "Worker.h"

class FormalWorker : public Worker
{
private:
    double tax;                 // ����˰
    double realSalary;          // ʵ������
    static int formalCount;     // ��̬��������: ��ʽְ��������   (ֻ������, ���⻹��Ҫ��cpp�ļ��ж��� !!!)
    static double totalSalary;  // ��̬��������: ��ʽְ���ܹ��ʡ�ƽ������
public:
    FormalWorker();
    FormalWorker(string name, double basicSalary, double tax);
    virtual ~FormalWorker();

    double getTax();
    double getRealSalary();

    void show();                // �����ʽְ�����������������ʡ�����˰��ʵ������
    static void showCount();    // �����ʽְ��������
    static void showSalary();   // �����ʽְ�����ܹ��ʡ�ƽ������
};

/* ������������� (�������һ���������Ϣ) */
ostream& operator<<(ostream& cout, FormalWorker& f);