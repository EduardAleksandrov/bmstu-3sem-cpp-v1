// Лекция 3: расчет пересечения линий - работает
#include <iostream>

struct pointf
{
    double x, y, z;
};
struct line
{
    pointf t1, t2;
    double k, b;
};

pointf form_p(line, line);

int main(void)
{
    pointf a1, a2, a3, a4;
    a1.x = 5;
    a1.y = 6;
    a2.x = 9;
    a2.x = 55;
    a3.x = 8;
    a3.y = 1;
    a4.x = 2;
    a4.x = 15;

    line l1;
    l1.t1 = a1;
    l1.t2 = a2;
    l1.k = 5;
    l1.b = 8;

    line l2;
    l2.t1 = a3;
    l2.t2 = a4;
    l2.k = 1;
    l2.b = 12;
    
    pointf resultPoint = form_p(l1, l2);

    std::cout << "x=" << resultPoint.x << " y="<< resultPoint.y << std::endl;

    return 0;
}

pointf form_p(line l1, line l2)
{
    pointf t;
    t.x = (l2.b - l1.b)/(l1.k - l2.k);
    t.y = l1.k * t.x + l1.b;
    return t;
}