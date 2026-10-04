#include <stdio.h>
#include <string.h>
#include "reports.h"

/* Employee data from employees.c */
extern char employeeName[][50];
extern char employeeGender[][10];
extern char department[][50];
extern float basicSalary[];

/* ================= EMPLOYEE REPORTS ================= */

void employeeStatistics(int count)
{
    int i;
    float total = 0;
    float highest = 0;
    float lowest = 0;
    float average;

    printf("\n===== EMPLOYEE STATISTICS =====\n");

    if (count <= 0)
    {
        printf("No employee records available.\n");
        return;
    }

    highest = basicSalary[0];
    lowest = basicSalary[0];

    for (i = 0; i < count; i++)
    {
        total += basicSalary[i];

        if (basicSalary[i] > highest)
            highest = basicSalary[i];

        if (basicSalary[i] < lowest)
            lowest = basicSalary[i];
    }

    average = total / count;

    printf("Total Employees: %d\n", count);
    printf("Total Payroll: N$%.2f\n", total);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);
    printf("Average Salary: N$%.2f\n", average);
}

void departmentStatistics(int count)
{
    int i, j, found, number;

    printf("\n===== DEPARTMENT STATISTICS =====\n");

    if (count <= 0)
    {
        printf("No employee records available.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        found = 0;

        for (j = 0; j < i; j++)
        {
            if (strcmp(department[i], department[j]) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found)
            continue;

        number = 0;

        for (j = 0; j < count; j++)
        {
            if (strcmp(department[i], department[j]) == 0)
                number++;
        }

        printf("%s: %d employee(s)\n", department[i], number);
    }
}

void genderStatistics(int count)
{
    int i;
    int male = 0;
    int female = 0;

    printf("\n===== GENDER STATISTICS =====\n");

    if (count <= 0)
    {
        printf("No employee records available.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        if (strcmp(employeeGender[i], "Male") == 0)
            male++;
        else if (strcmp(employeeGender[i], "Female") == 0)
            female++;
    }

    printf("Male Employees: %d\n", male);
    printf("Female Employees: %d\n", female);
    printf("Total Employees: %d\n", count);
}

void employeeReport(int count)
{
    int choice;

    do
    {
        printf("\n===== EMPLOYEE REPORT =====\n");
        printf("1. Employee Statistics\n");
        printf("2. Department Statistics\n");
        printf("3. Gender Statistics\n");
        printf("4. Return\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                employeeStatistics(count);
                break;

            case 2:
                departmentStatistics(count);
                break;

            case 3:
                genderStatistics(count);
                break;

            case 4:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
}


/* ================= SUPPLIER REPORTS ================= */

void displaySupplierReport(char ids[][20],
                           char names[][50],
                           char emails[][40],
                           char phones[][20],
                           char towns[][30],
                           int count)
{
    int i;

    printf("\n===== DISPLAY SUPPLIERS =====\n");

    if (count <= 0)
    {
        printf("No supplier records available.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("ID: %s\n", ids[i]);
        printf("Name: %s\n", names[i]);
        printf("Email: %s\n", emails[i]);
        printf("Phone: %s\n", phones[i]);
        printf("Town: %s\n", towns[i]);
    }
}

void supplierLocationReport(char towns[][30], int count)
{
    int i, j, found, number;

    printf("\n===== SUPPLIER LOCATION REPORT =====\n");

    if (count <= 0)
    {
        printf("No supplier records available.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        found = 0;

        for (j = 0; j < i; j++)
        {
            if (strcmp(towns[i], towns[j]) == 0)
            {
                found = 1;
                break;
            }
        }

        if (found)
            continue;

        number = 0;

        for (j = 0; j < count; j++)
        {
            if (strcmp(towns[i], towns[j]) == 0)
                number++;
        }

        printf("%s: %d supplier(s)\n", towns[i], number);
    }
}

void totalSupplierReport(int count)
{
    printf("\n===== TOTAL SUPPLIERS REPORT =====\n");
    printf("Total Suppliers: %d\n", count);
}

void supplierReport(char ids[][20],
                    char names[][50],
                    char emails[][40],
                    char phones[][20],
                    char towns[][30],
                    int count)
{
    int choice;

    do
    {
        printf("\n===== SUPPLIER REPORT =====\n");
        printf("1. Display Suppliers\n");
        printf("2. Supplier Location Report\n");
        printf("3. Total Suppliers Report\n");
        printf("4. Return\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                displaySupplierReport(ids, names, emails, phones, towns, count);
                break;

            case 2:
                supplierLocationReport(towns, count);
                break;

            case 3:
                totalSupplierReport(count);
                break;

            case 4:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
}


/* ================= REPORTS MENU ================= */

void displayReports(void)
{
    printf("\n===== REPORTS =====\n");
    printf("1. Employee Report\n");
    printf("2. Supplier Report\n");
    printf("3. Return\n");
}
