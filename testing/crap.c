#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_BUFF 50

#define debug(name, fmt, ...) \
  fprintf(stderr, "\033[0;34m DEBUG %s[%d] %s() - " name " - " fmt "\n\033[0m", \
          __FILE__, \
          __LINE__, \
          __func__, \
          ##__VA_ARGS__)

double getNextNum(char *arr, int size, int *lastIndex); 

int main() {
  char input[50], expression[50] = "";
  int expressionLength, prevIndex, lastIndex = 0;
  double lastNum = 0;

  printf("Super Simple C Calculator\n");
  printf("Enter your expression:\n"); 
  
  gets(input);
  //if ((int)input[0] == 0 || !(47 < (int)input[0] && (int)input[0] < 58)) { 
  //  fprintf(stderr, "\033[0;31mWARNING: Your expression has to start with a number\n\033[0m");
  //  return 1;
  //}
  /*
  for (int i=0; i < 50; i++) 
  {
    //if ((int)input[i] == 0) { break; };
    debug("Input", "%s", input);
    if ((39 < (int)input[i]) || ((int)input[i] < 58) || 1) {
      expression[prevIndex] = input[i];
      prevIndex++;
      debug("In Loop","%s", expression);
    }  
  }*/
  debug("input", "%s", input);
  for (int i=0; i<50; i++) {
    if (39 < (int) input[i] && (int) input[i] < 58) {
      expression[prevIndex] = input[i];
      prevIndex++;
    }  
  }
  printf("\nYou entered: \n %s", expression);
  //expressionLength = prevIndex;
  //debug("Expression", "%s", expression);
    
  //lastNum = getNextNum(expression, expressionLength, &lastIndex);

  /*
  for (int i = 0; i <= expressionLength; ++i) 
  {
    switch (expression[i]) {
      case '0' ... '9':
        
        break;
      case '(' ... '/':

        break;
      default:
          fprintf(stderr, "WARNING: Characters found in expression that are not allowed");
          return 1;
        break;
    }
  }
  */
  return 0; 
}

double getNextNum(char *arr, int size, int *lastIndex) { 
  double num;
  char buff[MAX_BUFF];
  for (int i = 0; i < size; ++i) 
  {
    if (47 < (int)arr[i] && (int)arr[i] < 58) { 
      buff[i] = arr[i]; 
    } else { 
      *lastIndex = i;
      break; 
    }; 
  }
  debug("Buff", "%s", buff);
  sscanf(buff, "%f", &num);
  debug("Double Num", "%f", num);
  return num;
}


