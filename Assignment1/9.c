#include <stdio.h>
#include <stdlib.h>

struct Car {
    char model[50];
    int year;
    float price;
};

int main() {
    int n;
    printf("Number of cars: ");
    scanf("%d", &n);

    struct Car *cars = (struct Car*)malloc(n * sizeof(struct Car));
    float total = 0;

    for (int i = 0; i < n; i++) {
        printf("Car %d:\n", i+1);
        printf("Model: "); scanf(" %[^\n]%*c", cars[i].model);
        printf("Year: "); scanf("%d", &cars[i].year);
        printf("Price: "); scanf("%f", &cars[i].price);
        total += cars[i].price;
    }

    printf("\nAverage price: $%.2f\n", total / n);
    free(cars);
    return 0;
}