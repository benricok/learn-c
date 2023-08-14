#include <stdio.h>

int main() {
  int max = 14;

  for (int i = 1; i < max; i++) {
    for (int k = 1; k <= max-i; k++) {
      printf(" ");
    }

    for (int j = 1; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}

