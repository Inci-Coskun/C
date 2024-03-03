#include <stdio.h>

void main () {

	int grades[5], total = 0, minCounter = 1, maxCounter = 1;

	for (int i = 0; i <= 4; i++) {
		printf("Enter the grade of student %d: ", i + 1);
		scanf("%d", &grades[i]);
	}
	
	printf("Grades of students: ");
	
	for (int i = 0; i <= 4; i++) {
		printf("%d  ", grades[i]);
	}
	
	for (int i = 0; i <= 4; i++) {
		total = total + grades[i];
	}
	
	printf("\nClass average: %0.2f\n", total / 5.0);
	
	int minGrade = grades[0];
	int maxGrade = grades[0];
	
	for (int i = 1; i <= 4; i++) {
		if (grades[i] < minGrade) {
			minGrade = grades[i];
			minCounter = i + 1;	
		}
		else if (grades[i] > maxGrade) {
			maxGrade = grades[i];	
			maxCounter = i + 1;
		}
	}	
	
	printf("Minimum grade: %d\n", minGrade);
	printf("Maximum grade: %d\n", maxGrade);
	printf("Student number with the lowest grade: %d\n", minCounter);
	printf("Student number with the highest grade: %d\n", maxCounter);
}
