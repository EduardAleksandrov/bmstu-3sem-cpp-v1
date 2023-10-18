#include <iostream>


#include "11.one.hpp"
#include "11.two.hpp"


using namespace std;





int main()
{   
    int res = system("echo Hello system");
    if(!res) cout << "OK" << endl;
    else cout << "FAIL" << endl;

    
    return 0;
}