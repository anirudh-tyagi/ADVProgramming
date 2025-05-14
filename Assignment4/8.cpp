#include <iostream>

class Base {
protected:
    void protectedFunction() {
        std::cout << "Protected function in Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    using Base::protectedFunction; // Change access level to public
};

int main() {
    Derived obj;
    obj.protectedFunction(); // Call the function using an object of the derived class
    return 0;
}