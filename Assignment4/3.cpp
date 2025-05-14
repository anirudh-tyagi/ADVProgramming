#include <iostream>

class Base {
public:
    virtual void virtualFunction() {
        std::cout << "Base class virtual function" << std::endl;
    }

    void nonVirtualFunction() {
        std::cout << "Base class non-virtual function" << std::endl;
    }
};

class Derived : public Base {
public:
    void virtualFunction() override {
        std::cout << "Derived class virtual function" << std::endl;
    }

    void nonVirtualFunction() {
        std::cout << "Derived class non-virtual function" << std::endl;
    }
};

int main() {
    Base* basePtr;
    Derived derivedObj;

    basePtr = &derivedObj;

    // Dynamic binding for virtual function
    basePtr->virtualFunction();

    // Static binding for non-virtual function
    basePtr->nonVirtualFunction();

    return 0;
}