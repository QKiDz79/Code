/*
Assignment 1 - Income tax
Class ID : IA1807
Student ID : HE180119
Student Name : Nguyễn Thuỵ Quân
Due Date :
I declare that this assignment is my own work
in accordance with FPT Policy.
*/

#include <stdio.h>

float calculateTax(float income) {
    float tax;
    
    if (income <= 5000) {
        tax = 5;
    } else if (income <= 10000) {
        tax = 10;
    } else if (income <= 18000) {
        tax = 15;
    } else if (income <= 32000) {
    	tax = 20;
	} else if (income <= 52000) {
		tax = 25;
	} else if (income <= 80000) {
		tax = 30;
	} else { 
        tax = 35;
    }
    return tax;
}

void clear_input_buffer() {
    int v;
    while ((v = getchar()) != '\n' && v != EOF);
}

int main() {
	
	while (1) {
        printf("Choose one of the following options:\n");
        printf("1. Tax calculator\n");
        printf("0. Exit\n");

        int selection;
        printf("Your selection (0 -> 1): ");
        if (scanf("%d", &selection) != 1) {
            printf("Invalid input, try again.\n");
            clear_input_buffer();
            continue;
        }

        if (selection == 0) {
            printf("Exiting...\n");
            exit(0);
        } else if (selection == 1) {
            break;
        }
	}
	
    float income;
    
    printf("Income Tax Calculator\n");
    printf("=====================\n");
    printf("Enter your income:\n");
    printf("Income for the current month (in thousand VND):");
    scanf("%f", &income);
    float tax = calculateTax(income);
    
	char pension;
    float a;
do {
        printf("Pension contributions (5%%) y/n? ");
        scanf(" %c", &pension);

        if (pension == 'y' || pension == 'Y') {
            a = 5;
            break;  // Exit the loop if 'Y' or 'y' is pressed
        } else if (pension == 'n' || pension == 'N') {
            a = 0;
            break;  // Exit the loop if 'N' or 'n' is pressed
        } else {
            printf("You must press 'Y' or 'N' only. Please try again.\n");
        }
    } while (1);
    
    char health;
    float b;
do	{
		printf("Health insurance (1%) y/n ? ");
        scanf(" %c", &health);

        if (health == 'y' || health == 'Y') {
            b = 1;
            break;  // Exit the loop if 'Y' or 'y' is pressed
        } else if (health == 'n' || health == 'N') {
            b = 0;
            break;  // Exit the loop if 'N' or 'n' is pressed
        } else {
            printf("You must press 'Y' or 'N' only. Please try again.\n");
        }
    } while (1);
    
    float c;
	printf ("Number of dependants < 18 years old: ");
    while (scanf("%f", &c) != 1) {
        // Clear the input buffer
        while (getchar() != '\n');
        
        printf("Invalid input. Please enter a number: ");
    }
	
	float d;
	printf ("Gift of charity: ");
    while (scanf("%f", &d) != 1) {
        // Clear the input buffer
        while (getchar() != '\n');
        
        printf("Invalid input. Please enter a number: ");
    }
	
	
    float grossIncome = income;
    float personalAllowance = 4000.0;
    float pensionContributions = income * ( a / 100 );
    float healthInsurance = income * ( b / 100);
    float dependant = c * 1600.0;
    float charity = d;
    float total = personalAllowance + pensionContributions + healthInsurance + dependant + charity;
    float taxableIncome = grossIncome - total;
    float Tax = (tax/100) * taxableIncome;
    float netIncome = grossIncome - Tax;
    
    
	printf("\nGross Income: %.1f\n", grossIncome);
	printf("Deduction\n");
	printf("  Personal allowance: %.1f\n", personalAllowance);
    printf("  Pension contributions: %.1f\n", pensionContributions);
    printf("  Health insurance: %.1f\n", healthInsurance);
    printf("  Dependant: %.1f\n", dependant);
    printf("  Charity: %.1f\n", charity);
    printf(" ----------------------------------\n");
    printf("Total: %.1f\n", total);
    printf("Taxable Income: %.1f\n", taxableIncome);
    printf("Tax: %.1f\n", Tax);
    printf("Net Income: %.1f\n", netIncome);

	return 0;
}