#pragma once
#include <iostream>
using namespace std;

class Date
{
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);


public:
    Date(int year = 1, int month = 1, int day = 1)//构造函数
        :_year(year)
        ,_month(month)
        ,_day(day)
    {
        if ((year < 0)
            || (month <= 0 || month >= 13)
            || (day <= 0 || day > GetMonthDay(year, month)))
            cout << "非法日期" << endl;
    }

    Date(const Date& d)//拷贝构造函数
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    ~Date()//析构函数
    {
        _year = _month = _day = 0;
    }

    int GetMonthDay(int year, int month);//获取对应月份的天数

    bool operator==(const Date& d) const;//比较两个日期是否相等

    bool operator!=(const Date& d) const;//以！=的形式比较两个日期是否相等

    Date& operator+=(int day);//获取日期加上一定天数后得到的日期（会修改原对象）

    Date operator+(int day);//获取日期加上一定天数后得到的日期（不会修改原对象）

    Date& operator-=(int day);//获取日期减去一定天数后得到的日期（会修改原对象）

    Date operator-(int day);//获取日期减去一定天数后得到的日期（不会修改原对象）

    bool operator<(const Date& d) const;//以小于的形式比较日期的大小

    bool operator<=(const Date& d) const;//以小于等于的形式比较日期的大小

    bool operator>(const Date& d) const;//以大于的形式比较日期的大小

    bool operator>=(const Date& d) const;//以大于等于的形式比较日期的大小

    Date& operator=(const Date& d);

    Date& operator++();//以前置++的形式增加日期

    Date operator++(int);//以后置++的形式增加日期

    Date& operator--();//以后置--的形式减去日期

    Date operator--(int);//以后置--的形式减去日期

    int operator-(Date& d) const;//两个日期相减

    //Date* operator&();//获取普通对象的地址

    //const Date* operator&() const;//获取const对象的地址

private:
    int _year;
    int _month;
    int _day;
};  