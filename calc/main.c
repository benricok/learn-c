#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {
  char input[49];
  char expression[49] = "";
  int prevIndex = 0;
  printf("Super Simple C Calculator");
  printf("Enter your expression:\n"); 
  gets(input);
  for (int i=0; i<50; i++) {
    if (39 < (int) input[i] && (int) input[i] < 58) {
      expression[prevIndex] = input[i];
      prevIndex++;
    }  
  }
  printf("\nYou entered: \n %s", expression);
}



