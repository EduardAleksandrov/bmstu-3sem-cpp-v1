/*
    Лекция 7
    Табуляция, указатель на функцию
    Наследование
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
double f3(double x)
{
    return sin(x)+cos(x);
}

class Baza_tab
{
    double a, b;
protected:
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
        std::cout << "конструктор Baza_tab" << std::endl;

    }
    int get_n()
    {
        return n;
    }
    void init_z()
    {
        z = new Point0[n];
    }
    Point0* tabul()
    {
        // z = new Point0[n];
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
        // z = new Point0[n];
        double x, h;
        for(int i = 0, h=(b-a)/n, x = a; i<n; i++)
        {
            z[i] = Point0(x, f(x));
            x+=h;
        }
        return z;
    }
    ~Baza_tab()
    {
        std::cout << "Деструктор Baza_tub" << std::endl;

        if(n>0 && z != nullptr)
        {
            std::cout << "clear" << std::endl;

            delete [] z;
            z = nullptr;
        }
    }
};

class Interval_nul: public Baza_tab
{
    Point0 *p0;
    int m;
public:
    Interval_nul(double av, double bv, int nv): Baza_tab(av, bv, nv)
    {
        std::cout << "конструктор Interval_nul" << std::endl;
        p0 = 0;
        m = 0;
    }
    Interval_nul(): Baza_tab() {}
    Point0 *poisk_interval()
    {
        Point0* dt;
        int i, j;
        dt = new Point0[n];
        for(i = 0, j = 0; i < n-1; i++)
        {
            if(z[i].get_y()*z[i+1].get_y() < 0)
            {
                dt[j++] = Point0(z[i].get_x(), z[i+1].get_x());
            }
        }
        m = j;
        if(j>0)
        {
            p0 = new Point0[j];
            for(i = 0; i < j; i++)
            {
                p0[i] = dt[i];
            }
        }
        delete [] dt;
        return p0;
    }
    int get_m()
    {
        return m;
    }
    ~Interval_nul()
    {
        std::cout << "Деструктор interval_nul" << std::endl;
        if(m>0) 
        {
            delete [] p0;
        }
    }
};




int main(void)
{
// --- способ 1
    Interval_nul z;
    Point0 *t1, *t2;
    int i, j, n = 20;
    double a = -10, b = 20;

    z = Interval_nul(a, b, n); // создается временный объект и присваивается z
    // Interval_nul z = Interval_nul(a, b, n)  // создается z
    z.init_z();
    t1 = z.tabul(f1);
    t2 = z.poisk_interval();

    if(z.get_m()>0)
        for(i = 0; i < z.get_m(); i++)
            std::cout << t2[i].get_x() << " " << t2[i].get_y() << std::endl;
    
    
    std::cout << std::endl;

    
// --- способ 2 через массив
    // z = {};
    Interval_nul *zt;
    t1 = nullptr;
    t2 = nullptr;
    i = j = 0;
    int m;
    n = 3;
    double(*fc[])(double) = {f1, f2, f3};

    zt = new Interval_nul[n];
    for(i=0; i<n; i++)
    {
        zt[i] = Interval_nul(a, b, 20);
        zt[i].init_z();
        t1 = zt[i].tabul(fc[i]);
        t2 = zt[i].poisk_interval();
        m = zt[i].get_m();

        std:: cout << "Функция: " << i+1 << std::endl;
        if(m>0)
            for(j = 0; j < m; j++)
                std::cout << t2[j].get_x() << " " << t2[j].get_y() << std::endl;
        std::cout << std::endl;
    }
    delete [] zt;

    return 0;
}