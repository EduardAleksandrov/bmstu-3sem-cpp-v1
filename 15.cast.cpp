// запись и чтение объекта в файл
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct One
{
    int x;
    int z;
    string yy;
    string y;
    vector<int> v;
};

void fun()
{
    auto f = []()->int{int x = 5; return x;};
}

int main()
{
    One t{5, 4, "bb", "h"};
    for(long int i=0; i<=110000000; i++)//! размер НЕ увеличивается при увеличении количества, ПОЧЕМУ
        t.v.push_back(1000000);
    cout<<sizeof(t)<<"\n";

    // cout << t.v.capacity()*sizeof(int) + sizeof(t.v) << "\n";

    int arr[3] = {4, 5, 6}; // размер увеличивается при увеличении количества
    cout<<sizeof(arr)<<"\n";

//запись и чтение из файла объекта
    int size = sizeof(t);
    ofstream out;          // поток для записи
    out.open("15.hello.dat", ios::out | ios::binary);
    char* p = reinterpret_cast<char*>(&t);
    for(int i = 0; i < size; i++)
        out.write((p++), 1);
    out.close();



    t.v.clear();
    for(long int i=0; i<=110000000; i++)//! ПОТОМУ ЧТО копируется указатель на динамическую память, в которой осталась старая информация о векторе
        t.v.push_back(1000001);         //! нужно копировать информацию из динамической памяти для точной сериализации объекта
    
    ifstream in;
    in.open("15.hello.dat", ios::in | ios::binary);
    One* pp = new One();
    char* c = reinterpret_cast<char*>(pp);
    int i{0};  // char
    // while ((i = in.get())!=EOF) // первый способ
    // {
    //     *c = i;
    //     c++;
    // }
    while ((in.read(c,(int)sizeof(char)))) //второй способ
    {
        c++;
        i++;
    }
    in.close();

    cout<< pp->v[10] <<"\n";
// ---

    cout << 1.0/3 << "\n";
    return 0;

}