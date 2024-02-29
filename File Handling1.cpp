//46.	Write a program to enter records in a file with members as id, name and salary. 
//Develop a program to read the file and find out employee highest salary.
#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    FILE *file;
    struct Employee emp;
    float maxSalary = 0;

    // Open file in write mode
    file = fopen("employee_records.txt", "w");
    if (file == NULL) {
        printf("Error opening file.");
        return 1;
    }

    // Input records
    printf("Enter employee details (id, name, salary):\n");
    while (1) {
        printf("Enter employee id (-1 to exit): ");
        scanf("%d", &emp.id);
        if (emp.id == -1) {
            break;
        }
        printf("Enter employee name: ");
        scanf("%s", emp.name);
        printf("Enter employee salary: ");
        scanf("%f", &emp.salary);

        // Write record to file
        fprintf(file, "%d %s %.2f\n", emp.id, emp.name, emp.salary);
    }

    // Close file
    fclose(file);

    // Open file in read mode
    file = fopen("employee_records.txt", "r");
    if (file == NULL) {
        printf("Error opening file.");
        return 1;
    }

    // Read records and find highest salary
    printf("\nEmployee records:\n");
    while (fscanf(file, "%d %s %f", &emp.id, emp.name, &emp.salary) != EOF) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
        if (emp.salary > maxSalary) {
            maxSalary = emp.salary;
        }
    }

    // Close file
    fclose(file);

    printf("\nHighest salary among employees: %.2f\n", maxSalary);

    return 0;
}

