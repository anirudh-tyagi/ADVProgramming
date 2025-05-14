#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show function called" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show function called" << std::endl;
    }

    void derivedFunction() {
        std::cout << "Derived class specific function called" << std::endl;
    }
};

int main() {
    Derived derivedObj;
    Base* basePtr = &derivedObj; // Implicit upcasting

    basePtr->show(); // Calls Derived class show function due to polymorphism

    // Explicit downcasting using dynamic_cast
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->derivedFunction(); // Calls Derived class specific function
    } else {
        std::cout << "Downcasting failed" << std::endl;
    }

    return 0;
}