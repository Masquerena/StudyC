#include "Date.h"

int Date::GetMonthDay(int year, int month)//��ȡ��Ӧ�·ݵ�����
{
    static int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        return 29;

    return MonthDay[month];
}

bool Date::operator==(const Date& d) const//��==�Ƚ����������Ƿ����
{
    return _year == d._year
        && _month == d._month
        && _day == d._day;
}

bool Date::operator!=(const Date& d) const//�ԣ�=����ʽ�Ƚ����������Ƿ����
{
    return !(*this == d);
}

Date& Date::operator+=(int day)//��ȡ���ڼ���һ��������õ������ڣ����޸�ԭ����
{
    if (day < 0)
        return *this -= -day;

    _day += day;
    while (_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        ++_month;

        if (_month == 13)
        {
            _month = 1;
            ++_year;
        }
    }

    return *this;
}

Date Date::operator+(int day)//��ȡ���ڼ���һ��������õ������ڣ������޸�ԭ����
{
    if (day < 0)
        return *this - -day;

    Date ret(*this);
    ret += day;

    return ret;
}

Date& Date::operator-=(int day)//��ȡ���ڼ�ȥһ��������õ������ڣ����޸�ԭ����
{
    if (day < 0)
        return *this += -day;

    _day -= day;
    while (_day <= 0)
    {
        --_month;
        if (_month == 0)
        {
            --_year;
            _month = 12;
        }

        _day += GetMonthDay(_year, _month);        
    }

    return *this;
}

Date Date::operator-(int day)//��ȡ���ڼ�ȥһ��������õ������ڣ������޸�ԭ����
{
    if (day < 0)
        return *this + -day;

    Date ret(*this);
    ret -= day;

    return ret;
}

bool Date::operator<(const Date& d) const//��С�ڵ���ʽ�Ƚ����ڵĴ�С
{
    if (_year < d._year)
        return true;
    else if (_year == d._year && _month < d._month)
        return true;
    else if (_year == d._year && _month == d._month && _day < d._day)
        return true;

    return false;
}

bool Date::operator<=(const Date& d) const//��С�ڵ��ڵ���ʽ�Ƚ����ڵĴ�С
{
    return *this < d || *this == d;
}

bool Date::operator>(const Date& d) const//�Դ��ڵ���ʽ�Ƚ����ڵĴ�С
{
    return !(*this <= d);
}

bool Date::operator>=(const Date& d) const//�Դ��ڵ��ڵ���ʽ�Ƚ����ڵĴ�С
{
    return !(*this < d);
}

Date& Date::operator=(const Date& d)
{
    _year = d._year;
    _month = d._month;
    _day = d._day;

    return *this;
}

Date& Date::operator++()//��ǰ��++����ʽ��������
{
    return *this += 1;
}

Date Date::operator++(int)//�Ժ���++����ʽ��������
{
    Date ret(*this);
    *this += 1;

    return ret;
}

Date& Date::operator--()//��ǰ��--����ʽ��ȥ����
{
    return *this -= 1;
}

Date Date::operator--(int)//�Ժ���--����ʽ��ȥ����
{
    Date ret(*this);
    *this -= 1;

    return ret;
}

int Date::operator-(Date& d) const//�����������
{
    Date max = *this;
    Date min = d;
    int flag = 1;

    if (*this < d)
    {
        max = d;
        min = *this;
        flag = -1;
    }

    int n = 0;
    while (min != max)
    {
        ++min;
        ++n;
    }
    return flag * n;
}

ostream& operator<<(ostream& out, const Date& d)//�������<<������
{
    out << d._year << "-" << d._month << "-" << d._day << endl;
    
    return out;
}

istream& operator>>(istream& in, Date& d)//����ȡ��>>������
{
    in >> d._year >> d._month >> d._day;

    return in;
}

//Date* Date::operator&()//��ȡ��ͨ����ĵ�ַ
//{
//    return this;
//}
//
//const Date* Date::operator&() const//��ȡconst����ĵ�ַ
//{
//    return this;
//}