#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#define DEBUG_ENABLED 1
#define MAX_BUFF 50

#define debug(name, fmt, ...) \
  do { \
    if (DEBUG_ENABLED) { \
      fprintf(stderr, "\033[0;34m DEBUG %s[%d] %s() - " name ": " fmt "\n\033[0m", \
              __FILE__, \
              __LINE__, \
              __func__, \
              ##__VA_ARGS__); }; \
  } while (0)

float getfloat(char *arr, int size, int *ptr);
enum MathOperator getOperator(char *arr, int *ptr);
float calc(float a, float b, enum MathOperator OPERATOR);

enum MathOperator { MULTIPLY, DEVIDE, PLUS, MINUS, NONE };

int main(int argc, char *argv[]) {
  printf("\033[0;33mSuper Simple C Calculator\nEnter a mathmatical expression: \033[0m");
  char input[MAX_BUFF], expression[MAX_BUFF] = "";
  int exLenth = 0;
  fgets(input, MAX_BUFF, stdin);
  printf("\n");

  // Check if expression starts with a number
  if ((int)input[0] == 0 || !(47 < (int)input[0] && (int)input[0] < 58)) {
    fprintf(stderr, "\033[0;31mWARNING: Your expression has to start with a number\n\033[0m");
    return 1;
  }

  // Filter expression for only allowed characters and remove spaces
  for (int i = 0; i < MAX_BUFF; i++)
  {
    // Exit on buffer end
    if ((int)input[i] == 0) { break; };

    // Copy characters (, ), *, +, -, ., /, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    if (39 < (int)input[i] && (int)input[i] < 58)
    {
      // Convert , to . for numbers with decimals
      if ((int)input[i] == 44) {
        expression[exLenth] = 46;
      } else {
        expression[exLenth] = input[i];
      }
      exLenth++;
    }
  }

  int curIndex = 0;
  int indexState = 0;
  float valA = 0.0, valB = 0.0;
  enum MathOperator operator;

  debug("Filtered Expression","%s", expression);
  debug("Expression Length", "%d", exLenth);

  for (; curIndex < exLenth-1;) {
    debug("Current Index", "%d", curIndex);
    switch (indexState) {
      case 0:
        valA = getfloat(expression, exLenth, &curIndex);
        indexState++;
        break;
      case 1:
        operator = getOperator(expression, &curIndex);
        indexState++;
        break;
      case 2:
        valB = getfloat(expression, exLenth, &curIndex);
        valA = calc(valA, valB, operator);
        indexState++;
        break;
      case 3:
        operator = getOperator(expression, &curIndex);
        indexState = 2;
        break;
      default:
        break;
    }
  }

  printf("\n\033[0;32mResult: %f\n\n\033[0m", valA);
  return 0;
}

// Convert char array of float or integer type to float
// Note: ignores multiple decimal indicators '.'
float getfloat(char *arr, int size, int *ptr) {
  char buf[MAX_BUFF] = "";
  bool isFloat = false;
  float f = 0.0;
  int d = 0, j = 0;

  for (int i = *ptr; i < size; ++i)
  {
    if (i == size-1) { *ptr = i; };                // FIX

    // Copy number characters to buffer
    if (47 < (int)arr[i] && (int)arr[i] < 58) {
      buf[j] = arr[i];
      ++j;

    } else if (arr[i] == '.' && !isFloat) {
      isFloat = true;
      buf[j] = arr[i];
      ++j;

    } else if (arr[i] == '.' && isFloat) {
      ++j;

    } else {
      *ptr = i;
      break;
    }
  }

  debug("Buf value", "%s", buf);
  (isFloat) ? sscanf(buf, "%f", &f) : sscanf(buf, "%d", &d);
  return f + d;
}

enum MathOperator getOperator(char *arr, int *ptr) {
  debug("Operator", "%c", arr[*ptr]);
  int i = *ptr;
  *ptr = *ptr + 1;
  switch(arr[i]) {
    case '*':
      return MULTIPLY;
    case '/':
      return DEVIDE;
    case '+':
      return PLUS;
    case '-':
      return MINUS;
    default:
      return NONE;
  }
}

float calc(float a, float b, enum MathOperator OPERATOR) {
  switch (OPERATOR) {
    case MULTIPLY:
      return a * b;
    case DEVIDE:
      return a / b;
    case PLUS:
      return a + b;
    case MINUS:
      return a - b;
    default:
      if (a != 0) { return a; } else { return 0.0; };
      break;
  }
}
