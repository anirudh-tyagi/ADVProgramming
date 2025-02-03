#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure 'Employee'
struct Employee {
    int id;
    char name[100];
    float salary;
};

// Function to input employee details
void inputEmployeeDetails(struct Employee *employees, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &employees[i].id);
        printf("Name: ");
        scanf(" %[^\n]%*c", employees[i].name); // Read string with spaces
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }
}

// Function to sort employees by salary in descending order
void sortEmployeesBySalary(struct Employee *employees, int count) {
    struct Employee temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (employees[i].salary < employees[j].salary) {
                // Swap employees[i] and employees[j]
                temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

// Function to print employee details
void printEmployeeDetails(struct Employee *employees, int count) {
    printf("\nEmployee details sorted by salary (descending):\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Salary: %.2f\n\n", employees[i].salary);
    }
}

int main() {
    int n;
    struct Employee *employees;

    // Ask user for the number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array of employees
    employees = (struct Employee*)malloc(n * sizeof(struct Employee));
    if (employees == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input employee details
    inputEmployeeDetails(employees, n);

    // Sort the employees by salary
    sortEmployeesBySalary(employees, n);

    // Print the sorted employee details
    printEmployeeDetails(employees, n);

    // Free the allocated memory
    free(employees);

    return 0;
}