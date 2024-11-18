#include <stdio.h>
#include <string.h>

int main() {
    char binary[100], parity;
    int count = 0;

    printf("Enter the binary number as a string:");
    scanf("%s", &binary);
    printf("Enter parity choice(\"e\" for even parity & \"o\" for odd parity):");
    scanf("\n%c", &parity);

    for(int i = 0; i < strlen(binary); ++i) {
        if(binary[i] == '1')
            ++count;
    }

    if(parity == 'e') {
        if(count % 2 == 0) {
            strcat(binary, "0");
        }
        else {
            strcat(binary, "1");
        }
    }
    else if(parity == 'o') {
        if(count % 2 == 0) {
            strcat(binary, "1");
        }
        else {
            strcat(binary, "0");
        }
    }

    else {
        printf("Invalid input!!\n");
    }

    printf("Encoded parity bit: %s", binary);
}