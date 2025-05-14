#include <iostream>
#include <typeinfo> // For typeid

// Base class
class Base {
public:
    virtual void print() const {
        std::cout << "Base class print function" << std::endl;
    }
    virtual ~Base() {} // Virtual destructor for proper cleanup
};

// Derived class
class Derived : public Base {
public:
    void print() const override {
        std::cout << "Derived class print function" << std::endl;
    }
    void derivedSpecificFunction() const {
        std::cout << "Function specific to Derived class" << std::endl;
    }
};

int main() {
    // Implicit Upcasting
    Derived derivedObj;
    Base* basePtr = &derivedObj; // Upcasting: Derived* to Base*
    basePtr->print(); // Calls Derived::print() due to virtual function

    // Explicit Downcasting using dynamic_cast
    Base* anotherBasePtr = new Derived(); // Base pointer pointing to Derived object
    Derived* derivedPtr = dynamic_cast<Derived*>(anotherBasePtr); // Downcasting: Base* to Derived*
    if (derivedPtr) {
        std::cout << "Downcasting successful." << std::endl;
        derivedPtr->derivedSpecificFunction(); // Accessing Derived specific function
    } else {
        std::cout << "Downcasting failed." << std::endl;
    }

    // Attempting to downcast a Base object to Derived (unsafe)
    Base baseObj;
    Derived* invalidDerivedPtr = dynamic_cast<Derived*>(&baseObj);
    if (invalidDerivedPtr) {
        std::cout << "Invalid downcasting successful." << std::endl;
    } else {
        std::cout << "Invalid downcasting failed." << std::endl;
    }

    // Cleanup
    delete anotherBasePtr;

    return 0;
}