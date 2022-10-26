#pragma once
#include <iostream>
using namespace std;

class Date
{
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);


public:
    Date(int year = 1, int month = 1, int day = 1)//���캯��
        :_year(year)
        ,_month(month)
        ,_day(day)
    {
        if ((year < 0)
            || (month <= 0 || month >= 13)
            || (day <= 0 || day > GetMonthDay(year, month)))
            cout << "�Ƿ�����" << endl;
    }

    Date(const Date& d)//�������캯��
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    ~Date()//��������
    {
        _year = _month = _day = 0;
    }

    int GetMonthDay(int year, int month);//��ȡ��Ӧ�·ݵ�����

    bool operator==(const Date& d) const;//�Ƚ����������Ƿ����

    bool operator!=(const Date& d) const;//�ԣ�=����ʽ�Ƚ����������Ƿ����

    Date& operator+=(int day);//��ȡ���ڼ���һ��������õ������ڣ����޸�ԭ����

    Date operator+(int day);//��ȡ���ڼ���һ��������õ������ڣ������޸�ԭ����

    Date& operator-=(int day);//��ȡ���ڼ�ȥһ��������õ������ڣ����޸�ԭ����

    Date operator-(int day);//��ȡ���ڼ�ȥһ��������õ������ڣ������޸�ԭ����

    bool operator<(const Date& d) const;//��С�ڵ���ʽ�Ƚ����ڵĴ�С

    bool operator<=(const Date& d) const;//��С�ڵ��ڵ���ʽ�Ƚ����ڵĴ�С

    bool operator>(const Date& d) const;//�Դ��ڵ���ʽ�Ƚ����ڵĴ�С

    bool operator>=(const Date& d) const;//�Դ��ڵ��ڵ���ʽ�Ƚ����ڵĴ�С

    Date& operator=(const Date& d);

    Date& operator++();//��ǰ��++����ʽ��������

    Date operator++(int);//�Ժ���++����ʽ��������

    Date& operator--();//�Ժ���--����ʽ��ȥ����

    Date operator--(int);//�Ժ���--����ʽ��ȥ����

    int operator-(Date& d) const;//�����������

    //Date* operator&();//��ȡ��ͨ����ĵ�ַ

    //const Date* operator&() const;//��ȡconst����ĵ�ַ

private:
    int _year;
    int _month;
    int _day;
};  