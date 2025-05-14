#include <iostream>

class ClassA {
public:
    void display() {
        std::cout << "ClassA object" << std::endl;
    }
};

class ClassB {
public:
    void show() {
        std::cout << "ClassB object" << std::endl;
    }
};

int main() {
    ClassA a;
    ClassB b;

    // Static cast
    // This will result in a compilation error because ClassA and ClassB are unrelated
    // ClassB* bPtr = static_cast<ClassB*>(&a);

    // Reinterpret cast
    // This will compile but is unsafe and can lead to undefined behavior
    ClassB* bPtr = reinterpret_cast<ClassB*>(&a);
    bPtr->show(); // This may cause a crash or undefined behavior

    // Dynamic cast
    // This will result in a compilation error because dynamic_cast requires at least one polymorphic base class
    // ClassB* bPtr2 = dynamic_cast<ClassB*>(&a);

    return 0;
}