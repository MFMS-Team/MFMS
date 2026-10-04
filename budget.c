#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "budget.h"
#include "assets.h"
#include "utilities.h"

int budget_count = 0;
char department_name[MAX_DEPARTMENTS][50];
float allocated_budget[MAX_DEPARTMENTS];
float expenditure[MAX_DEPARTMENTS];

/* Compares two texts and ignores upper/lower case. Returns 1 if they match. */
static int sameText(char a[], char b[])
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0')
    {
        if (tolower((unsigned char)a[i]) != tolower((unsigned char)b[i]))
        {
            return 0;
        }
        i++;
    }
    return a[i] == b[i];
}

/* Returns the position of a department, or -1 if it is not in the list. */
static int findDepartment(char department[])
{
    for (int i = 0; i < budget_count; i++)
    {
        if (sameText(department_name[i], department) == 1)
        {
            return i;
        }
    }
    return -1;
}

int validateDepartmentName(char department[])
{
    if (strlen(department) == 0 || department[0] == ' ')
    {
        printf("Error: the department name cannot be empty.\n");
        return 0;
    }
    if (strlen(department) >= 50)
    {
        printf("Error: the department name is too long (maximum 49 characters).\n");
        return 0;
    }
    return 1;
}

float calculateRemainingBudget(int index)
{
    return allocated_budget[index] - expenditure[index];
}

void checkBudgetStatus(int index)
{
    if (expenditure[index] <= allocated_budget[index])
    {
        printf("WITHIN BUDGET");
    }
    else
    {
        printf("OVER BUDGET");
    }
}

void displayBudgetDetails(int index)
{
    printf("\nDepartment       : %s\n", department_name[index]);
    printf("Allocated Budget : N$%.2f\n", allocated_budget[index]);
    printf("Expenditure      : N$%.2f\n", expenditure[index]);
    printf("Remaining Budget : N$%.2f\n", calculateRemainingBudget(index));
    printf("Status           : ");
    checkBudgetStatus(index);
    printf("\n");
}

void addBudget(void)
{
    char name[100];
    float allocated;
    float spent;

    if (budget_count >= MAX_DEPARTMENTS)
    {
        printf("The budget list is full.\n");
        return;
    }

    printf("\n--- ADD DEPARTMENT BUDGET ---\n");
    printf("Department name: ");
    readLine(name, sizeof(name));

    if (validateDepartmentName(name) == 0)
    {
        return;
    }
    if (findDepartment(name) != -1)
    {
        printf("Error: that department already exists.\n");
        return;
    }

    allocated = readAmount("Allocated budget (N$): ");
    while (allocated <= 0)
    {
        printf("Error: the budget must be greater than zero.\n");
        allocated = readAmount("Allocated budget (N$): ");
    }
    spent = readAmount("Expenditure so far (N$, enter 0 if none): ");
    while (spent < 0)
    {
        printf("Error: the expenditure cannot be negative.\n");
        spent = readAmount("Expenditure so far (N$, enter 0 if none): ");
    }

    strcpy(department_name[budget_count], name);
    allocated_budget[budget_count] = allocated;
    expenditure[budget_count] = spent;
    budget_count++;

    printf("Department added.\n");
    displayBudgetDetails(budget_count - 1);
}

void displayBudget(void)
{
    printf("\n--- BUDGET INFORMATION ---\n");
    if (budget_count == 0)
    {
        printf("No budgets have been entered yet.\n");
        return;
    }

    printf("%-4s %-20s %-14s %-14s %-14s %s\n",
           "No.", "Department", "Allocated", "Spent", "Remaining", "Status");
    for (int i = 0; i < budget_count; i++)
    {
        printf("%-4d %-20s %-14.2f %-14.2f %-14.2f ",
               i + 1, department_name[i], allocated_budget[i],
               expenditure[i], calculateRemainingBudget(i));
        checkBudgetStatus(i);
        printf("\n");
    }
}

void searchBudget(void)
{
    char name[100];
    int index;

    printf("\n--- SEARCH BUDGET ---\n");
    printf("Enter the department name: ");
    readLine(name, sizeof(name));

    index = findDepartment(name);
    if (index == -1)
    {
        printf("Department not found.\n");
    }
    else
    {
        displayBudgetDetails(index);
    }
}

