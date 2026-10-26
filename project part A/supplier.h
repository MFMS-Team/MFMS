#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#include <stdio.h>
#include <string.h>
#define MAX_SUPPLIERS 100
/* Variables */
extern int supplier_start;
extern int supplier_end;
extern int supplier_count;
extern char supplier_id[MAX_SUPPLIERS][20];
extern char supplier_name[MAX_SUPPLIERS][50];
extern char supplier_email[MAX_SUPPLIERS][50];
extern  char supplier_phone[MAX_SUPPLIERS][20];
extern char supplier_location[MAX_SUPPLIERS][50];
/* Menu */
void SupplierMenu();
/* CRUD */
void AddSupplier(void);
void DisplaySuppliers(void);
void SearchSupplier(void);
void UpdateSupplier(void);
void DeleteSupplier(void);
/* Display */
void PrintSupplier(int index);
/* Validation */
int ValidateSupplierID(char id[]);
int ValidateSupplierName(char name[]);
int ValidateSupplierEmail(char email[]);
int ValidateSupplierPhone(char phone[]);
int ValidateLocation(char location[]);
#endif