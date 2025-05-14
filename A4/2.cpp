#include <iostream>
#include <typeinfo> // For typeid

// First unrelated class
class ClassA {
public:
    void printA() const {
        std::cout << "ClassA print function" << std::endl;
    }
};

// Second unrelated class
class ClassB {
public:
    void printB() const {
        std::cout << "ClassB print function" << std::endl;
    }
};

int main() {
    ClassA objA;
    ClassB objB;

    // Attempting implicit casting (will cause a compilation error)
    // ClassB* invalidCast = &objA; // Uncommenting this line will result in an error

    // Using static_cast (will cause a compilation error)
    // ClassB* staticCastPtr = static_cast<ClassB*>(&objA); // Uncommenting this line will result in an error

    // Using reinterpret_cast (allowed but unsafe)
    ClassB* reinterpretCastPtr = reinterpret_cast<ClassB*>(&objA);
    std::cout << "Using reinterpret_cast: ";
    reinterpretCastPtr->printB(); // Unsafe, may lead to undefined behavior

    // Using dynamic_cast (will cause a compilation error)
    // ClassB* dynamicCastPtr = dynamic_cast<ClassB*>(&objA); // Uncommenting this line will result in an error

    return 0;
}