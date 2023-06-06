#include <iostream>
#include "./2.two_linkfile_header.hpp"

// #include <cstdio>   //нужна для std::getchar();




int main()
{
// данные из linker
    std::cout << message << times << "\n" << std::endl;
    
// отладка программы 1) std::cin.get()  2) std::exit(0)
    // std::getchar();
    char x = std::cin.get();   // int x - получим код цифры в ASCII
    std::cout << x << '\n';
    std::exit(0);
    return 0;
}
