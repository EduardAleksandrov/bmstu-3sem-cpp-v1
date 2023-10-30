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

class Baza_poisk
{
protected:
    double a, b;
    fun f;
public:
    Baza_poisk(double av, double bv, fun ff): a{av}, b{bv}, f{ff}{}
    Baza_poisk(){}
    virtual double poisk(double eps) = 0;
};

class Pol_del: public Baza_poisk
{
public:
    double poisk(double eps)
    {
        double c;
        c = (a+b)/2;
        int i{0};
        while(fabs(f(c)>eps) && fabs(b-a)>eps && i<10000)
        {
            c = (a+b)/2;
            if(f(a)*f(c)<0) b = c;
            else a = c;
            i++;
        }
        return c;
    }
    Pol_del(double av, double bv, fun ff): Baza_poisk(av, bv, ff){}
    Pol_del(){}

};

class Met_hord: public Baza_poisk
{
public:
    double poisk(double eps)
    {
        double d, xt, xp, fa, fb, fx;
        int n;
        fa=f(a);
        fb=f(b);
        xt = a - fa*((b-a)/(fb-fa));
        d=1;
        n=0;
        fx=f(xt);
        while(fabs(fx)>eps && n< 10000)
        {
            if(fa*fx < 0)
            {
                b=xt;
                fb=fx;
            } else {
                a=xt;
                fa=fx;
            }
            xt = a - fa*((b-a)/(fb-fa));
            fx = f(xt);
            d=xt-xp;
            xp=xt;
            n++;
        }
        return xt;
    }
    Met_hord(double av, double bv, fun ff): Baza_poisk(av, bv, ff){}
    Met_hord(){}

};

int main()
{
    Baza_poisk *fp;
    fp = new Pol_del(-7,-6,f1);
    cout << fp->poisk(0.0001) << endl;

    Baza_poisk *fp_hord;
    fp_hord = new Met_hord(-7,-6,f1);
    cout << fp_hord->poisk(0.0001) << endl;


    return 0;
}