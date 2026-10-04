#ifndef MUNICIPAL_BUDGET_H
#define MUNICIPAL_BUDGET_H

int getNumberOfDepartments();
double getBudget(int dept);
double getExpenditure(int dept);
double calculateRemaining(double budget, double expenditure);
void displayDepartment(int dept, double budget, double expenditure, double remaining);
void checkExceeded(int n, double budget[], double expenditure[]);

#endif

