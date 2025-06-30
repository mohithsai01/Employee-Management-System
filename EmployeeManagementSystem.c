#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

typedef struct {
    int id;
    char name[50];
    char position[50];
    float salary;
} Employee;

Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Employee limit reached. Cannot add more employees.\n");
        return;
    }
    
    Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp.name);
    printf("Enter Employee Position: ");
    scanf(" %[^\n]", emp.position);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);
    
    employees[employeeCount++] = emp;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    if (employeeCount == 0) {
        printf("No employees to display.\n");
        return;
    }
    
    printf("\nEmployee List:\n");
    printf("ID\tName\t\tPosition\tSalary\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < employeeCount; i++) {
        printf("%d\t%s\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].position, employees[i].salary);
    }
}

void searchEmployee() {
    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            printf("Employee Found:\n");
            printf("ID: %d\nName: %s\nPosition: %s\nSalary: %.2f\n", employees[i].id, employees[i].name, employees[i].position, employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

int main() {
    int choice;
    
    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
