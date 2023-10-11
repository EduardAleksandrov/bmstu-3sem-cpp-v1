#include <iostream>
#include "9.1.stack.hpp"

Stack::Stack()
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
Stack::~Stack()
{
    delete [] stack;
    stack = nullptr;
}
void Stack::printStack()
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
bool Stack::pushStack(int value)
{
    if(stackPointer == (stackBase + STACKSIZE))
    {
        return 1;
    }
    *stackPointer = value;
    (stackPointer)++;
    return 0;
}
bool Stack::popStack(int &upperElement)
{
    if(stackPointer == stackBase)
    {
        return 1;
    }
    stackPointer--;
    upperElement = *stackPointer;
    return 0;
}