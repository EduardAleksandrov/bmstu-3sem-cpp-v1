#include <iostream>
#include <string>
#include <vector>
#include <fstream>


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

    // std::vector <int> vec {};
    // for(int i = 0; i < 3 ; i++)
    // {
    //     int x;
    //     std::cin>> x;
    //     vec.push_back(x);
    //     std::cout<< vec[i] << std::endl;
    // }

    
    std::ifstream in;       // поток для чтения
    in.open("8.cin.txt", std::ios::in);
    char c;
    std::string s {};
    if (in.is_open())
    {
        while(in)
        {
            c = in.get();
            if(in.eof()) break;
            s+=c;
            if(c == '\n') std::cout << -1;
        }
        std::cout << s << "\n";

    }
    in.close();


    return 0;
}