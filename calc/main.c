#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_BUFF 50 

float getfloat(char *arr, int size, int *ptr); 


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
  float valA = 0.0, valB = 0.0;

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
  
  if (curIndex < exLenth) {
    debug("Current Index", "%d", curIndex);
    valA = getfloat(expression, exLenth, &curIndex);
    debug("Current Index", "%d", curIndex);
  }

  return 0;
}

float getfloat(char *arr, int size, int *ptr) { 
  float f;
  int d = 0;
  char buf[MAX_BUFF] = "";
  bool isFloat = false;

  for (int i = *ptr; i < size; ++i) 
  {
    if (i == size-1) {*ptr = i+1;};
    // Copy number characters to buffer
    if (47 < (int)arr[i] && (int)arr[i] < 58) {
      buf[i] = arr[i];
    } else if (arr[i] == '.' && !isFloat) {
      isFloat = true;
      buf[i] = arr[i];
    } else {
      *ptr = i+1;
      break;
    }
  }
  debug("Buf value", "%s", buf);
  (isFloat) ? sscanf(buf, "%f", &f) : sscanf(buf, "%d", &d);
  f += d;
  debug("Float value", "%f", f);
  return f;
}
