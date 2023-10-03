// Вернули из функции массив только положительных элементов + сортировка  -- через ссылку
#include <iostream>

void possitiveElements(int**, int, int, int*&, int*);
void sort_po(int*, int);
void obmen(int *, int *);


int main(void)
{
    int ac[] {5,3,-6,1,-8,9,-33,511,68};
    int n = 3, m = 3;

// инициализация
    int **a {new int*[n]};
    for(int i = 0; i<n; i++)
        *(a+i) = new int [m];   //a[i]   *-это есть указатель(не разыменование) инициализация
// запись
    int k {0};
    for(int i = 0; i<n; i++)
        for(int j=0; j<m;j++)
            a[i][j] = ac[k++];

    for(int i = 0; i<n;i++)
    {
        for(int j=0; j<m;j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

// поиск положительных
    int *result;
    int z;
    possitiveElements(a, n, m, result, &z);

    for(int i = 0; i < z; i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

// сортировка
    sort_po(result, z);

    for(int i = 0; i< z; i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;


// очистка
    for(int i = 0; i<n; i++)
        delete[] a[i];
    delete [] a;

    delete [] result;
    result = nullptr;






    return 0;
}
// плохой способ
// void possitiveElements(int **a, int n, int m, int *&result, int *z)
// {
    
//     int k = 0;
//     int *tmp = new int[k];
    
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < m; j++)
//         {
//             if(a[i][j] > 0)
//             {
//                 k++;
//                 tmp[k-1] = a[i][j];
//                 int* new_tmp = new int[k];
//                 for(int j = 0; j < k; j++)
//                     new_tmp[j] = tmp[j];
//                 delete[] tmp;
//                 tmp = new_tmp;

//             }
//         }
//     }

//     // *result = tmp;
//     result = tmp;
//     *z = k;
// }

void possitiveElements(int **a, int n, int m, int *&result, int *z)
{
    
    int k = 0;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] > 0)
            {
                k++;
            }
        }
    }
    if(k > 0)
    {
        result = new int[k];
        k = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] > 0)
                {
                    result[k++] = a[i][j];
                }
            }
        }
    }
    *z = k;
}

void sort_po(int *b, int n)
{
    int i, j, flag;
    flag = 1;
    while(flag)
    {
        flag = 0;
        for(i = 0; i < n-1; i++)
        {
            if(b[i]>b[i+1])
            {
                obmen(&b[i], &b[i+1]);
                flag = 1;
            }
        }
    }
}

void obmen(int *a, int *b)
{
    int buf;
    buf = *a;
    *a = *b;
    *b = buf;
}


