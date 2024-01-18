// virtual destructor
#include <iostream>
#include <vector>
#include <typeinfo>

using std::cout, std::endl;

class Shape
{
    int x;
public:
    Shape(int xx):x{xx}
    {
        cout << "shape constructor" << endl;
    }
    Shape(){}
    virtual void print()
    {
        cout<< x << " shape print" << endl;
    }
    virtual ~Shape()
    {
        cout << "shape destructor" << endl;
    }
};

class Circle: public Shape
{
public:
    Circle(int xx):Shape(xx)
    {
        cout << "Circle constructor" << endl;
    }
    void print()
    {
        Shape::print();
        cout << "Circle print" << endl;
    }
    ~Circle()
    {
        cout << "circle destructor" << endl;

    }
};

class Rect: public Shape
{
    int xt;
public:
    Rect(int xx): xt{xx}, Shape(xx)
    {
        cout << "Rect constructor" << endl;
    }
    void print()
    {
        cout << "Rect print" << endl;
    }
    ~Rect()
    {
        cout << "Rect destructor" << endl;

    }
};

int main()
{
    // Circle cr = Circle(5);

    // Shape* sh {&cr};
    // sh->print();
    // sh->Shape::print();

    std::vector <Shape*> vect {new Circle(5), new Rect(6)};

    vect[0]->print();
    vect[1]->print();

    Circle* vk1 = dynamic_cast<Circle*> (vect[0]);
    const std::type_info& ti1 = typeid(vk1);
    cout << endl << ti1.name() << endl;
    vk1->print();

    //! нужен virtual destructor для удаления объектов Circle и Rect
    for(int i = 0; i < 2; i++)
        delete vect[i];
        
    return 0;
}