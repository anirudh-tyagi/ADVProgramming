#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int initial = 3, additional = 2;
    char **strings = (char**)malloc(initial * sizeof(char*));

    for (int i = 0; i < initial; i++) {
        strings[i] = (char*)malloc(100 * sizeof(char));
        printf("String %d: ", i+1);
        scanf(" %[^\n]%*c", strings[i]);
    }

    strings = (char**)realloc(strings, (initial + additional) * sizeof(char*));
    for (int i = initial; i < initial + additional; i++) {
        strings[i] = (char*)malloc(100 * sizeof(char));
        printf("String %d: ", i+1);
        scanf(" %[^\n]%*c", strings[i]);
    }

    printf("\nAll strings:\n");
    for (int i = 0; i < initial + additional; i++)
        printf("- %s\n", strings[i]);

    // Free memory
    for (int i = 0; i < initial + additional; i++) free(strings[i]);
    free(strings);
    return 0;
}