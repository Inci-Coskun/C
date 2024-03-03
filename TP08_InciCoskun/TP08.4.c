#include <stdio.h>
#include <string.h>

int main () {
	
	int p, k; 
	char s[1024];
	int min = 3000, max = 0;
	char minS[32]; 
	char maxS[32]; 

	FILE* f = fopen("sehir.txt", "r");
		
	if (f == NULL) {
		printf("Impossible to open the file!\n");
		return 1;
	}

	while (fscanf(f,"%d\t%s\t%d\n", &p, s, &k) != EOF) {
	
		if (k < min) {
			min = k;
			strcpy(minS,s); 
		}
		
		else if (k > max) {
			max = k;
			strcpy(maxS,s);
		}
		
	}
	
	fclose(f);
		
	printf("Closest city to Istanbul is %s with %d kilometers.\n", minS, min);
	printf("Farthest city to Istanbul is %s with %d kilometers.\n", maxS, max);

	return 0;
}
