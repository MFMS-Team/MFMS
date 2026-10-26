#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 100
extern int start;
extern int end;
extern char employee_id[MAX_EMPLOYEES][20];
extern char employeeName[MAX_EMPLOYEES][50];
extern char employeeGender[MAX_EMPLOYEES][10];
extern char maritalStatus[MAX_EMPLOYEES][20];
extern char department[MAX_EMPLOYEES][50];
extern char position[MAX_EMPLOYEES][50];
extern char phoneNumber[MAX_EMPLOYEES][20];
extern char email[MAX_EMPLOYEES][50];
extern char employmentStatus[MAX_EMPLOYEES][20];
extern char dateHired[MAX_EMPLOYEES][20];
extern float basicSalary[MAX_EMPLOYEES];
extern float housingAllowance[MAX_EMPLOYEES];
extern float transportAllowance[MAX_EMPLOYEES];
void EmployeeMenu();
int ValidateEmployeeFullName(char employeeName[]);
int ValidateEmployeePhoneNumber(char phoneNumber[]);
int ValidateEmployeeEmail(char email[]);
void SelectEmployeePosition(char position[]);
void SelectEmployeeGender(char employeeGender[]);
void SelectEmploymentStatus(char employmentStatus[]);
void SelectDateHired(char dateHired[]);
int ValidateEmployeeIDNumber(char employee_id[]);
void SelectEmployeeMaritalStatus(char maritalStatus[]);
int IsLeapYear(int year);
int GetDaysInMonth(int month, int year);
void PrintEmployee(int position);
void AddEmployee(void);
void DisplayEmployees(int end);
void SearchEmployee(int end);
void UpdateEmployee(int end);
void DeleteEmployee(void);
void DepartmentStatistics(int end);
void TopEarner(int end);
void LowEarner(int end);
void SortEmployees(int end);
void searchByDepartment(int end);
void SelectEmployeeDepartment(char department[]);

#endif