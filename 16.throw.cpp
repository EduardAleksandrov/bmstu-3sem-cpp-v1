#include <iostream>


unsigned int fun()
{
    throw 1;
    return 5;
}

int main()
{
    try
    {
        unsigned int x = fun();
        std::cout << "i am ...!" << x << "\n";

    }
    catch(int err)
    {
        std::cerr << err << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "i am here!" << "\n";
    return 0;
}