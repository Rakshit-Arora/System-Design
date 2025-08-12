/// Open for extension, closed for modification
/// This code demonstrates the Open/Closed Principle by allowing new functionality


///OCP Violation Example:

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

enum class ShapeType {
    Circle,
    Rectangle
};

struct Rectangle {
    double width;
    double height;
};

struct Circle {
    double radius;
};

struct Shape {
    ShapeType type;

    union {
        Circle circle;
        Rectangle rectangle;
    };

    Shape(Circle c) : type(ShapeType::Circle), circle(c) {}
    Shape(Rectangle r) : type(ShapeType::Rectangle), rectangle(r) {}
};

class AreaCalculator_violationOCP{
    public:

    double area(Shape& shape) {
        if(shape.type == ShapeType::Circle) {
            return 3.14159 * shape.circle.radius * shape.circle.radius;
        } else if(shape.type == ShapeType::Rectangle) {
            return shape.rectangle.width * shape.rectangle.height;
        }
        //if we add a new shape, we have to modify this method -> voilation of OCP
        return 0.0; // Unsupported shape
    }
};


///OCP Compliant Example:

class Shape_OCP {
    public:
    virtual double area() const = 0; // Pure virtual function
    virtual ~Shape_OCP() = default; // Virtual destructor for proper cleanup
};

class Circle_OCP : public Shape_OCP {
    double radius;

    public:
    Circle_OCP(double r){
        radius = r;
    }

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle_OCP : public Shape_OCP {
    double width;
    double height;

    public:
    Rectangle_OCP(double w, double h){
        width = w;
        height = h;
    }

    double area() const override {
        return width * height;
    }
};

class AreaCalculator_OCP {
    public:
    double area(const Shape_OCP& shape) {
        return shape.area(); // No need to modify this method when adding new shapes
    }
};


// calling both the examples

int main() {
    cout << "OCP Violation Example:" << endl;

    Shape rect1 = Rectangle{5, 10};
    Shape circle1 = Circle{3};
    AreaCalculator_violationOCP cal1;

    cout<<"Rectangle Area: " << cal1.area(rect1) << endl;
    cout<<"Circle Area: " << cal1.area(circle1) << endl;

    // TO add a new shape, we would have to modify the AreaCalculator_violationOCP class.

    cout<< "\nOCP Compliant Example:" << endl;

    Rectangle_OCP rect2(5, 10);
    Circle_OCP circle2(3);

    AreaCalculator_OCP cal2;

    cout<<"Rectangle Area: " << cal2.area(rect2) << endl;
    cout<<"Circle Area: " << cal2.area(circle2) << endl;
    // Now we can add new shapes without modifying the AreaCalculator_OCP class.

    return 0;
}

