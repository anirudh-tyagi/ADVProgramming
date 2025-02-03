#include <stdio.h>
#include <stdlib.h>

void pattern(int a) {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", a);
            a++;
        }
        printf("\n");  
    }
}

int main() {
    pattern(1);
    return 0;
}
