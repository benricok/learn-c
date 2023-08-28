#include <stdio.h>

/* Picking out command line options into a list of option letters;
this is an example of how it might by typically done by an
experienced codes, but it makes it very much more difficult for
the newcomer to follow with all the ** and ++ stuff! */

int main(int argc, char **argv) {

        char optable[40]; /* for options */
        int optcount = 0;

        while (argc) {
                printf("We have %s\n", *argv);
                if (**argv == '-') {
                        while (*++*argv != '\0') {
                                printf("Option is %d\n",**argv);
                                optable[optcount++] = **argv;
                        }
                }
                ++argv; --argc;
        }
        optable[optcount] = '\0';
        printf("Option list %s\n",optable);
}
