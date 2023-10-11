// реализация стека через класс в разных файлах
#include <iostream>

#include "9.1.stack.hpp"


int main()
{
    Stack st = Stack();

    int chooseNumber, value;
    bool check;
    for(;;)
    {
        std::cout << "Выберете пункт" << std::endl;
        std::cout << "1.добавить значение в стек" << std::endl;
        std::cout << "2.убрать значение из стека" << std::endl;
        std::cout << "3.печатать стек" << std::endl;
        std::cin >> chooseNumber;
        
        if(chooseNumber == 1)
        {
            std::cout << "Введите значение" << std::endl;
            std::cin >> value;
            check = st.pushStack(value);
            if(check == 1)
            {
                std::cout << "Стек полон" << std::endl;
                continue;
            }
        }
        if(chooseNumber == 2)
        {
            int upperElement;
            check = st.popStack(upperElement);
            if(check == 1)
            {
                std::cout << "Стек пуст" << std::endl;
                continue;
            } 
            std::cout << "Верхний элемент получен: " << upperElement << std::endl;
        }
        if(chooseNumber == 3)
        {
            st.printStack();
        }
    }
    
    return 0;
}
