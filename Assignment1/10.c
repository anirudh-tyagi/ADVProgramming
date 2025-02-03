#include <stdio.h>

struct Complex { float real, imag; };

struct Complex add(struct Complex *a, struct Complex *b) {
    struct Complex result = {a->real + b->real, a->imag + b->imag};
    return result;
}

int main() {
    struct Complex c1, c2;
    printf("Complex 1 (real imag): "); scanf("%f %f", &c1.real, &c1.imag);
    printf("Complex 2 (real imag): "); scanf("%f %f", &c2.real, &c2.imag);

    struct Complex sum = add(&c1, &c2);
    printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);
    return 0;
}