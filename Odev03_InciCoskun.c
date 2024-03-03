#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 6
#define STUDENT 111

int i = 0, y = 0, j, sum = 0, aa = 0, ba = 0, bb = 0, cb = 0, cc = 0, f = 0;
float average = 0, averageHolder = 0, minHolder, mini, maxHolder, maxi, stdDev = 0, sumStd = 0, stdDevHolder;
float mean(float n[]);
float min(float n[]);
float max(float n[]);
float std(float n[]);

void main() {

	srand(time(0));
	int homeworks[STUDENT][N];
	double personalSum[STUDENT];
	float n[STUDENT];

	for (i = 0; i < STUDENT; i++) {
		for (y = 0; y < N; y++) {
			homeworks[i][y] = rand() % 101;
			personalSum[i] = homeworks[i][y] + personalSum[i];
			n[i] = personalSum[i] / N;
		}
	}
	
	// b icin ancak asagida basili bu yuzden yoruma aldim
	/*
	for (i = 0; i < STUDENT; i++) {
		printf("%.2f\n", n[i]);
	}
	*/	
	
	minHolder = min(n);
	printf("\nMinimum : %.2f\n", minHolder);
	
	maxHolder = max(n);
	printf("Maximum : %.2f\n", maxHolder);
	
	averageHolder = mean(n);
	printf("Average : %.2f\n", averageHolder);
	
	stdDevHolder = std(n);
	printf("Standard deviation : %.2f\n", stdDevHolder);
	
	printf("\nNotes of Students :\n");
	
	for (i = 0; i < STUDENT; i++) {
	
		if (n[i] >= average + ((3*stdDev) / 2)) {
			printf("Student %d : %.2f >>> AA\n", i+1, n[i]);
			aa++;	
		}
	
		else if ((n[i] < average + ((3*stdDev) / 2)) && (n[i] >= average + stdDev)) {
			printf("Student %d : %.2f >>> BA\n", i+1, n[i]);
			ba++;
		}
	
		else if ((n[i] < average + stdDev) && (n[i] >= average + stdDev/2)) {
			printf("Student %d : %.2f >>> BB\n", i+1, n[i]);
			bb++;
		}
	
		else if ((n[i] < average + stdDev/2) && (n[i] >= average )) {
			printf("Student %d : %.2f >>> CB\n", i+1, n[i]);
			cb++;
		}
	
		else if ((n[i] < average) && (n[i] >= average - stdDev)) {
			printf("Student %d : %.2f >>> CC\n", i+1, n[i]);
			cc++;
		}
	
		else if (n[i] < average - stdDev) {
			printf("Student %d : %.2f >>> F\n", i+1, n[i]);
			f++;
		}
		
	}
	
	int hist[6] = {aa, ba, bb, cb, cc, f};
	char* note[6] = {"AA", "BA", "BB", "CB", "CC", "F "}; 
	printf("\nHistogram\n");
	
	for (i = 0; i < 6; i++) {
		printf("%s   ", note[i]);
		for(j = 0; j < hist[i]; j++) {
			printf("*");
		}
		printf("\n");
	}
}
	
	
float mean(float n[]) {
	for (i = 0; i < STUDENT; i++)  {
		sum = n[i] + sum;
	}
	average = sum / 111.0;
	return average;
}


float min(float n[]) {
	mini = 101.0;
	for (i = 0; i < STUDENT; i++)  {
		if (n[i] < mini) {
			mini = n[i];
		}
	}
	return mini;
}


float max(float n[]) {
	maxi = 0.0;
	for (i = 0; i < STUDENT; i++)  {
		if (n[i] > maxi) {
			maxi = n[i];
		}
	}
	return maxi;
}


float std(float n[]) {
	for (i = 0; i < STUDENT; i++) {
       		sumStd += (n[i] - average)*(n[i] - average);
   	}
	stdDev = sqrt( (1 / 111.0) * (sumStd) );
	return stdDev;
}

