#include <iostream>
#include <set>

int main()
{
    std::set<int> numbers {15, 2, 3, 4, 5};

    for(int i: numbers)
    {
        std::cout << i << std::endl;
    }

    int a {5};
    int b {6};

    bool c {a==b}; // можем присваивать логические выражения
    std::cout << c << std::endl;
    return 0;
}
