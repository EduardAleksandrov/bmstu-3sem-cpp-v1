/*
    Лекция 9
    Перегрузка операторов
*/
#include <iostream>

class Array
{
    int *ptr;
    int size;
public:
    Array();
    Array(int);
    Array(const Array&);
    ~Array();
    void setArray();
    void setsArray(int*);
    void getArray();
    Array* operator+(Array&);
    Array& operator-(Array&);
    Array& operator*(Array&);
    int seach(int key);
};
Array::Array(): size{1}
{
    ptr = new int[size];
}
Array::Array(int n): size {n}
{
    ptr = new int[size];
    for(int i = 0; i< size; i++)
        ptr[i] = 0;
}
Array::Array(const Array& arr): size {arr.size}
{
    ptr = new int[size];
    for(int i = 0; i < size; i++)
        ptr[i] = arr.ptr[i];
}
void Array::setArray()
{
    for(int i = 0; i< size; i++)
        std::cin>>ptr[i];
}
void Array::setsArray(int* xc)
{
    for(int i = 0; i<size; i++)
        ptr[i] = xc[i];
}
void Array::getArray()
{
    for(int i = 0; i<size; i++)
        std::cout << ptr[i];
    std::cout << std::endl;
}
Array::~Array()
{
    delete [] ptr;
}
Array* Array::operator+(Array& rt)
{
    Array* r;
    int i;
    r = new Array(size);
    for(i = 0; i<size; i++)
        r->ptr[i] = ptr[i]+rt.ptr[i];
    return r;
}
Array& Array::operator-(Array& rt)
{
    Array* r;
    int i;
    r = new Array(size);
    for(i = 0; i<size; i++)
        r->ptr[i] = ptr[i]-rt.ptr[i];
    return *r;
}
int Array::seach(int key)
{
    for(int i =0; i < size; i++)
        if(key == ptr[i]) return i;
    return -1;
}
Array& Array::operator*(Array& rt) // пересечение массивов
{
    Array* r;
    int i, k;
    r = new Array(size);
    for(i = 0, k=0;i <rt.size; i++)
        if(seach(rt.ptr[i]) < 0)
            r->ptr[k++] = rt.ptr[i];
    Array* rn;
    rn = new Array(k);
    for(i=0;i<k;i++)
        rn->ptr[i] = r->ptr[i];
    delete [] r->ptr;
    return *rn;

}

int main()
{
    int xc[5] = {1,2,3,4,5};
    int yc[5] = {1,7,3,8,5};
    int i,j,n,m;
    n=5;
    m=5;
    Array a1 = Array(n);
    Array a2 = Array(m);
    a1.setsArray(xc);
    a2.setsArray(xc);
    Array a3 = Array(a1);
    a3.getArray();

    Array* b;
    b = a1+a2;
    b->getArray();
    Array c;
    c = a1-a2;
    c.getArray();

    Array a11 = Array(n);
    Array a22 = Array(m);
    a11.setsArray(xc);
    a22.setsArray(yc);
    Array a5;
    a5 = a11*a22;
    a5.getArray();

    return 0;
}