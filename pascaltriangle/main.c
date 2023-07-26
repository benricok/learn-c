#include <stdio.h>

int binomialCoeff(int n, int k);

int main() {
    int rows = 7;

    for (int line = 0; line < rows; line++ ) {
        for (int i = 0; i <= line; i++) {
            printf("%d ", binomialCoeff(line, i));
        }
        printf("\n");
    }
    return 0;
}

int binomialCoeff(int n, int k) {
    int x = 1;
    k = n - k;
    
    for (int i = 0; i < k; ++i) {
        x *= (n - i);
        x /= (i + 1);
    }
    return x;
}