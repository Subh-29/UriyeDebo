#include <stdio.h>
#include <string.h>

int checkError(const char* binary, const char parity) {
    int count = 0;
    char parity_bit;
    for(int i = 0; i < strlen(binary); ++i) {
        if(binary[i] == 1) {
            ++count;
        }
    }

    if(parity == 'e') {
        parity_bit = (count % 2 == 0) ? '0' : '1';
    }
    else if(parity == 'o') {
        parity_bit = (count % 2 == 0) ? '1' : '0';
    }
    else {
        return -1;
    }

    return parity_bit == binary[strlen(binary) - 1];
}

int main() {
    char binary[100], parity;
    printf("Enter encoded data: ");
    scanf("%s", &binary);
    printf("Enter parity choice: ");
    scanf("\n%c", &parity);
    if(checkError(binary, parity)) {
        printf("Data is error free!\n");
    }

    else if (!checkError(binary, parity))
    {
        printf("Data has error!\n");
    }

    else {
        printf("Data is corrupted!\n");
    }
    
}