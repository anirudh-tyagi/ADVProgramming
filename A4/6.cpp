#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Base class with at least one virtual function (making it polymorphic)
class Shape {
protected:
    std::string name;
    
public:
    Shape(const std::string& name) : name(name) {}
    
    // Virtual function makes this class polymorphic, enabling dynamic_cast
    virtual void draw() const {
        std::cout << "Drawing a generic shape: " << name << std::endl;
    }
    
    const std::string& getName() const {
        return name;
    }
    
    // Virtual destructor is important for proper cleanup
    virtual ~Shape() {
        std::cout << "Destroying Shape: " << name << std::endl;
    }
};

// First derived class
class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(const std::string& name, double radius) 
        : Shape(name), radius(radius) {}
    
    void draw() const override {
        std::cout << "Drawing Circle: " << name << " with radius " << radius << std::endl;
    }
    
    // Circle-specific method
    double getArea() const {
        return 3.14159 * radius * radius;
    }
    
    ~Circle() override {
        std::cout << "Destroying Circle: " << name << std::endl;
    }
};

// Second derived class
class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(const std::string& name, double width, double height) 
        : Shape(name), width(width), height(height) {}
    
    void draw() const override {
        std::cout << "Drawing Rectangle: " << name << " with width " << width 
                  << " and height " << height << std::endl;
    }
    
    // Rectangle-specific method
    double getArea() const {
        return width * height;
    }
    
    ~Rectangle() override {
        std::cout << "Destroying Rectangle: " << name << std::endl;
    }
};

// Third derived class - different inheritance branch
class Triangle : public Shape {
private:
    double base;
    double height;
    
public:
    Triangle(const std::string& name, double base, double height) 
        : Shape(name), base(base), height(height) {}
    
    void draw() const override {
        std::cout << "Drawing Triangle: " << name << " with base " << base 
                  << " and height " << height << std::endl;
    }
    
    // Triangle-specific method
    double getArea() const {
        return 0.5 * base * height;
    }
    
    ~Triangle() override {
        std::cout << "Destroying Triangle: " << name << std::endl;
    }
};

// Function that demonstrates dynamic_cast with a pointer
void processShape(Shape* shape) {
    // First, use the virtual function polymorphically
    shape->draw();
    
    std::cout << "Attempting to access shape-specific functionality:" << std::endl;
    
    // Try to dynamic_cast to Circle
    if (Circle* circle = dynamic_cast<Circle*>(shape)) {
        std::cout << "This is a Circle! Area = " << circle->getArea() << std::endl;
    }
    // Try to dynamic_cast to Rectangle
    else if (Rectangle* rectangle = dynamic_cast<Rectangle*>(shape)) {
        std::cout << "This is a Rectangle! Area = " << rectangle->getArea() << std::endl;
    }
    // Try to dynamic_cast to Triangle
    else if (Triangle* triangle = dynamic_cast<Triangle*>(shape)) {
        std::cout << "This is a Triangle! Area = " << triangle->getArea() << std::endl;
    }
    // dynamic_cast failed for all derived types
    else {
        std::cout << "Could not determine the specific shape type or access its special methods" << std::endl;
    }
    
    std::cout << std::endl;
}

// Function demonstrating dynamic_cast with references (which throws on failure)
void processShapeRef(Shape& shape) {
    try {
        // Attempt to dynamic_cast to Circle reference
        Circle& circle = dynamic_cast<Circle&>(shape);
        std::cout << "Reference cast to Circle succeeded! Area = " << circle.getArea() << std::endl;
    }
    catch (const std::bad_cast& e) {
        std::cout << "Reference cast to Circle failed! Exception: " << e.what() << std::endl;
        
        try {
            // If it's not a Circle, try Rectangle
            Rectangle& rectangle = dynamic_cast<Rectangle&>(shape);
            std::cout << "Reference cast to Rectangle succeeded! Area = " << rectangle.getArea() << std::endl;
        }
        catch (const std::bad_cast& e) {
            std::cout << "Reference cast to Rectangle failed too! Exception: " << e.what() << std::endl;
        }
    }
}

int main() {
    // Create objects of different types
    auto circle = std::make_unique<Circle>("MyCircle", 5.0);
    auto rectangle = std::make_unique<Rectangle>("MyRectangle", 4.0, 6.0);
    auto triangle = std::make_unique<Triangle>("MyTriangle", 3.0, 7.0);
    auto genericShape = std::make_unique<Shape>("GenericShape");
    
    std::cout << "=== Dynamic Cast with Pointers ===\n" << std::endl;
    
    // Store them in a vector of base class pointers
    std::vector<Shape*> shapes = {circle.get(), rectangle.get(), triangle.get(), genericShape.get()};
    
    // Process each shape
    for (Shape* shape : shapes) {
        processShape(shape);
    }
    
    std::cout << "=== Dynamic Cast with References ===\n" << std::endl;
    
    std::cout << "Processing Circle by reference:" << std::endl;
    processShapeRef(*circle);
    
    std::cout << "\nProcessing Rectangle by reference:" << std::endl;
    processShapeRef(*rectangle);
    
    std::cout << "\nProcessing generic Shape by reference (will cause exception):" << std::endl;
    processShapeRef(*genericShape);
    
    return 0;
}