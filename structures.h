#ifndef STRUCTURES_H
#define STRUCTURES_H

/* ======================================================================
   SHARED DATA STRUCTURES — Municipal Financial Management System (MFMS)
   ======================================================================
   These struct definitions are shared across every module (Employee,
   Budget, Supplier, Asset, Reports). In a real group project, ONE agreed
   version of this file should be committed to the shared GitHub repo so
   every member's .c/.h files use identical field names and types.

   Coordinate these exact field names with your Employee, Budget,
   Supplier and Asset teammates BEFORE they start coding their modules —
   Reports only works if it reads the same struct shapes they produce.
   ====================================================================== */

#define MAX_NAME_LEN        50
#define MAX_DEPARTMENT_LEN  30
#define MAX_EMAIL_LEN       50
#define MAX_PHONE_LEN       20
#define MAX_TYPE_LEN        30
#define MAX_CONDITION_LEN   20

typedef struct {
    int   employeeID;
    char  name[MAX_NAME_LEN];
    char  department[MAX_DEPARTMENT_LEN];
    float basicSalary;
    float housingAllowance;
    float transportAllowance;
} Employee;

typedef struct {
    char  departmentName[MAX_DEPARTMENT_LEN];
    float allocatedBudget;
    float expenditure;
} Budget;

typedef struct {
    int  supplierID;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
    char location[MAX_DEPARTMENT_LEN];
} Supplier;

typedef struct {
    int   assetID;
    char  name[MAX_NAME_LEN];
    char  type[MAX_TYPE_LEN];
    float purchaseValue;
    char  department[MAX_DEPARTMENT_LEN];
    char  condition[MAX_CONDITION_LEN];  /* e.g. "Good", "Fair", "Poor" */
} Asset;

#endif /* STRUCTURES_H */
