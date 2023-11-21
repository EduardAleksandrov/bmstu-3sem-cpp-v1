/*
    Лекция 10
    Шаблоны
*/
#include <iostream>
#include <typeinfo>
#include <cmath>

template<class T>
class Matrixt
{
    T** a;
    int n, m;
public:
    Matrixt();
    Matrixt(int n1, int n2);
    Matrixt(const Matrixt&r);
    void set_matrix();
    void get_matrix();
    Matrixt& operator*(const Matrixt<T>&r);
    Matrixt& operator=(const Matrixt<T>&r);
    Matrixt& transponirov();
    friend std::istream& operator>>(std::istream&in, const Matrixt <T>&r)
    {
        for(int i = 0; i<r.n; i++)
            for(int j = 0; j<r.m; j++)
                in>>r.a[i][j];
        return in;
    }
};

template<class T>
Matrixt <T>::Matrixt(int n1, int m1): n{n1}, m{m1}
{
    a = new T*[n];
    for(int i = 0; i<n;i++)
        a[i] = new T[m];
}
template<class T>
Matrixt <T>::Matrixt(): n{1}, m{1}
{
    a = new T*[n];
    for(int i = 0; i<n;i++)
        a[i] = new T[m];
}
template<class T>
Matrixt <T>::Matrixt(const Matrixt<T>& r)
{
    int i,j;
    a = new T*[r.n];
    for(int i = 0; i<r.n; i++)
        a[i] = new T*[r.m];
    for(int i = 0; i<n; i++)
        for(int j = 0; j <m;j++)
            a[i][j] = r.a[i][j];
}
template<class T>
void Matrixt<T>::set_matrix()
{
    T min = 0;
    T max = 150;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
        {
            if(typeid(max).name()==typeid(2).name()) a[i][j]= min + rand() % (int)(max - min + 1); 
            if(typeid(max).name()==typeid(2.0).name() || typeid(max).name()==typeid(2.0f).name())
            {
                T value = rand() % (int)pow(10, 4);
                a[i][j] = min + (value / pow(10, 4)) * (max - min);
            }
        }
    // std::cout <<(typeid(min).name()==typeid(2.0).name());
}
template<class T>
void Matrixt<T>::get_matrix()
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            std::cout << a[i][j]<<" ";
        std::cout << std::endl;
    }
}
template<class T>
Matrixt<T>& Matrixt<T>::operator*(const Matrixt<T>&r)
{
    int i, j, k;
    Matrixt *z;
    z=new Matrixt(n, r.m);
    for(i=0;i<n;i++)
        for(j=0;j<r.m;j++)
            for(k=0, z->a[i][j]=0;k<m;k++)
                z->a[i][j]+=(a[i][k]*r.a[k][j]);
    return *z;
}
template<class T>
Matrixt<T>& Matrixt<T>::operator=(const Matrixt<T>& r)
{
    if(&r!=this) 
    {
        m = r.m;
        n = r.n;
        for(int i =0 ; i<n;i++)
            for(int j = 0;j<m;j++)
                a[i][j] = r.a[i][j];
    }
    return *this;
}
template <class T>
Matrixt <T>& Matrixt<T>::transponirov()
{
    int i,j;
    Matrixt *fp = new Matrixt(m,n);
    for(i = 0; i<n; i++)
        for(j=0;j<m;j++)
            fp->a[j][i] = a[i][j];
    return *fp;
}
int main()
{
    srand(time(NULL));
    Matrixt<double> a(1,3);
    Matrixt<double> b(3,1);
    a.set_matrix();
    a.get_matrix();
    b.set_matrix();
    b.get_matrix();

    Matrixt <double> ct;
    ct = a*b;
    ct.get_matrix();

    Matrixt <double> pt;
    pt = b.transponirov();
    pt.get_matrix();
    // Matrixt<double> p1;
    // p1 = pt*ct;
    // p1.get_matrix();
    
    Matrixt<double> ci(1,3);
    std::cin >> ci;
    ci.get_matrix();



    return 0;
}