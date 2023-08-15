#include <stdio.h>
#define MAX 5

int calc_middle(int n1,int n2,int n3,int n4,int n5);


int main() {
    printf("\n\n%d", calc_middle(1, 435,234,53,23));
}

int calc_middle(int n1,int n2,int n3,int n4,int n5) {
    int arr[5] = {n1,n2,n3,n4,n5};
    int temp;

    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 5; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\n");
    for (int k= 0; k < 5; k++){
        printf("%d ", arr[k]);
    }
    printf("\n");

    return arr[1];
}