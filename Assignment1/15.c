#include <stdio.h>
#include <stdlib.h>

int strLength(char *s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

void reverse(char *s) {
    int len = strLength(s);
    for (int i = 0; i < len/2; i++) {
        char temp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = temp;
    }
}

int main() {
    char *str = (char*)calloc(100, sizeof(char));
    printf("Enter a string: ");
    scanf(" %[^\n]%*c", str);

    printf("Length: %d\n", strLength(str));
    reverse(str);
    printf("Reversed: %s\n", str);

    free(str);
    return 0;
}