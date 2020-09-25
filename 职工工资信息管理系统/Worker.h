#pragma once         // ��ֹͷ�ļ��ظ�����
#include <string>
using namespace std;

class Worker
{
private:
    string name;         // ����
    double basicSalary;  // ����ְ����
public:
    bool flag;           // 0��ʾ���ɷ���, 1��ʾ�ɷ���

    Worker();
    Worker(string name, double basicSalary);
    virtual ~Worker();

    double getBasicSalary();
    string getName();
    void setName(string name);
    //void setBasicSalary(double basicSalary);

    virtual void show();
    virtual void showCount();    // ���ﲻ�ܼ���static, ��Ϊ: ���Ǿ�̬��Ա�����ǿ��������
    virtual void showSalary();   // ���ﲻ�ܼ���static, ��Ϊ: ���Ǿ�̬��Ա�����ǿ��������
};

/* ������������� (�������һ���������Ϣ) */
ostream& operator<<(ostream& cout, Worker& w);