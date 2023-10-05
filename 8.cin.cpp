#include <iostream>
#include <string>
#include <vector>

int main(void)
{
    int choseInputExpression;
    std::cin >> choseInputExpression;
    std::cin.get();
    // (std::cin >> choseInputExpression).get();
    std::string str;
    std::cout << "Введите ваше имя: "<<std::endl;
    std::getline(std::cin, str);
    // std::cout << str << "\n";

    std::vector <int> vec {};
    for(int i = 0; i < 3 ; i++)
    {
        int x;
        std::cin>> x;
        vec.push_back(x);
        std::cout<< vec[i] << std::endl;
    }


    return 0;
}