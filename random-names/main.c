#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

char * names[] = { "name1", "name2", "name3", "name4", "name5", "name6", "name7", "name8", "name9", "name10", "name11" };

int order[11];

int main(/*int argc, char *argv[]*/)
{
    int rnd = 12;
    bool exist = false;
    
    srand(time(NULL));

    for (int idx = -1; idx < 11; ) {
        // random num 0 - 11
        rnd = random() % 12;
        
        for (int i = 0; i <= idx; i++) {
            exist = (order[i] == rnd);
        }
        if (!exist) { order[idx++] = rnd; }
    }   

    for (int i = 0; i < 12; i++) {
        printf("\n%s", names[order[i]]);
    }
    
    return EXIT_SUCCESS;
}
