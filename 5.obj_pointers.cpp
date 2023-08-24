#include <iostream>

class one
{
public:
    int x;
    std::string name;
};

class two 
{
public:
    one pointer;
    one *pointerDin {new one()};
};

int main()
{
    two create;
    create.pointer.x = 5;
    std::cout << create.pointer.x << std::endl;

    two *Ptr {new two()};
    Ptr->pointer.name = "pointer";
    std::cout << Ptr->pointer.name << std::endl;
    delete Ptr;
    Ptr = nullptr;

    two *Ptr2 {new two()};
    Ptr2->pointerDin->name = "pointer2";
    std::cout << Ptr2->pointerDin->name << std::endl;
    delete Ptr2;
    Ptr2 = nullptr;

}
