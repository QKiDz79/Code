#include <stdio.h>
#include <stdbool.h>

bool validateISBN(const char *isbn) {
    int length = 0;
    const char *ptr = isbn;
    
    while (*ptr != '\0') {
        length++;
        ptr++;
    }

    if (length != 10) {
        return false;
    }

    int checksum = 0;
    for (int i = 0; i < 9; i++) {
        if (*isbn < '0' || *isbn > '9') {
            return false;
        }
        checksum += (*isbn - '0') * (10 - i);
        isbn++;
    }

    int checkDigit = *isbn == 'X' ? 10 : *isbn - '0';
    return (checksum + checkDigit) % 11 == 0;
}

int main() {
    char isbn[11];
    while (1) {
        printf("Enter an ISBN (0 to quit): ");
        scanf("%10s", isbn);

        if (strcmp(isbn, "0") == 0) {
        	printf("Have a Nice Day!");
            break;
        }

        if (validateISBN(isbn)) {
            printf("This is a valid ISBN\n");
        } else {
            printf("This is not a valid ISBN.\n");
        }
    }

    return 0;
}