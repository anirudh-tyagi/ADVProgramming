#include <iostream>
#include <string>

// Base class
class Animal {
protected:
    std::string name;
    
public:
    Animal(const std::string& name) : name(name) {}
    
    virtual void makeSound() const {
        std::cout << name << " makes a generic sound" << std::endl;
    }
    
    virtual ~Animal() {} // Virtual destructor for proper cleanup
};

// Derived class
class Dog : public Animal {
private:
    std::string breed;
    
public:
    Dog(const std::string& name, const std::string& breed) 
        : Animal(name), breed(breed) {}
    
    void makeSound() const override {
        std::cout << name << " barks loudly!" << std::endl;
    }
    
    // Derived class specific method
    void wagTail() const {
        std::cout << name << " (a " << breed << ") wags its tail happily" << std::endl;
    }
};

int main() {
    // Create a derived class object
    Dog* myDog = new Dog("Rex", "German Shepherd");
    
    // Upcast to base class pointer (implicit conversion, no cast needed)
    Animal* animalPtr = myDog;
    
    // Base class pointer can only access base class methods
    std::cout << "Using base class pointer:" << std::endl;
    animalPtr->makeSound(); // Will call Dog::makeSound() due to virtual function
    
    // animalPtr->wagTail(); // Error: 'class Animal' has no member named 'wagTail'
    
    std::cout << "\nUsing static_cast to downcast:" << std::endl;
    // Downcast back to derived class using static_cast
    Dog* dogPtr = static_cast<Dog*>(animalPtr);
    
    // Now we can access the derived class specific method
    dogPtr->wagTail();
    
    // Clean up
    delete myDog;
    
    std::cout << "\nDemonstrating an unsafe downcast:" << std::endl;
    // This is a pure Animal object, not a Dog
    Animal* pureAnimal = new Animal("Generic Animal");
    
    // This compiles but is unsafe - undefined behavior at runtime
    // since pureAnimal is not actually a Dog
    Dog* unsafeDogPtr = static_cast<Dog*>(pureAnimal);
    
    // This might crash or produce unexpected results
    // because pureAnimal is not actually a Dog
    std::cout << "Attempting to call wagTail() on an incorrectly cast object:" << std::endl;
    unsafeDogPtr->wagTail(); // Undefined behavior!
    
    delete pureAnimal;
    
    return 0;
}