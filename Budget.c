#include <stdio.h>

int getNumberOfDepartments();
double getBudget(int dept);
double getExpenditure(int dept);
double calculateRemaining(double budget, double expenditure);
void displayDepartment(int dept, double budget, double expenditure, double remaining);
void checkExceeded(int n, double budget[], double expenditure[]);

int main() {
    int n = getNumberOfDepartments();

    double budget[n], expenditure[n], remaining[n];

    for (int i = 0; i < n; i++) {
        budget[i] = getBudget(i + 1);
        expenditure[i] = getExpenditure(i + 1);
        remaining[i] = calculateRemaining(budget[i], expenditure[i]);
    }

    printf("\n--- Municipal Budget Information ---\n");
    for (int i = 0; i < n; i++) {
        displayDepartment(i + 1, budget[i], expenditure[i], remaining[i]);
    }

    checkExceeded(n, budget, expenditure);

    return 0;
}

int getNumberOfDepartments() {
    int n;
    printf("Enter number of departments: ");
    scanf("%d", &n);
    return n;
}

double getBudget(int dept) {
    double allocated budget;

    do{
printf("Enter allocate budget: ", dept);
if(scanf("%lf", &allocated_budget)!=1 || allocated_budget<=0.00) {
printf("Invalid allocated budget entered. Please try again.\n");
while(getchar()!='\n');
allocated_budget=-1.00;
}
}while(allocated_budget<=0.00);

return allocated_budget;

}

double getExpenditure(int dept) {
    double expenditure;

do{
printf("Enter expenditure for Department %d: ", dept);
if(scanf("%lf", &expenditure)!=1 || expenditure <=0.00) {
printf("Invalid expenditure entered. Please try again.\n");
while(getchar()!='\n');
allocated_budget=-1.00;
}
}while(expenditure<=0.00);

return expenditure;

}

double calculateRemaining(double budget, double expenditure) {
    return budget - expenditure;
}

void displayDepartment(int dept, double budget, double expenditure, double remaining) {
    printf("\nDepartment %d:\n", dept);
    printf("  Budget:      %.2f\n", budget);
    printf("  Expenditure: %.2f\n", expenditure);
    printf("  Remaining:   %.2f\n", remaining);

    if (expenditure <= budget) {
        printf("  Status: Expenditure is within budget.\n");
    } else {
        printf("  Status: Exceeded budget!\n");
    }
}

void checkExceeded(int n, double budget[], double expenditure[]) {
    printf("\n--- Departments Exceeding Budget ---\n");
    int exceeded = 0;
    for (int i = 0; i < n; i++) {
        if (expenditure[i] > budget[i]) {
            printf("Department %d exceeded its budget.\n", i + 1);
            exceeded = 1;
        }
    }
    if (!exceeded) {
        printf("No department exceeded its budget.\n");
    }
}