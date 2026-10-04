#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 100

/* Parallel arrays: the same index belongs to the same department.
   They are declared here with extern and created once in budget.c. */
extern int budget_count;
extern char department_name[MAX_DEPARTMENTS][50];
extern float allocated_budget[MAX_DEPARTMENTS];
extern float expenditure[MAX_DEPARTMENTS];

/* Menu */
void budgetMenu(void);

/* CRUD Operations */
void addBudget(void);
void displayBudget(void);
void searchBudget(void);
void updateBudget(void);
void deleteBudget(void);

/* Budget Processing */
float calculateRemainingBudget(int index);
void checkBudgetStatus(int index);
void displayBudgetDetails(int index);

/* Validation */
int validateDepartmentName(char department[]);

/* Department Selection */
void selectDepartment(char department[]);

#endif
