#define STACKSIZE 5

class Stack
{
    int *stackBase, *stackPointer, *stack;

public:
    Stack();
    ~Stack();
    void printStack();
    bool pushStack(int value);
    bool popStack(int &upperElement);
};