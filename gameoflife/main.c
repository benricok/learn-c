#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define row 70
#define col 300

#define delay 200000

int aliveNeighbours(int a[row][col], int r, int c); 

int main()
{
    int a[row][col], b[row][col];
    int rnd = 0, liveCells = 0;
 
    srand(time(NULL));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            rnd = rand() % 100;
            if(rnd < 15) { 
                a[i][j] = 1; 
            } else { 
                a[i][j] = 0; 
            }
        }
    }

    clock_t startTime = clock();

    while (true) {
        if (clock() > startTime + delay) {
            printf("\e[1;1H\e[2J");

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    (a[i][j]) ? printf("#") : printf(" ");
                }
                printf("\n");
            }

            for (int i = 0; i < row; i++) {
                for (int j = 0 ; j < col; j++) {
                    liveCells = aliveNeighbours(a, i, j);

                    if(a[i][j] == 1 && (liveCells == 2 || liveCells == 3)) {
                        b[i][j] = 1;
                    } else if(a[i][j] == 0 && liveCells == 3) {
                        b[i][j] = 1;
                    } else {
                        b[i][j] = 0;
                    }
                }
            }
            memcpy(a, b, sizeof b);
            startTime = clock();
        }
    }
    return EXIT_SUCCESS;
}

int aliveNeighbours(int a[row][col], int r, int c) {
    int count = 0;

    for (int i = r-1; i <= r+1; i++) {
        for (int j = c-1; j <= c+1; j++) {
            if ((i == r && j == c) || (i < 0 || i < 0 ) || (i >= row || i >= col)) {
                continue;
            }
            if (a[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}
