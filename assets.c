#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "assets.h"

/* ----------------------------------------------------------------------
   Helpers (same pattern as budget.c, kept local to this file)
   ---------------------------------------------------------------------- */
static void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

static void flushInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

static int equalsIgnoreCase(const char *a, const char *b) {
    while (*a && *b) {
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) {
            return 0;
        }
        a++;
        b++;
    }
    return *a == '\0' && *b == '\0';
}

/* Validates that the condition entered is one of the three allowed
   values, using strcmp() to compare against each allowed string. */
static int isValidCondition(const char *condition) {
    return strcmp(condition, "Good") == 0 ||
           strcmp(condition, "Fair") == 0 ||
           strcmp(condition, "Poor") == 0;
}

int findAssetIndexByID(Asset assets[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (assets[i].assetID == id) {
            return i;
        }
    }
    return -1;
}

int findAssetIndexByName(Asset assets[], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (equalsIgnoreCase(assets[i].name, name)) {
            return i;
        }
    }
    return -1;
}

/* ----------------------------------------------------------------------
   Add a new asset.
   Validation: ID must be unique and positive, name must not be empty,
   purchase value must not be negative, condition must be one of
   "Good" / "Fair" / "Poor" (re-prompted until valid).
   ---------------------------------------------------------------------- */
int addAsset(Asset assets[], int *count, int maxSize) {
    if (*count >= maxSize) {
        printf("Cannot add asset: asset register is full.\n");
        return 0;
    }

    int id;
    printf("Enter asset ID: ");
    if (scanf("%d", &id) != 1) {
        flushInputBuffer();
        printf("Invalid asset ID.\n");
        return 0;
    }
    flushInputBuffer();

    if (id <= 0) {
        printf("Asset ID must be a positive number.\n");
        return 0;
    }
    if (findAssetIndexByID(assets, *count, id) != -1) {
        printf("An asset with ID %d already exists.\n", id);
        return 0;
    }

    char name[MAX_NAME_LEN];
    printf("Enter asset name: ");
    readLine(name, MAX_NAME_LEN);
    if (strlen(name) == 0) {
        printf("Asset name cannot be empty.\n");
        return 0;
    }

    char type[MAX_TYPE_LEN];
    printf("Enter asset type (e.g. Vehicle, Computer, Building): ");
    readLine(type, MAX_TYPE_LEN);

    float value;
    printf("Enter purchase value: N$");
    if (scanf("%f", &value) != 1) {
        flushInputBuffer();
        printf("Invalid purchase value.\n");
        return 0;
    }
    flushInputBuffer();
    if (value < 0) {
        printf("Purchase value cannot be negative.\n");
        return 0;
    }

    char department[MAX_DEPARTMENT_LEN];
    printf("Enter department: ");
    readLine(department, MAX_DEPARTMENT_LEN);

    char condition[MAX_CONDITION_LEN];
    do {
        printf("Enter condition (Good / Fair / Poor): ");
        readLine(condition, MAX_CONDITION_LEN);
        if (!isValidCondition(condition)) {
            printf("Invalid condition. Please type exactly: Good, Fair, or Poor.\n");
        }
    } while (!isValidCondition(condition));

    assets[*count].assetID = id;
    strcpy(assets[*count].name, name);
    strcpy(assets[*count].type, type);
    assets[*count].purchaseValue = value;
    strcpy(assets[*count].department, department);
    strcpy(assets[*count].condition, condition);
    (*count)++;

    printf("Asset '%s' added successfully.\n", name);
    return 1;
}

/* ----------------------------------------------------------------------
   Display every registered asset.
   ---------------------------------------------------------------------- */
void displayAssets(Asset assets[], int count) {
    printf("\n========================================\n");
    printf(" ASSET REGISTER\n");
    printf("========================================\n");

    if (count <= 0) {
        printf("No assets recorded yet.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("\nAsset ID       : %d\n", assets[i].assetID);
        printf("Name           : %s\n", assets[i].name);
        printf("Type           : %s\n", assets[i].type);
        printf("Purchase Value : N$%.2f\n", assets[i].purchaseValue);
        printf("Department     : %s\n", assets[i].department);
        printf("Condition      : %s\n", assets[i].condition);
    }
}

/* ----------------------------------------------------------------------
   Search for an asset by ID or by name, chosen by the user.
   ---------------------------------------------------------------------- */
void searchAssetMenu(Asset assets[], int count) {
    if (count <= 0) {
        printf("No assets recorded yet.\n");
        return;
    }

    int option;
    printf("\nSearch by:\n");
    printf("1. Asset ID\n");
    printf("2. Asset Name\n");
    printf("Enter choice: ");
    if (scanf("%d", &option) != 1) {
        flushInputBuffer();
        printf("Invalid choice.\n");
        return;
    }
    flushInputBuffer();

    int index = -1;

    if (option == 1) {
        int id;
        printf("Enter asset ID to search: ");
        if (scanf("%d", &id) != 1) {
            flushInputBuffer();
            printf("Invalid asset ID.\n");
            return;
        }
        flushInputBuffer();
        index = findAssetIndexByID(assets, count, id);
    } else if (option == 2) {
        char name[MAX_NAME_LEN];
        printf("Enter asset name to search: ");
        readLine(name, MAX_NAME_LEN);
        index = findAssetIndexByName(assets, count, name);
    } else {
        printf("Invalid choice. Please select 1 or 2.\n");
        return;
    }

    if (index == -1) {
        printf("Asset not found.\n");
        return;
    }

    printf("\n--- Asset Found ---\n");
    printf("Asset ID       : %d\n", assets[index].assetID);
    printf("Name           : %s\n", assets[index].name);
    printf("Type           : %s\n", assets[index].type);
    printf("Purchase Value : N$%.2f\n", assets[index].purchaseValue);
    printf("Department     : %s\n", assets[index].department);
    printf("Condition      : %s\n", assets[index].condition);
}

/* ----------------------------------------------------------------------
   Asset sub-menu — entry point from the main menu.
   ---------------------------------------------------------------------- */
void assetMenu(Asset assets[], int *count, int maxSize) {
    int choice;
    int running = 1;

    while (running) {
        printf("\n========================================\n");
        printf(" ASSET MANAGEMENT MENU\n");
        printf("========================================\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            flushInputBuffer();
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            continue;
        }
        flushInputBuffer();

        switch (choice) {
            case 1:
                addAsset(assets, count, maxSize);
                break;
            case 2:
                displayAssets(assets, *count);
                break;
            case 3:
                searchAssetMenu(assets, *count);
                break;
            case 4:
                running = 0;
                break;
            default:
                printf("Invalid choice. Please select an option between 1 and 4.\n");
        }
    }
}
