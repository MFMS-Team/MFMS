#include <stdio.h>
#include "report.h"
int main() {
int choice=0;

do{
printf("\n======================================\n");
printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM.\n");
printf("========================================\n");
printf("\n1. Employee Management\n");
printf("2. Budget Management.\n");
printf("3. Supplier Management.\n");
printf("4. Asset Management.\n");
printf("5. Reports.\n");
printf("6. Exit.\n");
printf("   \n");
printf("\n_____________________________________________\n");
printf("Enter your choice:");
if(scanf("%d", &choice)!=1 || choice<=0) {
while(getchar()!='\n');
choice=-1;
} 
printf("<><><><><><><><><><><><><><><>><><><><><><>\n");

switch(choice) {
case 1:EmployeeMenu() ; break;
case 2:BudgetMenu(); break;
case 3:SupplierMenu(); break;
case 4:AssetMenu(); break;
case 5:ReportMenu(); break;
case 6:printf("Thanks for interacting with our interface.Goodbey.\n"); break;
default: printf("Invalid choice entered.\n");break;
}
}while(choice!=6);
return 0;
}