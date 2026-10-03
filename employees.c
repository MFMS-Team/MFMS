#include "employees.h"
#include <stdio.h>
#include <string.h>
int IsLeapYear(int year){
if(year % 400 == 0){
return 1;
}else if(year % 100 == 0){
return 0;
}else if(year % 4 == 0){
return 1;
}
return 0;
}
int GetDaysInMonth(int month, int year){

switch(month) {
case 1:
case 3:
case 5:
case 7:
case 8:
case 10:
case 12:
return 31;
case 4:
case 6:
case 9:
case 11:
return 30;
case 2:if(IsLeapYear(year)){
return 29;
}else{
return 28;
}
default: return 0;
}
}

int ValidateEmployeeFullName(char employeeName[]) {
int i;

if(strlen(employeeName)==0) {
return 0;
}

for(i=0; employeeName[i]!='\0'; i++) {
if(!((employeeName[i]>='A' && employeeName[i]<='Z') || (employeeName[i]>='a' && employeeName[i]<='z') || employeeName[i]==' ')) {
return 0;
}

}
return 1;
}
int ValidateEmployeePhoneNumber(char phoneNumber[]) {
int i;

if(strlen(phoneNumber)==0) {
return 0;
}

for(i=0; phoneNumber[i]!='\0'; i++) {

if(phoneNumber[i]< '0' || phoneNumber[i]>'9') {
return 0;
}

}

return 1;
}
int ValidateEmployeeEmail(char email[]) {
int i, at=-1, dot=-1, at_found=0, dot_found=0;

if(strlen(email)==0) {
return 0;
}

for(i=0; email[i]!='\0'; i++) {

if(email[i]=='@' && !at_found) {
at_found=1;
at=i;
}else if(email[i]=='.' && !dot_found) {
dot=i;
dot_found=1;
}

}

if(at<=3) {
return 0;
}else if(dot<at+1) {
return 0;
}else if(email[i-1]=='.') {
return 0;
}
return 1;
}
void SelectEmployeePosition(char position[]) {
int choice=0;

do{
printf("\n===============================================\n");
printf("PLEASE SELECT A VALID POSITION FROM BELOW.\n");
printf("\n===============================================\n");
printf("\nEMPLOYEE POSITIONS\n");
printf("\n1. Manager.\n");
printf("2. Accountant.\n");
printf("3.Human Resource Officer.\n");
printf("4. Procurement Officer.\n");
printf("5. IT Officer.\n");
printf("6. Engineer.\n");
printf("7. Technician.\n");
printf("8. Administrative Officer.\n");
printf("9. Clerk.\n");
printf("10. Cashier.\n");
printf("11. Driver.\n");
printf("12. Security Officer.\n");
printf("13. Customer Service Officer.\n");
printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><>\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>13) {
while(getchar()!='\n');
choice=-1;
}
printf("<><><><><><><><><><><><><><><><><><><><><><><><><>\n");

switch(choice) {
case 1:strcpy(position, "Manager"); break;
case 2:strcpy(position, "Accountant"); break;
case 3:strcpy(position, "Human Resource Officer"); break;
case 4:strcpy(position, "Procurement Officer"); break;
case 5:strcpy(position, "IT Officer"); break;
case 6:strcpy(position, "Engineer"); break;
case 7:strcpy(position, "Technician"); break;
case 8:strcpy(position, "Administrative Officer"); break;
case 9:strcpy(position, "Clerk"); break;
case 10:strcpy(position, "Cashier"); break;
case 11:strcpy(position, "Driver"); break;
case 12:strcpy(position, "Security Officer"); break;
case 13:strcpy(position, "Customer Service Officer"); break;
default:printf("Invalid choice entered. Please try again.\n"); break;

}
}while(choice<=0);

