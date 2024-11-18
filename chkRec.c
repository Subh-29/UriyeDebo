#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[100], b[100], sum[100], wsum[100], chksum[100], carry = 0, n = 0;
    printf("Enter number of bits in each segment: ");
    scanf("%d", &n);
    printf("For 1st seg enter:\n");
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    printf("For 2nd seg enter:\n");
    for(int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }

    for(int i = 0; i < n; ++i) {
        sum[i] = (a[i] + b[i] + carry) % 2;
        carry = (a[i] + b[i] + carry) / 2;
    }
    int p = 0;
    for(int i = 0; i < n; ++i) {
        p = (sum[i] + carry) % 2;
        carry = (sum[i] + carry) / 2;
        sum[i] = p;
    }

    for(int i = 0; i < n; ++i) {
        wsum[i] = sum[i];
    }
    printf("\nWrap sum: ");
    for(int i = 0; i < n; ++i) {
        printf("%d, ", wsum[i]);
    }

    for(int i = 0; i < n; ++i) {
        chksum[i] = (wsum[i] == 1) ? 0 : 1;
    }

    printf("\nCheck sum: ");
    for(int i = 0; i < n; ++i) {
        printf("%d ", chksum[i]);
    }
}