#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    const char NAME[] = "John";
    int age;
    const double AVERAGE = 82.4;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Hello, this is %s\n", NAME);
    printf("I'm %d years old\n", age);
    printf("My final average was %f\n", AVERAGE);

    age = 22;
    printf("%s %d %f\n", NAME, age, AVERAGE);

    printf("%f\n", 6.0 / 5 * 4);

    printf("%f\n", pow(2,3));
    printf("%f\n", sqrt(36));
    printf("%f\n", floor(3.4));
    printf("%f\n", ceil(3.4));

    char string[20];
    fgets(string, 20, stdin);
    printf("%s", string);

    return 0;
}     
