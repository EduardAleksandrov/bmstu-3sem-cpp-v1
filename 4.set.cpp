#include <iostream>
#include <set>

int main()
{
    std::set<int> numbers {15, 2, 3, 4, 5};

    for(int i: numbers)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
