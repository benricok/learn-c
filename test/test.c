#include <stdio.h>

int countD(char * str);

int main() {
    char x[] = "dDDd";
    char *xPtr;
    xPtr = x;
    printf("Total = %d",countD(xPtr));
}

int countD(char * str) {
    int count = 0;
    while ( *str != '\0') {
        if (*str == 'D' || *str == 'd') {
            count++;
        }
        str++;
    }
    return count;
}