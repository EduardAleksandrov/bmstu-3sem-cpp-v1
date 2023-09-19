// Лекция 2: сделано на 2 занятии на лабораторной
// среднее значение расстояния между всеми точками
#include <iostream>

struct point
{
    double x, y;
};
struct line
{
    point t1, t2;
    double k, b;
};
struct middle
{
    double x, y;
};

int main(void)
{
    int n = 5;
    int x[5] = {4,8,3,2,9};
    int y[5] = {5,1,9,4,2};

    point *t1 = new point[n];
    for(int i = 0; i < n; i++)
    {
        t1[i].x = x[i];
        t1[i].y = y[i];
    }

    for(int i = 0; i < n; i++)
        std::cout << "x: " << t1[i].x << " y:" << t1[i].y << std::endl;

    //поиск среднего арифметического точек
    middle *mid = new middle[0];
    int k = 0;
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
        {
            middle* new_tmp = new middle[k+1];
            for(int l = 0; l < k; l++)
            {
                new_tmp[l].x = mid[l].x;
                new_tmp[l].y = mid[l].y;
            }
                
            delete[] mid;
            mid = new_tmp;
            
            mid[k].x = (t1[i].x+t1[j].x)/2;
            mid[k].y = (t1[i].y+t1[j].y)/2;
            k++;
            
            
        }
    for(int i=0; i<k; i++)
        std::cout << mid[i].x <<" "<< mid[i].y << std::endl;

    delete[] t1;
    delete[] mid;





    std::getchar();

    return 0;
}




