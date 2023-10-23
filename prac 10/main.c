#include <stdio.h>
#include <stdlib.h>

#define START 1
#define DESTINATION 2
#define OBSTACLE 3
#define CLEAR 0
#define PATH 4
#define SIZE 6

#define OUTPUT_FILE "solution.txt"

struct node {
    int data;
    int x_pos;
    int y_pos;
    struct node *parentPtr;
    struct node *downPtr;
    struct node *rightPtr;
};
typedef struct node Node;
typedef Node *NodePtr;

struct node *newNode(int data, int x_pos, int y_pos); 
struct node *newNode(int data, int x_pos, int y_pos) {
    // struct node* node = (struct node*)malloc(sizeof(struct node));
    struct node *node = malloc(sizeof *node);
    node->x_pos = x_pos;
    node->y_pos = y_pos;
    node->data = data;
    node->parentPtr = NULL;
    node->downPtr = NULL;
    node->rightPtr = NULL;
    return node;
}

void findStart(int *x_pos, int *y_pos);
void propagateSolution(NodePtr Ptr);
void recursiveSolve(NodePtr nodePtr);
void printSolution();

int maze[SIZE][SIZE] = {{1, 0, 0, 0, 0, 3}, {3, 0, 3, 3, 0, 3},
                        {0, 0, 0, 0, 0, 3}, {0, 3, 3, 3, 0, 3},
                        {0, 0, 0, 0, 0, 2}, {3, 3, 3, 3, 3, 3}};

int main() {
    // find start
    int x_pos;
    int y_pos;

    findStart(&x_pos, &y_pos);
    //printf("Start: (%d, %d)\n", x_pos, y_pos);

    struct node *root = newNode(START, x_pos, y_pos);
    recursiveSolve(root);
    printSolution();

    return 0;
}

void recursiveSolve(NodePtr Ptr) {
    int val_down = -1;
    if (Ptr->y_pos + 1 < SIZE) {
        val_down = maze[Ptr->y_pos + 1][Ptr->x_pos];
    }
    
    //printf("val_down: %d\n", val_down);

    struct node *newPtr = NULL;

    switch (val_down) {
        case DESTINATION:
            //printf("End: (%d, %d)\n", Ptr->x_pos + 1, Ptr->y_pos);
            propagateSolution(Ptr);
            break;
        case OBSTACLE:
            // do nothing
            break;
        case CLEAR:
        case PATH:
            newPtr = newNode(val_down, Ptr->x_pos, Ptr->y_pos + 1);
            Ptr->downPtr = newPtr;
            newPtr->parentPtr = Ptr;
            recursiveSolve(newPtr); 
            break;
        default:
            Ptr->downPtr = NULL;
            break;
    }

    // move right:
    int val_right = -1;
    if (val_right + 1 < SIZE) {
        val_right = maze[Ptr->y_pos][Ptr->x_pos + 1];
    }
    
    //printf("val_right: %d\n", val_right);

    switch (val_right) {
        case DESTINATION:
            propagateSolution(Ptr);
            break;
        case OBSTACLE:
            // do nothing
            break;
        case CLEAR:
        case PATH:
            newPtr = newNode(val_down, Ptr->x_pos + 1, Ptr->y_pos);
            Ptr->downPtr = newPtr;
            newPtr->parentPtr = Ptr;
            recursiveSolve(newPtr); 
            break;
        default:
            break;
    }
}
void propagateSolution(NodePtr Ptr) {
    while (Ptr->data != START) {
        maze[Ptr->y_pos][Ptr->x_pos] = 4;//Ptr->data;
        Ptr = Ptr->parentPtr;
    }
}

void printSolution() {
    FILE *f = fopen(OUTPUT_FILE, "wb");  // create and/or overwrite
    if (!f) {
        printf("Error in creating file. Aborting.\n");
        exit(1);
    }

    char buff[SIZE + 1] = "";
    buff[SIZE] = '\n';
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", maze[i][j]);
            buff[j] = maze[i][j] + '0';
        }
        printf("\n");
        fwrite(buff, 1, sizeof buff, f);
    }
    fclose(f);
}

void findStart(int *x_pos, int *y_pos) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maze[i][j] == START) {
                *x_pos = j;
                *y_pos = i;
            }
        }
    }
}
