// Вычисления на этапе компиляции
#include <iostream>
#include <cassert>

using std::cout, std::endl;

constexpr bool fun() //вычисляет в момент компиляции
{
    return (1==12 && 2!=3);
}
void zero(int&& n)
{
    cout << n << endl;
}

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

    return 0;
}