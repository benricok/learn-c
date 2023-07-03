#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_BUFF 50 

float getNextNum(char *arr, int size, int *lastIndex); 

#define debug(name, fmt, ...) \
  fprintf(stderr, "\033[0;34m DEBUG %s[%d] %s() - " name " - " fmt "\n\033[0m", \
          __FILE__, \
          __LINE__, \
          __func__, \
          ##__VA_ARGS__)

int main() {
  char input[MAX_BUFF], expression[MAX_BUFF] = "";
  int exLenth = 0;
  int curIndex = 0;
  float numA = 0.0;

  printf("Super Simple C Calculator\n");
  printf("Enter your expression:\n"); 

  // Get input
  gets(input);
  
  // Check if expression starts with a number
  if ((int)input[0] == 0 || !(47 < (int)input[0] && (int)input[0] < 58)) { 
    fprintf(stderr, "\033[0;31mWARNING: Your expression has to start with a number\n\033[0m");
    return 1;
  }
  
  // Filter expression for only allowed characters and remove spaces
  for (int i=0; i < MAX_BUFF; i++) 
  {
    // Exit on buffer end
    if ((int)input[i] == 0) { break; };
    
    // Copy characters (, ), *, +, -, ., /, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    // Convert , to . for numbers with decimals 
    if (39 < (int)input[i] && (int)input[i] < 58) {
      if ((int)input[i] == 44) { 
        expression[exLenth] = 46;
      } else {
        expression[exLenth] = input[i];
      }
      exLenth++;
    }  
  }

  debug("Filtered Expression","%s", expression);
  debug("Expression Length", "%d", exLenth);
  
  numA = getNextNum(expression, exLenth, &curIndex);

  return 0;
}

float getNextNum(char *arr, int size, int *lastIndex) { 
  float f;
  char buf[MAX_BUFF] = "";
  for (int i = 0; i < size; ++i) 
  {
    if ((47 < (int)arr[i] && (int)arr[i] < 58) || (int)arr[i] == 46) { 
      buf[i] = arr[i]; 
    } else { 
      *lastIndex = i;
      break; 
    }; 
  }
  debug("Buf", "%s", buf);
  sscanf(buf, "%f", &f);
  debug("Double Num", "%f", f);
  return f;
}