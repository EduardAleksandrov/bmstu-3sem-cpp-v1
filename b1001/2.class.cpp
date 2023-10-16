/*
    Лекция 5
*/
#include <iostream>
#include <cmath>

class Point0
{
public:
    double x, y;
    double rast0()
    {
        return sqrt(x*x + y*y);
    }
    int prov()
    {
        if(x>0 && y>0) return 1;
        else if(x<0 && y>0) return 2;
        else if(x<0 && y<0) return 3;
        else if(x>0 && y<0) return 4;
    }
    double rast(Point0& t)
    {
        return sqrt((x-t.x)*(x-t.x) + (y-t.y)*(y-t.y));
    }
    Point0(){}
    Point0(double xv, double yv)
    {
        x = xv;
        y = yv;
    }
    Point0(Point0& t)
    {
        x = t.x;
        y = t.y;
    }
    Point0(Point0&& t)
    {
        x = t.x;
        y = t.y;
    }
    void print(); // прототип функции
};

void Point0::print() // реализация функции
{
    std::cout << "Hello from print function" << std::endl;
}

int main(void)
{
    Point0 dot;
    dot.x = 5;
    dot.y = 6;
    // std::cout << dot.x << " " << dot.y << " " << dot.rast0() << std::endl;

    Point0 dot2 = Point0(4, 3);
    // Point0 dot2(5, 6);
    // Point0 dot2{5, 6};
    // std::cout << dot2.x << " " << dot2.y << " " << dot2.rast0() << std::endl;

    dot.print();


// для матрицы расстояний
    double xc[] = {3, 2, 6};
    double yc[] = {7, 12, 9};
    int n = 3;
    Point0* z = new Point0[n]; //вызывается конструктор по умолчанию
    for(int i = 0; i < n; i++) // можно вызвать конструктор
    {
        z[i].x = xc[i];
        z[i].y = yc[i];
        // std::cout << z[i].x << " " << z[i].y  << std::endl;
    }
    double** a = new double*[n];
    for(int i = 0; i < n; i++)
        a[i] = new double[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[i][j] = z[i].rast(z[j]);
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
//очистка
    for(int i = 0; i<n; i++)
        delete [] a[i];
    delete [] a;
    delete [] z;

// rvalue
    Point0 rv = Point0(Point0(11, 12));
    std::cout << rv.x << " " << rv.y << std::endl;


    return 0;
}