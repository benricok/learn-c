#include <stdio.h>

int main() {
  int max = 8;

  for (int i = 0; i < max; i++) {
    for (int j = 0; j < i; j++) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
