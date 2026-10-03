#include <stdio.h>
#include "reports.h"

void employeeReport(int count)
{
    printf("\n===== EMPLOYEE REPORT =====\n");
    printf("Total Employees: %d\n", count);
}

void budgetReport(char departments[][50],
                  float allocated[],
                  float expenditure[],
                  int count)
{
    int i;
    float totalAllocated = 0;
    float totalExpenditure = 0;

    printf("\n===== BUDGET REPORT =====\n");

    for (i = 0; i < count; i++)
    {
        totalAllocated += allocated[i];
        totalExpenditure += expenditure[i];
    }

    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Remaining Budget: N$%.2f\n",
           totalAllocated - totalExpenditure);

    printf("\nDepartments Over Budget:\n");

    for (i = 0; i < count; i++)
    {
        if (expenditure[i] > allocated[i])
        {
            printf("%s\n", departments[i]);
        }
    }
}

void supplierReport(char ids[][20],
                    char names[][50],
                    char emails[][40],
                    char phones[][20],
                    char towns[][30],
                    int count)
{
    int i;

    printf("\n===== SUPPLIER REPORT =====\n");

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

void assetReport(char assetIds[][20],
                 char assetNames[][50],
                 char assetTypes[][30],
                 float purchaseValue[],
                 char departments[][50],
                 char conditions[][30],
                 int count)
{
    int i;
    float totalValue = 0;

    printf("\n===== ASSET REPORT =====\n");

    for (i = 0; i < count; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("ID: %s\n", assetIds[i]);
        printf("Name: %s\n", assetNames[i]);
        printf("Type: %s\n", assetTypes[i]);
        printf("Purchase Value: N$%.2f\n", purchaseValue[i]);
        printf("Department: %s\n", departments[i]);
        printf("Condition: %s\n", conditions[i]);

        totalValue += purchaseValue[i];
    }

    printf("\nTotal Assets: %d\n", count);
    printf("Total Asset Value: N$%.2f\n", totalValue);
}

void displayReports(void)
{
    printf("\n===== REPORTS =====\n");
    printf("1. Employee Report\n");
    printf("2. Budget Report\n");
    printf("3. Supplier Report\n");
    printf("4. Asset Report\n");
}
