#include <stdio.h>
#include <stdlib.h>

struct Movie {
    char title[100];
    float rating;
    int year;
};

void printMoviesAfterYear(struct Movie *movies, int n, int year) {
    printf("\nMovies released after %d:\n", year);
    for (int i = 0; i < n; i++)
        if (movies[i].year > year)
            printf("- %s (%.1f)\n", movies[i].title, movies[i].rating);
}

int main() {
    int n = 5;
    struct Movie *movies = (struct Movie*)malloc(n * sizeof(struct Movie));

    for (int i = 0; i < n; i++) {
        printf("Movie %d:\n", i+1);
        printf("Title: "); scanf(" %[^\n]%*c", movies[i].title);
        printf("Rating: "); scanf("%f", &movies[i].rating);
        printf("Year: "); scanf("%d", &movies[i].year);
    }

    int filterYear;
    printf("\nEnter minimum year: ");
    scanf("%d", &filterYear);
    printMoviesAfterYear(movies, n, filterYear);

    free(movies);
    return 0;
}