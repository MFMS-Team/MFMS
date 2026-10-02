#include <stdio.h>
#include <string.h>
#include "supplier.h"

int ValidateSupplierName(char name[]) {
    int i;
    if(strlen(name)==0) {
        return 0;
    }
    for(i=0; name[i]!='\0'; i++) {
        if(!((name[i]>='a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z') || name[i]==' ')) {
            return 0;
        }
    }
    return 1;
}

int ValidateSupplierTown(char name[]) {
    int i;
    if(strlen(name)==0) {
        return 0;
    }
    for(i=0; name[i]!='\0'; i++) {
        if(!((name[i]>='a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z') || name[i]==' ')) {
            return 0;
        }
    }
    return 1;
}

int ValidateSupplierPhone(char num[]) {
    int i;
    if(strlen(num)==0) {
        return 0;
    }
    for(i=0; num[i]!='\0'; i++) {
        if(num[i]<'0' || num[i]>'9') {
            return 0;
        }
    }
    return 1;
}

int ValidateSupplierIDNumber(char num[]) {
    int i;
    if(strlen(num)==0) {
        return 0;
    }
    for(i=0; num[i]!='\0'; i++) {
        if(num[i]<'0' || num[i]>'9') {
            return 0;
        }
    }
    return 1;
}

int ValidateSupplierEmail(char email[]) {
    int i, at=-1, dot=-1, at_found=0, dot_found=0;

    if(strlen(email)==0) {
        return 0;
    }

    for(i=0; email[i]!='\0'; i++) {
        if(email[i]=='@' && !at_found) {
            at=i;
            at_found=1;
        }
        if(email[i]=='.' && !dot_found) {
            dot=i;
            dot_found=1;
        }
    }

    if(at<0) {
        return 0;
    }
    if(dot<0) {
        return 0;
    }
    if(dot<=at+1) {
        return 0;
    }
    if(email[strlen(email)-1]=='.') {
        return 0;
    }

    return 1;
}

int isDuplicateID(char newID[], char ids[][20], int count) {
    int i;
    for(i=0; i<count; i++) {
        if(strcmp(ids[i], newID)==0) {
            return 1;
        }
    }
    return 0;
}

void displaySuppliers(char ids[][20], char names[][50], char emails[][40], char phones[][20], char towns[][30], int count) {
    int i;
    if(count==0) {
        printf("No suppliers yet.\n");
        return;
    }
    printf("\n--- ALL SUPPLIERS ---\n");
    for(i=0; i<count; i++) {
        printf("\nSupplier %d\n", i+1);
        printf("ID    : %s\n", ids[i]);
        printf("Name  : %s\n", names[i]);
        printf("Email : %s\n", emails[i]);
        printf("Phone : %s\n", phones[i]);
        printf("Town  : %s\n", towns[i]);
    }
}

void searchSupplier(char ids[][20], char names[][50], char emails[][40], char phones[][20], char towns[][30], int count) {
    char searchID[20];
    int i, found=0;

    if(count==0) {
        printf("No suppliers to search.\n");
        return;
    }

    printf("Enter supplier ID to search: ");
    fgets(searchID, sizeof(searchID), stdin);
    searchID[strcspn(searchID, "\n")]='\0';

    for(i=0; i<count; i++) {
        if(strcmp(ids[i], searchID)==0) {
            printf("\n[FOUND]\n");
            printf("ID    : %s\n", ids[i]);
            printf("Name  : %s\n", names[i]);
            printf("Email : %s\n", emails[i]);
            printf("Phone : %s\n", phones[i]);
            printf("Town  : %s\n", towns[i]);
            found=1;
            break;
        }
    }

    if(found==0) {
        printf("Supplier not found.\n");
    }
}

int main() {
    int i, end;
    char supplierName[100][50], supplier_id[100][20], supplierEmails[100][40], supplierPhones[100][20], supplierTowns[100][30];

    do {
        printf("How many supplier records do you want to add? ");
        if(scanf("%d", &end)!=1 || end<=0) {
            printf("Invalid number of supplier to add entered. Please try again.\n");
            while(getchar()!='\n');
            end=0;
        }
    } while(end<=0);
    while(getchar()!='\n');

    for(i=0; i<end; i++) {
        do {
            printf("\nEnter supplier ID: ");
            fgets(supplier_id[i], sizeof(supplier_id[i]), stdin);
            supplier_id[i][strcspn(supplier_id[i], "\n")] = '\0';

            if(!ValidateSupplierIDNumber(supplier_id[i])) {
                printf("Invalid ID number entered. Please try again.\n");
            }
            else if(isDuplicateID(supplier_id[i], supplier_id, i)) {
                printf("This ID already exists. Please enter a different ID.\n");
                supplier_id[i][0] = '\0';
            }
        } while(!ValidateSupplierIDNumber(supplier_id[i]) || isDuplicateID(supplier_id[i], supplier_id, i));

        do {
            printf("Enter supplier name: ");
            fgets(supplierName[i], sizeof(supplierName[i]), stdin);
            supplierName[i][strcspn(supplierName[i], "\n")] = '\0';

            if(!ValidateSupplierName(supplierName[i])) {
                printf("Invalid supplier name entered. Please try again.\n");
            }
        } while(!ValidateSupplierName(supplierName[i]));

        do {
            printf("Enter email: ");
            fgets(supplierEmails[i], sizeof(supplierEmails[i]), stdin);
            supplierEmails[i][strcspn(supplierEmails[i], "\n")] = '\0';

            if(!ValidateSupplierEmail(supplierEmails[i])) {
                printf("Invalid supplier Email entered. Please try again.\n");
            }
        } while(!ValidateSupplierEmail(supplierEmails[i]));

        do {
            printf("Enter phone: ");
            fgets(supplierPhones[i], sizeof(supplierPhones[i]), stdin);
            supplierPhones[i][strcspn(supplierPhones[i], "\n")] = '\0';

            if(!ValidateSupplierPhone(supplierPhones[i])) {
                printf("Invalid Supplier phone number entered. Please try again.\n");
            }
        } while(!ValidateSupplierPhone(supplierPhones[i]));

        do {
            printf("Enter town: ");
            fgets(supplierTowns[i], sizeof(supplierTowns[i]), stdin);
            supplierTowns[i][strcspn(supplierTowns[i], "\n")] = '\0';

            if(!ValidateSupplierTown(supplierTowns[i])) {
                printf("Invalid Supplier town entered. Please try again.\n");
            }
        } while(!ValidateSupplierTown(supplierTowns[i]));
    }

    printf("\nSupplier saved!\n");

    int choice;
    do {
        printf("\n===== SUPPLIER MANAGEMENT =====\n");
        printf("1. Display All Suppliers\n");
        printf("2. Search Supplier by ID\n");
        printf("3. Exit\n");
        printf("Enter choice: ");

        if(scanf("%d", &choice)!=1) {
            while(getchar()!='\n');
            printf("Invalid input.\n");
            continue;
        }
        getchar();

        switch(choice) {
            case 1:
                displaySuppliers(supplier_id, supplierName, supplierEmails, supplierPhones, supplierTowns, end);
                break;
            case 2:
                searchSupplier(supplier_id, supplierName, supplierEmails, supplierPhones, supplierTowns, end);
                break;
            case 3:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!=3);

    return 0;
}

