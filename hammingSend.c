#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int flag, len, bit;
    
    // *************START CODE FOR Hamming SENDER ************//
    char data[100];
    int data1[100], data2[100];
    int dl, r, i, j, k, z, c;
    char buf[100];

    memset(data, '\0', 100);
    printf("\nEnter the data:\n");  
    scanf("%s", data);

    dl = strlen(data);
    i = 0;

    // Calculate the number of parity bits 'r' required
    while (1) {
        if (pow(2, i) >= i + dl + 1) 
            break;
        i++;    
    }
    r = i;
    printf("\nNumber of parity bits (r) is: %d\n", r);

    // Convert input data (string) into integer array
    for (i = 0; i < dl; i++) {
        data1[i] = data[i] - 48;    
    }

    // Initialize data2 with 999 at positions corresponding to powers of 2
    for (i = 0; i < r; i++) {
        z = pow(2, i);
        data2[z] = 999;
    }

    // Copy the data into data2, skipping parity bit positions
    j = 0;
    for (i = dl + r; i >= 1; i--) {
        if (data2[i] != 999) {
            data2[i] = data1[j];
            j++;
        }    
    }

    // Calculate parity bits
    for (i = 0; i < r; i++) {
        z = pow(2, i);
        c = 0;
        for (j = z; j <= dl + r; j = z + k) {
            for (k = j; k < z + j; k++) {
                if (k <= r + dl)
                    if (data2[k] != 999)
                        c = c + data2[k];
            }
        }
        data2[z] = c % 2;
    }

    // Print the final Hamming codeword
    printf("\nFinal codeword is: \n");
    j = 0;
    for (i = dl + r; i >= 1; i--) {
        printf("%d ", data2[i]);
        buf[j] = data2[i] + 48;
        j++;
    }
    // *************END CODE FOR Hamming SENDER ************//

    return 0;
}
