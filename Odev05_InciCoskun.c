#include <stdio.h>
#include <ctype.h>

int mystrlen(char *dest);
char* mystrcpy(char*, char*);
char* mystrcat(char *src, char *dest);
char* mystrstr(char *str, int c);


int main() {
	
	int alCou = 0, majCou = 0, minCou = 0, spcCou = 0, punCou = 0, dgCou = 0;
	char chain[500]= "Human-robot interaction is the study of interactions between humans and robots. It is often referred as HRI by researchers. Human-robot interaction is a multidisciplinary field with contributions from human-computer interaction, artificial intelligence, robotics, natural language understanding, design, humanities and social sciences.";


	for (int i = 0; chain[i] != '\0'; i++) {
		if (isupper(chain[i])) {
			majCou++;
		}
		
		if (islower(chain[i])) {
			minCou++;
		}

		if (isalpha(chain[i])) {
			alCou++;
		}

		if (isspace(chain[i])) {
			spcCou++;
		}

		if (ispunct(chain[i])) {
			punCou++;
		}

		if (isdigit(chain[i])) {
			dgCou++;
		}
	}

	printf("\nCharacter chain :\n");
	puts(chain);
	
	printf("\nUppercases    : %d\n", majCou);
	printf("Lowercases    : %d\n", minCou);
	printf("Alphabeticals : %d\n", alCou);
	printf("Numbers       : %d\n", dgCou);
	printf("Spaces        : %d\n", spcCou);
	printf("Ponctuations  : %d\n", punCou);	

	printf("\nAll in uppercase  : \n");
	for (int i = 0; chain[i] != '\0'; i++) {
    		putchar(toupper(chain[i]));
	}	

	printf("\n\nAll in lowercase  : \n");	
	for (int i = 0; chain[i] != '\0'; i++) {
    		putchar(tolower(chain[i]));
	}
	
	printf("\n\n------------\nWith my functions : \n");
	
	char src[256];
	char cpy[256];
	char s3[256];
	
	printf("Please enter a character chain >>> ");
	gets(src);
	
	printf("Character number  : %d\n", mystrlen(src));
	printf("Copy of the character chain : %s\n", mystrcpy(src, cpy));
	
	printf("Please enter a second chain for concenation >>> ");
	gets(s3);
	printf("Character number of the second chain : %d\n", mystrlen(s3));
	
	char *s4 = mystrcat(s3, src);
	printf("Concenation of these two chains : %s\n", s4);
	
	printf("Please enter a character >>> ");
	char c;
	scanf("%c", &c);
	
	if (mystrstr(s4,c) == NULL) {
		printf("%c not found", c);
	}
	else printf("%s\n", mystrstr(s4,c));
		
	return 0;
}

int mystrlen(char *str) {
	int lenght = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		lenght++;
	} 
	return lenght;
}


char* mystrcpy(char *src, char *dest) {
	char* a = dest;
	while(*src) {
		*dest = *src;        
		dest++;        
		src++;
	}	    
	*dest = '\0';
	return a;
}


char* mystrcat(char *src, char *dest) {
	int i = 0;
	char* b = dest;
	int len = mystrlen(dest);
	int len2 = mystrlen(src);
	dest[len] = 32 ;
	
	for(i = 0; i < len2; i++) {
		dest[i + len + 1] = src[i];	
	}
	dest[i + len + 1] = '\0';	
	return b;
}


char* mystrstr(char *str, int c) {
	char* d = str;
	int i = 0;
	int len3 = mystrlen(str);
	
	for (i=0; i < len3; i++) {
		if (str[i] == c) {
			return (d+i);
		}
	}

	return NULL;
}
