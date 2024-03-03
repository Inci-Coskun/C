#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	char *x = "0";
	if (argc < 3) printf("You should have entered more arguments!\n");
	
	if (3 <= argc) {
	
		if (atoi(argv[1])!=0) printf("You should have entered a character chain first!\n");
		
		else {
		
			if (!strcmp(argv[1], x)) printf("You should have entered a character chain first!\n");
			
			else {
			
				if (atoi(argv[2]) < 0) printf("Impossible to write the character chain negative times.\n");
				else if (atoi(argv[2]) > 0) {
					if (3 < argc) printf("You have entered more than enough arguments but it works too.\n");
					for (int i = 0; i < atoi(argv[2]); i++) {
						printf("%s  ", argv[1]);
					}
				}
				
				else {
				
					if (!strcmp(argv[2], x)) printf("Enter a number different than 0 after the character chain!\n");
					else printf("You should have entered a number after the character chain!\n");
				}		
			
			}		
		
		}	
	}
	
	return 0;
}

