#include <stdio.h>
#include <stdlib.h>

void largest(int num) {
    int max_digit = 0; 

    while (num != 0) {
        int digit = num % 10;
        if (digit > max_digit) {
            max_digit = digit; 
        }
        num /= 10; 
    }

    printf("Largest digit: %d\n", max_digit);
}

int main() {
    printf("Enter a Number: "); 
    int num;
    scanf("%d", &num);

    
    if (num < 0) {
        num = -num;
    }

    largest(num);

    return 0;
}
