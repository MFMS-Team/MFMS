#include "budget.h"
int budget_start=0;
 int budget_count;
int budget_end;
char department_id[ MAX_DEPARTMENTS][25];
char department_name[MAX_DEPARTMENTS][50];
float allocated_budget[MAX_DEPARTMENTS];
float expenditure[MAX_DEPARTMENTS];
int ValidateDepartmentName(char department[]) {
int i;

if(strlen(department)==0) {
return 0;
}

for(i=0; department[i]!='\0'; i++) {

if(!((department[i]>='A' && department[i]<='Z') || (department[i]>='a' && department[i]<='z') || department[i]==' ')) {
return 0;
}

}

return 1;
}
void SelectBudgetDepartment(char department[]) {
int choice=0;

do{
printf("\n=================================\n");
printf("        DEPARTMENT MENU          \n");
printf("=================================\n");
printf("\n1. Finance\n");
printf("2. Human Resources\n");
printf("3. Information Technology\n");
printf("4. Procurement \n");
printf("5. Engineering \n");
printf("6. Water Management \n");
printf("7. Electricity Services \n");
printf("8. Town Planning \n");
printf("9. Customer Care \n");
printf("10. Legal Services \n");
printf("\n=================================\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>10) {
while(getchar()!='\n');
choice=-1;
}
printf("<><><><><><><><><><><><><><<><>\n");


switch(choice) {
case 1: strcpy(department, "Finance"); break;
case 2: strcpy(department, "Human Resources"); break;
case 3: strcpy(department, "Information Technology"); break;
case 4: strcpy(department, "Procurement"); break;
case 5: strcpy(department, "Engineering"); break;
case 6: strcpy(department, "Water Management"); break;
case 7: strcpy(department, "Electricity Services"); break;
case 8: strcpy(department, "Town Planning"); break;
case 9: strcpy(department, "Customer Care"); break;
case 10: strcpy(department, "Legal Services"); break;
default: printf("Invalid department choice entered. Please try again.\n"); break;
}

}while(choice<=0);
return;
}

int ValidateDepartmentID(char id[]) {
int i;
if(strlen(id)==0) {
return 0;
}

for(i=0; id[i]!='\0'; i++) {
if(!((id[i]>='0' && id[i]<='9') ||(id[i]>='A' && id[i]<='Z'))) {
return 0;
}

}
return 1;
}
void PrintBudget(int index) {
if(budget_start==0) {
printf("No budget records available.\n");
return;
}
float remaining, utilization;

remaining=allocated_budget[index]-expenditure[index];
utilization=(expenditure[index]/allocated_budget[index])*100;
printf("Deparment identity Number: %s\n", department_id[index]);
printf("Department name: %s\n", department_name[index]);
printf("Allocated budget: N$%.2f\n", allocated_budget[index]);
printf("Expendeture: N$%.2f\n", expenditure[index]);
printf("Remaining Budget: N$%.2f\n", remaining);

if(utilization>100) {
printf("Status: OVER BUDGET.\n");
}else if(utilization>90) {
printf("Status: CRITICAL.\n");
}else if(utilization>75) {
printf("Status: WARNING.\n");
}else{
printf("Status: HEALTHY.\n");
}

return;
}
void AddBudget(void) {
int i, j, found=0; 
if(budget_start==99) {
printf("The list is full you cannot add any budget details.\n");
return;
}else {
do{
printf("How may budget detail do you want to add? ");

if(scanf("%d", &budget_end)!=1 || budget_end<=0) {
printf("Invalid budget tdetails to add entered. Please try again.\n");
while(getchar()!='\n');
budget_end=0;
}

if((budget_start+budget_end)>99) {
printf("You have ecxeeded the maximum list. Please try again adding few budget.\n");
continue;
}
}while(budget_end<=0);

}

budget_count=0;
budget_end+=budget_start;

for(i=budget_start; i<budget_end; i++) {
printf("\n=========Enter budget detail %d=================\n", i+1);
while(getchar()!='\n');
do{
found=0;
do{
printf("Department Idendity number: ");
fgets(department_id[i], sizeof(department_id[i]), stdin);
department_id[i][strcspn(department_id[i], "\n")]='\0';

if(!ValidateDepartmentID(department_id[i])) {
printf("Invalid department Identity number entered. Please try again.\n");
}
}while(!ValidateDepartmentID(department_id[i]));

for(j=0; j<i; j++) {

if(strcmp(department_id[j], department_id[i])==0) {
found=1;
break;
}
}
if(found) {
printf("The department ID number Already exist. Please try again.\n");
}

}while(found);


SelectBudgetDepartment(department_name[i]);

do{
printf("Allocated budget: ");
if(scanf("%f", &allocated_budget[i])!=1 || allocated_budget[i]<=0.00) {
printf("Invalid  allocated budget entered. Please try again.\n");
while(getchar()!='\n');
allocated_budget[i]=0.00;
}
}while(allocated_budget[i]<=0.00);

do{
printf("Enter the expenditure: ");
if(scanf("%f", &expenditure[i])!=1 || expenditure[i]<=0.00) {
printf("Invalid expenditure amount entered.\n");
while(getchar()!='\n');
expenditure[i]=0.00;
}
}while(expenditure[i]<=0.00);

budget_count++;
}

printf("\n==============================================\n");
printf("%d budget details successfully added on the list.\n", budget_count);
printf("===============================================\n");
budget_start=budget_end;
return;
}

