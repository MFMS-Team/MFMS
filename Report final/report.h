#ifndef REPORTS_H
#define REPORTS_H
#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "employees.h"
#include "budget.h"
#include "supplier.h"
/* Main Reports Menu */
void ReportMenu();
/* Budget Reports */
void BudgetReport();
void TotalBudget(void);
void RemainingBudget(void);
void ExceededBudget(void);
void BudgetStatisticsReport(void);
void AssetReport();
void AssetType(void);
void AssetCondition(void);
void AssetDepartment(void);
void AssetStatistics(void);
void MaritalStatusReport(void);
void SalaryStatistics(void);
void DepartmentReport(void);
void GenderReport(void);
void EmployeeReport();
void DisplaySupplier(void);
void SupplierLocationReport(void);
void TotalSupplierReport(void);
void SupplierReport();
#endif