return;
}
void SelectEmployeeGender(char employeeGender[]) {
int choice=0;

do{
printf("\n=========================================\n");
printf("SELECT EMPLOYEE GENDER.\n");
printf("\n========================================\n");
printf("\n1. Male.\n");
printf("2. Female.\n");
printf("\n____________________________________________\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>2) {
while(getchar()!='\n');
choice=-1;
}
printf("_______________________________________________\n");

switch(choice) {
case 1: strcpy(employeeGender, "Male"); break;
case 2: strcpy(employeeGender, "Female"); break;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(choice<=0);
return;
}
void SelectEmploymentStatus(char employmentStatus[]) {
int choice=0;

do{
printf("\n======================================\n");
printf("SELECT VALID EMPLOYEE STATUS.\n");
printf("======================================\n");
printf("\n1. Permanent.\n");
printf("2. Contract.\n");
printf("3. Temporary.\n");
printf("4. Intern.\n");
printf("5. Probation.\n");
printf("\n<><><><><><><><><><><><><><><><><><><>\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>5) {
while(getchar()!='\n');
choice=-1;
}
printf("<><><><><><><><><><><><><<<><><><<><><>\n");

switch(choice) {
case 1: strcpy(employmentStatus, "Permanent"); break;
case 2: strcpy(employmentStatus, "Contract"); break;
case 3: strcpy(employmentStatus, "Temporary"); break;
case 4: strcpy(employmentStatus, "Intern"); break;
case 5: strcpy(employmentStatus, "Probation"); break;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(choice<=0);
return;
}
void PrintEmployee(int posi) {
printf("ID number: %s\n", employee_id[posi]);
printf("Full Name: %s\n", employeeName[posi]);
printf("Gender: %s\n", employeeGender[posi]);
printf("Marital Status: %s\n", maritalStatus[posi]);
printf("Department Name: %s\n", department[posi]);
printf("Position : %s\n", position[posi]);
printf("Phone Number: %s\n", phoneNumber[posi]);
printf("Email: %s\n", email[posi]);
printf("Employee Status: %s\n", employmentStatus[posi]);
printf("Date Hired: %s\n", dateHired[posi]);
printf("Basic Salary: N$%.2f\n", basicSalary[posi]);
printf("Housing Allowance: N$%.2f\n", housingAllowance[posi]);
printf("Transport Allowance: N$%.2f\n", transportAllowance[posi]);
return;
}

void SelectDateHired(char dateHired[]) {
int day, month, year;
int maxDays;
const char months[][15] ={ "January", "February", "March", "April",
"May", "June", "July", "August",
"September", "October", "November", "December"};
do{
printf("Enter Year (2000-2100): ");
if(scanf("%d", &year)!=1 || year>2026 || year < 2000 || year > 2100) {
printf("Invalid year of employeement Entered. Please try again.\n");
while(getchar()!='\n');
year=2101;
}

} while(year < 2000 || year > 2100);
do{
printf("\n===== MONTHS =====\n");
for(int i = 0; i < 12; i++){
printf("%d. %s\n", i + 1, months[i]);
}
printf("Select Month: ");

if(scanf("%d", &month)!=1 || month < 1 || month > 12) {
printf("Invalid Month choice entered. Please try again.\n");
while(getchar()!='\n');
month=0;
}

} while(month < 1 || month > 12);

maxDays = GetDaysInMonth(month, year);
do{
printf("Enter Day (1-%d): ", maxDays);
scanf("%d", &day);
} while(day < 1 || day > maxDays);
sprintf(dateHired,"%02d %s %04d", day, months[month - 1], year);

return;
}
int ValidateEmployeeIDNumber(char employee_id[]) {
int i;
if(strlen(employee_id)==0) {
return 0;
}

for(i=0; employee_id[i]!='\0'; i++) {
if(!((employee_id[i]>='0' && employee_id[i]<='9') || employee_id[i]==' ')) {
return 0;
}
} 
return 1;
}
void SelectEmployeeMaritalStatus(char maritalStatus[]) {
int choice=0;
do{
printf("\n=================================\n");
printf("     MARITAL STATUS MENU\n");
printf("=================================\n");
printf("\n1. Single.\n");
printf("2. Married.\n ");
printf("3. Divorced.\n");
printf("4. Widowed.\n");
printf("=================================\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>4) {
while(getchar()!='\n');
choice=0;
}
printf("<><><><><><><><><><><><><><><><>\n");

switch(choice) {
case 1: strcpy(maritalStatus, "Single"); break;
case 2: strcpy(maritalStatus, "Married"); break;
case 3: strcpy(maritalStatus, "Divorced"); break;
case 4: strcpy(maritalStatus, "Widowed"); break;
default: printf("Invalid marital status entered. Please try again.\n"); break;
}
}while(choice<=0);

return;
}
void SelectDepartment(char department[]) {
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
void AddEmployee(void) {
int i, count=0;
if(start==99) {
printf("The employee list is full.\n");
return;
}

do{
printf("How many Employee do you want to add? ");
if(scanf("%d", &end)!=1 || end<=0 || (start+end)>99) {
printf("Invalid number of employee entered. Please try again.\n");
while(getchar()!='\n');
end=0;
}
}while(end<=0);
end+=start;

for(i=start; i<end; i++) {
while(getchar()!='\n');
printf("\n============================================================\n");
printf("ENTER EMPLOYEE DETAIL OR SELECT FOR EMPLOYEE NUMBER %d\n", i+1);
printf("_______________________________________________________________________\n");
do{
printf("\nEnter ID number: ");
fgets(employee_id[i], sizeof(employee_id[i]), stdin);
employee_id[i][strcspn(employee_id[i], "\n")]='\0';
if(!ValidateEmployeeIDNumber(employee_id[i])) {
printf("Invalid employee ID number entered. Please try again.\n");
}

}while(!ValidateEmployeeIDNumber(employee_id[i]));

do{
printf("Enter Employee Full Name: ");
fgets(employeeName[i], sizeof(employeeName[i]), stdin);
employeeName[i][strcspn(employeeName[i], "\n")]='\0';

if(!ValidateEmployeeFullName(employeeName[i])) {
printf("Invalid Employee's full name entered. Please try again.\n");
}

}while(!ValidateEmployeeFullName(employeeName[i]));
SelectEmployeeGender(employeeGender[i]);
SelectEmployeeMaritalStatus(maritalStatus[i]);
SelectDepartment(department[i]);
SelectEmployeePosition(position[i]);
while(getchar()!='\n');
do{
printf("Enter employee phone number: ");
fgets(phoneNumber[i], sizeof(phoneNumber[i]), stdin);
phoneNumber[i][strcspn(phoneNumber[i], "\n")]='\0';
if(!ValidateEmployeePhoneNumber(phoneNumber[i])) {
printf("Invalid employe phone number entered. Please try again.\n");
}

}while(!ValidateEmployeePhoneNumber(phoneNumber[i]));

do{
printf("Enter employee email: ");
fgets(email[i], sizeof(email[i]), stdin);
email[i][strcspn(email[i], "\n")]='\0';
if(!ValidateEmployeeEmail(email[i])) {
printf("Invalid Employe Email entered. Please try again.\n");
}
}while(!ValidateEmployeeEmail(email[i]));

SelectEmploymentStatus(employmentStatus[i]);
SelectDateHired(dateHired[i]);

do{
printf("Enter employee basic salary: ");
if(scanf("%f", &basicSalary[i])!=1 || basicSalary[i]<=0.00) {
printf("Invalid employee basic salary entered. Please try again.\n");
while(getchar()!='\n');
basicSalary[i]=0.00;
}

}while(basicSalary[i]<=0.00);
do{
printf("Enter employee housing allowance: ");
if(scanf("%f", &housingAllowance[i])!=1 || housingAllowance[i]<0.00) {
printf("Invalid employee housing allowance entered. Please try again.\n");
while(getchar()!='\n');
basicSalary[i]=-1;
}

}while(housingAllowance[i]<0.00);
do{
printf("Enter employee transport allowance: ");
if(scanf("%f", &transportAllowance[i])!=1 ||transportAllowance[i]<0.00) {
printf("Invalid employee transport allowance entered. Please try again.\n");
while(getchar()!='\n');
transportAllowance[i]=-1;
}

}while(transportAllowance[i]<0.00);

count++;
}
start=end;
printf("\n============================================\n");
printf("%d Employee details successfull add on the list.\n", count);
printf("=============================================\n");
return;
}
void DisplayEmployees(int end) {
if(start==0) {
printf("No employee records is available.\n");
return;
}

int count=0, i; 
printf("\n===========================================\n");
printf("		EMPLOYEE REPORT DETAILS.			\n");
printf("=============================================\n");

for(i=0; i<end; i++) {
printf("\n----------employee details number %d----------------------\n", i+1);
printf("Employee ID: %s\n", employee_id[i]);
printf("Full Name: %s\n", employeeName[i]);
printf("Department: %s\n", department[i]);
printf("Position: %s\n", position[i]);
printf("Employment Status: %s\n", employmentStatus[i]);
printf("_________________________________________________\n");
count++;
}

printf("\n<><><><><><><><><><><><><><><><><>\n");
printf("%d Employee records available. \n", count);
printf("<><><><><><><><><><><><><><><><><><>\n");

return;
}
void SearchEmployee(int end) {
if(start==0) {
printf("No employee records available.\n");
return;
}
int i, found, attempt=0, choice=0, position=-1;
char search_id[20], search_name[50];
do{
found=0;
printf("\n========================================\n");
printf("WELCOME TO SEARCH EMPLOYEE INTERFACE.\n");
printf("______________________________________________\n");
printf("\n1. Employee ID number.\n");
printf("2. Employee full name.\n");
printf("3. Exit.\n");
printf("<><><><><><><><><><><><><><><><><><>.\n");
printf("Enter your choice to search for employee: ");
if(scanf("%d", &choice)!=1) {
while(getchar()!='\n');
choice=0;
}
printf("<><><><><><><><><><><><><><><><><><><>\n");
while(getchar()!='\n');

switch(choice) {
case 1:do{
printf("\nEnter ID number: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';
if(!ValidateEmployeeIDNumber(search_id)) {
printf("Invalid employee ID number entered. Please try again.\n");
}

}while(!ValidateEmployeeIDNumber(search_id));

for(i=0; i<end; i++) {
if(strcmp(employee_id[i], search_id)==0) {
found=1;
position=i;
break;
}
}
break;
case 2:do{
printf("Enter Employee Full Name: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';

if(!ValidateEmployeeFullName(search_name)) {
printf("Invalid Employee's full name entered. Please try again.\n");
}

}while(!ValidateEmployeeFullName(search_name));

for(i=0; i<end; i++) {
if(strcmp(search_name, employeeName[i])==0) {
found=1;
position=i;
break;
}
}
break;
case 3:printf("Thanks for interacting with our system. Goodbey.\n"); return;
default: printf("Invalid choice entered. Please try again.\n"); continue;
}
if(found) {
printf("\n=======================================\n");
printf("Employee details Found in the employee database.\n");
printf("______________________________________________\n");
PrintEmployee(position);
printf("<><><<><><><><><><><><><><><><><><><>\n");
return;
}else {
printf("Employe details not found.\n");
}

attempt++;
if(attempt>4) {
printf("You have reached maximumu attempt. Please try again in next 5 minutes to come.\n");
return;
}

}while(!found);

return;
}
void UpdateEmployee(int end) {
if(start==0) {
printf("No employee records available.\n");
return;
}
int i, found, attempt=0, choice=0, update_choice, posi=-1, money, ch;
char search_id[20], search_name[50];
char confirm;
char full_name[50], gender[20], marital_status[20], temp_number[20], temp_department[40];
char status[20], emil[40], work[30], date[15];
float temp_salary, housing_alowance, transport_alowance;

do{
found=0;
printf("\n===============================================\n");
printf("Welcome to Update Employee Interface to search employee\n");
printf("================================================\n");
printf("1. Employee ID number.\n");
printf("2. Employee full Name.\n");
printf("3. Exit.\n");
printf("______________________________________________________\n");
printf("Enter your choice to search: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>3) {
while(getchar()!='\n');
choice=-1;
}
printf("<><><><><><><><><><><><><><><><><><><><><><>\n");


while(getchar()!='\n');

switch(choice) {
case 1:do{
printf("\nEnter ID number: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';
if(!ValidateEmployeeIDNumber(search_id)) {
printf("Invalid employee ID number entered. Please try again.\n");
}

}while(!ValidateEmployeeIDNumber(search_id));

for(i=0; i<end; i++) {
if(strcmp(employee_id[i], search_id)==0) {
found=1;
posi=i;
break;
}
}
break;
case 2:do{
printf("Enter Employee Full Name: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';

if(!ValidateEmployeeFullName(search_name)) {
printf("Invalid Employee's full name entered. Please try again.\n");
}

}while(!ValidateEmployeeFullName(search_name));

for(i=0; i<end; i++) {
if(strcmp(search_name, employeeName[i])==0) {
found=1;
posi=i;
break;
}
}
break;
case 3:printf("Thanks for interacting with our system. Goodbey.\n"); return;
default: printf("Invalid choice entered. Please try again.\n"); continue;

}

if(found) {
printf("\n=======================================\n");
printf("Employee details Found in the employee database.\n");
printf("______________________________________________\n");
PrintEmployee(posi);
printf("<><><<><><><><><><><><><><><><><><><>\n");
printf("Do you realy want to update this employee? \n");
printf("Enter Y or y to update or anykey to do not: ");
scanf(" %c", &confirm);
while((ch=getchar())!='\n' && ch!=EOF);

if(confirm=='Y' || confirm=='y') {
do{
printf("\n=========================================\n");
printf("WELCOME TO UPDATE CHOICE INTERFACE.\n");
printf("===========================================\n");
printf("1. Update Full Name.\n");
printf("2. Update Gender.\n");
printf("3. Update Marital Status.\n");
printf("4. Update Department.\n");
printf("5. Update Position.\n");
printf("6. Update Phone Number.\n");
printf("7. Update Email Address.\n");
printf("8. Update Employment Status.\n");
printf("9. Update Date Hired.\n");
printf("10. Update Basic Salary.\n");
printf("11. Update Housing Allowance.\n");
printf("12. Update Transport Allowance.\n");
printf("<><><><><><><><><><><><><><><><><>\n");
printf("Enter choice: ");
if(scanf("%d", &update_choice)!=1 || update_choice<=0 || update_choice>12) {
while(getchar()!='\n');
update_choice=-1;
}

while(getchar()!='\n');

switch(update_choice) {
case 1:do{
printf("Enter the full name: ");
fgets(full_name, sizeof(full_name), stdin);
full_name[strcspn(full_name, "\n")]='\0';
if(!ValidateEmployeeFullName(full_name)) {
printf("Invalid Full Name entered. Please try again.\n");

}

}while(!ValidateEmployeeFullName(full_name));
printf("Old employee full name: %s\n", employeeName[posi]);
strcpy(employeeName[posi], full_name);
printf("Updated employee full name: %s\n", employeeName[posi]);
break;
case 2: SelectEmployeeGender(gender);
printf("Old employee gender: %s\n", employeeGender[posi]);
strcpy(employeeGender[posi], gender);
printf("Updated employee gender: %s\n", employeeGender[posi]);
break;
case 3:SelectEmployeeMaritalStatus(marital_status);
printf("Old marital status: %s\n", maritalStatus[posi]);
strcpy(maritalStatus[posi], marital_status);
printf("Updated marital status: %s\n", maritalStatus[posi]);
break;
case 4:SelectDepartment(temp_department);
printf("Old department name is: %s\n", department[posi]);
strcpy(department[posi], temp_department);
printf("Updated department name is: %s\n", department[posi]);
break;
case 5:SelectEmployeePosition(work); 
printf("Old employee position: %s\n", position[posi]);
strcpy(position[posi], work);
printf("Updated employee position: %s\n", position[posi]);
break;
case 6:do{
printf("Enter new phone number: ");
fgets(temp_number, sizeof(temp_number), stdin);
temp_number[strcspn(temp_number, "\n")]='\0';
if(!ValidateEmployeePhoneNumber(temp_number)) {
printf("Invalid Phone number entered. Please try again.\n");
}
}while(!ValidateEmployeePhoneNumber(temp_number));
printf("Old employee phone number: %s\n", phoneNumber[posi]);
strcpy(phoneNumber[posi], temp_number);
printf("Updated employee phone number: %s\n", phoneNumber[posi]);
break;
case 7:do{
printf("Enter new Email: ");
fgets(emil, sizeof(emil), stdin);
emil[strcspn(emil, "\n")]='\0';

if(!ValidateEmployeeEmail(emil)) {
printf("Invalid new email entered. Please try again.\n");
}
}while(!ValidateEmployeeEmail(emil));
printf("Old employee email: %s\n", email[posi]);
strcpy(email[posi], emil);
printf("Updated employee email: %s\n", email[posi]);
break;
case 8:SelectEmploymentStatus(status);
printf("Old employee status: %s\n", employmentStatus[posi]);
strcpy(employmentStatus[posi], status);
printf("Updated employee status: %s\n", employmentStatus[posi]);
break;
case 9:SelectDateHired(date);
printf("Old date hired: %s\n", dateHired[posi]);
strcpy(dateHired[posi], date);
printf("Updated date hired: %s\n", dateHired[posi]);
break;
case 10:do{
printf("Enter new basic salary:  ");
if(scanf("%f", &temp_salary)!=1 || temp_salary<=0.00) {
printf("Invailad basic salary entered. Please try again.\n");
while(getchar()!='\n');
temp_salary=-1;
}
}while(temp_salary<=0.00);
printf("Old basic salary is: N$%.2f\n", basicSalary[posi]);
do{
money=0;
printf("\n===========================================\n");
printf("Welcome to update baisc salary interface.\n");
printf("==============================================\n");
printf("1. Add basic salary.\n");
printf("2. Multiply basic salary.\n");
printf("3. Substract basic salary.\n");
printf("4. Divid basic salary.\n");
printf("<><><><><><><><><><><><><><><><><><><><><><><>\n");
printf("Enter your choice: ");
if(scanf("%d", &money)!=1 || money<=0 || money>40) {
while(getchar()!='\n');
money=0;
}
printf("<><><><><><><><><><><><><><><><><><><><><><>\n");

switch(money) {
case 1:basicSalary[posi]+=temp_salary;
break;
case 2:basicSalary[posi]*=temp_salary;
break;
case 3:basicSalary[posi]-=temp_salary;
break;
case 4:basicSalary[posi]/=temp_salary; break;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(money<=0);
printf("Updated basic salary is: N$%.2f\n", basicSalary[posi]);
break;
case 11:do{
printf("Enter new Housing allowance:  ");
if(scanf("%f", &housing_alowance)!=1 || housing_alowance<=0.00) {
printf("Invailad housing allowance entered. Please try again.\n");
while(getchar()!='\n');
housing_alowance=-1;
}
}while(housing_alowance<=0.00);
printf("Old housing allowance is: N$%.2f\n", housingAllowance[posi]);
do{
money=0;
printf("\n===========================================\n");
printf("Welcome to update Housing Allowance interface.\n");
printf("==============================================\n");
printf("1. Add housing allowance.\n");
printf("2. Multiply housing allowance.\n");
printf("3. Substract housing allowance.\n");
printf("4. Divid housing allowance.\n");
printf("<><><><><><><><><><><><><><><><><><><><><><><>\n");
printf("Enter your choice: ");
if(scanf("%d", &money)!=1 || money<=0 || money>40) {
while(getchar()!='\n');
money=0;
}
printf("<><><><><><><><><><><><><><><><><><><><><><>\n");

switch(money) {
case 1:housingAllowance[posi]+=housing_alowance;
break;
case 2:housingAllowance[posi]*=housing_alowance;
break;
case 3:housingAllowance[posi]-=housing_alowance;
break;
case 4:housingAllowance[posi]/=housing_alowance; break;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(money<=0);
printf("The update housing Allowance: N$%.2f\n", housingAllowance[posi]);
break;
case 12:do{
printf("Enter new Transport allowance:  ");
if(scanf("%f", &transport_alowance)!=1 || transport_alowance<=0.00) {
printf("Invailad transport allowance entered. Please try again.\n");
while(getchar()!='\n');
transport_alowance=-1;
}
}while(transport_alowance<=0.00);
printf("Old transport allowance is: N$%.2f\n", transportAllowance[posi]);

do{
money=0;
printf("\n===========================================\n");
printf("Welcome to update Transport Allowance interface.\n");
printf("==============================================\n");
printf("1. Add transport allowance.\n");
printf("2. Multiply transport allowance.\n");
printf("3. Substract transport allowance.\n");
printf("4. Divid transport allowance.\n");
printf("<><><><><><><><><><><><><><><><><><><><><><><>\n");
printf("Enter your choice: ");
if(scanf("%d", &money)!=1 || money<=0 || money>40) {
while(getchar()!='\n');
money=0;
}
printf("<><><><><><><><><><><><><><><><><><><><><><>\n");

switch(money) {
case 1:transportAllowance[posi]+=transport_alowance;
break;
case 2:transportAllowance[posi]*=transport_alowance;
break;
case 3:transportAllowance[posi]-=transport_alowance;
break;
case 4:transportAllowance[posi]/=transport_alowance; break;
default: printf("Invalid choice entered. Please try again.\n"); break;
}
}while(money<=0);
printf("The update transport Allowance: N$%.2f\n", transportAllowance[posi]);
break;
default: printf("Invalid update choice entered. Please try again.\n"); continue;
}

}while(update_choice<=0);
printf("You have successfully update employee record.\n");
return;
}else {
printf("No changes where made.\n");
}

}else {
printf("\nEmployee records not found. Please try again.\n");
}
attempt++;
if(attempt>4) {
printf("You have reached maximum attempt. please try again in few minutes to come.\n");
return;
}
}while(!found);
return;
}
void DeleteEmployee(void) {
if(start==0) {
printf("No employee records available.\n");
return;
}
int i, found, attempt=0, choice=0, ch, posi;
char search_id[20], search_name[50];
char confirm;

do{
found=0;
printf("\n===============================================\n");
printf("Welcome to Delete Employee Interface to search employee\n");
printf("================================================\n");
printf("1. Employee ID number.\n");
printf("2. Employee full Name.\n");
printf("3. Exit.\n");
printf("______________________________________________________\n");
printf("Enter your choice to search: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>3) {
while(getchar()!='\n');
choice=-1;
}
printf("<><><><><><><><><><><><><><><><><><><><><><>\n");


while(getchar()!='\n');

switch(choice) {
case 1:do{
printf("\nEnter ID number: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';
if(!ValidateEmployeeIDNumber(search_id)) {
printf("Invalid employee ID number entered. Please try again.\n");
}

}while(!ValidateEmployeeIDNumber(search_id));

for(i=0; i<end; i++) {
if(strcmp(employee_id[i], search_id)==0) {
found=1;
posi=i;
break;
}
}
break;
case 2:do{
printf("Enter Employee Full Name: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';

if(!ValidateEmployeeFullName(search_name)) {
printf("Invalid Employee's full name entered. Please try again.\n");
}

}while(!ValidateEmployeeFullName(search_name));

for(i=0; i<end; i++) {
if(strcmp(search_name, employeeName[i])==0) {
found=1;
posi=i;
break;
}
}
break;
case 3:printf("Thanks for interacting with our system. Goodbey.\n"); return;
default: printf("Invalid choice entered. Please try again.\n"); continue;
}

if(found) {
printf("\n==========================================\n");
printf("Employee found in the employee database.\n");
printf("__________________________________________________\n");
PrintEmployee(posi);
printf("<><><><><><><><><><><><><><><><><><><><><><>\n");
printf("\nDo you real want to delete this employeee detail? \n");
printf("Enter Y or y to delete or an key to not: ");
scanf(" %c", &confirm);

while((ch=getchar())!='\n' && ch!=EOF);
if(confirm=='Y' || confirm=='y') {

for(i=posi; i<end-1; i++) {
strcpy(employee_id[i], employee_id[i+1]);
strcpy(employeeName[i], employeeName[i+1]);
strcpy(employeeGender[i], employeeGender[i+1]);
strcpy(maritalStatus[i],maritalStatus[i+1]);
strcpy(department[i],department[i+1]);
strcpy(position[i], position[i+1]);
strcpy(phoneNumber[i], phoneNumber[i+1]);
strcpy(email[i], email[i+1]);
strcpy(employmentStatus[i], employmentStatus[i+1]);
strcpy(dateHired[i], dateHired[i+1]);
basicSalary[i]=basicSalary[i+1];
housingAllowance[i]=housingAllowance[i+1];
transportAllowance[i]=transportAllowance[i+1];
}
end--;
start=end;
printf("You have successfully delete the employee records.\n");
return;
}else{
printf("No changes were made.\n");
}
}else{
printf("Employee record not found. Please try again.\n");
}
attempt++;
if(attempt>4) {
printf("You have reached Maximum attempt. Please try again in next few minutes.\n");
return;
}

}while(!found);
return;
}
void SalaryReport(int end) {
if(start==0) {
printf("No employee records available.\n");
return;
}
float total_payroll=0.00, highest_salary=0.00, lowest_salary=0.00, average_salary, mode_salary=0.00;
int count=0, i, maxi_count=0, already_count, counted, j;

for(i=0; i<end; i++) {

if(basicSalary[i]>highest_salary) {
highest_salary=basicSalary[i];
}
if(basicSalary[i]<lowest_salary) {
lowest_salary=basicSalary[i];
}
total_payroll+=basicSalary[i];
count++;
}

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
counted=1;
for(j=i+1; j<end; j++) {
if(basicSalary[i]==basicSalary[j]) {
counted++;
}

}

if(counted>maxi_count) {
maxi_count=counted;
mode_salary=basicSalary[i];
}

}

average_salary=total_payroll/count;

printf("\n======================================\n");
printf("EMPLOYEE BASIC SALARY REPORT.\n ");
printf("========================================\n");
printf("\nTotal Employees: %d\n", count);
printf("Total Payroll: N$%.2f\n", total_payroll);
printf("Highest Salary: N$%.2f\n", highest_salary);
printf("Lowest salary: N$%.2f\n", lowest_salary);
printf("Average salary: N$%.2f\n", average_salary);
printf("Most frequency salary: N$%.2f\n", mode_salary);
printf("<><><><><><><><><><><><><><><><><>\n");

return;
}
void DepartmentStatistics(int end) {
if(start==0) {
printf("No employee records available.\n");
return;
}
int i, j, count, already_count;

printf("\n=======================================\n");
printf("EMPLOYEE DEPARTMENT STATISTICS REPORT\n");
printf("==========================================\n");

for(i=0; i<end; i++) {
already_count=0;
for(j=0; j<i; j++) {
if(strcmp(department[i], department[j])==0) {
already_count=1;
break;
}
}

if(already_count) {
continue;
}

count=1;
for(j=i+1; j<end; j++) {
if(strcmp(department[i], department[j])==0) {
count++;
}
}

printf(" %s : %d\n", department[i], count);

}
printf("\n=========================================\n");

return;
}
void TopEarner(int end) {
if(start==1) {
printf("No employee records available.\n");
return;
}
float highest_salary=basicSalary[0];
int count=0, i;

for(i=1; i<end; i++) {
if(basicSalary[i]>highest_salary) {
highest_salary=basicSalary[i];
}
}

printf("\n==================================\n");
printf("TOP EARNING EMPLOYEE DETAILS.\n");
printf("====================================\n");

for(i=0; i<end; i++) {
if(basicSalary[i]==highest_salary) {
printf("\nIdentity number: %s\n", employee_id[i]);
printf("Full Name: %s\n", employeeName[i]);
printf("Department: %s\n", department[i]);
printf("Position : %s\n", position[i]);
printf("Gross Salary: N$%.2f\n", basicSalary[i]);
count++;
}

}
printf("\n=====================================\n");

if(count>1) {
printf("\n<><><><><><><><><><><><><><><><><><><>\n");
printf("Total number of highest salary employee is: %d\n", count);
printf("<><><><><><><><><><><><><><><><><><><>\n");
}
return;
}
void LowEarner(int end) {
if(start==1) {
printf("No employee records available.\n");
return;
}
float lowest_salary=basicSalary[0];
int count=0, i;

for(i=1; i<end; i++) {
if(basicSalary[i]<lowest_salary) {
lowest_salary=basicSalary[i];
}
}

printf("\n==================================\n");
printf("TOP EARNING EMPLOYEE DETAILS.\n");
printf("====================================\n");

for(i=0; i<end; i++) {
if(basicSalary[i]==lowest_salary) {
printf("\nIdentity number: %s\n", employee_id[i]);
printf("Full Name: %s\n", employeeName[i]);
printf("Department: %s\n", department[i]);
printf("Position : %s\n", position[i]);
printf("Gross Salary: N$%.2f\n", basicSalary[i]);
count++;
}

}
printf("\n=====================================\n");

if(count>1) {
printf("\n<><><><><><><><><><><><><><><><><><><>\n");
printf("Total number of lowest salary employee is: %d\n", count);
printf("<><><><><><><><><><><><><><><><><><><>\n");
}
return;
}
void SortEmployees(int end) {
if(start==0) {
printf("No employee records available.\n");
return;
}

int i, j;

char temp_id[20], temp_name[50], temp_gender[10], temp_marital_status[20], temp_department[50], temp_position[50];
char temp_number[20], temp_email[50], temp_employment_status[20], temp_date_hired[20];
float temp_basic_salary, temp_housing_allowance, temp_transport_allowance;

for(i=0; i<end-1; i++) {

for(j=i+1; j<end; j++) {
if(strcmp(employeeName[i], employeeName[j])>0) {
strcpy(temp_name, employeeName[i]);
strcpy(employeeName[i], employeeName[j]);
strcpy(employeeName[j], temp_name);

strcpy(temp_id, employee_id[i]);
strcpy(employee_id[i], employee_id[j]);
strcpy(employee_id[j], temp_id);

strcpy(temp_gender, employeeGender[i]);
strcpy(employeeGender[i], employeeGender[j]);
strcpy(employeeGender[j], temp_gender);

strcpy(temp_marital_status, maritalStatus[i]);
strcpy(maritalStatus[i], maritalStatus[j]);
strcpy(maritalStatus[j], temp_marital_status);

strcpy(temp_department, department[i]);
strcpy(department[i], department[j]);
strcpy(department[j], temp_department);

strcpy(temp_position, position[i]);
strcpy(position[i], position[j]);
strcpy(position[j], temp_position);

strcpy(temp_number, phoneNumber[i]);
strcpy(phoneNumber[i], phoneNumber[j]);
strcpy(phoneNumber[j], temp_number);

strcpy(temp_email, email[i]);
strcpy(email[i], email[j]);
strcpy(email[j], temp_email);

strcpy(temp_employment_status, employmentStatus[i]);
strcpy(employmentStatus[i], employmentStatus[j]);
strcpy(employmentStatus[j], temp_employment_status);

strcpy(temp_date_hired, dateHired[i]);
strcpy(dateHired[i], dateHired[j]);
strcpy(dateHired[j], temp_date_hired);

temp_basic_salary=basicSalary[i];
basicSalary[i]=basicSalary[j]; 
basicSalary[j]=temp_basic_salary;

temp_housing_allowance=housingAllowance[i];
housingAllowance[i]=housingAllowance[j];
housingAllowance[j]=temp_housing_allowance;

temp_transport_allowance=transportAllowance[i];
transportAllowance[i]=transportAllowance[j];
transportAllowance[j]=temp_transport_allowance;

}
}
}

printf("\nThe employees successfully sorted.\n");
return;
}
void searchByDepartment(int end) {
if(start==0) {
printf("No employee records available.\n");
return;
}

int i, count=0, found=0, attempt=0, j;
char search[50];

do{
SelectDepartment(search);
for(i=0; i<end; i++) {
if(strcmp(search, department[i])==0) {
found=1;
break;
}
}

if(found) {
printf("\n=================================\n");
printf("FOUD EMPLOYEE IN DEPARTMENT %s\n", search);
printf("===================================\n");
for(j=0; j<end; j++) {
if(strcmp(search, department[j])==0) {
printf("\nID number: %s\n", employee_id[j]);
printf("Full Name: %s\n", employeeName[j]);
printf("Position : %s\n", position[j]);
printf("Phone Number: %s\n", phoneNumber[j]);
printf("Employee status: %s\n", employmentStatus[j]);
count++;
printf("\n==================================\n");
}
}

if(count>1) {
printf("\n========================================\n");
printf("Total number of employee within the deparment is: %d\n", count);
printf("==========================================\n");
}
return;
}else {
printf("No employee were found within the the department records. Please try again.\n");
}
attempt++;

if(attempt>4) {
printf("You have reached maximum attempt. Please try again in next few minutes.\n");
return;
}
}while(!found);
return;
}
void EmployeeMenu() {
int choice=0;
do{
printf("==========================================\n");
printf("		EMPLOYEE MANAGEMENT		\n");
printf("==========================================\n");
printf("\n1. Add Employee.\n");
printf("2. Display Employees.\n");
printf("3. Search Employee.\n");
printf("4. Update Employee.\n");
printf("5. Delete Employee.\n");
printf("6. Sort Employees.\n");
printf("7. Return To Main Menu.\n");
printf("==========================================\n");
printf("Enter Choice: ");
if(scanf("%d", &choice)!=1 || choice<=0 ) {
while(getchar()!='\n');
choice=0;
}

switch(choice) {
case 1: AddEmployee(); break;
case 2: DisplayEmployees(end); break;
case 3: SearchEmployee(end); break;
case 4: UpdateEmployee(end); break;
case 5: DeleteEmployee(); break;
case 6:SortEmployees(end); break;
case 7:printf("Thanks for interacting with our employee interface. Goodbey.\n"); break;
default: printf("Invalid choice entered. please try again.\n"); break;
}
}while(choice!=7);
return;
}


