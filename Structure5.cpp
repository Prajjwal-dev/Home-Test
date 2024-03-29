//Write a program to input 5 employee records (Emp_id, Emp_name and Emp_Salary). Display employee information whose name starts with 'D'.
#include <stdio.h>
#include <string.h>

#define NUM_EMPLOYEES 5

// Define structure for employee
struct Employee {
    int emp_id;
    char emp_name[50];
    float emp_salary;
};

int main() {
    struct Employee e[NUM_EMPLOYEES];

    // Input data for each employee
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Enter employee ID: ");
        scanf("%d", &e[i].emp_id);
        printf("Enter employee name: ");
        scanf("%s", e[i].emp_name);
        printf("Enter employee salary: ");
        scanf("%f", &e[i].emp_salary);
    }

    // Display employee information whose name starts with 'D'
    printf("\nEmployee information whose name starts with 'D':\n");
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        if (e[i].emp_name[0] == 'D') {
            printf("Employee ID: %d\n", e[i].emp_id);
            printf("Employee Name: %s\n", e[i].emp_name);
            printf("Employee Salary: %.2f\n", e[i].emp_salary);
            printf("\n");
        }
    }

    return 0;
}


