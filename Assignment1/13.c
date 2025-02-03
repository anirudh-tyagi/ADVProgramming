#include <stdio.h>
#include <stdlib.h>

struct Person { char name[50]; int age; };

int main() {
    int n = 5;
    struct Person *people = (struct Person*)malloc(n * sizeof(struct Person));

    for (int i = 0; i < n; i++) {
        printf("Person %d (name age): ", i+1);
        scanf("%s %d", people[i].name, &people[i].age);
    }

    int maxAge = 0, oldestIdx = 0;
    for (int i = 0; i < n; i++)
        if (people[i].age > maxAge) {
            maxAge = people[i].age;
            oldestIdx = i;
        }

    printf("Oldest: %s (%d)\n", people[oldestIdx].name, maxAge);
    free(people);
    return 0;
}