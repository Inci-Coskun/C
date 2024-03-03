#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMaxGradeNumber(int n[]);
int findMinGradeNumber(int n[]);
float average(int n[]);
int grades[100];
float mean = 0, total = 0;
int maxHolder = 0, maxCounter = 0;
int minHolder = 0, minCounter = 0;
int max, min;

void main(int argc, char *argv[]) {
    srand(time(0));

    printf("Students' grades:\n");
    for (int i = 0; i < 100; i++) {
        grades[i] = rand() % 101;
        printf("Grade of student %d: %d\n", i + 1, grades[i]);
    }

    mean = average(grades);
    printf("\nAverage: %.2f\n\n", mean);

    maxHolder = findMaxGradeNumber(grades);
    printf("Student number with the highest grade: %d    Grade: %d\n\n", maxHolder, max);

    minHolder = findMinGradeNumber(grades);
    printf("Student number with the lowest grade: %d    Grade: %d\n", minHolder, min);
}

float average(int n[]) {
    for (int i = 0; i < 100; i++) {
        total += n[i];
    }
    return total / 100.0;
}

int findMaxGradeNumber(int n[]) {
    max = 0;
    for (int i = 0; i < 100; i++) {
        if (n[i] > max) {
            max = n[i];
            maxCounter = i + 1;
        }
    }
    return maxCounter;
}

int findMinGradeNumber(int n[]) {
    min = 101;
    for (int x = 0; x < 100; x++) {
        if (n[x] < min) {
            min = n[x];
            minCounter = x + 1;
        }
    }
    return minCounter;
}
