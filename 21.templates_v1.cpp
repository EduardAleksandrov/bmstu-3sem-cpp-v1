// Вычисления на этапе компиляции
// Замыкания
#include <iostream>
#include <cassert>
#include <functional>

using std::cout, std::endl;

//!вычисляет в момент компиляции
constexpr bool fun() 
{
    return (1==12 && 2!=3);
}
void zero(int&& n)
{
    cout << n << endl;
}
// ---

//!замыкание
typedef int(*cl)();
using cll = std::function<int()>;
cll closure()
{
    int z = 5;
    auto f = [=]()mutable->int{int x = 5; return x+(z++);};
    return f;
}
// ---

int main()
{
    constexpr bool x = fun();
    static_assert(x==0);
    const int xx = 5;
    static_assert(xx==5, "Error static assert");
    cout << x << endl;

    int v = 5;
    assert(("wrong number", v==5));

    zero(int{9}); //rvalue может быть передан по значению или по rvalue ссылке
    
    
    
    cll t = closure();
    cout << t() << " " << t() << endl;

    return 0;
}