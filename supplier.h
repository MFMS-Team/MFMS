#ifndef SUPPLIER_H
#define SUPPLIER_H


#include <stdio.h>
#include <string.h>


int ValidateSupplierName(char name[]);
int ValidateSupplierTown(char name[]);
int ValidateSupplierPhone(char num[]);
int ValidateSupplierIDNumber(char num[]);
int ValidateSupplierEmail(char email[]);


int isDuplicateID(char newID[], char ids[][20], int count);


void displaySuppliers(char ids[][20], char names[][50], char emails[][40], char phones[][20], char towns[][30], int count);
void searchSupplier(char ids[][20], char names[][50], char emails[][40], char phones[][20], char towns[][30], int count);

#endif