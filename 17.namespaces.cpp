#include <iostream>
#include "17.ns.hpp"

#include <cstdio>

using std::cout;

namespace { // видно в текущей единице трансляции (в текущем файле)
    int hello {5};
}
int main()
{
    // Parser::print2();
    Parser::print1();

    cout << hello << "\n";

    printf("Hi \n");

    return 0;
}