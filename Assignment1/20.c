#include <stdio.h>
#include <stdlib.h>

int main() {
    int *scores = NULL;
    int initialSize, newSize;

    printf("Initial number of scores: ");
    scanf("%d", &initialSize);
    scores = (int*)malloc(initialSize * sizeof(int));

    printf("Enter scores: ");
    for (int i = 0; i < initialSize; i++) scanf("%d", &scores[i]);

    printf("New size: ");
    scanf("%d", &newSize);
    scores = (int*)realloc(scores, newSize * sizeof(int));

    if (newSize > initialSize) {
        printf("Enter %d additional scores: ", newSize - initialSize);
        for (int i = initialSize; i < newSize; i++) scanf("%d", &scores[i]);
    }

    printf("All scores: ");
    for (int i = 0; i < newSize; i++) printf("%d ", scores[i]);

    free(scores);
    return 0;
}