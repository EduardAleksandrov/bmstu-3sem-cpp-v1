/*
    Лекция 14
    Ввод вывод из файла
*/
#include <iostream>
#include <fstream>
#include <string>

int prosmotr_file(std::string);
int** matr_in_file(std::string, int&, int&);
template <class T>
void zap_file(std::string, T**, int, int);

template <class T>
void readFl(std::string, T**&, int&, int&);

int main()
{
    int l;
    l = prosmotr_file("3.dat1.txt");

    int** c;
    int n1{0}, m1{0};
    c= matr_in_file("3.dat2.txt", n1, m1);
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < m1; j++)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }
        
    zap_file("3.dat1_zap.txt", c, n1, m1);

    double** d;
    readFl("3.dat3.txt", d, n1, m1);
    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < m1; j++)
        {
            std::cout << d[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}

int prosmotr_file(std::string name)
{
    std::ifstream f1;
    int i, k;
    f1 = std::ifstream(name);
    i=0;
    while(!f1.eof())
    {
        f1>>k;
        std::cout<<k<<" ";
        i++;
    }
    std::cout<<std::endl;

    f1.close();
    return i;
}

int** matr_in_file(std::string name, int& n, int& m)
{
    int** a;
    std::ifstream f;
    int i, j;
    f = std::ifstream(name);
    f>>n>>m;
    a = new int*[n];
    for(i = 0; i < n; i++)
        a[i] = new int[m];
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            f>>a[i][j];
    f.close();
    return a;
}

template <class T>
void zap_file(std::string name, T** a, int n, int m)
{
    std::ofstream f;
    int i, j;
    f = std::ofstream(name);
    for(i=0; i < n; i++)
    {
        for(j=0; j < m; j++)
        {
            f<< a[i][j] << " ";
        }
        f<<"\n"; 
    }
    //     
    f.close();

}

template <class T>
void readFl(std::string name, T**& a, int& n, int& m)
{
    std::ifstream f;
    f=std::ifstream(name);
    int i,j;
    f>>n>>m;
    a = new T*[n];
    for(i = 0; i < n; i++)
        a[i] = new T[m];
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            f>>a[i][j];
    f.close();
}





