#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "budget.h"
#include "utilities.h"

int asset_count = 0;
char asset_id[MAX_ASSETS][20];
char asset_name[MAX_ASSETS][50];
char asset_type[MAX_ASSETS][50];
char asset_department[MAX_ASSETS][50];
char asset_condition[MAX_ASSETS][30];
float purchase_value[MAX_ASSETS];

char type_list[TYPE_COUNT][20] =
    {"Vehicle", "Computer", "Building", "Equipment", "Office Furniture", "Other"};
char condition_list[CONDITION_COUNT][20] =
    {"Excellent", "Good", "Fair", "Poor"};

/* Returns the position of an asset, or -1 if the ID is not in the list. */
static int findAsset(char id[])
{
    for (int i = 0; i < asset_count; i++)
    {
        if (strcmp(asset_id[i], id) == 0)
        {
            return i;
        }
    }
    return -1;
}

/* ---------- Validation ---------- */

int validateAssetId(char id[])
{
    int length = strlen(id);

    if (length == 0)
    {
        printf("Error: the asset ID cannot be empty.\n");
        return 0;
    }
    if (length >= 20)
    {
        printf("Error: the asset ID is too long (maximum 19 characters).\n");
        return 0;
    }
    for (int i = 0; i < length; i++)
    {
        if (id[i] == ' ')
        {
            printf("Error: the asset ID cannot contain spaces.\n");
            return 0;
        }
    }
    return 1;
}

int validateAssetName(char name[])
{
    if (strlen(name) == 0 || name[0] == ' ')
    {
        printf("Error: the asset name cannot be empty.\n");
        return 0;
    }
    if (strlen(name) >= 50)
    {
        printf("Error: the asset name is too long (maximum 49 characters).\n");
        return 0;
    }
    return 1;
}

int validateAssetType(char type[])
{
    if (strlen(type) == 0)
    {
        printf("Error: no asset type was chosen.\n");
        return 0;
    }
    return 1;
}

/* Returns the value if it is valid, otherwise -1. */
float validatePurchaseValue(float value)
{
    if (value <= 0)
    {
        printf("Error: the purchase value must be greater than zero.\n");
        return -1;
    }
    return value;
}

/* ---------- Selection ---------- */

void selectAssetType(char type[])
{
    int choice;

    type[0] = '\0';
    printf("\nSelect the asset type:\n");
    for (int i = 0; i < TYPE_COUNT; i++)
    {
        printf("%d. %s\n", i + 1, type_list[i]);
    }
    printf("Enter number (0 to cancel): ");
    choice = readInt();

    if (choice >= 1 && choice <= TYPE_COUNT)
    {
        strcpy(type, type_list[choice - 1]);
    }
    else if (choice != 0)
    {
        printf("Invalid choice.\n");
    }
}

