#include <iostream>


int main()
{
    const char* p = "Hello";
    const char* pn = "Hello";

    if(p==pn) std::cout << "one!" << std::endl;

    int* u = nullptr;
    if(u == nullptr) std::cout << "nullptr yes" << std::endl;

    int a[3] = {1,2,3};
    int i = 2;
    std::cout << a[i] << " " << i[a] << std::endl;

    return 0;
}
