#include <iostream>               // подключаем заголовочный файл iostream
#include <sqlite3.h>
#include <vector>

void example(void); // прототип функции
class Person; // прототип класса (потому что вышележащий класс еще не знает про нижележащий, а дружественную функцию или дружественный класс нужно описать)

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


int main()                          // определяем функцию main
{                                   // начало функции
    std::cout << "Hello World! \n";   // выводим строку на консоль

// ссылка адрес и значение
    int x {5};
    int &y {x};
    std::cout << y << "\n";
    std::cout << &y << "\n";
    std::cout << &x << "\n" << std::endl;
// инициализация переменной
    int z = 5.5;
    int zz (5.5);
    int zzz {5}; // проверяет типы, компилятор выбросит исключение при float
    std::cout << z << "\n";
    std::cout << zz << "\n";
    std::cout << zzz << "\n" << std::endl;
// bool
    bool t;
    t = true; // = т.к. нет преобразование типов
    std::cout << t << "\n" << std::endl;
// function prototype
    example();
// динамический объект
    Person *personPtr {new Person("Tom")}; // {} можно использовать
    delete personPtr;
    personPtr = nullptr;
// объект в динамическом массиве вектор
    std::vector<Person> v(3, Person("Name"));
    std::vector<std::string> strname(3);
    strname[0] = "Sam";
    strname[1] = "Tomas";
    strname[2] = "Julia";
    for(int i = 0; i < 3; i++)
    {
        v[i].setName(strname[i]);
        v[i].setAge(i+40);
    }
    v[2].print();


    return 0;                       // выходим из функции
}

void example()
{
    std::cout << "прототип функции" << "\n";
}

void Person::setAge(unsigned int f_age)
{
    age = f_age;
}