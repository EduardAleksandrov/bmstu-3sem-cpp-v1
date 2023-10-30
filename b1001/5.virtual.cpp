/*
    Лекция 8
    Динамический полиморфизм
*/
#include <iostream>
#include <cmath>

using namespace std;

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

class Baza_Integ_Virt
{
protected:
    double a, b;
    fun f;
    long int n;
public:
    virtual double integral(double eps) = 0;
    Baza_Integ_Virt(double av, double bv, fun ff): a{av}, b{bv}, f{ff}
    {
        n = 100;
    }
    Baza_Integ_Virt(){}
};

class Integ_trap_virt: public Baza_Integ_Virt
{
public:
    Integ_trap_virt(double av, double bv, fun ff): Baza_Integ_Virt(av, bv, ff){}
    Integ_trap_virt(){}
    double integral(double eps)
    {
        double s,sp,h,d,x;
        long int i,j;
        sp = 0;
        d = 1;
        while(fabs(d)>eps)
        {
            for(h=(b-a)/n, s = (f(a)+f(b))*(h/2), i = 1, x = a; i<n-1; i++)
            {
                x+=h;
                s+=(f(x)*h);
            }
            d = s-sp;
            sp = s;
            n=n*10;
        }
        return s;
    }
};
class Integ_rect_virt: public Baza_Integ_Virt
{
public:
    Integ_rect_virt(double av, double bv, fun ff): Baza_Integ_Virt(av, bv, ff){}
    Integ_rect_virt(){}
    double integral(double eps)
    {
        double s,sp,h,d,x;
        long int i,j;
        sp = 0;
        d = 1;
        while(fabs(d)>eps)
        {
            for(h=(b-a)/n, i = 0, s = 0, x = a; i<n; i++)
            {
                s+=f(x)*h;
                x+=h;
            }
            d = s-sp;
            sp = s;
            n=n*10;
        }
        return s;
    }
};

int main()
{
    Baza_Integ_Virt *df_trap, *df_rect;

    df_trap = new Integ_trap_virt(-1,1,f1);
    cout << df_trap->integral(0.1) << endl;

    df_rect = new Integ_rect_virt(-1,1,f1);
    cout << df_rect->integral(0.1) << endl;

    int m;
    m = 2;
    Baza_Integ_Virt *pt[m];
    pt[0] = new Integ_trap_virt(-1, 1, f1);
    pt[1] = new Integ_rect_virt(-1, 1, f1);
    for(int i = 0; i<m; i++)
        cout<<pt[i]->integral(0.0001) << endl;


    return 0;
}