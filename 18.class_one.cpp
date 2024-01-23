#include <iostream>

using std::cout, std::endl;

class Date
{
    int d, m, y;

    protected: // protected используется при наследовании, для объектов класса он также закрыт
    int x;

    public:
    int zz;
    static Date default_date; //!композиция
    Date(int dd = 0, int mm = 0, int yy = 0, int xx = 55);
    Date();
    void init(int, int, int, int);
    void print();
};
Date::Date(int dd, int mm, int yy, int xx): d{dd}, m{mm}, y{yy}, x{xx} {cout<<"Конструктор";}
Date::Date(){cout<<"Конструктор базовый";}
void Date::init(int dd, int mm, int yy, int xx)
{
    d = dd;
    m = mm;
    y = yy;
    x = xx;
}
void Date::print()
{
    cout << x << endl;
}

Date Date::default_date {1,2,2004,12}; //статический член обязательно определить

class Time: public Date
{
public:
    Time():Date(1,2,3,4){}
};

int main()
{
    Date dt {1,2,3,6};
    dt.print();
    dt.init(5, 12, 2023, 8);
    dt.print();

    Date::default_date.print();

    // int xx = dt.x;       // protected используется при наследовании, для объектов класса он также закрыт

    Time t;
    t.zz = 5;

    int m = 5;
    int* mm = std::move(&m);
    cout << endl<< &m << " "<< mm<< "\n";

    Date* dtr = &t;
    cout << dtr->zz <<endl;

    return 0;
}