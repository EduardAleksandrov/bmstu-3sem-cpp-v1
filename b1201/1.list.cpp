/*
    Лекция 12
    Связанные списки с шаблонами
*/
#include <iostream>

template <class T>
class Elem
{
public:
    T data;
    Elem *next, *prev;
    Elem(T d): data {d}, next {0}, prev {0} {}
    static int n;
    int operator > (T& t)
    {
        if(data > t) return 1;
        else return 0;
    }
    void print()
    {
        data.print();
    }
};

template <class T>
int Elem<T>::n = 0;

template <class T>
class List
{
public:
    Elem<T> *first, *last, *cur;
    void add(T temp);
    void add_xwast(T temp);
    void print_list();
};

template <class T>
void List<T>::add(T temp)
{
    cur = new Elem<T>(temp);
    cur->n++;
    if(last)
    {
        last->next = cur;
        cur->prev = last;
        last = cur;
    }else {
        first = last = cur;
    }
}
template <class T>
void List<T>::print_list()
{
    cur = first;
    while(cur)
    {
        cur->print();
        cur=cur->next;
    }
}

class Rect
{
    double a, b, s;
public:
    Rect(){}
    Rect(double av, double bv): a{av}, b{bv} {}
    void print()
    {
        std::cout<< a << " " << b << " " << area() << std::endl;
    }
    double area()
    {
        return s = a*b;
    }
    int operator > (Rect& t)
    {
        if(area() > t.area()) return 1;
        else return 0;
    }
};

template <class T>
Elem <T>* poisk(List<T>*sp1)
{
    T d;
    Elem<T>*q;
    sp1->cur = sp1->first;
    d = sp1->cur->data;
    q = sp1->cur;
    while(sp1->cur->next)
    {
        if(sp1->cur->data > d)
        {
            d=sp1->cur->data;
            q=sp1->cur;
            // sp1->cur->data.print();
        }

        // sp1->cur->data.print();
        sp1->cur = sp1->cur->next;

        if(sp1->cur == sp1->last && sp1->cur->data > d)
        {
            d=sp1->cur->data;
            q=sp1->cur;
        }
    }
    return q;
}

int main(void)
{
    List<Rect>* spr;
    Rect pr[] = {Rect(95, 7), Rect(100, 70), Rect(195, 17), Rect(950, 71), Rect(4500, 54)};
    spr = new List<Rect>;
    int n=5;
    for(int i = 0; i < n; i++)
        spr->add(pr[i]);
    spr->print_list();

    std::cout << "n=" << Elem<Rect>::n << std::endl;

    Elem<Rect> *q;
    q = poisk(spr);
    std::cout << "max area: ";
    q->data.print();


    return 0;
}