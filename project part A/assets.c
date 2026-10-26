#include "assets.h"
int asset_end;
int asset_start=0;
int asset_count;
char asset_id[MAX_ASSETS][20];
char asset_name[MAX_ASSETS][50];
char asset_type[MAX_ASSETS][50];
char asset_department[MAX_ASSETS][50];
char asset_condition[MAX_ASSETS][30];
float purchase_value[MAX_ASSETS];
int ValidateAssetID(char id[]) {
if(strlen(id)==0) {
return 0;
}
int i;

for(i=0; id[i]!='\0'; i++) {

if(!(id[i]>='0' && id[i]<='9')) {
return 0;
}

}

return 1;
}
int ValidateAssetName(char name[]) {
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
void SelectAssetType(char assets_type[]){
printf("Select Assest type: \n");
int choice;
do{
printf("\n===================================\n");
printf("         ASSET TYPE MENU\n");
printf("====================================\n");
printf("1. Vehicle\n");
printf("2. Computer\n");
printf("3. Printer\n");
printf("4. Building\n");
printf("5. Office Furniture\n");
printf("6. Equipment\n");
printf("7. Generator\n");
printf("8. Water Infrastructure\n");
printf("9. Electrical Infrastructure\n");
printf("10. Other\n");

printf("===================================\n");
printf("Enter your choice: ");

if(scanf("%d", &choice) != 1 || choice<1 || choice>10){
while(getchar() != '\n');
choice = 0;
}
switch(choice){
case 1:strcpy(assets_type, "Vehicle");break;
case 2:strcpy(assets_type, "Computer");break;
case 3:strcpy(assets_type, "Printer");break;
case 4:strcpy(assets_type, "Building");break;
case 5:strcpy(assets_type, "Office Furniture");break;
case 6:strcpy(assets_type, "Equipment");break;
case 7:strcpy(assets_type, "Generator");break;
case 8:strcpy(assets_type, "Water Infrastructure");break;
case 9:strcpy(assets_type, "Electrical Infrastructure");break;
case 10:strcpy(assets_type, "Other");break;
default:printf("Invalid asset type selected. Please try again.\n");break;
}
} while(choice < 1);
return;
}
void SelectAssetCondition(char assets_condition[]) {
printf("Select asset condition from bellow please: \n");
int choice;
do{
printf("\n========================================\n");
printf("		ASSETS CONDITION MENU			\n");
printf("=========================================\n");
printf("\n1.Excellent.\n");
printf("2. Good\n");
printf("3. Fair.\n");
printf("4. Poor.\n");
printf("5. Damage.\n");
printf("\n_____________________________________________\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>5) {
while(getchar()!='\n');
choice=0;
}
printf("__________________________________________________\n");

switch(choice) {
case 1:strcpy(assets_condition, "Excellent"); break;
case 2:strcpy(assets_condition, "Good"); break;
case 3:strcpy(assets_condition, "Fair"); break;
case 4:strcpy(assets_condition, "Poor"); break;
case 5:strcpy(assets_condition, "Damage"); break;
default: printf("Invalid choice entered. Please try again.\n"); break;
}


}while(choice<=0);

return;
}
void SelectAssetDepartment(char assets_department[]) {
printf("\nSelect Asset Department name below: \n");
int choice;

do{
printf("\n===============================\n");
printf("	ASSETS DEPARTMENT NAME MENU	.\n");
printf("=================================\n");
printf("\n1. Finance\n");
printf("2. Human Resources\n");
printf("3. Information Technology\n");
printf("4. Procurement\n");
printf("5. Engineering\n");
printf("6. Water Management\n");
printf("7. Electricity Service\n");
printf("8. Town Planning\n");
printf("9. Customer Care\n");
printf("10. Legal\n");
printf("\n--------------------------------------------------\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>10) {
while(getchar()!='\n');
choice=0;
}
printf("--------------------------------------------------\n");

switch(choice) {
case 1:strcpy(assets_department, "Finance");break;
case 2:strcpy(assets_department, "Human Resources");break;
case 3:strcpy(assets_department, "Information Technology");break;
case 4:strcpy(assets_department, "Procurement");break;
case 5:strcpy(assets_department, "Engineering");break;
case 6:strcpy(assets_department, "Water Management");break;
case 7:strcpy(assets_department, "Electricity Service");break;
case 8:strcpy(assets_department, "Town Planning");break;
case 9:strcpy(assets_department, "Customer Care");break;
case 10:strcpy(assets_department, "Legal");break;
default: printf("Invalid choice entered. please try again.\n"); break;
}
}while(choice<=0);

return;
}
void AddAsset(void) {
if(asset_start>=99) {
printf("\nThe list is full you can not add any Assets detail.\n");
return;
}

int i;
do{
printf("How Asset details do you want to add? ");
if(scanf("%d", &asset_end)!=1 || asset_end<=0) {
printf("Invalid number of Asset detail to add entered. Please try again.\n");
while(getchar()!='\n');
asset_end=0;
}

if((asset_start+asset_end)>=99) {
printf("The number you want to add is too much try to reduce.\n");
continue;
}
}while(asset_end<=0);
asset_end+=asset_start;
asset_count=0;

for(i=asset_start; i<asset_end; i++) {
while(getchar()!='\n');
printf("\n======================================\n");
printf("Enter Asset Detail for asset number %d\n", asset_count+1);
printf("=========================================\n");

do{
printf("Enter Asset Identity number: ");
fgets(asset_id[i], sizeof(asset_id[i]), stdin);
asset_id[i][strcspn(asset_id[i], "\n")]='\0';
if(!ValidateAssetID(asset_id[i])) {
printf("Invalid Asset Identity number entered. Please try again.\n");
}
}while(!ValidateAssetID(asset_id[i]));

do{
printf("Enter Asset name: ");
fgets(asset_name[i], sizeof(asset_name[i]), stdin);
asset_name[i][strcspn(asset_name[i], "\n")]='\0';

if(!ValidateAssetName(asset_name[i])) {
printf("Invalid asset name entered. Please try again.\n");
}

}while(!ValidateAssetName(asset_name[i]));

SelectAssetType(asset_type[i]);
SelectAssetDepartment(asset_department[i]);
SelectAssetCondition(asset_condition[i]);
do{
printf("Enter the purchase value: ");
if(scanf("%f", &purchase_value[i])!=1 || purchase_value[i]<=0.00) {
printf("Invalid purchase value entered. Please try again.\n");
while(getchar()!='\n');
purchase_value[i]=0.00;
}
}while(purchase_value[i]<=0.00);

asset_count++;
}
asset_start=asset_end;
printf("\n================================================\n");
printf("%d Asset records successfully added to the list.\n", asset_count);
printf("==================================================\n");

return;
}
void PrintAsset(int index) {
if(asset_start==0) {
printf("No Asset records available.\n");
}

printf("Asset Identity number: %s\n", asset_id[index]);
printf("Asset Name: %s\n", asset_name[index]);
printf("Asset type: 	%s\n", asset_type[index]);
printf("Asset department: %s\n", asset_department[index]);
printf("Asset Condition: %s\n", asset_condition[index]);
printf("Purchase value: N$%.2f\n", purchase_value[index]);

}

void DisplayAsset(void) {
if(asset_start==0) {
printf("No asset records available.\n");
return;
}
int i;
asset_count=0;
printf("\n================================\n");
printf("Asset Records report.\n");
printf("===================================\n");

for(i=0; i<asset_end; i++) {
printf("\n______________Asset detail number %d_________________\n", i+1);
PrintAsset(i);
printf("--------------------------------------------------------------------------\n");
asset_count++;
}

printf("\n<><><><><><><><><><><><><><><><><><><>\n");
printf("Total number of Asset details is: %d\n", asset_count);
printf("<><><><><><><><><><><><><><><><><><><><>\n");
return;
}
void SearchAsset(void) {
if(asset_start==0) {
printf("No asset records available.\n");
return;
}
int i, found, attempt=0, choice=0;
char search_id[25], search_name[50];

do{
found=0;
printf("\n=======================================\n");
printf("WELCOME TO OUR SEARCH ASSET INTERFACE\n");
printf("==========================================");
printf("\n1. Asset identity number\n");
printf("2. Asset name\n");
printf("3. Exit\n");
printf("_____________________________________________\n");
printf("Enter your choice to search: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>3) {
while(getchar()!='\n');
choice=0;
}
printf("_____________________________________________\n");

while(getchar()!='\n');

switch(choice) {
case 1:do{
printf("Enter asset ID number to search: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';

if(!ValidateAssetID(search_id)) {
printf("Invalid the ID number you want to search entered. Please try again.\n");
}
}while(!ValidateAssetID(search_id));

for(i=0; i<asset_end; i++) {
if(strcmp(search_id, asset_id[i])==0) {
found=1;
break;
}
}
break;
case 2:do{
printf("Enter asset name to search: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';

if(!ValidateAssetID(search_name)) {
printf("Invalid the asset name you want to search entered. Please try again.\n");
}
}while(!ValidateAssetID(search_name));

for(i=0; i<asset_end; i++) {
if(strcmp(search_name, asset_name[i])==0) {
found=1;
break;
}
}
break;
case 3:printf("Thanks for intracting with our interface.Goodbey\n");return;
default: printf("Invalid choice entered. Please try again.\n");continue;
}

if(found) {
printf("\n=============================\n");
printf("Asset records Found in asset database.\n");
printf("===============================\n");
PrintAsset(i);
printf("<><><><><><><><><><><><><><>\n");
return;
}else {
printf("Assset records not found in the asset database.\n");
}

attempt++;

if(attempt>4) {
printf("You have reached maximum search attempt. Please try again later.\n");
return;
}
}while(!found);

return;
}
void UpdateAsset(void) {
if(asset_start==0) {
printf("No asset records avalable.\n");
return;
}
int i, found=0, attempt=0, choice=0, update=0, ch;
char confirm;
char search_id[20], search_name[50], update_id[20], update_name[50], update_type[50], update_department[50], update_condition[30];
float update_purchase_value;
do{
found=0;
printf("\n=======================================\n");
printf("WELCOME TO OUR UPDATE ASSET INTERFACE\n");
printf("==========================================");
printf("\n1. Asset identity number\n");
printf("2. Asset name\n");
printf("3. Exit\n");
printf("_____________________________________________\n");
printf("Enter your choice to search: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>3) {
while(getchar()!='\n');
choice=0;
}
printf("_____________________________________________\n");

while(getchar()!='\n');

switch(choice) {
case 1:do{
printf("Enter asset ID number to search: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';

if(!ValidateAssetID(search_id)) {
printf("Invalid the ID number you want to search entered. Please try again.\n");
}
}while(!ValidateAssetID(search_id));

for(i=0; i<asset_end; i++) {
if(strcmp(search_id, asset_id[i])==0) {
found=1;
break;
}
}
break;
case 2:do{
printf("Enter asset name to search: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';

if(!ValidateAssetName(search_name)) {
printf("Invalid the asset name you want to search entered. Please try again.\n");
}
}while(!ValidateAssetName(search_name));

for(i=0; i<asset_end; i++) {
if(strcmp(search_name, asset_name[i])==0) {
found=1;
break;
}
}
break;
case 3:printf("Thanks for intracting with our interface.Goodbey\n");return;
default: printf("Invalid choice entered. Please try again.\n");continue;
}

if(found) {
printf("\n=============================\n");
printf("Asset records Found in asset database.\n");
printf("===============================\n");
PrintAsset(i);
printf("<><><><><><><><><><><><><><>\n");

printf("\nDo you real want to update the asset records? \n");
printf("Enter Y or y to update asset records or any key to not: ");
scanf(" %c", &confirm);
while((ch=getchar())!='\n' && ch!=EOF);
if(confirm=='Y' || confirm=='y') {
do{
update=0;
printf("\n=====================================\n");
printf("WELCOME TO UPDATE CHOICE INTERFACE.\n");
printf("======================================\n");
printf("\n1. Update asset ID number\n");
printf("2. Update asset name\n");
printf("3. Update asset type\n");
printf("4. Update asset department.\n");
printf("5. Update asset condition\n");
printf("6. Update purchase value\n");
printf("\n<><><><><><><><><><><><><><><><><><>\n");
printf("Enter your choice: ");
if(scanf("%d", &update)!=1 || update<=0) {
while(getchar()!='\n');
update=0;
}
printf("________________________________________\n");
while(getchar()!='\n');
switch(update) {
case 1: do{
printf("Enter Asset  ID number to update: ");
fgets(update_id, sizeof(update_id), stdin);
update_id[strcspn(update_id, "\n")]='\0';
if(!ValidateAssetID(update_id)) {
printf("Invalid Update id number entered. Please try to enter a valid id number.\n");
}
}while(!ValidateAssetID(update_id));
printf("The old Asset ID number is: %s\n", asset_id[i]);
strcpy(asset_id[i], update_id);
printf("The Updated Asset ID number is: %s\n", asset_id[i]);
break;
case 2:do{
printf("Enter Asset name to update: ");
fgets(update_name, sizeof(update_name), stdin);
update_name[strcspn(update_name, "\n")]='\0';
if(!ValidateAssetName(update_name)) {
printf("Invalid Update name entered. Please try to enter a valid name.\n");
}
}while(!ValidateAssetName(update_name));
printf("The old Asset name is: %s\n", asset_name[i]);
strcpy(asset_name[i], update_name);
printf("The Updated Asset name is: %s\n", asset_name[i]);
break;
case 3:SelectAssetType(update_type);
printf("The old asset type is: %s\n", asset_type[i]);
strcpy(asset_type[i], update_type);
printf("The updated asset type is: %s\n", asset_type[i]);
break;
case 4:SelectAssetDepartment(update_department);
printf("The old asset type is: %s\n", asset_department[i]);
strcpy(asset_department[i], update_department);
printf("The updated asset type is: %s\n", asset_department[i]);
break;
case 5:SelectAssetCondition(update_condition);
printf("The old asset type is: %s\n", asset_condition[i]);
strcpy(asset_condition[i], update_condition);
printf("The updated asset type is: %s\n", asset_condition[i]);
break;
case 6: do{
printf("Enter the amount you want to update: ");
if(scanf("%f", &update_purchase_value)!=1 || update_purchase_value<=0) {
printf("Invalid Update purchase value entered. Please try again.\n");
while(getchar()!='\n');
update_purchase_value=0;
}
}while(update_purchase_value<=0);
do{
choice=0;
printf("\n=========================================\n");
printf("WELCOME TO UPDATE PURCHASE VALUE CHOICE\n");
printf("===========================================\n");
printf("\n1. Add to axisted purchase value.\n");
printf("2. Substract from axisted purchase value.\n");
printf("3. Multiply with axisted purchase value.\n");
printf("4. Divid with axisted purchase value.\n");
printf("\n---------------------------------------------------------------\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1 || choice<=0) {
while(getchar()!='\n');
choice=0;
}
printf("___________________________________________\n");
switch(choice) {
case 1:printf("The old purchase value is: N$%.2f\n", purchase_value[i]);
purchase_value[i]+=update_purchase_value;
printf("The updated purchase value is: N$%.2f\n", purchase_value[i]);
break;
case 2:printf("The old purchase value is: N$%.2f\n", purchase_value[i]);
purchase_value[i]-=update_purchase_value;
printf("The updated purchase value is: N$%.2f\n", purchase_value[i]);
break;
case 3: printf("The old purchase value is: N$%.2f\n", purchase_value[i]);
purchase_value[i]*=update_purchase_value;
printf("The updated purchase value is: N$%.2f\n", purchase_value[i]);
break;
case 4:printf("The old purchase value is: N$%.2f\n", purchase_value[i]);
purchase_value[i]/=update_purchase_value;
printf("The updated purchase value is: N$%.2f\n", purchase_value[i]);
break;
default: printf("Invalide purchase value entered. Please try again.\n");continue;
}

}while(choice<=0);
break;
default: printf("Invalid update choice entered. Please try again.\n"); continue;
}

}while(update<=0);
printf("The asset Record has been updated successfully.\n");

return;
}else {
printf("No changes were made.\n");
}
}else {
printf("Assset records not found in the asset database.\n");
}

attempt++;

if(attempt>4) {
printf("You have reached maximum search attempt. Please try again later.\n");
return;
}
}while(!found);

return;
}
void DeleteAsset(void) {
if(asset_start==0) {
printf("No asset records available.\n");
return;
}
int i, found=0, choice=0, attempt=0, j;
char confirm;
char search_id[20], search_name[50];

do{
found=0;
printf("\n=======================================\n");
printf("WELCOME TO OUR DELETE ASSET INTERFACE\n");
printf("==========================================");
printf("\n1. Asset identity number\n");
printf("2. Asset name\n");
printf("3. Exit\n");
printf("_____________________________________________\n");
printf("Enter your choice to search: ");
if(scanf("%d", &choice)!=1 || choice<=0 || choice>3) {
while(getchar()!='\n');
choice=0;
}
printf("_____________________________________________\n");

while(getchar()!='\n');

switch(choice) {
case 1:do{
printf("Enter asset ID number to search: ");
fgets(search_id, sizeof(search_id), stdin);
search_id[strcspn(search_id, "\n")]='\0';

if(!ValidateAssetID(search_id)) {
printf("Invalid the ID number you want to search entered. Please try again.\n");
}
}while(!ValidateAssetID(search_id));

for(i=0; i<asset_end; i++) {
if(strcmp(search_id, asset_id[i])==0) {
found=1;
break;
}
}
break;
case 2:do{
printf("Enter asset name to search: ");
fgets(search_name, sizeof(search_name), stdin);
search_name[strcspn(search_name, "\n")]='\0';

if(!ValidateAssetID(search_name)) {
printf("Invalid the asset name you want to search entered. Please try again.\n");
}
}while(!ValidateAssetID(search_name));

for(i=0; i<asset_end; i++) {
if(strcmp(search_name, asset_name[i])==0) {
found=1;
break;
}
}
break;
case 3:printf("Thanks for intracting with our interface.Goodbey\n");return;
default: printf("Invalid choice entered. Please try again.\n");continue;
}

if(found) {
printf("\n=============================\n");
printf("Asset records Found in asset database.\n");
printf("===============================\n");
PrintAsset(i);
printf("<><><><><><><><><><><><><><>\n");
printf("Do you really want to delete asset records? \n");
printf("Enter Y or y to delete or any key to not: ");
scanf(" %c", &confirm);
if(confirm=='Y' || confirm=='y') {
for(j=i; j<asset_end-1; j++) {
strcpy(asset_id[j], asset_id[j+1]);
strcpy(asset_name[j], asset_name[j+1]);
strcpy(asset_type[j], asset_type[j+1]);
strcpy(asset_department[j], asset_department[j+1]);
strcpy(asset_condition[j], asset_condition[j+1]);
purchase_value[j]=purchase_value[j+1];
}
asset_end--;
asset_start=asset_end;
printf("You have successfully deleted the asset records.\n");
return;
}else {
printf("No changes were made.\n");
}
}else {
printf("Assset records not found in the asset database.\n");
}

attempt++;
if(attempt>4) {
printf("You have reached maximum search attempt. Please try again later.\n");
return;
}
}while(!found);

return;
}
void AssetMenu() {
int choice=0;

do{
printf("\n========================================\n");
printf("WELCOME TO ASSETS MANAGEMENT SYSTEM.\n");
printf("==========================================\n");
printf("\n1. Add asset records\n");
printf("2. Display assets\n");
printf("3. Search asset\n");
printf("4. Update asset\n");
printf("5. Delete asset\n");
printf("6. Return to menu\n");
printf("\n-----------------------------------------------------------------\n");
printf("Enter your choice: ");
if(scanf("%d", &choice)!=1 || choice<=0) {
while(getchar()!='\n');
choice=0;
}
printf("_______________________________________________\n");

switch(choice) {
case 1: AddAsset(); break;
case 2: DisplayAsset(); break;
case 3: SearchAsset(); break;
case 4: UpdateAsset(); break;
case 5: DeleteAsset(); break;
case 6: printf("Returning to MENU..........................\n"); return;
default: printf("Invalid choice entered. Please try again.\n");
}
}while(choice!=6);

return;
}






