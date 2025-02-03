#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure 'Point'
struct Point {
    float x;
    float y;
};

// Function to calculate Euclidean distance between two points
float calculateDistance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    int n;
    struct Point *points;

    // Ask user for the number of points
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' points
    points = (struct Point*)malloc(n * sizeof(struct Point));
    if (points == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input coordinates for each point
    for (int i = 0; i < n; i++) {
        printf("Enter coordinates for point %d (x y): ", i + 1);
        scanf("%f %f", &points[i].x, &points[i].y);
    }

    // Calculate Euclidean distance between the first and last points
    float distance = calculateDistance(points[0], points[n - 1]);
    printf("\nEuclidean distance between the first and last points: %.2f\n", distance);

    // Free the allocated memory
    free(points);

    return 0;
}