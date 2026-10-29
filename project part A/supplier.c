#include "supplier.h"
int supplier_start=0;
int supplier_end;
int supplier_count;
char supplier_id[MAX_SUPPLIERS][20];
char supplier_name[MAX_SUPPLIERS][50];
char supplier_email[MAX_SUPPLIERS][50];
char supplier_phone[MAX_SUPPLIERS][20];
char supplier_location[MAX_SUPPLIERS][50];
int ValidateSupplierID(char id[]) {
int i;
if(strlen(id)==0) {
return 0;
}

for(i=0; id[i]!='\0'; i++) {
if(id[i]<'0' || id[i]>'9') {
return 0;
}
}
return 1;
}
int ValidateSupplierName(char name[]) {
int i;
if(strlen(name)==0) {
return 0;
}

for(i=0; name[i]!='\0'; i++) {

if(!((name[i]>='A' && name[i]<='Z') || (name[i]>='a' && name[i]<='z') || name[i]==' ')) {
return 0;
}

}
return 1;

}
int ValidateSupplierEmail(char email[]) {

if((strlen(email))==0) {
return 0;
}
int at=-1;
int dot=-1, i, found_dot=0, found_at=0;

for(i=0; email[i]!='\0'; i++) {

if(email[i]=='.' && !found_dot) {
dot=i;
found_dot=1;
}

if(email[i]=='@' && !found_at) {
at=i;
found_at=1;
}

}

if(at <=0) {
return 0;
}else if(dot<=at+1) {
return 0;
}else if(email[i-1]=='.'){
return 0;
}

return 1;
}
int ValidateSupplierPhone(char phone[]) {

int i;
if(strlen(phone)==0) {
return 0;
}

for(i=0; phone[i]!='\0'; i++) {

if(phone[i]<'0' || phone[i]> '9') {
return 0;
}

}

return 1;
}
int ValidateLocation(char location[]) {
int i;
if(strlen(location)==0) {
return 0;
}

for(i=0; location[i]!='\0'; i++) {

if(!((location[i]>='A' && location[i]<='Z') || (location[i]>='a' && location[i]<='z') || location[i]==' ')) {
return 0;
}

}
return 1;
}
void PrintSupplier(int index) {
if(supplier_start==0) {
printf("No student records is available.\n");
return;
}
printf("Supplier Identity Number: %s\n", supplier_id[index]);
printf("Supplier Name: %s\n", supplier_name[index]);
printf("Contact Number: %s\n", supplier_phone[index]);
printf("Supplier Email: %s\n", supplier_email[index]);
printf("Supplier Location: %s\n", supplier_location[index]);

return;
}
void AddSupplier(void) {
int i, j, found=0; 
if(supplier_start==99) {
printf("The list is full you cannot add any budget details.\n");
return;
}else {
do{
printf("How may supplier detail do you want to add? ");

if(scanf("%d", &supplier_end)!=1 || supplier_end<=0) {
printf("Invalid budget tdetails to add entered. Please try again.\n");
while(getchar()!='\n');
supplier_end=0;
}

if((supplier_start+supplier_end)>99) {
printf("You have ecxeeded the maximum list. Please try again adding few budget.\n");
continue;
}
}while(supplier_end<=0);
}

supplier_count=0;
supplier_end+=supplier_start;

while(getchar()!='\n');
for(i=supplier_start; i<supplier_end; i++) {
printf("\n=========Enter supplier detail %d=================\n", i+1);
do{
found=0;
do{
printf("supplier Idendity number: ");
fgets(supplier_id[i], sizeof(supplier_id[i]), stdin);
supplier_id[i][strcspn(supplier_id[i], "\n")]='\0';

if(!ValidateSupplierID(supplier_id[i])) {
printf("Invalid supplier Identity number entered. Please try again.\n");
}
}while(!ValidateSupplierID(supplier_id[i]));

for(j=0; j<i; j++) {

if(strcmp(supplier_id[j], supplier_id[i])==0) {
found=1;
break;
}
}
if(found) {
printf("The supplier ID number Already exist. Please try again.\n");
}

}while(found);


do{
printf("Supplier Full name: ");
fgets(supplier_name[i], sizeof(supplier_name[i]), stdin);
supplier_name[i][strcspn(supplier_name[i], "\n")]='\0';

if(!ValidateSupplierName(supplier_name[i])) {
printf("Invalid Supplier name entered. Please try again.\n");
}
}while(!ValidateSupplierName(supplier_name[i]));
do{
printf("Supplier phone number: ");
fgets(supplier_phone[i], sizeof(supplier_phone[i]), stdin);
supplier_phone[i][strcspn(supplier_phone[i], "\n")]='\0';

if(!ValidateSupplierPhone(supplier_phone[i])) {
printf("Invalid Supplier phone number entered. Please try again.\n");
}
}while(!ValidateSupplierPhone(supplier_phone[i]));

do{
printf("Supplier email: ");
fgets(supplier_email[i], sizeof(supplier_email[i]), stdin);
supplier_email[i][strcspn(supplier_email[i], "\n")]='\0';

if(!ValidateSupplierEmail(supplier_email[i])) {
printf("Invalid Supplier email entered. Please try again.\n");
}

}while(!ValidateSupplierEmail(supplier_email[i]));

do{
printf("Supplier location: ");
fgets(supplier_location[i], sizeof(supplier_location[i]), stdin);
supplier_location[i][strcspn(supplier_location[i], "\n")]='\0';

if(!ValidateLocation(supplier_location[i])) {
printf("Invalid Supplier location entered. Please try again.\n");
}
}while(!ValidateLocation(supplier_location[i]));

supplier_count++;
}

printf("\n==============================================\n");
printf("%d supplier details successfully added on the list.\n", supplier_count);
printf("===============================================\n");
supplier_start=supplier_end;
return;
}
void DisplaySuppliers(void) {
if(supplier_start==0) {
printf("No supplier records is available.\n");
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
void SearchSupplier(void) {
if(supplier_start==0) {
printf("No supplier records available.\n");
return;
}
char search_name[50], search_id[25];
int found=0, attempt=0, choice=0, i;

do{
found=0;
printf("\n==================================================\n");
printf("WELCOME TO OUR SEARCH SUPPLIER RECORDS INTERFACE.\n");
printf("====================================================\n");
printf("1. Supplier Identity number.\n");
printf("2. Supplier Full Name.\n");
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
printf("Enter supplier identity number: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';
if(!ValidateSupplierID(search_id)) {
printf("Invalid supplier Identity number entered. Please try again.\n");
}
}while(!ValidateSupplierID(search_id));
for(i=0; i<supplier_end; i++) {
if(strcmp(supplier_id[i], search_id)==0) {
found=1;
break;
}
}
break;
case 2: do{
printf("Enter supplier full name: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';
if(!ValidateSupplierName(search_name)) {
printf("Invalide Supplier Name entered. Please try again.\n");
}

}while(!ValidateSupplierName(search_name));
for(i=0; i<supplier_end; i++) {
if(strcmp(supplier_name[i], search_name)==0) {
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
printf("Supplier details Found in the database.\n");
printf("<><><><><><><><><>><><><><><>><><><><><><><>\n");
PrintSupplier(i);
printf("__________________________________________________\n");
return;
}else {
printf("Supplier records not found in the database. Please try again.\n");
}
attempt++;

if(attempt>4) {
printf("You have reached maximum attempt. Please try again in next few minutes.\n");
return;
}
}while(!found);
return;
}
void UpdateSupplier(void) {
if(supplier_start==0) {
printf("No supplier records available.\n");
return;
}
char search_id[25], search_name[50];
int found=0, attempt=0, choice=0, ch, update=0, i;
char number[20], name[50], email[50], location[50];
char confirm;
do{
found=0;
printf("\n==================================================\n");
printf("WELCOME TO OUR UPDATE SUPPLER INTERFACE.\n");
printf("====================================================\n");
printf("1. Supplier Identity number.\n");
printf("2. Supplier Full Name.\n");
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
printf("Enter supplier identity number: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';
if(!ValidateSupplierID(search_id)) {
printf("Invalid supplier Identity number entered. Please try again.\n");
}
}while(!ValidateSupplierID(search_id));
for(i=0; i<supplier_end; i++) {
if(strcmp(supplier_id[i], search_id)==0) {
found=1;
break;
}
}
break;
case 2: do{
printf("Enter supplier full name: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';
if(!ValidateSupplierName(search_name)) {
printf("Invalide Supplier Name entered. Please try again.\n");
}

}while(!ValidateSupplierName(search_name));
for(i=0; i<supplier_end; i++) {
if(strcmp(supplier_name[i], search_name)==0) {
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
printf("Supplier details Found in the database.\n");
printf("<><><><><><><><><>><><><><><>><><><><><><><>\n");
PrintSupplier(i);
printf("__________________________________________________\n");
printf("Do you really want to update the supplier? \n");
printf("Enter Y or y to update or any key to not update: ");
scanf(" %c", &confirm);
while((ch=getchar())!='\n' && ch!=EOF);
if(confirm=='Y' || confirm=='y') {
do{
printf("\n=========================================\n");
printf("WELCOME TO UPDATE CHOICE INTERFACE.\n");
printf("==========================================\n");
printf("1. Supplier Name.\n");
printf("2. Email.\n");
printf("3. Cellphone Number.\n");
printf("4. Location.\n");
printf("___________________________________________\n");
printf("Enter update choice: ");
if(scanf("%d", &update)!=1 || update<=0 || update>4) {
while(getchar()!='\n');
update=-1.00;
}
printf("<><><><><><><><><><><><><><><><><><><><><><>.\n");
while(getchar()!='\n');

switch(update) {
case 1:do{
printf("Supplier Full name to update: ");
fgets(name, sizeof(name), stdin);
name[strcspn(name, "\n")]='\0';

if(!ValidateSupplierName(name)) {
printf("Invalid Supplier name entered. Please try again.\n");
}
}while(!ValidateSupplierName(name));
printf("Old supplier name is: %s\n", supplier_name[i]);
strcpy(supplier_name[i], name);
printf("Updated supplier full name is: %s\n", supplier_name[i]);
break;
case 2:do{
printf("Supplier email to update: ");
fgets(email, sizeof(email), stdin);
email[strcspn(email, "\n")]='\0';

if(!ValidateSupplierEmail(email)) {
printf("Invalid Supplier email entered. Please try again.\n");
}
}while(!ValidateSupplierEmail(email));
printf("Old supplier email is: %s\n", supplier_email[i]);
strcpy(supplier_email[i], email);
printf("Updated supplier email is: %s\n", supplier_email[i]);
break;
case 3:do{
printf("Supplier phone number to update: ");
fgets(number, sizeof(number), stdin);
number[strcspn(number, "\n")]='\0';

if(!ValidateSupplierPhone(number)) {
printf("Invalid Supplier phone number entered. Please try again.\n");
}
}while(!ValidateSupplierPhone(number));

printf("Old supplier Phone number is: %s\n", supplier_phone[i]);
strcpy(supplier_phone[i], number);
printf("Updated supplier phone number is: %s\n", supplier_phone[i]);
break;
case 4:do{
printf("Supplier location to update: ");
fgets(location, sizeof(location), stdin);
location[strcspn(location, "\n")]='\0';

if(!ValidateLocation(location)) {
printf("Invalid Supplier location entered. Please try again.\n");
}
}while(!ValidateLocation(location));
printf("Old supplier location is: %s\n", supplier_location[i]);
strcpy(supplier_location[i], location);
printf("Updated supplier location is: %s\n", supplier_location[i]);
break;
default: printf("Invalid update choice entered. Please try again.\n"); break;
}
}while(update<=0);
printf("You have successfully update the supplier detail.\n");
return;
}else {
printf("No changes were made.\n");
}
}else {
printf("supplier records not found in the database. Please try again.\n");
}
attempt++;

if(attempt>4) {
printf("You have reached maximum attempt. Please try again in next few minutes.\n");
return;
}
}while(!found);
return;
}
void DeleteSupplier(void) {
if(supplier_start==0) {
printf("No supplier records available.\n");
return;
}
char search_id[25], search_name[50]; 
int found=0, attempt=0, choice=0, ch, position, i;
char confirm;
do{
found=0;
printf("\n==================================================\n");
printf("WELCOME TO OUR DELETE SUPPLIER RECORDS INTERFACE.\n");
printf("====================================================\n");
printf("1. Supplier Identity number.\n");
printf("2. Supplier Full Name.\n");
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
printf("Enter supplier identity number: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';
if(!ValidateSupplierID(search_id)) {
printf("Invalid supplier Identity number entered. Please try again.\n");
}
}while(!ValidateSupplierID(search_id));
for(i=0; i<supplier_end; i++) {
if(strcmp(supplier_id[i], search_id)==0) {
found=1;
position=i;
break;
}
}
break;
case 2: do{
printf("Enter supplier full name: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';
if(!ValidateSupplierName(search_name)) {
printf("Invalide Supplier Name entered. Please try again.\n");
}

}while(!ValidateSupplierName(search_name));
for(i=0; i<supplier_end; i++) {
if(strcmp(supplier_name[i], search_name)==0) {
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
printf("Supplier details Found in the database.\n");
printf("<><><><><><><><><>><><><><><>><><><><><><><>\n");
PrintSupplier(position);
printf("__________________________________________________\n");
printf("Do you really want to delete the supplier records?\n ");
printf("Enter Y or y to update or any key to not update: ");
scanf(" %c", &confirm);
while((ch=getchar())!='\n' && ch!=EOF);
if(confirm=='Y' || confirm=='y') {
for(i=position; i<supplier_end-1; i++) {
strcpy(supplier_id[i], supplier_id[i+1]);
strcpy(supplier_name[i], supplier_name[i+1]);
strcpy(supplier_phone[i], supplier_phone[i+1]);
strcpy(supplier_email[i], supplier_email[i+1]);
strcpy(supplier_location[i], supplier_location[i+1]);

}
supplier_end--;
supplier_start=supplier_end;
printf("Supplier records successfully deleted.\n");
return;
}else {
printf("No changes were made.\n");
}
}else {
printf("Supplier records not found in the database. Please try again.\n");
}
attempt++;

if(attempt>4) {
printf("You have reached maximum attempt. Please try again in next few minutes.\n");
return;
}

}while(!found);

return;
}
void SupplierMenu() {
int choice=0;
do{
 printf("\n===================================\n");
printf("     SUPPLIER MANAGEMENT SYSTEM\n");
printf("===================================\n");
printf("1. Add Supplier\n");
printf("2. Display Suppliers\n");
printf("3. Search Supplier\n");
printf("4. Update Supplier\n");
printf("5. Delete Supplier\n");
printf("6. Exit\n");
printf("===================================\n");
printf("Enter Choice: ");
 if(scanf("%d", &choice) != 1){
while(getchar() != '\n');
choice = 0;
}
switch(choice) {
case 1: AddSupplier();break;
case 2:DisplaySuppliers();break;
case 3:SearchSupplier();break;
case 4:UpdateSupplier();break;
case 5:DeleteSupplier();break;
case 6:printf("Returning to Main Menu...\n");break;
default:printf("Invali choice entered. Please try again.\n");
}
}while(choice!=6);
return;
}