/* The department must be one of the departments in the Budget module. */
void selectAssetDepartment(char department[])
{
    int choice;

    department[0] = '\0';
    if (budget_count == 0)
    {
        printf("No departments exist yet. Add a department in Budget Management first.\n");
        return;
    }

    printf("\nSelect the department:\n");
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

void selectAssetCondition(char condition[])
{
    int choice;

    condition[0] = '\0';
    printf("\nSelect the condition:\n");
    for (int i = 0; i < CONDITION_COUNT; i++)
    {
        printf("%d. %s\n", i + 1, condition_list[i]);
    }
    printf("Enter number (0 to cancel): ");
    choice = readInt();

    if (choice >= 1 && choice <= CONDITION_COUNT)
    {
        strcpy(condition, condition_list[choice - 1]);
    }
    else if (choice != 0)
    {
        printf("Invalid choice.\n");
    }
}

/* ---------- Display ---------- */

void displayAssetDetails(int position)
{
    char label[100];

    /* build "ID - Name" with strcpy and strcat */
    strcpy(label, asset_id[position]);
    strcat(label, " - ");
    strcat(label, asset_name[position]);

    printf("\nAsset          : %s\n", label);
    printf("Asset Type     : %s\n", asset_type[position]);
    printf("Department     : %s\n", asset_department[position]);
    printf("Condition      : %s\n", asset_condition[position]);
    printf("Purchase Value : N$%.2f\n", purchase_value[position]);
}

void displayAssets(void)
{
    float total = 0;

    printf("\n--- ASSET REGISTER ---\n");
    if (asset_count == 0)
    {
        printf("No assets have been entered yet.\n");
        return;
    }

    printf("%-10s %-20s %-16s %-16s %-10s %s\n",
           "ID", "Name", "Type", "Department", "Condition", "Value (N$)");
    for (int i = 0; i < asset_count; i++)
    {
        printf("%-10s %-20s %-16s %-16s %-10s %.2f\n",
               asset_id[i], asset_name[i], asset_type[i],
               asset_department[i], asset_condition[i], purchase_value[i]);
        total = total + purchase_value[i];
    }
    printf("\nTotal assets: %d\n", asset_count);
    printf("Total value : N$%.2f\n", total);
}

/* ---------- CRUD ---------- */

void addAsset(void)
{
    char id[100];
    char name[100];
    char type[50];
    char department[50];
    char condition[30];
    float value;

    if (asset_count >= MAX_ASSETS)
    {
        printf("The asset register is full.\n");
        return;
    }

    printf("\n--- ADD ASSET ---\n");
    printf("Asset ID (for example AST001): ");
    readLine(id, sizeof(id));
    if (validateAssetId(id) == 0)
    {
        return;
    }
    if (findAsset(id) != -1)
    {
        printf("Error: an asset with that ID already exists.\n");
        return;
    }

    printf("Asset name: ");
    readLine(name, sizeof(name));
    if (validateAssetName(name) == 0)
    {
        return;
    }

    selectAssetType(type);
    if (validateAssetType(type) == 0)
    {
        return;
    }

    selectAssetDepartment(department);
    if (strlen(department) == 0)
    {
        printf("Asset not added.\n");
        return;
    }

    selectAssetCondition(condition);
    if (strlen(condition) == 0)
    {
        printf("Asset not added.\n");
        return;
    }

    do
    {
        value = validatePurchaseValue(readAmount("Purchase value (N$): "));
    } while (value < 0);

    strcpy(asset_id[asset_count], id);
    strcpy(asset_name[asset_count], name);
    strcpy(asset_type[asset_count], type);
    strcpy(asset_department[asset_count], department);
    strcpy(asset_condition[asset_count], condition);
    purchase_value[asset_count] = value;
    asset_count++;

    printf("Asset added.\n");
    displayAssetDetails(asset_count - 1);
}

void searchAsset(void)
{
    char text[100];
    int choice;
    int found = 0;
    int match;

    printf("\n--- SEARCH ASSETS ---\n");
    printf("1. Search by asset ID\n");
    printf("2. Search by asset name\n");
    printf("3. Search by asset type\n");
    printf("4. Search by department\n");
    printf("Enter choice: ");
    choice = readInt();
    if (choice < 1 || choice > 4)
    {
        printf("Invalid choice.\n");
        return;
    }

    printf("Enter the text to search for: ");
    readLine(text, sizeof(text));

    for (int i = 0; i < asset_count; i++)
    {
        match = 0;
        if (choice == 1 && strcmp(asset_id[i], text) == 0)
        {
            match = 1;
        }
        else if (choice == 2 && strcmp(asset_name[i], text) == 0)
        {
            match = 1;
        }
        else if (choice == 3 && strcmp(asset_type[i], text) == 0)
        {
            match = 1;
        }
        else if (choice == 4 && strcmp(asset_department[i], text) == 0)
        {
            match = 1;
        }

        if (match == 1)
        {
            displayAssetDetails(i);
            found++;
        }
    }

    if (found == 0)
    {
        printf("No asset found.\n");
    }
}

void updateAsset(void)
{
    char id[100];
    char text[100];
    int index;
    int choice;
    float value;

    printf("\n--- UPDATE ASSET ---\n");
    printf("Enter the asset ID: ");
    readLine(id, sizeof(id));
    index = findAsset(id);
    if (index == -1)
    {
        printf("Asset not found.\n");
        return;
    }
    displayAssetDetails(index);

    printf("\n1. Change name\n");
    printf("2. Change type\n");
    printf("3. Change department\n");
    printf("4. Change condition\n");
    printf("5. Change purchase value\n");
    printf("Enter choice: ");
    choice = readInt();

    switch (choice)
    {
    case 1:
        printf("New name: ");
        readLine(text, sizeof(text));
        if (validateAssetName(text) == 0)
        {
            return;
        }
        strcpy(asset_name[index], text);
        break;
    case 2:
        selectAssetType(text);
        if (validateAssetType(text) == 0)
        {
            return;
        }
        strcpy(asset_type[index], text);
        break;
    case 3:
        selectAssetDepartment(text);
        if (strlen(text) == 0)
        {
            return;
        }
        strcpy(asset_department[index], text);
        break;
    case 4:
        selectAssetCondition(text);
        if (strlen(text) == 0)
        {
            return;
        }
        strcpy(asset_condition[index], text);
        break;
    case 5:
        do
        {
            value = validatePurchaseValue(readAmount("New purchase value (N$): "));
        } while (value < 0);
        purchase_value[index] = value;
        break;
    default:
        printf("Invalid choice.\n");
        return;
    }

    printf("Asset updated.\n");
    displayAssetDetails(index);
}

void deleteAsset(void)
{
    char id[100];
    int index;

    printf("\n--- DELETE ASSET ---\n");
    printf("Enter the asset ID: ");
    readLine(id, sizeof(id));
    index = findAsset(id);
    if (index == -1)
    {
        printf("Asset not found.\n");
        return;
    }

    displayAssetDetails(index);
    if (askYesNo("Are you sure you want to delete this asset") == 0)
    {
        printf("Delete cancelled.\n");
        return;
    }

    /* move every later asset up one place to close the gap */
    for (int i = index; i < asset_count - 1; i++)
    {
        strcpy(asset_id[i], asset_id[i + 1]);
        strcpy(asset_name[i], asset_name[i + 1]);
        strcpy(asset_type[i], asset_type[i + 1]);
        strcpy(asset_department[i], asset_department[i + 1]);
        strcpy(asset_condition[i], asset_condition[i + 1]);
        purchase_value[i] = purchase_value[i + 1];
    }
    asset_count--;
    printf("Asset deleted.\n");
}

void assetMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("           ASSET MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add asset\n");
        printf("2. Display asset register\n");
        printf("3. Search assets\n");
        printf("4. Update asset\n");
        printf("5. Delete asset\n");
        printf("6. Back to main menu\n");
        printf("Enter your choice: ");
        choice = readInt();

        switch (choice)
        {
        case 1: addAsset(); break;
        case 2: displayAssets(); break;
        case 3: searchAsset(); break;
        case 4: updateAsset(); break;
        case 5: deleteAsset(); break;
        case 6: break;
        default: printf("Invalid choice. Enter a number from 1 to 6.\n");
        }
    } while (choice != 6);
}
