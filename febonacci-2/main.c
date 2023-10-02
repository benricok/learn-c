#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}

int feb(int a) {
    if (a == 0) {
        return 1;
    } else if (a == 1) {
        return 1;
    } else {
        return feb(a) + feb(a-1);
    }

}
