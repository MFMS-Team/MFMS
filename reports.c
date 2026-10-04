#include <stdio.h>
#include <string.h>
#include "reports.h"
#include "utilities.h"

/* ---------- Budget reports ---------- */

void budgetReport(void)
{
    float total_allocated = 0;
    float total_spent = 0;
    int over = 0;

    printf("\n===== BUDGET REPORT =====\n");
    if (budget_count == 0)
    {
        printf("No budgets have been entered yet.\n");
        return;
    }

    for (int i = 0; i < budget_count; i++)
    {
        total_allocated = total_allocated + allocated_budget[i];
        total_spent = total_spent + expenditure[i];
        if (expenditure[i] > allocated_budget[i])
        {
            over++;
        }
    }

    printf("Total Departments       : %d\n", budget_count);
    printf("Total Allocated Budget  : N$%.2f\n", total_allocated);
    printf("Total Expenditure       : N$%.2f\n", total_spent);
    printf("Remaining Budget        : N$%.2f\n", total_allocated - total_spent);
    printf("Departments Over Budget : %d\n", over);

    if (over > 0)
    {
        printf("\nDepartments exceeding their budget:\n");
        for (int i = 0; i < budget_count; i++)
        {
            if (expenditure[i] > allocated_budget[i])
            {
                printf("- %s\n", department_name[i]);
            }
        }
    }
}

void totalBudgetReport(void)
{
    float total = 0;

    printf("\n===== TOTAL BUDGET REPORT =====\n");
    if (budget_count == 0)
    {
        printf("No budgets have been entered yet.\n");
        return;
    }

    printf("%-20s %s\n", "Department", "Allocated (N$)");
    for (int i = 0; i < budget_count; i++)
    {
        printf("%-20s %.2f\n", department_name[i], allocated_budget[i]);
        total = total + allocated_budget[i];
    }
    printf("\nTotal allocated budget: N$%.2f\n", total);
}

void remainingBudgetReport(void)
{
    float total_remaining = 0;

    printf("\n===== REMAINING BUDGET REPORT =====\n");
    if (budget_count == 0)
    {
        printf("No budgets have been entered yet.\n");
        return;
    }

    printf("%-20s %-14s %-14s %s\n", "Department", "Allocated", "Spent", "Remaining");
    for (int i = 0; i < budget_count; i++)
    {
        printf("%-20s %-14.2f %-14.2f %.2f\n", department_name[i],
               allocated_budget[i], expenditure[i], calculateRemainingBudget(i));
        total_remaining = total_remaining + calculateRemainingBudget(i);
    }
    printf("\nTotal remaining budget: N$%.2f\n", total_remaining);
    printf("(A negative amount means the department has overspent.)\n");
}

void exceededBudgetReport(void)
{
    int found = 0;
    float total_over = 0;

    printf("\n===== EXCEEDED BUDGET REPORT =====\n");
    for (int i = 0; i < budget_count; i++)
    {
        if (expenditure[i] > allocated_budget[i])
        {
            printf("%-20s Allocated: N$%.2f  Spent: N$%.2f  Over by: N$%.2f\n",
                   department_name[i], allocated_budget[i], expenditure[i],
                   expenditure[i] - allocated_budget[i]);
            total_over = total_over + (expenditure[i] - allocated_budget[i]);
            found++;
        }
    }

    if (found == 0)
    {
        printf("No department has exceeded its budget.\n");
    }
    else
    {
        printf("\nDepartments over budget: %d\n", found);
        printf("Total overspent        : N$%.2f\n", total_over);
    }
}

void budgetStatisticsReport(void)
{
    float total_allocated = 0;
    float total_spent = 0;
    int highest = 0;
    int lowest = 0;
    int over = 0;

    printf("\n===== BUDGET STATISTICS REPORT =====\n");
    if (budget_count == 0)
    {
        printf("No budgets have been entered yet.\n");
        return;
    }

    /* the first department starts as both the highest and the lowest */
    for (int i = 0; i < budget_count; i++)
    {
        total_allocated = total_allocated + allocated_budget[i];
        total_spent = total_spent + expenditure[i];

        if (allocated_budget[i] > allocated_budget[highest])
        {
            highest = i;
        }
        if (allocated_budget[i] < allocated_budget[lowest])
        {
            lowest = i;
        }
        if (expenditure[i] > allocated_budget[i])
        {
            over++;
        }
    }

    printf("Number of Departments : %d\n", budget_count);
    printf("Total Allocated       : N$%.2f\n", total_allocated);
    printf("Total Expenditure     : N$%.2f\n", total_spent);
    printf("Average Allocation    : N$%.2f\n", total_allocated / budget_count);
    printf("Average Expenditure   : N$%.2f\n", total_spent / budget_count);
    printf("Highest Allocation    : N$%.2f (%s)\n", allocated_budget[highest], department_name[highest]);
    printf("Lowest Allocation     : N$%.2f (%s)\n", allocated_budget[lowest], department_name[lowest]);
    printf("Within Budget         : %d department(s)\n", budget_count - over);
    printf("Over Budget           : %d department(s)\n", over);
}

/* ---------- Asset reports ---------- */

void assetReport(void)
{
    printf("\n===== ASSET REPORT =====");
    displayAssets();
}

