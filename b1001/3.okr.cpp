/*
    Лекция 6
    Табуляция, указатель на функцию
*/
#include <iostream>
#include <cmath>

class Point0
{

    double x, y;
public:
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
    void print(); // прототип функции
    double get_x()
    {
        return x;
    }
    double get_y()
    {
        return y;
    }
    void set(double xv, double yv)
    {
        x = xv;
        y = yv;
    }
};
typedef double(*fun)(double);

double f1(double x)
{
    return x*sin(x);
}
double f2(double x)
{
    return cos(x)*x;
}

class Baza_tab
{
    double a, b;
    int n;
    Point0 *z;
public:
    Baza_tab(){}
    Baza_tab(double av, double bv, int nv)
    {
        a = av;
        b = bv;
        n = nv;
        z = new Point0[n];
    }
    int get_n()
    {
        return n;
    }
    Point0* tabul()
    {
        double x, h;
        for(int i = 0, h=(b-a)/n, x = a; i<n; i++)
        {
            z[i] = Point0(x, f1(x));
            x+=h;
        }
        return z;
    }
    Point0* tabul(double(*f)(double))
    {
        double x, h;
        for(int i = 0, h=(b-a)/n, x = a; i<n; i++)
        {
            z[i] = Point0(x, f(x));
            x+=h;
        }
        return z;
    }
};

class Okr
{
    Point0 center;
    double r;
public:
    Okr(double xv, double yv, double rv)
    {
        center.set(xv, yv);
        r = rv;
    }
    Okr(Point0& tv, double rv)
    {
        center = tv; // копируется полностью, не указатель
        r = rv;
    }
    double get_x()
    {
        return center.get_x();
    }
    Okr(){}
    void set_x(double xv, double yv)
    {
        center.set(xv, yv);
    }
};

void Point0::print() // реализация функции
{
    std::cout << "Hello from print function" << std::endl;
}

int main(void)
{
// ---
    Baza_tab pv;
    double a, b;
    int n, m;
    Point0 *z, *zz;
    a = -10;
    b = 20;
    n = 10;

    pv = Baza_tab(a, b, n);

    z = pv.tabul();
    for(int i = 0; i<pv.get_n(); i++)
    {
        std::cout << z[i].get_x() << " " << z[i].get_y() << std::endl;
    }

    std::cout << std::endl;

    zz = pv.tabul(f2);
    for(int i = 0; i<pv.get_n(); i++)
    {
        std::cout << zz[i].get_x() << " " << zz[i].get_y() << std::endl;
    }


// ---
    Point0 new_point = Point0(4,5);
    Okr new_okr = Okr(new_point,2);
    std::cout << new_okr.get_x() << std::endl;
    new_okr.set_x(1,1);
    std::cout << new_okr.get_x() << std::endl;
    std::cout << new_point.get_x() << std::endl;

    // копирование объекта, конструктор копирования вызывается по умолчанию
    Point0 point1 = Point0(8,9);
    Point0 point2;
    point2 = point1;
    std::cout << point2.get_x() << std::endl;



// ---
    fun fc[] = {f1, f2};
    Baza_tab *zv;
    m = 2;
    zv = new Baza_tab[m];
    
    a = -10;
    b = 10;
    n = 10;

    Point0* t1 = new Point0[n];

    for(int i = 0; i < m; i++)
    {
        zv[i] = Baza_tab(a, b, n);
        a += 5;
        b += 10;
        t1 = zv[i].tabul(fc[i]);
        for(int j = 0; j < n; j++)
        {
            std::cout << t1[j].get_x() << " " << t1[j].get_y() << std::endl;
        }
    }

    delete [] zv;
    delete [] t1;

// ---

    double(*p[])(double) = {f1, f2};
    std::cout << p[0](0.5) << std::endl;

    return 0;
}