// интерфейс
#include <iostream>

extern std::string message;
extern unsigned int times;

class Person
{
public:
    Person(std::string p_name) //конструктор
    {
        name = p_name;
        std::cout << "Person " << name << " created" << std::endl;
    }
    ~Person() //Деструктор
    {
        std::cout << "Person " << name << " deleted" << std::endl;
    }
    void print()
    {
        std::cout << "Person name: " << name  << " Person age: " << age  << std::endl;
    }
    void setName(std::string f_name)
    {
        name = f_name;
    }
    void setAge(unsigned int f_age);
private:
    std::string name;
    unsigned int age;
};