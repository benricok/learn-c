#include <stdio.h>
#include <stdlib.h>

#define MAXNAME 20

typedef struct {
    int id, mark;
    char name[MAXNAME];
} Student;

double calcAverage(Student* class,int size); 

int main(int argc, char *argv[])
{
    int countStudents = 0;
    printf("Enter the amount of students in the class:\n");
    scanf("%d", &countStudents);
    if (countStudents < 1) {
        return EXIT_FAILURE;
    }

    Student class[countStudents];
    
    for (int i = 0; i < countStudents; i++) {
        class[i].id = i;
        printf("\nEnter student %d's name\n", i+1); 
        fgets(class[i].name, MAXNAME, stdin);
        printf("\nEnter) the student's mark\n");
        scanf("%d", &class[i].mark);
    }
    printf("\n\nCLASS DATA:");

    for (int i = 0; i < countStudents; i++ ){
        printf("%s %d\n", class[i].name, class[i].mark);

    }
    printf("----------------------------------\n");
    printf("Average: %0.2f", calcAverage(class, countStudents));


    return EXIT_SUCCESS;
}

double calcAverage(Student* class,int size) {
    long sum = 0;

    for(int i = 0; i < size; i++) {
        sum += class[i].mark;
    }
    return sum / size;
}
