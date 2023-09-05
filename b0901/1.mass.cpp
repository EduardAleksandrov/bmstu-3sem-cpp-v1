#include <iostream>

int main(void)
{

    int ac[] {5,3,6,1,-8,9,33,51,68};

    int **a {new int*[3]};
    for(int i = 0; i<3; i++)
        *(a+i) = new int [3];   //a[i]   *-это есть указатель(не разыменование) инициализация
    
    int k {0};
    for(int i = 0; i<3; i++)
        for(int j=0; j<3;j++)
            a[i][j] = ac[k++];
    
    for(int i = 0; i<3;i++)
    {
        for(int j=0; j<3;j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
        
    std::cout << sizeof(a)/sizeof(*a) << std::endl; // длину массива созданного через указатели найти нельзя
        

    // int length = sizeof(ac)/sizeof(*ac);
    // for(int i = 0; i<length; i++)
    //     std::cout << ac[i] << std::endl;
    
    
    
    return 0;
}