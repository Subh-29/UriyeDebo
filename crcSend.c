#include <stdio.h>
#include <string.h>

int main() {
    char dataCopy[100], div[20], rem[100], data[100];
    int divlen = 0, datalen = 0;
    printf("Enter the dataCopy to be sent: ");
    scanf("\n%s", &data);
    datalen = strlen(data);
    strcpy(dataCopy, data);
    printf("Enter the divisior: ");
    scanf("\n%s", &div);
    divlen = strlen(div);
    for(int i = 0; i < divlen - 1; ++i) {
        dataCopy[datalen + i] = '0';
    }
    dataCopy[datalen + divlen - 1] = '\0';
    printf("Appended dataCopy: ");
    printf("%s\n", dataCopy);
    for(int i = 0; i <= datalen; i++) {
        if(dataCopy[i] == '1') {
            printf("Yes 1\n%s\n", dataCopy);
            for(int j = 0; j < divlen; j++) {
                if(dataCopy[i + j] == div[j]) {
                printf("Yes xor\n%s\n", dataCopy);
                    rem[j] = '0';
                }
                else {
                    printf("Not xor\n%s\n", dataCopy);

                    rem[j] = '1';
                }
                printf("Rem: %s\n", rem);
            }
            rem[divlen] = '\0';
            for(int k = 0; k < divlen; k++) {
                dataCopy[i+k] = rem[k];
            }
        }
        else {
            for(int k = 0; k < divlen; ++k) {
                rem[k] = dataCopy[i + k];
            }
        }
    }
   
    //rem[divlen] = dataCopy[datalen+divlen-1]; // Null-terminate the remainder string
    rem[divlen] = '\0';
    printf("Reminder: %s\n", rem);
    for(int i = 0; i < divlen - 1; ++i) {
        data[datalen + i] = rem[i+1];
    }
    printf("Sent data: %s", data);
}