#include <iostream>               // подключаем заголовочный файл iostream
#include <sqlite3.h>
#include "./1.one_linkfile_header.hpp"

void example(void);

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
private:
    std::string name;
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
    t = true;
    std::cout << t << "\n" << std::endl;
// function prototype
    example();
// динамический объект
    Person *personPtr{new Person("Tom")}; // {} можно использовать
    delete personPtr;
    personPtr = nullptr;
// данные из linker
    std::cout << message << times << "\n" << std::endl;




    return 0;                       // выходим из функции
}

void example()
{
    std::cout << "прототип функции" << "\n";
}