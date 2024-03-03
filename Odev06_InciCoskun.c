#include <stdio.h>
#include <ctype.h>

int main (int argc, char* argv[]) {

	char dec[3000] = {0};
	int frq[128] = {0};
	char x[3000] = {0};
	int frq2[128] = {0};
	char ch = 0, t = 0, q = 0;
	
	FILE *s;
	FILE *d;
	FILE *p;
	
	s = fopen(argv[1], "r");
	d = fopen(argv[2], "w+");
	
	if (!d || !s) {
		printf("Error!\n");
		return 1;
	}
	
	int i = 0;
	while ( (ch = fgetc(s))!= EOF ) {
		dec[i] = ch;
		(frq[ch])++;
		i++;
	}	
	
	int max = 0;
	int chMax = 0;
	for (int i = 32; i <= 126 ; i++) {
		if (frq[i] > max) {
			max = frq[i];
			chMax = i;
		}
	}
	
	int dif = chMax - 32;
	rewind(s);
	
	int c = 0;
	while ( (t = fgetc(s))!= EOF ) {
		if (t == 10) {
			fputc('\n',d);	
			x[c] = '\n';
			c++;
		}
		 	
		else {
			fputc(t - dif, d);
			x[c] = t - dif;
			c++;
		}	
	}
		
	printf("Decryption... DONE\n");
	fclose(s);
	
	for (int a = 0; a < c; a++) {
		x[a]= tolower(x[a]);
		q = x[a];
		(frq2[q])++;
	}

	p = fopen("stats.txt", "w");
	
	if (p == NULL) {
		printf("Error!\n");
		return 1;	
	}
	
	fprintf(p, "Name of the file : %s\n", argv[2]);
	fprintf(p, "Line number : %d\n", frq2[10]);
	fprintf(p, "Word number : %d\n", frq2[32] + 1);
	fprintf(p, "Characters and their frequencies :\n");
	
	for (int a = 97; a < 123; a++) {
		fprintf(p, "%c : %d\n", a, frq2[a]);
	}	
	
	printf("Stats... DONE\n");
	printf("Bye bye!\n");
	
	fclose(d);
	fclose(p);
	
	return 0;
}


