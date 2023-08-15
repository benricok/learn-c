#include <stdio.h>

int calc_middle(int n1, int n2, int n3);

int main() {
    printf("\n\n%d", calc_middle(67,-5,3));

    return 0;
}

int calc_middle(int n1, int n2, int n3) {
    int temp;

    if (n2 < n1) {
        temp = n2;
        n2 = n1;
        n1 = temp;
    }
    if (n3 < n2) {
        temp = n3;
        n3 = n2;
        n2 = temp;
    }
    
    if (n2 < n1) {
        temp = n2;
        n2 = n1;
        n1 = temp;
    }
    return n2;
}