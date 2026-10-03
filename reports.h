#ifndef REPORTS_H
#define REPORTS_H

void employeeReport(int count);
void employeeStatistics(int count);
void departmentStatistics(int count);
void genderStatistics(int count);

void supplierReport(char ids[][20], char names[][50],
                    char emails[][40], char phones[][20],
                    char towns[][30], int count);

void displaySupplierReport(char ids[][20], char names[][50],
                           char emails[][40], char phones[][20],
                           char towns[][30], int count);

void supplierLocationReport(char towns[][30], int count);
void totalSupplierReport(int count);

void displayReports(void);

#endif
