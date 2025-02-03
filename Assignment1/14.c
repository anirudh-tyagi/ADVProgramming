#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 3;
    int **arr = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int));
        printf("Value %d: ", i+1);
        scanf("%d", arr[i]);
    }

    printf("Values: ");
    for (int i = 0; i < n; i++) printf("%d ", *arr[i]);

    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    return 0;
}