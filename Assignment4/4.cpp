#include <iostream>

class Base {
public:
    virtual void show() {
        std::cout << "Base class show function" << std::endl;
    }
    virtual ~Base() = default; // Always good practice to have a virtual destructor in base class
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show function" << std::endl;
    }

    void derivedSpecificMethod() {
        std::cout << "Derived class specific method" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived(); // Base class pointer pointing to a derived class object
    basePtr->show(); // Calls the overridden method in Derived class

    // Use static_cast to convert the pointer back to the derived class
    Derived* derivedPtr = static_cast<Derived*>(basePtr);
    derivedPtr->derivedSpecificMethod(); // Access derived class-specific method

    delete basePtr; // Clean up
    return 0;
}