#include "Date.h"

int Date::GetMonthDay(int year, int month)//获取对应月份的天数
{
    static int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        return 29;

    return MonthDay[month];
}

bool Date::operator==(const Date& d) const//以==比较两个日期是否相等
{
    return _year == d._year
        && _month == d._month
        && _day == d._day;
}

bool Date::operator!=(const Date& d) const//以！=的形式比较两个日期是否相等
{
    return !(*this == d);
}

Date& Date::operator+=(int day)//获取日期加上一定天数后得到的日期（会修改原对象）
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

Date Date::operator+(int day)//获取日期加上一定天数后得到的日期（不会修改原对象）
{
    if (day < 0)
        return *this - -day;

    Date ret(*this);
    ret += day;

    return ret;
}

Date& Date::operator-=(int day)//获取日期减去一定天数后得到的日期（会修改原对象）
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

Date Date::operator-(int day)//获取日期减去一定天数后得到的日期（不会修改原对象）
{
    if (day < 0)
        return *this + -day;

    Date ret(*this);
    ret -= day;

    return ret;
}

bool Date::operator<(const Date& d) const//以小于的形式比较日期的大小
{
    if (_year < d._year)
        return true;
    else if (_year == d._year && _month < d._month)
        return true;
    else if (_year == d._year && _month == d._month && _day < d._day)
        return true;

    return false;
}

bool Date::operator<=(const Date& d) const//以小于等于的形式比较日期的大小
{
    return *this < d || *this == d;
}

bool Date::operator>(const Date& d) const//以大于的形式比较日期的大小
{
    return !(*this <= d);
}

bool Date::operator>=(const Date& d) const//以大于等于的形式比较日期的大小
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

Date& Date::operator++()//以前置++的形式增加日期
{
    return *this += 1;
}

Date Date::operator++(int)//以后置++的形式增加日期
{
    Date ret(*this);
    *this += 1;

    return ret;
}

Date& Date::operator--()//以前置--的形式减去日期
{
    return *this -= 1;
}

Date Date::operator--(int)//以后置--的形式减去日期
{
    Date ret(*this);
    *this -= 1;

    return ret;
}

int Date::operator-(Date& d) const//两个日期相减
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

ostream& operator<<(ostream& out, const Date& d)//流插入符<<的重载
{
    out << d._year << "-" << d._month << "-" << d._day << endl;
    
    return out;
}

istream& operator>>(istream& in, Date& d)//流提取符>>的重载
{
    in >> d._year >> d._month >> d._day;

    return in;
}

//Date* Date::operator&()//获取普通对象的地址
//{
//    return this;
//}
//
//const Date* Date::operator&() const//获取const对象的地址
//{
//    return this;
//}