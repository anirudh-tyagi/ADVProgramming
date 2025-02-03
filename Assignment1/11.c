#include <stdio.h>
#include <stdlib.h>

struct Student {
    int *subjects;
    int total;
};

int main() {
    int nStudents = 2, nSubjects = 3;
    struct Student *students = (struct Student*)malloc(nStudents * sizeof(struct Student));

    for (int i = 0; i < nStudents; i++) {
        students[i].subjects = (int*)malloc(nSubjects * sizeof(int));
        students[i].total = 0;

        printf("Student %d marks:\n", i+1);
        for (int j = 0; j < nSubjects; j++) {
            scanf("%d", &students[i].subjects[j]);
            students[i].total += students[i].subjects[j];
        }
    }

    printf("\nTotal marks:\n");
    for (int i = 0; i < nStudents; i++)
        printf("Student %d: %d\n", i+1, students[i].total);

    // Free memory
    for (int i = 0; i < nStudents; i++) free(students[i].subjects);
    free(students);
    return 0;
}