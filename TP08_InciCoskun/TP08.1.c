#include <stdio.h>

int main(int argc, char* argv[]){

	printf("Argument count (argc) : %d\n", argc);
	printf("Argument vector (argv) :\n");
	
	for (int i = 0; i <  argc; i++) {
		
		if (i == 0) printf("argv[%d] : %s ---> name of the executable\n", i, argv[i]);
		else printf("argv[%d] : %s\n", i, argv[i]);
	}
	
	return 0;
}
