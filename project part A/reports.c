#include "report.h"
void TotalBudget(void) {
if(budget_start==0) {
printf("No budget records available.\n");
return;
}
int i;
float total_budget=0, total_expendi=0;

for(i=0; i<budget_end; i++) {
total_budget+=allocated_budget[i];
total_expendi+=expenditure[i];
}
printf("\n==============================\n");
printf("THE TOTAL BUDGET RECORDS.\n");
printf("================================\n");
printf("\nTotal allocated budget is:N$%.2f\n", total_budget);
printf("Total expenditure: N$%.2f\n", total_expendi);
printf("<><><><><><><><><><><><><><>\n");
return;
}
void RemainingBudget(void) {
if(budget_start==0) {
printf("No budget records is available. please try againg.\n");
return;
}
int i;
float remaining_budget, total_budget=0, total_expenditure=0;
for(i=0; i<budget_end; i++) {
total_budget+=allocated_budget[i];
total_expenditure+=expenditure[i];
}

if(total_budget>=total_expenditure) {
remaining_budget=total_budget-total_expenditure;
printf("\nThe remaining budget:N$%.2f\n", remaining_budget);
}else {
remaining_budget=total_expenditure-total_budget;
printf("\nBudget overdue with: N$%.2f\n", remaining_budget);
}
return;
}
void ExceededBudget(void) {
if(budget_start==0) {
printf("No budget records available.\n");
return;
}
int i, count=0, found=0;
for(i=0; i<budget_end; i++) {
if(allocated_budget[i]<expenditure[i]) {
found=1;
break;
}
}
if(found) {
printf("\n============================\n");
printf("THE EXCEEDING BUDGET REPORT.\n");
printf("==============================\n");
for(i=0; i<budget_end; i++) {
if(allocated_budget[i]<expenditure[i]) {
printf("\n-----------------------------------------\n");
PrintBudget(i);
printf("--------------------------------------------\n");
count++;
}
}
printf("\n____________________________\n");
printf("%d Budget records exceeded the allocated budget\n", count);
printf("______________________________\n");
}else {
printf("\n<><><><<<<><><><><><><><><>\n");
printf("No budget had exceeded the allocated budget.\n");
printf("_________________________________\n");
}
return;
}
void BudgetStatisticsReport(void) {
if(budget_start==0) {
printf("No Budget records available.\n");
return;
}
int i, j, count, already_count, max_count=0, position;
float total_budget, average, highest_budget, lowest_budget, median; 

for(i=0; i<budget_end; i++) {
already_count=0;
for(j=0; j<i; j++) {
if(allocated_budget[i]==allocated_budget[j]) {
already_count=1;
break;
}
}

if(already_count) {
continue;
}

count=1;
for(j=0; j<budget_end; j++) {
if(allocated_budget[i]==allocated_budget[j]) {
count++;
}
}

if(count>max_count) {
max_count=count;
position=i;
}

}
highest_budget=0;
lowest_budget=allocated_budget[0];
count=0;
for(i=0; i<budget_end; i++) {
total_budget+=allocated_budget[i];
count++;
if(highest_budget<allocated_budget[i]) {
highest_budget=allocated_budget[i];
}

if(lowest_budget>allocated_budget[i]) {
lowest_budget=allocated_budget[i];
}

}
if(budget_end%2==0) {
median=(allocated_budget[count/2]+allocated_budget[(count/2)+1])/2;
}else {
median=allocated_budget[count/2];
}
average=total_budget/count;

printf("\n=============================\n");
printf("BUDGET STATISTICS REPORT.\n");
printf("===============================\n");
printf("\nMode allocated budget: N$%.2f\n", allocated_budget[position]);
printf("Median allocated budget: N$%.2f\n", median);
printf("Mean allocated budget: N$%.2f\n", average);
printf("Lowest allocated budget: N$%.2f\n", lowest_budget);
printf("Highest allocated budget: N$%.2f\n", highest_budget);
printf("The range of allocated budget: N$%.2f\n", highest_budget-lowest_budget);
 printf("The total number of allocated budget: %d\n", count);
printf("<><><><><><><><><><><><><><>\n");
return;
}
void BudgetReport() {
int choice;

do{
printf("\n=========================================\n");
printf("WELCOME TO OUR BUDGET REPORT INTERFACE.\n");
printf("==========================================\n");
printf("\n1.Total budget report.\n ");
printf("2. Remaining budget report\n");
printf("3. Exceeding budget report\n");
printf("4. Budget statistics report\n");
printf("5. Exit\n");
printf("\n-----------------------------------------------\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');
choice=0;
}
printf("________________________________\n");

switch(choice) {
case 1:TotalBudget(); break;
case 2:RemainingBudget(); break;
case 3:ExceededBudget(); break;
case 4:BudgetStatisticsReport(); break;
case 5:printf("Returning to the report menu..............................\n"); return;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(choice!=5);
return;
}
void AssetType(void) {
if(asset_start==0) {
printf("No asset records available.\n");
return;
}
int count=0, found=0, attempt=0, i;
char assets[30];
do{
found=0;
SelectAssetType(assets);
for(i=0; i<asset_end; i++) {
if(strcmp(asset_type[i], assets)==0) {
found=1;
break;
}
}

if(found) {
printf("\n===============================\n");
printf("ASSET TYPE REPORT\n");
printf("================================\n");
for(i=0; i<asset_end; i++) {
if(strcmp(asset_type[i], assets)==0) {
printf("\n---------------------------------------\n");
PrintAsset(i);
printf("_______________________________\n");
count++;
}
}
printf("\n==================================\n");
printf("%d asset records on the asset type you have chosen.\n", count);
printf("<><><><><><><><><><><><><><><><><>\n");
return;
}else {
printf("No records is available within your choosen asset type. Please try again\n");
}
attempt++;
if(attempt>4) {
printf("You have reached maximum attempt. please try again.\n");
return;
}

}while(!found);
return;
}
void AssetCondition(void) {
if(asset_start==0) {
printf("No asset records available.\n");
return;
}
int count=0, found=0, attempt=0, i;
char condition[30];
do{
found=0;
SelectAssetCondition(condition);
for(i=0; i<asset_end; i++) {
if(strcmp(asset_condition[i], condition)==0) {
found=1;
break;
}
}

if(found) {
printf("\n=================================\n");
printf("ASSETS CONDITION REPORT.\n");
printf("==================================\n");
for(i=0; i<asset_end; i++) {
if(strcmp(asset_condition[i], condition)==0) {
printf("\n---------------------------------------\n");
PrintAsset(i);
printf("_______________________________\n");
count++;
}
}
printf("\n==================================\n");
printf("%d asset records on the asset condition you have chosen.\n", count);
printf("<><><><><><><><><><><><><><><><><>\n");
return;
}else {
printf("No records is available within your choosen asset condition. Please try again\n");
}
attempt++;
if(attempt>4) {
printf("You have reached maximum attempt. please try again.\n");
return;
}

}while(!found);
return;
}
void AssetDepartment(void) {
if(asset_start==0) {
printf("No asset records available.\n");
return;
}
int count=0, found=0, attempt=0, i;
char department[50];
do{
found=0;
SelectAssetDepartment(department);
for(i=0; i<asset_end; i++) {
if(strcmp(asset_department[i], department)==0) {
found=1;
break;
}
}

if(found) {
printf("\n=================================\n");
printf("ASSETS DEPARTMENT REPORT.\n");
printf("==================================\n");
for(i=0; i<asset_end; i++) {
if(strcmp(asset_department[i], department)==0) {
printf("\n---------------------------------------\n");
PrintAsset(i);
printf("_______________________________\n");
count++;
}
}
printf("\n==================================\n");
printf("%d asset records on the asset department you have chosen.\n", count);
printf("<><><><><><><><><><><><><><><><><>\n");
return;
}else {
printf("No records is available within your choosen asset department. Please try again\n");
}
attempt++;
if(attempt>4) {
printf("You have reached maximum attempt. please try again.\n");
return;
}

}while(!found);
return;
}
void AssetStatistics(void) {
if(asset_start==0) {
printf("No Asset records available.\n");
return;
}
int i, j, count, already_count, max_count=0, position;
float total_value, average, highest_value, lowest_value, median; 

for(i=0; i<asset_end; i++) {
already_count=0;
for(j=0; j<i; j++) {
if(purchase_value[i]==purchase_value[j]) {
already_count=1;
break;
}
}

if(already_count) {
continue;
}

count=1;
for(j=0; j<asset_end; j++) {
if(purchase_value[i]==purchase_value[j]) {
count++;
}
}

if(count>max_count) {
max_count=count;
position=i;
}

}
highest_value=0;
lowest_value=purchase_value[0];
count=0;
for(i=0; i<asset_end; i++) {
total_value+=purchase_value[i];
count++;
if(highest_value<purchase_value[i]) {
highest_value=purchase_value[i];
}

if(lowest_value>purchase_value[i]) {
lowest_value=purchase_value[i];
}

}
if(asset_end%2==0) {
median=(purchase_value[count/2]+purchase_value[(count/2)+1])/2;
}else {
median=purchase_value[count/2];
}
average=total_value/count;

printf("\n=============================\n");
printf("ASSET STATISTICS REPORT.\n");
printf("===============================\n");
printf("\nMode purchase value: N$%.2f\n", purchase_value[position]);
printf("Median purchase value: N$%.2f\n", median);
printf("Mean purchase value: N$%.2f\n", average);
printf("Lowest purchase value: N$%.2f\n", lowest_value);
printf("Highest purchase value: N$%.2f\n", highest_value);
printf("The range of purchase value N$%.2f\n", highest_value-lowest_value);
 printf("The total number of purchase value: %d\n", count);
printf("<><><><><><><><><><><><><><>\n");
return;
}
void AssetReport() {
int choice;

do{
printf("\n=========================================\n");
printf("WELCOME TO OUR ASSETS REPORT INTERFACE.\n");
printf("==========================================\n");
printf("\n1.Asset type report.\n ");
printf("2.Asset condition report\n");
printf("3.Asset department report\n");
printf("4.  statistics report\n");
printf("5. Exit\n");
printf("\n-----------------------------------------------\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');
choice=0;
}
printf("________________________________\n");

switch(choice) {
case 1:AssetType(); break;
case 2:AssetCondition(); break;
case 3:AssetDepartment(); break;
case 4:AssetStatistics(); break;
case 5:printf("Returning to the report menu..............................\n"); return;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(choice!=5);
return;
}
void MaritalStatusReport(void) {
if(start==0) {
printf("No employee records available.\n");
return;
}
int count=0, found=0, attempt=0, i;
char marital[30];
do{
found=0;
printf("\n===============================\n");
printf("WELCOME TO MARITAL STATUS CHOICE.\n");
printf("================================\n");
SelectEmployeeMaritalStatus(marital);
for(i=0; i<end; i++) {
if(strcmp(maritalStatus[i], marital)==0) {
found=1;
break;
}
}

if(found) {
printf("\n=================================\n");
printf("MARITAL STATUS REPORT.\n");
printf("==================================\n");
for(i=0; i<end; i++) {
if(strcmp(maritalStatus[i], marital)==0) {
printf("\n---------------------------------------\n");
PrintEmployee(i);
printf("_______________________________\n");
count++;
}
}
printf("\n==================================\n");
printf("%d employee records on the marital status you have chosen.\n", count);
printf("<><><><><><><><><><><><><><><><><>\n");
return;
}else {
printf("No records is available within your choosen marital status. Please try again\n");
}
attempt++;
if(attempt>4) {
printf("You have reached maximum attempt. please try again.\n");
return;
}

}while(!found);
return;
}
void SalaryStatistics(void) {
if(start==0) {
printf("No Employee records available.\n");
return;
}
int i, j, count, already_count, max_count=0, posi;
float total_salary, average, highest_salary, lowest_salary, median; 

for(i=0; i<end; i++) {
already_count=0;
for(j=0; j<i; j++) {
if(basicSalary[i]==basicSalary[j]) {
already_count=1;
break;
}
}

if(already_count) {
continue;
}

count=1;
for(j=0; j<end; j++) {
if(basicSalary[i]==basicSalary[j]) {
count++;
}
}

if(count>max_count) {
max_count=count;
posi=i;
}

}
highest_salary=0;
lowest_salary=basicSalary[0];
count=0;
for(i=0; i<end; i++) {
total_salary+=basicSalary[i];
count++;
if(highest_salary<basicSalary[i]) {
highest_salary=basicSalary[i];
}

if(lowest_salary>basicSalary[i]) {
lowest_salary=basicSalary[i];
}

}
if(end%2==0) {
median=(basicSalary[count/2]+basicSalary[(count/2)+1])/2;
}else {
median=basicSalary[count/2];
}
average=total_salary/count;

printf("\n=============================\n");
printf("EMPLOYEE SALARY REPORT.\n");
printf("===============================\n");
printf("\nMode salary: N$%.2f\n", basicSalary[posi]);
printf("Median salary: N$%.2f\n", median);
printf("Mean salary: N$%.2f\n", average);
printf("Lowest salary: N$%.2f\n", lowest_salary);
printf("Highest salary: N$%.2f\n", highest_salary);
printf("The range of salary: N$%.2f\n", highest_salary-lowest_salary);
 printf("The total number of salary: %d\n", count);
printf("The total salary is: N$%.2f\n", total_salary);
printf("<><><><><><><><><><><><><><>\n");
return;

}
void DepartmentReport(void) {
if(start==0) {
printf("No employee records available.\n");
return;
}
int count=0, found=0, attempt=0, i;
char depart[50];
do{
found=0;
printf("\n===============================\n");
printf("WELCOME TO EMPLOYEE DEPARTMENT CHOICE.\n");
printf("================================\n");
SelectEmployeeDepartment(depart);
for(i=0; i<end; i++) {
if(strcmp(department[i], depart)==0) {
found=1;
break;
}
}

if(found) {
printf("\n=================================\n");
printf("EMPLOYEE DEPARTMENT REPORT.\n");
printf("==================================\n");
for(i=0; i<end; i++) {
if(strcmp(department[i], depart)==0) {
printf("\n---------------------------------------\n");
PrintEmployee(i);
printf("_______________________________\n");
count++;
}
}
printf("\n==================================\n");
printf("%d employee records on the Employee department you have chosen.\n", count);
printf("<><><><><><><><><><><><><><><><><>\n");
return;
}else {
printf("No records is available within your choosen employee department. Please try again\n");
}
attempt++;
if(attempt>4) {
printf("You have reached maximum attempt. please try again.\n");
return;
}

}while(!found);
return;
}
void GenderReport(void) {
if(start==0) {
printf("No employee records available.\n");
return;
}
int count=0, found=0, attempt=0, i;
char gender[50];
do{
found=0;
printf("\n===============================\n");
printf("WELCOME TO EMPLOYEE GENDER CHOICE.\n");
printf("================================\n");
SelectEmployeeGender(gender);
for(i=0; i<end; i++) {
if(strcmp(employeeGender[i], gender)==0) {
found=1;
break;
}
}

if(found) {
printf("\n=================================\n");
printf("EMPLOYEE GENDER REPORT.\n");
printf("==================================\n");
for(i=0; i<end; i++) {
if(strcmp(employeeGender[i], gender)==0) {
printf("\n---------------------------------------\n");
PrintEmployee(i);
printf("_______________________________\n");
count++;
}
}
printf("\n==================================\n");
printf("%d employee records on the %s Employee .\n", count, gender);
printf("<><><><><><><><><><><><><><><><><>\n");
return;
}else {
printf("No records is available within %s employee . Please try again\n", gender);
}
attempt++;
if(attempt>4) {
printf("You have reached maximum attempt. please try again.\n");
return;
}

}while(!found);
return;
}
void EmployeeReport() {
int choice;

do{
printf("\n=========================================\n");
printf("WELCOME TO OUR EMPLOYEE REPORT INTERFACE.\n");
printf("==========================================\n");
printf("\n1.Employee marital status report.\n ");
printf("2.Employee salary statistics report\n");
printf("3.Employee department report\n");
printf("4.Employee gender report\n");
printf("5. Exit\n");
printf("\n-----------------------------------------------\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');
choice=0;
}
printf("________________________________\n");

switch(choice) {
case 1:MaritalStatusReport(); break;
case 2:SalaryStatistics(); break;
case 3:DepartmentReport(); break;
case 4:GenderReport(); break;
case 5:printf("Returning to the report menu..............................\n"); return;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(choice!=5);
return;
}
void DisplaySupplier(void) {
if(supplier_start==0) {
printf("No supplier records available.\n");
return;
}
int i;
supplier_count=0;
printf("\n=============================================\n");
printf("supplier records report.\n");
printf("<><><><><><><><><><><><><><><><><><><<><><><>\n");

for(i=0; i<supplier_end; i++) {
printf("\n------------budget details %d-----------------------------------\n", i+1);
PrintSupplier(i);
printf("____________________________________________________\n");
supplier_count++;
}

printf("\n<><><><><><><><><><><><><><><><><><><><><><>\n");
printf("The total number of supplier records is: %d\n", supplier_count);
printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
return;
}
void SupplierLocationReport(void) {
if(supplier_start==0) {
printf("No supplier records available.\n");
return;
}
int i, found=0, attempt=0, count=0;
char loca[30];

do{
found=0;
printf("\n============================================\n");
printf("WELCOME TO SEARCH SUPPLIER LOCATION REPORT.\n");
printf("==============================================\n");
do{
printf("Enter supplier location to search: ");
fgets(loca, sizeof(loca), stdin);
loca[strcspn(loca, "\n")]='\0';
if(!ValidateLocation(loca)) {
printf("Invalid location name entered. Please try again.\n");
}
}while(!ValidateLocation(loca));

for(i=0; i<supplier_end; i++) {
if(strcmp(supplier_location[i], loca)==0) {
found=1;
break;
}
}
if(found) {
printf("\n=======================================\n");
printf("SUPPLIER RECORDS WITHIN THE LOCATION.\n");
printf("========================================\n");
for(i=0; i<supplier_end; i++) {
if(strcmp(supplier_location[i], loca)==0) {
printf("\n-------------------------------------------------\n");
PrintSupplier(i);
printf("______________________________________\n");
count++;
}
}
printf("\n<><><><><><><><><><><><><><><><><><>\n");
printf("%d Suplier records within %s location.\n", count, loca);
printf("<><><><><><><><><><><><><><><><><><>\n");
return;
}else {
printf("No supplier records were found within the location. Please try again.\n");
}
attempt++;
if(attempt>4) {
printf("You have reached maximum attempt. Please try again later.\n");
return;
}

}while(!found);
return;
}
void TotalSupplierReport(void) {
if(supplier_start==0) {
printf("No supplier records available.\n");
return;
}
int i; 
supplier_count=0;
for(i=0; i<supplier_end; i++) {
supplier_count++;
}

printf("\n==============================\n");
printf("Total number of supplier is: %d\n", supplier_count);
printf("==============================\n");
return;
}
void SupplierReport() {
int choice;

do{
printf("\n=========================================\n");
printf("WELCOME TO OUR SUPPLIER REPORT INTERFACE.\n");
printf("==========================================\n");
printf("\n1.Display supplier.\n ");
printf("2.Supplier location report\n");
printf("3.Total supplier report\n");
printf("4. Exit\n");
printf("\n-----------------------------------------------\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');
choice=0;
}
printf("________________________________\n");

switch(choice) {
case 1:DisplaySupplier(); break;
case 2:SupplierLocationReport(); break;
case 3:TotalSupplierReport(); break;
case 4:printf("Returning to the report menu..............................\n"); return;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(choice!=4);
return;
}
void ReportMenu() {
int choice;

do{
printf("\n=========================================\n");
printf("WELCOME TO OUR REPORT INTERFACE.\n");
printf("==========================================\n");
printf("\n1.Budget report.\n ");
printf("2.Assets report\n");
printf("3.Employee report\n");
printf("4.Employee gender report\n");
printf("5. Exit\n");
printf("\n-----------------------------------------------\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');
choice=0;
}
printf("________________________________\n");

switch(choice) {
case 1:BudgetReport(); break;
case 2:AssetReport(); break;
case 3:EmployeeReport(); break;
case 4:SupplierReport(); break;
case 5:printf("Returning to the menu..............................\n"); return;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(choice!=5);
return;
}








