#include <iostream>
using namespace std;
bool isPrime(int num) {
   
    if (num <= 1) 
        return false;

    // Check divisibility from 2 to sqrt(num)
    for (int a = 2; a* a<= num; a++) {
        if (num % a == 0)
            return false;
    }

    return true;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (isPrime(num))
        std::cout << num << " is a prime number.\n";
    else
        std::cout << num << " is not a prime number.\n";

    return 0;
}