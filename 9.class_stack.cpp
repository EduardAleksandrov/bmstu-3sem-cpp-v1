// реализация стека через класс
#include <iostream>

#define STACKSIZE 5

class Stack
{
    int *stackBase, *stackPointer, *stack;
    int value, chooseNumber;
    bool check;

public:
    Stack()
    {
        try
        {
            stack = new int[STACKSIZE + 1];
        }
        catch(const std::bad_alloc& e)
        {
            std::cerr << e.what() << std::endl;
        }
        stackBase = stack;
        stackPointer = stack;
    }
    ~Stack()
    {
        delete [] stack;
        stack = nullptr;
    }
    void printStack()
    {
        int stackNum = stackPointer - stackBase;
        if (stackNum == 0)
        {
            std::cout << "Стек пуст" << std::endl;
            return;
        } 
        for(int i = 0; i < stackNum; i++)
            std::cout << stack[i] << " ";
        std::cout << std::endl;
    }
    bool pushStack(int value)
    {
        if(stackPointer == (stackBase + STACKSIZE))
        {
            return 1;
        }
        *stackPointer = value;
        (stackPointer)++; // к указателям и другим переменным имеется прямой доступ в классе по ссылке
        return 0;
    }
    bool popStack(int &upperElement)
    {
        if(stackPointer == stackBase)
        {
            return 1;
        }
        stackPointer--;
        upperElement = *stackPointer;
        return 0;
    }
};

int main()
{
    
    
    Stack st = Stack();
    // st.pushStack(5);

    // st.printStack();

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
