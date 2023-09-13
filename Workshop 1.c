#include <stdio.h>

int main() {
	int n;
    printf("Enter an integer number: ");
    scanf("%d", &n);
    
    int i1, S1 = 0;
    for (i1 = 1; i1 <= n; i1++) {
    	S1 += i1;
	}
    printf("1+2+...+n = %d\n", S1);

    int i2, S2 = 1;
     for (i2 = 1; i2 <= n; i2++) {
        S2 *= i2;
    }
    printf("n! = %d\n", S2);

    int i3;
	float S3 = 0.0;	
	for (i3 = 1; i3 <= n; i3++) {
		S3 += 1.0 / i3;
    }
    printf("1+1/2+...+1/n = %f\n", S3);
}