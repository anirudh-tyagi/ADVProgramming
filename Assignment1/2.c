#include <stdio.h>
#include <stdlib.h>

// Define the structure 'Book'
struct Book {
    char title[100];
    char author[100];
    float price;
};

// Function to input book details
void inputBookDetails(struct Book *books, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter details for book %d:\n", i + 1);
        printf("Title: ");
        scanf(" %[^\n]%*c", books[i].title); // Read string with spaces
        printf("Author: ");
        scanf(" %[^\n]%*c", books[i].author);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }
}

// Function to print books costing more than the specified price
void printExpensiveBooks(struct Book *books, int count, float minPrice) {
    printf("\nBooks costing more than %.2f:\n", minPrice);
    for (int i = 0; i < count; i++) {
        if (books[i].price > minPrice) {
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n\n", books[i].price);
        }
    }
}

int main() {
    int n = 10;
    float minPrice;
    struct Book *books;

    // Dynamically allocate memory for 10 books
    books = (struct Book*)malloc(n * sizeof(struct Book));
    if (books == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Take user input for books
    inputBookDetails(books, n);

    // Ask the user for the minimum price to filter
    printf("\nEnter the minimum price to display books: ");
    scanf("%f", &minPrice);

    // Print the books that cost more than the specified amount
    printExpensiveBooks(books, n, minPrice);

    // Free the allocated memory
    free(books);

    return 0;
}