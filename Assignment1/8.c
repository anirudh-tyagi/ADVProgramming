#include <stdio.h>
#include <stdlib.h>

struct Rectangle { float length, breadth; };

void calculateAreas(struct Rectangle *rects, int n) {
    printf("\nAreas:\n");
    for (int i = 0; i < n; i++)
        printf("Rectangle %d: %.2f\n", i+1, rects[i].length * rects[i].breadth);
}

int main() {
    int n = 3;
    struct Rectangle *rects = (struct Rectangle*)malloc(n * sizeof(struct Rectangle));

    for (int i = 0; i < n; i++) {
        printf("Rectangle %d (length breadth): ", i+1);
        scanf("%f %f", &rects[i].length, &rects[i].breadth);
    }

    calculateAreas(rects, n);
    free(rects);
    return 0;
}