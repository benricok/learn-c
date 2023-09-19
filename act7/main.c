#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 20

void loop();
void display(char a[HEIGHT][WIDTH]);
void calcProjectile(char a[HEIGHT][WIDTH], int s1, int a1, int s2, int a2);
void setup(char a[HEIGHT][WIDTH]);

char a[HEIGHT][WIDTH];

int main() {
    
    loop();

    printf("Enter 1 to try again, 0 to exit.\n");
    scanf("%d", b);

    if (b == 0) {
        return EXIT_SUCCESS;
    } else {
        loop();
    }
}

void loop() {
    int firstLaunchSpeed, secondLaunchSpeed, firstLaunchAngle, secondLaunchAngle, b; 
    setup(a);
    printf("Projectile Trajectory Display:\n");

    printf("First Launch Speed (m/sec)? ");
    scanf("%d", &firstLaunchSpeed);
    printf("\nSecond Launch Speed (m/sec)? ");
    scanf("%d", &secondLaunchSpeed);

    printf("\nFirst Launch Angle (deg)? ");
    scanf("%d", &firstLaunchAngle);
    printf("\nSecond Launch Angle (deg)? ");
    scanf("%d", &secondLaunchAngle);

    calcProjectile(a, firstLaunchSpeed, firstLaunchAngle, secondLaunchSpeed, secondLaunchAngle);

    display(a);
}

void setup(char a[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {

        for (int j = 0; j < WIDTH; j++) {

            a[i][j] = ' ';

            if (i == 0 || i == HEIGHT-1) {
                a[i][j] = '-';
            }

            if (j == 0 || j == WIDTH-1) {
                a[i][j] = '|';
            }
        }
    }
}

void calcProjectile(char a[HEIGHT][WIDTH], int s1, int a1, int s2, int a2) {
    
}

void display(char a[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}