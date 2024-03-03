#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char*argv[]) {

	srand(time(0));
	int n[25];
	int d = atoi(argv[1]);
	
	printf("Before summation :\n");
	for (int i = 0; i < 25; i++) {
		n[i] = rand() % 51;
		printf("%d  ", n[i]);
	}
	
	printf("\nAfter summation :\n");
	for (int i = 0; i < 25; i++) {
		n[i] = n[i] + d;
		printf("%d  ", n[i]);	
	}
	
	return 0;
}

