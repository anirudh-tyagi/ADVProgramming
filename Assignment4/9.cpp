#include <iostream>
#include <string>

class Base {
public:
    void show(int value) {
        std::cout << "Base show(int): " << value << std::endl;
    }

    void show(double value) {
        std::cout << "Base show(double): " << value << std::endl;
    }
};

class Derived : public Base {
public:
    using Base::show;

    void show(const std::string& value) {
        std::cout << "Derived show(string): " << value << std::endl;
    }
};

int main() {
    Base baseObj;
    Derived derivedObj;

    // Base class function calls
    baseObj.show(42);
    baseObj.show(3.14);

    // Derived class function calls
    derivedObj.show(42);
    derivedObj.show(3.14);
    derivedObj.show("Hello, World!");

    return 0;
}