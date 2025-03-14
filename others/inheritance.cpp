#include <iostream>
#include <string>

class Shape {
public:
    virtual void draw() const {
        std::cout << "Фигура\n";
    }

    virtual ~Shape() = default;
};

// помечаем virtual наследование, т.к. иначе будет diamond of death
class Rectangle : virtual public Shape {
public:
    void draw() const override {
        std::cout << "Прямоугольник\n";
    }
};

class Circle : virtual public Shape {
public:
    void draw() const override {
        std::cout << "Круг\n";
    }
};

class ColoredRectangle : public Rectangle {
    std::string color;
public:
    ColoredRectangle(const std::string& col) : color(col) {}

    void draw() const override {
        std::cout << "Рисуем " << color << " прямоугольник\n";
    }
};

class ColoredCircle : public Circle {
    std::string color;
public:
    ColoredCircle(const std::string& col) : color(col) {}

    void draw() const override {
        std::cout << "Рисуем " << color << " круг\n";
    }
};

class ColoredRectangleWithColor : public ColoredRectangle {
    std::string color;
public:
    ColoredRectangleWithColor(const std::string& col) : ColoredRectangle(col), color(col) {}

    void draw() const override {
        std::cout << "Рисуем " << color << " прямоугольник с виртуальныйм наследованием\n";
    }
};

class ColoredCircleWithColor : public ColoredCircle {
    std::string color;
public:
    ColoredCircleWithColor(const std::string& col) : ColoredCircle(col), color(col) {}

    void draw() const override {
        std::cout << "Рисуем " << color << " круг с виртуальныйм наследованием\n";
    }
};

int main() {
    Shape* shapes[] = {
        new Rectangle(),
        new Circle(),
        new ColoredRectangle("красный"),
        new ColoredCircle("синий"),
        new ColoredRectangleWithColor("зеленый"),
        new ColoredCircleWithColor("желтый")
    };

    for (Shape* shape : shapes) {
        shape->draw();
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
