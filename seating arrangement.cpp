#include <stdio.h>
#define ROWS 3
#define COLS 20

int main() {
    int seats[ROWS][COLS];  // using array for seat numbers and there description
    int number = 1;
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            seats[i][j] = number;
            number++;
        }}
    printf("\nSeating Arrangement:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%3d ", seats[i][j]); }
        printf("\n");
    }
    return 0;
}