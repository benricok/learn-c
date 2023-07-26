#include <stdio.h>

int main() {
    int prev1, prev2, new;
    int max = 14;
    prev1 = 1;
    prev2 = 1;

    for (int i = 0; i < max; i++) {
        printf("%d\n", prev1);
        new = prev1 + prev2;
        prev1 = prev2;
        prev2 = new;
    }
    return 0;
}