#ifndef BUDGET_H
#define BUDGET_H
#include <stdio.h>
#include <string.h>
#define MAX_DEPARTMENTS 100
extern int budget_count;
extern int budget_start;
extern int budget_end;
extern char department_id[ MAX_DEPARTMENTS][25];
extern char department_name[MAX_DEPARTMENTS][50];
extern float allocated_budget[MAX_DEPARTMENTS];
extern float expenditure[MAX_DEPARTMENTS];
/* Menu */
void BudgetMenu();
/* CRUD Operations */
void AddBudget(void);
void DisplayBudget(void);
void SearchBudget(void);
void UpdateBudget(void);
void DeleteBudget(void);
void PrintBudget(int index);
/* Validation */
int ValidateDepartmentID(char id[]);
int ValidateDepartmentName(char department[]);
/* Department Selection */
void SelectBudgetDepartment(char department[]);
#endif