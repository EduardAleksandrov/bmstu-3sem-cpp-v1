#include <iostream>

using namespace std;

namespace 
{
    int cur {0};
}

void fun(int&& value)
{
    
    // cout << value << " " << &value << endl; //!после того как передали value перестает быть rvalue, нужно явно указывать что это путем move(value)
    int* vp = &value;
    *vp = 7;
    // cout << value << " " << &value << endl;
    cur++;
    if(cur >= 3) return;
    fun(move(value)); //! ВОТ
    return;

}
int main()
{   
    int x = 5;
    int y;
    y = move(x);
    cout << y << " " << x << " " << &x << endl;
    fun(move(x));
    cout << x << endl;
    fun(6);
    cout << x << endl;

    x=5;
    int z = move(x); // объект сохраняется в памяти благодаря такой записи
    x=6;
    z=7;
    cout << z << " " << x <<" "<< &z << " "<< &x <<endl;
    
    return 0;
}