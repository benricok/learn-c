#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLASS_SIZE 4

typedef struct {
    int studentNR;
    float Grade;
} student;

student class[CLASS_SIZE];

char option; 

// Prototypes
void PopstudentMarks(student* class, int size);
void DisplayCertainMarks(student* class, int size);
void delay(unsigned long milliseconds);

int main()
{
    while (1) {
        char option = '0';

        printf("\nWhat do you want to do:\n"
               "1) Populate student marks\n"
               "2) Display certain marks\n"
               "Q) Quit\n"); 
        scanf("%c", &option);
        
        switch (option) {
            case '1': 
                printf("Option 1 was chosen\n");
                PopstudentMarks(class, CLASS_SIZE);
                break;
            case '2':
                printf("Option 2 was chosen\n");
                DisplayCertainMarks(class, CLASS_SIZE);
                break;
            case 'Q':
                return EXIT_SUCCESS;
                break;
            default:
                printf("ERR: invalid option\n");
                break;
        }
        delay(1000);
    }
}

void PopstudentMarks(student* class, int size) {
    for (int i = 0; i < size; i++) {
        printf("Please enter in the student number for student %d:", i+1);
        scanf("%d", &class[i].studentNR);
        printf("Please enter in the student grade:");
        scanf("%f", &class[i].Grade);
    }
}

void DisplayCertainMarks(student* class, int size) {
    float min = 0.0;
    printf("Please enter in the minimum grade you want to see: ");
    scanf("%f", &min);

    printf("Student ID %9sGrade", "");
    for (int i = 0; i < size; i ++) {
        if (class[i].Grade >= min) {
            printf("%d%12s%0.1f", class[i].studentNR, "", class[i].Grade);
        }
    }
}

void delay(unsigned long milliseconds) {
    long pause;
    clock_t now,then;

    pause = milliseconds * (CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
