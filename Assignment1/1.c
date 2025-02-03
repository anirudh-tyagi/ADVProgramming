#include <stdio.h>
#include <stdlib.h>

// Define the structure 'Student'
struct Student {
    char name[100];
    int rollno;
    float marks;
};

int main() {
    int n = 5;
    struct Student *students;

    // Dynamically allocate memory for 5 students
    students = (struct Student*)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input details for 5 students
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]%*c", students[i].name); // Read string with spaces
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Print details of students with marks > 75
    printf("\nStudents with marks greater than 75:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks > 75) {
            printf("Name: %s\n", students[i].name);
            printf("Roll No: %d\n", students[i].rollno);
            printf("Marks: %.2f\n\n", students[i].marks);
        }
    }

    // Free the allocated memory
    free(students);

    return 0;
}