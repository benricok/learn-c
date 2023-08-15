#include<stdio.h>
int main()
{
    int arr[6]= {12,5,10,9,7,6};
    int temp;
    
    for(int i=0; i<6; i++) {
        printf("%d ",arr[i]);
    }
    
    for(int i=0; i<6; i++) {
        for(int j=i+1; j<6; j++) { 
            if(arr[i]>arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\n\n");
    for(int i=0; i<6; i++) {
        printf("%d ",arr[i]);
    }

    return 0;
}