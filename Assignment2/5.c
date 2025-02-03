#include <stdio.h>

void primeFactors(int num) {
    printf("Prime factors: ");
    while (num % 2 == 0) {
        printf("%d ", 2);
        num /= 2;
    }
    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }
    if (num > 2) {
        printf("%d", num);
    }

    printf("\n");
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    primeFactors(num);

    return 0;
}