void DisplayBudget(void) {
if(budget_start==0) {
printf("No budget records is available.\n");
return;
}
int i;
budget_count=0;
printf("\n=============================================\n");
printf("Budget records report.\n");
printf("<><><><><><><><><><><><><><><><><><><<><><><>\n");

for(i=0; i<budget_end; i++) {
printf("\n------------budget details %d-----------------------------------\n", i+1);
PrintBudget(i);
printf("____________________________________________________\n");
budget_count++;
}

printf("\n<><><><><><><><><><><><><><><><><><><><><><>\n");
printf("The total number of budget records is: %d\n", budget_count);
printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
return;
}

void SearchBudget(void) {
if(budget_start==0) {
printf("No budget records available.\n");
return;
}
char search_name[50], search_id[25];
int found=0, attempt=0, choice=0, i;

do{
found=0;
printf("\n==================================================\n");
printf("WELCOME TO OUR SEARCH BUDGET RECORDS INTERFACE.\n");
printf("====================================================\n");
printf("1. Deparment Identity number.\n");
printf("2. Department Full Name.\n");
printf("3. Exit.\n");
printf("<><><><><><><><><><><><><><><><><>><><><><><><><>\n");
printf("Enter your choice to search: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>3) {
while(getchar()!='\n');
choice=-1;
}
printf("_____________________________________________________\n");

while(getchar()!='\n');
switch(choice) {
case 1: do{
printf("Enter department identity number: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';
if(!ValidateDepartmentID(search_id)) {
printf("Invalid department Identity number entered. Please try again.\n");
}
}while(!ValidateDepartmentID(search_id));
for(i=0; i<budget_end; i++) {
if(strcmp(department_id[i], search_id)==0) {
found=1;
break;
}
}
break;
case 2: do{
printf("Enter department full name: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';
if(!ValidateDepartmentName(search_name)) {
printf("Invalide department Name entered. Please try again.\n");
}

}while(!ValidateDepartmentName(search_name));
for(i=0; i<budget_end; i++) {
if(strcmp(department_name[i], search_name)==0) {
found=1;
break;
}
}
break;
case 3: printf("Thanks for interacting with our interface. Goodbey.\n"); return;
default: printf("Invalid choice entered. Please try again"); continue;
}

if(found) {
printf("\n===========================================\n");
printf("Budget details Found in the database.\n");
printf("<><><><><><><><><>><><><><><>><><><><><><><>\n");
PrintBudget(i);
printf("__________________________________________________\n");
return;
}else {
printf("Budget records not found in the database. Please try again.\n");
}
attempt++;

if(attempt>4) {
printf("You have reached maximum attempt. Please try again in next few minutes.\n");
return;
}
}while(!found);
return;
}

void UpdateBudget(void) {
if(budget_start==0) {
printf("No budget records available.\n");
return;
}
char search_id[25], search_name[50];
int found=0, attempt=0, choice=0, ch, update=0, i;
float alocate_budget, expend;
char confirm;
do{
found=0;
printf("\n==================================================\n");
printf("WELCOME TO OUR UPDATE  BUDGET INTERFACE.\n");
printf("====================================================\n");
printf("1. Deparment Identity number.\n");
printf("2. Department Full Name.\n");
printf("3. Exit.\n");
printf("<><><><><><><><><><><><><><><><><>><><><><><><><>\n");
printf("Enter your choice to search: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>3) {
while(getchar()!='\n');
choice=-1;
}
printf("_____________________________________________________\n");

while(getchar()!='\n');
switch(choice) {
case 1: do{
printf("Enter department identity number: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';
if(!ValidateDepartmentID(search_id)) {
printf("Invalid department Identity number entered. Please try again.\n");
}
}while(!ValidateDepartmentID(search_id));
for(i=0; i<budget_end; i++) {
if(strcmp(department_id[i], search_id)==0) {
found=1;
break;
}
}
break;
case 2: do{
printf("Enter department full name: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';
if(!ValidateDepartmentName(search_name)) {
printf("Invalide department Name entered. Please try again.\n");
}

}while(!ValidateDepartmentName(search_name));
for(i=0; i<budget_end; i++) {
if(strcmp(department_name[i], search_name)==0) {
found=1;
break;
}
}
break;
case 3: printf("Thanks for interacting with our interface. Goodbey.\n"); return;
default: printf("Invalid choice entered. Please try again"); continue;
}

if(found) {
printf("\n===========================================\n");
printf("Budget details Found in the database.\n");
printf("<><><><><><><><><>><><><><><>><><><><><><><>\n");
PrintBudget(i);
printf("__________________________________________________\n");
printf("Do you really want to update the allocated budget? \n");
printf("Enter Y or y to update or any key to not update: ");
scanf(" %c", &confirm);
while((ch=getchar())!='\n' && ch!=EOF);
if(confirm=='Y' || confirm=='y') {
do{
printf("\n===========================================\n");
printf("WELCOME TO UPDATE BUDGET INTERFACE.\n");
printf("<><><><><><><><><><><><><><><><><><><><><><><\n");
printf("1. Update Allocated budget.\n");
printf("2. Update expenditure.\n");
printf("<><><><><><><><><><><><><><><><><><><><><><>\n");
printf("Enter choice: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>2) {
while(getchar()!='\n');
choice=0.00;
}

switch(choice) {
case 1: do{
printf("Enter allocated budget to update: "); 
if(scanf("%f", &alocate_budget)!=1 || alocate_budget<=0.00) {
printf("Invalid allocate budget entered. Please try again.\n");
while(getchar()!='\n');
alocate_budget=-1.00;
}
}while(alocate_budget<=0.00);
do{
printf("\nOld allocated budget is: N$%.2f\n", allocated_budget[i]);
printf("\n=========================================\n");
printf("WELCOME BACK TO UPDATE CHOICE INTERFACE.\n");
printf("_________________________________________________\n");
printf("1. Add the amount to old allocated budget.\n");
printf("2. Substract amount to old allocated budget.\n");
printf("3. Multiply the amount with allocated budget.\n");
printf("4. divide the allocted budget with amount.\n");
printf("5. Exit.\n");
printf("<><><><><><><><><><><><><><><><><><><><><><>\n");
printf("Enter your choice: ");
if(scanf("%d", &update)!=1 || update<=0 || update>5) {
while(getchar()!='\n');
update=-1;
}
switch(update) {
case 1: allocated_budget[i]+=alocate_budget; break;
case 2: allocated_budget[i]-=alocate_budget; break;
case 3: allocated_budget[i]*=alocate_budget; break;
case 4: allocated_budget[i]/=alocate_budget; break; 
case 5: printf("No changes were made.\n"); return;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(update<=0);
printf("New allocated budget: N$%.2f\n", allocated_budget[i]);
break;
case 2: do{
printf("Enter expenditure to update: "); 
if(scanf("%f", &expend)!=1 ||expend<=0.00) {
printf("Invalid exependiture entered. Please try again.\n");
while(getchar()!='\n');
expend=-1.00;
}
}while(expend<=0.00);
do{
printf("\nOld expenditure is: N$%.2f\n", expenditure[i]);
printf("\n=========================================\n");
printf("WELCOME BACK TO UPDATE CHOICE INTERFACE.\n");
printf("_________________________________________________\n");
printf("1. Add the amount to old expendeture.\n");
printf("2. Substract amount to oldexpendeture.\n");
printf("3. Multiply the amount with expenditure.\n");
printf("4. divide the expenditure with amount.\n");
printf("5. Exit.\n");
printf("<><><><><><><><><><><><><><><><><><><><><><>\n");
printf("Enter your choice: ");
if(scanf("%d", &update)!=1 || update<=0 || update>5) {
while(getchar()!='\n');
update=-1;
}
switch(update) {
case 1: expenditure[i]+=expend; break;
case 2: expenditure[i]-=expend; break;
case 3: expenditure[i]*=expend; break;
case 4: expenditure[i]/=expend; break; 
case 5: printf("No changes were made.\n"); return;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(update<=0);
printf("New expenditure: N$%.2f\n", expenditure[i]);
break;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(choice<=0);

printf("budget records  successfully updated.\n");
return;
}else {
printf("No changes were made.\n");
}
}else {
printf("Budget records not found in the database. Please try again.\n");
}
attempt++;

if(attempt>4) {
printf("You have reached maximum attempt. Please try again in next few minutes.\n");
return;
}
}while(!found);
return;
}
void DeleteBudget(void) {
if(budget_start==0) {
printf("No budget records available.\n");
return;
}
char search_id[25], search_name[50]; 
int found=0, attempt=0, choice=0, ch, position, i;
char confirm;
do{
found=0;
printf("\n==================================================\n");
printf("WELCOME TO OUR DELETE BUDGET RECORDS INTERFACE.\n");
printf("====================================================\n");
printf("1. Deparment Identity number.\n");
printf("2. Department Full Name.\n");
printf("3. Exit.\n");
printf("<><><><><><><><><><><><><><><><><>><><><><><><><>\n");
printf("Enter your choice to search: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>3) {
while(getchar()!='\n');
choice=-1;
}
printf("_____________________________________________________\n");

while(getchar()!='\n');

switch(choice) {
case 1: do{
printf("Enter department identity number: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';
if(!ValidateDepartmentID(search_id)) {
printf("Invalid department Identity number entered. Please try again.\n");
}
}while(!ValidateDepartmentID(search_id));
for(i=0; i<budget_end; i++) {
if(strcmp(department_id[i], search_id)==0) {
found=1;
position=i;
break;
}
}
break;
case 2: do{
printf("Enter department full name: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';
if(!ValidateDepartmentName(search_name)) {
printf("Invalide department Name entered. Please try again.\n");
}

}while(!ValidateDepartmentName(search_name));
for(i=0; i<budget_end; i++) {
if(strcmp(department_name[i], search_name)==0) {
found=1;
position=i;
break;
}

}
break;
case 3: printf("Thanks for interacting with our interface. Goodbey.\n"); return;
default: printf("Invalid choice entered. Please try again"); continue;
}

if(found) {
printf("\n===========================================\n");
printf("Budget details Found in the database.\n");
printf("<><><><><><><><><>><><><><><>><><><><><><><>\n");
PrintBudget(i);
printf("__________________________________________________\n");
printf("Do you really want to delete the budget records?\n ");
printf("Enter Y or y to update or any key to not delete: ");
scanf(" %c", &confirm);
while((ch=getchar())!='\n' && ch!=EOF);
if(confirm=='Y' || confirm=='y') {
for(i=position; i<budget_end-1; i++) {
strcpy(department_id[i], department_id[i+1]);
strcpy(department_name[i], department_name[i+1]);
allocated_budget[i]=allocated_budget[i+1];
expenditure[i]=expenditure[i+1];
}
budget_end--;
budget_start=budget_end;
printf("Budget records successfully deleted.\n");
return;
}else {
printf("No changes were made.\n");
}
}else {
printf("Budget records not found in the database. Please try again.\n");
}
attempt++;

if(attempt>4) {
printf("You have reached maximum attempt. Please try again in next few minutes.\n");
return;
}

}while(!found);

return;
}
void BudgetMenu() {
int choice=0;
do{
printf("\n========================================\n");
printf("      BUDGET MANAGEMENT SYSTEM\n");
printf("========================================\n");
printf("1. Add Budget\n");
printf("2. Display Budgets\n");
printf("3. Search Budget\n");
printf("4. Update Budget\n");
printf("5. Delete Budget\n"); 
printf("6. Exit\n");
printf("========================================\n");
printf("Enter Choice: ");
if(scanf("%d", &choice) != 1){
while(getchar() != '\n');
choice = 0;
}
printf("=======================================\n");
switch(choice){
case 1:AddBudget();break;
case 2:DisplayBudget();break;
case 3:SearchBudget();break;
case 4:UpdateBudget(); break;
case 5: DeleteBudget();break;
case 6: printf("Returning to Main Menu...\n"); break;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
} while(choice != 6);

return;
}











