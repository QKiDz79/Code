#include <stdio.h>

int isPrime(int num) {
    if (num < 2)
        return 0;
        
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0)
            return 0;
    }
    
    return 1;
}

void displayPrimes(int low, int high, int perRow) {
    int primeCount = 0;
    int num = low;
    
    while (num <= high) {
        if (isPrime(num)) {
            printf("%d\t", num);
            primeCount++;
            
            if (primeCount % perRow == 0)
                printf("\n");
        }
        
        num++;
    }
}

int main() {
    int count, low, high, perRow;
    
    printf("Table of Primes\n");
    printf("===============\n");
    
	printf("Lower limit: ");
    scanf("%d", &low);
    
    printf("Upper limit: ");
    scanf("%d", &high);
    
    printf("# of columns: ");
    scanf("%d", &perRow);
    
    printf("\nPrime numbers:\n");
    displayPrimes(low, high, perRow);
    
    return 0;
}