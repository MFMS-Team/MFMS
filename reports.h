#ifndef REPORTS_H
#define REPORTS_H

#include "budget.h"
#include "assets.h"

/* Main Reports Menu */
void reportsMenu(void);

/* Budget Reports */
void budgetReport(void);
void totalBudgetReport(void);
void remainingBudgetReport(void);
void exceededBudgetReport(void);
void budgetStatisticsReport(void);

/* Asset Reports */
void assetReport(void);
void assetTypeReport(void);
void assetConditionReport(void);
void assetDepartmentReport(void);
void assetStatisticsReport(void);

#endif
