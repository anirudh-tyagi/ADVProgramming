#include <iostream>
#include <iomanip>

// An arbitrary class
class MyClass {
private:
    int x;
    double y;
    char z;

public:
    MyClass(int x = 0, double y = 0.0, char z = 'A') : x(x), y(y), z(z) {}
    
    void display() const {
        std::cout << "MyClass values: x = " << x << ", y = " << y << ", z = " << z << std::endl;
    }
};

int main() {
    // Create an instance of MyClass
    MyClass obj(42, 3.14, 'Z');
    obj.display();
    
    // Get a pointer to the object
    MyClass* pObj = &obj;
    
    std::cout << "\n---- Memory Address Conversion ----\n";
    
    // Print the original pointer address
    std::cout << "Original pointer address (MyClass*): 0x" 
              << std::hex << std::setw(12) << std::setfill('0')
              << reinterpret_cast<uintptr_t>(pObj) << std::endl;
    
    // Use reinterpret_cast to convert to int*
    int* pInt = reinterpret_cast<int*>(pObj);
    
    // Print the address after casting
    std::cout << "After reinterpret_cast (int*):     0x" 
              << std::hex << std::setw(12) << std::setfill('0')
              << reinterpret_cast<uintptr_t>(pInt) << std::endl;
    
    // Demonstrate accessing the first int in MyClass (dangerous!)
    std::cout << "\n---- Dangerous Memory Access ----\n";
    std::cout << "First int value through int*: " << std::dec << *pInt << std::endl;
    
    // Modify the value through the cast pointer (VERY DANGEROUS!)
    *pInt = 99;
    
    std::cout << "Modified first int through int*" << std::endl;
    obj.display();
    
    // Even more dangerous - accessing beyond the bounds
    std::cout << "\n---- EXTREMELY DANGEROUS: Accessing beyond object boundaries ----\n";
    std::cout << "WARNING: The following operations might crash the program or produce unpredictable results\n";
    
    // These accesses are undefined behavior and might cause crashes
    std::cout << "Attempt to read int values at different offsets (UNDEFINED BEHAVIOR):\n";
    std::cout << "pInt[0]: " << pInt[0] << std::endl;  // This is the x value
    std::cout << "pInt[1]: " << pInt[1] << std::endl;  // This might be part of the double y
    
    std::cout << "\n---- Converting between pointer and integer ----\n";
    // Convert pointer to integer
    uintptr_t addressValue = reinterpret_cast<uintptr_t>(pObj);
    std::cout << "Pointer converted to integer: 0x" 
              << std::hex << addressValue << std::endl;
    
    // Convert back to pointer
    MyClass* recoveredPtr = reinterpret_cast<MyClass*>(addressValue);
    std::cout << "Integer converted back to pointer: 0x" 
              << std::hex << reinterpret_cast<uintptr_t>(recoveredPtr) << std::endl;
    
    recoveredPtr->display();  // Should show the same values as before
    
    return 0;
}