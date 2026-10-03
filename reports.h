#ifndef REPORTS_H
#define REPORTS_H

void employeeReport(int count);

void budgetReport(char departments[][50],
                  float allocated[],
                  float expenditure[],
                  int count);

void supplierReport(char ids[][20],
                    char names[][50],
                    char emails[][40],
                    char phones[][20],
                    char towns[][30],
                    int count);

void assetReport(char assetIds[][20],
                 char assetNames[][50],
                 char assetTypes[][30],
                 float purchaseValue[],
                 char departments[][50],
                 char conditions[][30],
                 int count);

void displayReports(void);

#endif
