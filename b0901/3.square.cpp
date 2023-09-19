// Лекция 3: расчет площади треугольника - работает
#include <iostream>
#include <math.h>

double square(double, double, double);

int main(void)
{
    // std::cout << square(4,4,4);


    double ac[] {5,3,6,1,8,9,4,4,4,5,5,5};
    // инициализация
    int n = 4;
    double **a {new double*[n]};
    for(int i = 0; i<n; i++)
        *(a+i) = new double [n]; 

    int k {0};
    for(int i = 0; i<n; i++)
        for(int j=0; j<n-1;j++)
            a[i][j] = ac[k++];

    for(int i = 0; i < n; i++)
        a[i][n-1] = square(a[i][0], a[i][1], a[i][2]);

    for(int i = 0; i<n;i++)
    {
        for(int j=0; j<n;j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::getchar();

    for(int i = 0; i<n; i++)
        delete[] a[i];
    delete[] a;
    a = nullptr;

    return 0;
}

double square(double a, double b, double c)
{
    double s, p;
    p = (a+b+c)/2;
    s = p*(p-a)*(p-b)*(p-c);
    if(s > 0)
        s = sqrt(s);
    else s = 0;
    return s;
}




