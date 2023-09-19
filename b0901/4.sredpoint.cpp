// Лекция 3: среднее значение между точками - работает
#include <iostream>

struct pointf
{
    double x, y, z;
};
pointf sred(pointf *, int);

int main(void)
{
    pointf *a = new pointf[3];
    int k = 0;
    int n = 3;
    int ac[] {5,3,6,1,-8,9,33,51,68};
    for(int i = 0; i < n; i++) 
    {
        a[i].x = ac[k++];
        a[i].y = ac[k++];
        a[i].z = ac[k++];
    }
    for(int i = 0; i < n; i++)
    {
        std::cout << a[i].x<<" "<<a[i].y << " " <<a[i].z<< " ";
        std::cout << std::endl;
    }
    pointf result = sred(a, n);
    std::cout << result.x<<" "<<result.y << " " <<result.z<< " ";
    std::cout << std::endl;
    
    delete[] a;
    a = nullptr;

    return 0;
}

pointf sred(pointf *t, int n)
{
    pointf t0;
    t0.x = 0;
    t0.y = 0;
    t0.z = 0;
    for(int i = 0; i<n; i++)
    {
        t0.x += t[i].x;
        t0.y += t[i].y;
        t0.z += t[i].z;
    }
    t0.x /= n;
    t0.y /= n;
    t0.z = t0.z/n;
    return t0;
}







