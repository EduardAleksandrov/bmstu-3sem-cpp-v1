#include <iostream>
#include <vector>

//  вычисление средних значений по заданному критерию
void computeMiddleValue(int *, int);
// сортировка простым обменом
void sortSimpleExchange(int *, int);
// линейная сортировка
void sortLineExchange(int *, int);
// найти imax, jmax, a[imax][jmax]
void searchMaxElem(int **, int, int);
// выписать четные числа
void evenNumbers(int **, int, int);
// обмен элементов строк в матрице
void linesExchange(int **, int, int);

int main(void)
{

    int ac[] {5,3,6,1,-8,9,33,51,68};

// инициализация
    int **a {new int*[3]};
    for(int i = 0; i<3; i++)
        *(a+i) = new int [3];   //a[i]   *-это есть указатель(не разыменование) инициализация
// запись
    int k {0};
    for(int i = 0; i<3; i++)
        for(int j=0; j<3;j++)
            a[i][j] = ac[k++];
// печать
    for(int i = 0; i<3;i++)
    {
        for(int j=0; j<3;j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    } 
    std::cout << sizeof(a)/sizeof(*a) << std::endl; // длину массива созданного через указатели найти нельзя
    // int length = sizeof(ac)/sizeof(*ac);
    // for(int i = 0; i<length; i++)
    //     std::cout << ac[i] << std::endl;


    computeMiddleValue(ac, sizeof(ac)/sizeof(*ac));
    sortSimpleExchange(ac, sizeof(ac)/sizeof(*ac));
    sortLineExchange(ac, sizeof(ac)/sizeof(*ac));
    searchMaxElem(a, 3, 3);
    evenNumbers(a, 3, 3);
    linesExchange(a, 3, 3);



// очистка
    for(int i = 0; i<3; i++)
        delete[] a[i];
    delete[] a;

    std::getchar();

    return 0;
}

void computeMiddleValue(int *a, int n)
{
    float s = 0;
    for(int i = 0, k = 0; i < n; i++)
    {
        if(a[i] % 2 == 0 && a[i] > 0)
        {
            s+=a[i];
            k++;
        }
        if(k > 0)
            s/=k;
    }
    std::cout << s << std::endl;
}

void sortSimpleExchange(int *a, int n)
{
    bool flag = 1;
    while(flag)
    {   
        flag = 0;
        for(int i = 0; i<n-1; i++)
        {
            if(a[i]>a[i+1])
            {
                int buf = a[i];
                a[i] = a[i+1];
                a[i+1] = buf;
                flag = 1;
            }
        }
    }
    for(int i = 0; i< n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void sortLineExchange(int *a, int n)
{

    for(int i = 0; i<n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(a[i]<a[j])
            {
                int buf = a[i];
                a[i] = a[j];
                a[j] = buf;
            }
        }
    }
    for(int i = 0; i< n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void searchMaxElem(int **a, int n, int m)
{
    int z = a[0][0];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            if(a[i][j]>z) 
            {
                int imax = i;
                int jmax = j;
                z = a[i][j];
            }
    std::cout << z << std::endl;

}

void evenNumbers(int **a, int n, int m)
{
    // std::vector <int> s;
    int s[40];
    int k = 0;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            if(a[i][j] % 2 == 0 && a[i][j]>0)
            {
                // s.push_back(a[i][j]);
                s[k++] = a[i][j];
            }
    // for(int i: s)
    //     std::cout << i << " ";
    for(int i = 0; i<k; i++)
    {
        std::cout << s[i] << " ";
    }
    std::cout << std::endl;
}

void linesExchange(int **a, int n, int m)
{
    int i {1};
    for(int j = 0; j< m; j++)
    {
        int buf = a[i][j];
        a[i][j] = a[i+1][j];
        a[i+1][j] = buf;
    }

    for(int i = 0; i<n;i++)
    {
        for(int j=0; j<m;j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    } 
}


