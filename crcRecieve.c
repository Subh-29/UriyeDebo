#include <stdio.h>
#include <string.h>

int main() {
    char data[100], dataCopy[100], div[20], rem[20];
    int datalen = 0, divlen = 0;
    printf("Enter the data: ");
    scanf("%s", data);
    printf("Enter divisior: ");
    scanf("%s", div);
    datalen = strlen(data);
    divlen = strlen(div);
    strcpy(dataCopy, data);
    for(int i = 0; i < divlen - 1; ++i) {
        dataCopy[datalen + i] = '0';
    }
    dataCopy[datalen + divlen - 1] = '\0';

    printf("Appended data: %s\n", dataCopy);
    for(int i = 0; i < datalen; ++i) {
        if(dataCopy[i] == '1') {
            for(int j = 0; j < divlen; ++j) {
                rem[j] = (dataCopy[i + j] == div[j]) ? '0' : '1';
            }
            rem[divlen] = '\0';
            for(int k = 0; k < divlen; ++k) {
                dataCopy[k + i] = rem[k];
            }
            //printf("%s\n", rem);
        }
        else {
            for(int k = 0; k < divlen; ++k) {
                rem[k] = dataCopy[i + k];
            }
        }
    }
    rem[divlen] = '\0';

    for(int i = 0; i < divlen; ++i) {
        if(rem[i] != '0') {
            printf("Data has error\n");
            return 0;
        }
    }

    printf("Data has no error");
    return 0;

    // for(int i = 0; i < divlen; ++i) {
    //     rem[i] = rem[i+1];
    // }
    // rem[divlen - 1] = '\0';
    // printf("Remainder: %s\n", rem);
    // strcat(data, rem);
    // printf("Data: %s\n", data);
}