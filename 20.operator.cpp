#include <iostream>
using std::cout, std::endl;

class One
{
public:
    One(int xx, int yy=0): x{xx}, y{yy}{}
    void print();
    One operator+(const One&);
    One& operator=(const One&) = default;
    ~One(){cout << "деструктор" << endl;}
    
private:
    int x;
    int y;
};

void One::print()
{
    cout << x << " " << y << endl;
}
One One::operator+(const One& t)
{
    One tmp{0,0};
    tmp.x = x + t.x;
    tmp.y = y + t.y;
    return tmp;
}
int operator"" _minute(unsigned long long n) //пользовательский литерал
{
    return 60*n;
}

void fun(One&& x)
{
    x.print();
}

int main()
{
    One o{2,1}; //если нет конструктора, то идет почленная инициализация
    One t(3);   //если нет конструктора, то ошибка

    o.print();
    t.print();

    One th = o+t;
    th.print();

    int result = 5_minute;
    cout << result << endl;



    if (__cplusplus == 202101L) std::cout << "C++23";
    else if (__cplusplus == 202002L) std::cout << "C++20";
    else if (__cplusplus == 201703L) std::cout << "C++17";
    else if (__cplusplus == 201402L) std::cout << "C++14";
    else if (__cplusplus == 201103L) std::cout << "C++11";
    else if (__cplusplus == 199711L) std::cout << "C++98";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n";

    fun(One(3,4));

    return 0;
}