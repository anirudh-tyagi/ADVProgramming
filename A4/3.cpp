#include <iostream>

// Base class with virtual and non-virtual functions
class Base {
public:
    // Virtual function - will use dynamic binding
    virtual void virtualFunction() {
        std::cout << "Base::virtualFunction() called" << std::endl;
    }
    
    // Non-virtual function - will use static binding
    void nonVirtualFunction() {
        std::cout << "Base::nonVirtualFunction() called" << std::endl;
    }
};

// Derived class that overrides the virtual function
class Derived : public Base {
public:
    // Override the virtual function
    void virtualFunction() override {
        std::cout << "Derived::virtualFunction() called" << std::endl;
    }
    
    // Redefine the non-virtual function
    void nonVirtualFunction() {
        std::cout << "Derived::nonVirtualFunction() called" << std::endl;
    }
};

int main() {
    std::cout << "Creating objects:" << std::endl;
    Base baseObj;
    Derived derivedObj;
    
    // Create a base class pointer to a derived class object
    Base* basePtr = &derivedObj;
    
    std::cout << "\nDirect calls using objects:" << std::endl;
    baseObj.virtualFunction();     // Calls Base::virtualFunction()
    baseObj.nonVirtualFunction();  // Calls Base::nonVirtualFunction()
    derivedObj.virtualFunction();  // Calls Derived::virtualFunction()
    derivedObj.nonVirtualFunction(); // Calls Derived::nonVirtualFunction()
    
    std::cout << "\nCalls using Base pointer to Derived object:" << std::endl;
    // Dynamic binding - the actual type of the object determines which function is called
    basePtr->virtualFunction();    // Calls Derived::virtualFunction()
    
    // Static binding - the type of the pointer determines which function is called
    basePtr->nonVirtualFunction(); // Calls Base::nonVirtualFunction()
    
    return 0;
}