void selectDepartment(char department[])
{
    int choice;

    department[0] = '\0';
    if (budget_count == 0)
    {
        printf("No departments have been entered yet.\n");
        return;
    }

    printf("\nSelect a department:\n");
    for (int i = 0; i < budget_count; i++)
    {
        printf("%d. %s\n", i + 1, department_name[i]);
    }
    printf("Enter number (0 to cancel): ");
    choice = readInt();

    if (choice >= 1 && choice <= budget_count)
    {
        strcpy(department, department_name[choice - 1]);
    }
    else if (choice != 0)
    {
        printf("Invalid choice.\n");
    }
}

void updateBudget(void)
{
    char name[50];
    int index;
    int choice;
    float amount;

    printf("\n--- UPDATE BUDGET ---\n");
    selectDepartment(name);
    if (strlen(name) == 0)
    {
        return;
    }
    index = findDepartment(name);
    displayBudgetDetails(index);

    printf("\n1. Change allocated budget\n");
    printf("2. Add expenditure\n");
    printf("Enter choice: ");
    choice = readInt();

    switch (choice)
    {
    case 1:
        amount = readAmount("New allocated budget (N$): ");
        if (amount <= 0)
        {
            printf("Error: the budget must be greater than zero.\n");
            return;
        }
        allocated_budget[index] = amount;
        break;
    case 2:
        amount = readAmount("Expenditure to add (N$): ");
        if (amount < 0)
        {
            printf("Error: the expenditure cannot be negative.\n");
            return;
        }
        expenditure[index] = expenditure[index] + amount;
        break;
    default:
        printf("Invalid choice.\n");
        return;
    }

    printf("Budget updated.\n");
    displayBudgetDetails(index);
}

void deleteBudget(void)
{
    char name[50];
    int index;

    printf("\n--- DELETE DEPARTMENT ---\n");
    selectDepartment(name);
    if (strlen(name) == 0)
    {
        return;
    }
    index = findDepartment(name);

    /* a department that still has assets cannot be deleted */
    for (int i = 0; i < asset_count; i++)
    {
        if (strcmp(asset_department[i], department_name[index]) == 0)
        {
            printf("Cannot delete: assets are still assigned to this department.\n");
            return;
        }
    }

    if (askYesNo("Are you sure you want to delete this department") == 0)
    {
        printf("Delete cancelled.\n");
        return;
    }

    /* move every later department up one place to close the gap */
    for (int i = index; i < budget_count - 1; i++)
    {
        strcpy(department_name[i], department_name[i + 1]);
        allocated_budget[i] = allocated_budget[i + 1];
        expenditure[i] = expenditure[i + 1];
    }
    budget_count--;
    printf("Department deleted.\n");
}

/* Lists the departments that spent more than they were given. */
static void showOverBudget(void)
{
    int found = 0;

    printf("\n--- DEPARTMENTS OVER BUDGET ---\n");
    for (int i = 0; i < budget_count; i++)
    {
        if (expenditure[i] > allocated_budget[i])
        {
            printf("%s - over by N$%.2f\n", department_name[i],
                   expenditure[i] - allocated_budget[i]);
            found++;
        }
    }
    if (found == 0)
    {
        printf("No department has exceeded its budget.\n");
    }
}

void budgetMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("          BUDGET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add department budget\n");
        printf("2. Display budgets\n");
        printf("3. Search budget\n");
        printf("4. Update budget\n");
        printf("5. Delete department\n");
        printf("6. Show departments over budget\n");
        printf("7. Back to main menu\n");
        printf("Enter your choice: ");
        choice = readInt();

        switch (choice)
        {
        case 1: addBudget(); break;
        case 2: displayBudget(); break;
        case 3: searchBudget(); break;
        case 4: updateBudget(); break;
        case 5: deleteBudget(); break;
        case 6: showOverBudget(); break;
        case 7: break;
        default: printf("Invalid choice. Enter a number from 1 to 7.\n");
        }
    } while (choice != 7);
}
