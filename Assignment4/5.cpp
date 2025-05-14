#include <iostream>

class UnrelatedClass {
public:
    int data;
    UnrelatedClass(int val) : data(val) {}
};

int main() {
    UnrelatedClass obj(42);
    UnrelatedClass* objPtr = &obj;

    // Print the original pointer address
    std::cout << "Original pointer address: " << objPtr << std::endl;

    // Cast the pointer to int* using reinterpret_cast
    int* intPtr = reinterpret_cast<int*>(objPtr);

    // Print the casted pointer address
    std::cout << "Casted pointer address: " << intPtr << std::endl;

    return 0;
}