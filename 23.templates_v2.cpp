#include <iostream>
#include <type_traits>

using std::cout, std::endl;

template<typename T>
struct Integer
{
    T n;
};

template<bool C, typename T, typename F>
struct Conditional
{
    using type = T;
    char c;
};
template<typename T, typename F>
struct Conditional<false, T, F>
{
    using type = F;
    int c;
};

int main()
{
    Integer <int> s{5};
    cout << s.n << " " << std::is_pod<Integer<int>>::value<< endl;
    
    typename Conditional<true, char, int>::type ss; // тип вычисляется во время компиляции
    ss = 'h';
    cout << ss << endl;

    return 0;
}