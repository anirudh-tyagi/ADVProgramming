#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual void show() { std::cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived class\n"; }
};

class Unrelated {
public:
    void display() { std::cout << "Unrelated class\n"; }
};

void demonstrateCasts() {
    // Static cast
    int a = 10;
    double b = static_cast<double>(a);
    std::cout << "Static cast from int to double: " << b << "\n";

    // Dynamic cast
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->show();
    } else {
        std::cout << "Dynamic cast failed\n";
    }

    // Reinterpret cast
    int* intPtr = &a;
    char* charPtr = reinterpret_cast<char*>(intPtr);
    std::cout << "Reinterpret cast from int* to char*: " << *charPtr << "\n";

    // Const cast
    const int c = 20;
    int& d = const_cast<int&>(c);
    d = 30;
    std::cout << "Const cast to modify const int: " << c << " " << d << "\n";

    delete basePtr;
}

int main() {
    demonstrateCasts();
    return 0;
}