void assetTypeReport(void)
{
    int count;
    float total;

    printf("\n===== ASSET TYPE REPORT =====\n");
    if (asset_count == 0)
    {
        printf("No assets have been entered yet.\n");
        return;
    }

    printf("%-20s %-8s %s\n", "Type", "Assets", "Total Value (N$)");
    for (int t = 0; t < TYPE_COUNT; t++)
    {
        count = 0;
        total = 0;
        for (int i = 0; i < asset_count; i++)
        {
            if (strcmp(asset_type[i], type_list[t]) == 0)
            {
                count++;
                total = total + purchase_value[i];
            }
        }
        printf("%-20s %-8d %.2f\n", type_list[t], count, total);
    }
}

void assetConditionReport(void)
{
    int count;
    float total;

    printf("\n===== ASSET CONDITION REPORT =====\n");
    if (asset_count == 0)
    {
        printf("No assets have been entered yet.\n");
        return;
    }

    printf("%-20s %-8s %s\n", "Condition", "Assets", "Total Value (N$)");
    for (int c = 0; c < CONDITION_COUNT; c++)
    {
        count = 0;
        total = 0;
        for (int i = 0; i < asset_count; i++)
        {
            if (strcmp(asset_condition[i], condition_list[c]) == 0)
            {
                count++;
                total = total + purchase_value[i];
            }
        }
        printf("%-20s %-8d %.2f\n", condition_list[c], count, total);
    }
}

void assetDepartmentReport(void)
{
    int count;
    int counted = 0;
    float total;
    float counted_value = 0;
    float all_value = 0;

    printf("\n===== ASSET DEPARTMENT REPORT =====\n");
    if (asset_count == 0)
    {
        printf("No assets have been entered yet.\n");
        return;
    }

    printf("%-20s %-8s %s\n", "Department", "Assets", "Total Value (N$)");
    for (int d = 0; d < budget_count; d++)
    {
        count = 0;
        total = 0;
        for (int i = 0; i < asset_count; i++)
        {
            if (strcmp(asset_department[i], department_name[d]) == 0)
            {
                count++;
                total = total + purchase_value[i];
            }
        }
        printf("%-20s %-8d %.2f\n", department_name[d], count, total);
        counted = counted + count;
        counted_value = counted_value + total;
    }

    /* assets whose department was deleted from the Budget module */
    if (counted < asset_count)
    {
        for (int i = 0; i < asset_count; i++)
        {
            all_value = all_value + purchase_value[i];
        }
        printf("%-20s %-8d %.2f\n", "Other", asset_count - counted, all_value - counted_value);
    }
}

void assetStatisticsReport(void)
{
    float total = 0;
    int highest = 0;
    int lowest = 0;
    int count;

    printf("\n===== ASSET STATISTICS REPORT =====\n");
    if (asset_count == 0)
    {
        printf("No assets have been entered yet.\n");
        return;
    }

    for (int i = 0; i < asset_count; i++)
    {
        total = total + purchase_value[i];
        if (purchase_value[i] > purchase_value[highest])
        {
            highest = i;
        }
        if (purchase_value[i] < purchase_value[lowest])
        {
            lowest = i;
        }
    }

    printf("Total Assets           : %d\n", asset_count);
    printf("Total Purchase Value   : N$%.2f\n", total);
    printf("Average Purchase Value : N$%.2f\n", total / asset_count);
    printf("Highest Purchase Value : N$%.2f (%s)\n", purchase_value[highest], asset_name[highest]);
    printf("Lowest Purchase Value  : N$%.2f (%s)\n", purchase_value[lowest], asset_name[lowest]);

    printf("\nAssets by condition:\n");
    for (int c = 0; c < CONDITION_COUNT; c++)
    {
        count = 0;
        for (int i = 0; i < asset_count; i++)
        {
            if (strcmp(asset_condition[i], condition_list[c]) == 0)
            {
                count++;
            }
        }
        printf("%-10s : %d\n", condition_list[c], count);
    }
}

/* ---------- Reports menu ---------- */

void reportsMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("                REPORTS\n");
        printf("========================================\n");
        printf("1. Budget report\n");
        printf("2. Total budget report\n");
        printf("3. Remaining budget report\n");
        printf("4. Exceeded budget report\n");
        printf("5. Budget statistics report\n");
        printf("6. Asset report\n");
        printf("7. Asset type report\n");
        printf("8. Asset condition report\n");
        printf("9. Asset department report\n");
        printf("10. Asset statistics report\n");
        printf("11. Back to main menu\n");
        printf("Enter your choice: ");
        choice = readInt();

        switch (choice)
        {
        case 1: budgetReport(); break;
        case 2: totalBudgetReport(); break;
        case 3: remainingBudgetReport(); break;
        case 4: exceededBudgetReport(); break;
        case 5: budgetStatisticsReport(); break;
        case 6: assetReport(); break;
        case 7: assetTypeReport(); break;
        case 8: assetConditionReport(); break;
        case 9: assetDepartmentReport(); break;
        case 10: assetStatisticsReport(); break;
        case 11: break;
        default: printf("Invalid choice. Enter a number from 1 to 11.\n");
        }
    } while (choice != 11);
}
