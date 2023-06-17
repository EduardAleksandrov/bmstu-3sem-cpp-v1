// Абстрактные классы, виртуальные функции + перемещение

#include <iostream>
   
class Shape
{
public:
    virtual double getSquare() const = 0;     // площадь фигуры
    virtual double getPerimeter() const = 0;  // периметр фигуры
};
class Rectangle : public Shape  // класс прямоугольника
{
public:
    Rectangle(double w, double h) : width(w), height(h)
    { }
    double getSquare() const override
    {
        return width * height;
    }
    double getPerimeter() const override
    {
        return width * 2 + height * 2;
    }
private:
    double width;   // ширина
    double height;  // высота
};
class Circle : public Shape     // круг
{
public:
    Circle(double r) : radius(r) 
    { }
    Circle(Circle&& other)
    { 
        std::cout << "конструктор";
    }
    double getSquare() const override
    {
        return radius * radius * 3.14;
    }
    double getPerimeter() const override
    {
        return 2 * 3.14 * radius;
    }
    int *numbers {new int[1073000000]{1}};
    void setRadius(int Lradius)
    {
        radius = Lradius;
    }
private:
    double radius;  // радиус круга
};

Circle num(Circle&& a)
{
    Circle newCircle{0};
    newCircle.numbers = a.numbers;
    a.numbers = nullptr;
    newCircle.setRadius(30);
    return newCircle;
}
  
int main()
{
    Rectangle rect{30, 50};
    Circle circle{30};

    Shape* base = &circle;
    // Shape& base = circle;

    std::cout << "Rectangle square: " << rect.getSquare() << std::endl;
    std::cout << "Rectangle perimeter: " << rect.getPerimeter() << std::endl;
    std::cout << "Circle square: " << circle.getSquare() << std::endl;
    std::cout << "Circle perimeter: " << circle.getPerimeter() << std::endl;

    std::cout << "Circle perimeter: " << base->getPerimeter() << std::endl;

// rvalue
    int n {5};
    int&& tempRef {n+3};              // ссылка rvalue, &-ссылка lvalue
    n = 0;
    std::cout << tempRef << "\n" << &tempRef << "\n" << &n << std::endl;

// перемещение

    // int *x = num(std::move(circle)); // мы переместили объект circle в 
    // std::cout << *(x) << std::endl;

    // Circle x = num(std::move(circle));
    Circle x = num(Circle{30});
    std::cout << x.numbers[0] << "\n" << x.getSquare() <<std::endl;
    // std::cout << circle.numbers[0] << "\n" << circle.getSquare() <<std::endl; //segmentation fault

    // std::exit(0); 
    // std::cout << circle.numbers[0] << std::endl;   // выдает ошибку т.к. в функции num она очищается
// перемещение end

}

