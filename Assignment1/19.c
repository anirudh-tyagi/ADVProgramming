#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 2;
    int *evens = (int*)malloc(size * sizeof(int));
    evens[0] = 2; evens[1] = 4;

    char choice;
    do {
        printf("Evens: ");
        for (int i = 0; i < size; i++) printf("%d ", evens[i]);

        printf("\nAdd 2 more? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            size += 2;
            evens = (int*)realloc(evens, size * sizeof(int));
            printf("Enter two even numbers: ");
            scanf("%d %d", &evens[size-2], &evens[size-1]);
        }
    } while (choice == 'y');

    free(evens);
    return 0;
}