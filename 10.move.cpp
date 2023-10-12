#include <iostream>

using namespace std;

void fun(int&& value)
{
    
    cout << value << " " << &value << endl;

    int* vp = &value;
    *vp = 7;
    cout << value << " " << &value << endl;

}
int main()
{   
    int x = 5;
    int y;
    y = move(x);
    cout << y << " " << x << " " << &x << endl;
    fun(move(x));
    fun(6);
    cout << x << endl;
    
    return 0;
}