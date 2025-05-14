#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual void show() {
        std::cout << "Base class" << std::endl;
    }
    virtual ~Base() {}
};

class Derived1 : public Base {
public:
    void show() override {
        std::cout << "Derived1 class" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void show() override {
        std::cout << "Derived2 class" << std::endl;
    }
};

int main() {
    Base* basePtr = new Derived1();
    Derived1* derived1Ptr = dynamic_cast<Derived1*>(basePtr);

    if (derived1Ptr) {
        std::cout << "Successfully cast to Derived1" << std::endl;
        derived1Ptr->show();
    } else {
        std::cout << "Failed to cast to Derived1" << std::endl;
    }

    Derived2* derived2Ptr = dynamic_cast<Derived2*>(basePtr);

    if (derived2Ptr) {
        std::cout << "Successfully cast to Derived2" << std::endl;
        derived2Ptr->show();
    } else {
        std::cout << "Failed to cast to Derived2" << std::endl;
    }
