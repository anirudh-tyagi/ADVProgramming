#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*)malloc(5 * sizeof(int));
    printf("Enter 5 numbers: ");
    for (int i = 0; i < 5; i++) scanf("%d", &arr[i]);

    arr = (int*)realloc(arr, 10 * sizeof(int));
    printf("Enter 5 more numbers: ");
    for (int i = 5; i < 10; i++) scanf("%d", &arr[i]);

    printf("Final array: ");
    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

    free(arr);
    return 0;
}