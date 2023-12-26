/*
    Лекция 13
    Связанные списки с шаблонами и граф
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
    void del_head();
};
template <class T>
void List<T>::del_head()
{
    Elem <T> *tmp;
    if(first->next)
    {
        tmp=first;
        first->next->prev = 0;
        first=first->next;
        delete tmp;
    } else if(first){
        tmp=first;
        delete tmp;
        first=0;
        last=0;
    }
}

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

class Rebro
{
public:
    int firstnum, lastnum;
    int vs;
    int metka;
    Rebro(int fn, int ln, int ves)
    {
        firstnum = fn;
        lastnum = ln;
        vs = ves;
        metka = 0;
    }
    void print()
    {
        std::cout << firstnum << " " << lastnum << " " << vs << std::endl;
    }
};

class Tnum 
{
public:
    int num;
    int prosmotr;
    Tnum(int x)
    {
        num = x;
        prosmotr = 0;
    }
    void print()
    {
        std::cout << num << " " << prosmotr << std::endl;
    }

};

int main(void)
{
    Rebro reb[9] = {Rebro(0,1,10), Rebro(0,3,12), Rebro(0,4,13),
                    Rebro(1,2,11), Rebro(4,5,14), Rebro(3,2,16),
                    Rebro(3,5,15), Rebro(2,6,17), Rebro(5,6,18)};
    // List <Rebro> gr;
    
    // for(int i = 0; i<9; i++)
    //     gr.add(reb[i]);

    List<Rebro>* gr;
    gr = new List<Rebro>;
    for(int i = 0; i<9; i++)
        gr->add(reb[i]);
    gr->print_list();

    return 0;
}