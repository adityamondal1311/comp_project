#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char job_title[50];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int num_employees = 0;

void add_employee() {
    struct Employee new_employee;
    printf("Enter employee ID: ");
    scanf("%d", &new_employee.id);
    printf("Enter employee name: ");
    scanf("%s", new_employee.name);
    printf("Enter employee job title: ");
    scanf("%s", new_employee.job_title);
    printf("Enter employee salary: ");
    scanf("%f", &new_employee.salary);
    employees[num_employees++] = new_employee;
}

void display_employees() {
    printf("Employee ID\tName\tJob Title\tSalary\n");
    for (int i = 0; i < num_employees; i++) {
        printf("%d\t%s\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].job_title, employees[i].salary);
    }
}

void search_employee() {
    int search_id;
    printf("Enter employee ID to search: ");
    scanf("%d", &search_id);
    for (int i = 0; i < num_employees; i++) {
        if (employees[i].id == search_id) {
            printf("Employee found!\n");
            printf("Employee ID\tName\tJob Title\tSalary\n");
            printf("%d\t%s\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].job_title, employees[i].salary);
            return;
        }
    }
    printf("Employee not found!\n");
}

int main() {
    int choice;
    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                display_employees();
                break;
            case 3:
                search_employee();
                break;
            case 4:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);
    return 0;
}
