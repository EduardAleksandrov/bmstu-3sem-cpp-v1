	
#include <iostream>
  
class Person
{
public:
    Person(std::string name): name{name}
    { }
    virtual void print() const  // виртуальная функция
    {
        std::cout << "Name: " << name << std::endl;
    }
private:
    std::string name;
};
class Employee: public Person
{
public:
    Employee(std::string name, std::string company): Person{name}, company{company}
    { }
    void print() const
    {
        // Person::print();
        std::cout << "Works in " << company << std::endl;
    }
private:
    std::string company;
};
  
int main()
{
    Person tom {"Tom"};
    Person* person {&tom};
    person->print();     // Name: Tom
    Employee bob {"Bob", "Microsoft"};
    person = &bob;
    person->print();    // Name: Bob
                            // Works in Microsoft
}