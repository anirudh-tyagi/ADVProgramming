#include <iostream>

class MyClass {
private:
    const int data;

public:
    MyClass(int value) : data(value) {}

    int getData() const {
        return data;
    }

    void modifyData(int newValue) {
        // Using const_cast to modify the const data member
        int& modifiableData = const_cast<int&>(data);
        modifiableData = newValue;
    }
};

int main() {
    MyClass obj(10);
    std::cout << "Initial data: " << obj.getData() << std::endl;

    obj.modifyData(20);
    std::cout << "Modified data: " << obj.getData() << std::endl;

    return 0;
}