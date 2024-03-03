#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 10

// la definition de la structure
struct complexe{
	double re;
	double im;
};

// retourne la partie reelle du nombre complexe z
double partieReel(struct complexe z) {
	return z.re;	
}

// retourne la partie imaginaire du nombre complexe z
double partieImag(struct complexe z) {
	return z.im;	
}

// affiche a l'ecran le nombre complexe z en format z = a + bi avec a = re(z) et b = im(z)
void afficheComplexe(struct complexe *z) {
	printf("z = %.2lf + %.2lfi", (*z).re, (*z).im);
}

// calcule et retourne le module du nombre complexe z
double moduleComplexe(struct complexe *z) {
	double abs = sqrt( pow((*z).re,2) + pow((*z).im,2)  );
	return abs;	
}

// saisit de l'utilisateur le nombre complexe z, remplit les champs (re, im) et le retourne a la fin
struct complexe saisitComplexe(void) {
	struct complexe temp;
	printf("Please enter real part : ");
	scanf("%lf", &temp.re);
	printf("Please enter imaginary part : ");
	scanf("%lf", &temp.im);
	return temp;	
}

// multiplie 2 nombres complexes a et b, retourne le nombre complexe resultant
struct complexe multiComplexe(struct complexe a, struct complexe b) {
	struct complexe mult;
	double aRe = partieReel(a);
	double bRe = partieReel(b);
	double aIm = partieImag(a);
	double bIm = partieImag(b);
	mult.re = aRe*bRe - aIm*bIm;
	mult.im = aRe*bIm + bRe*aIm;
	return mult;	
}

// remplit alleatoirement un tableau de nombre complexe de longueur N
void remplitTableau(struct complexe *z) {
	srand(time(0));
	for(int i = 0; i<N; i++) {
		(*z).re = (float)rand() / RAND_MAX;
		(*z).im = (float)rand() / RAND_MAX;
		z++;
	}
}

int main() {

	// definissez ici les variables que vous allez utiliser comme par ex. int i, etc...
	int i = 0;
	double max = 0;
	double t = 0;
	int iMax = 0;

	// definissez les nombres complexes que vous allez utiliser
	struct complexe user1;
	struct complexe user2;
	struct complexe mul;
	 
	printf("Entrez le 1er nombre complexe\n");
	// saisissez de l'utilisateur le premier nombre
	user1 = saisitComplexe();
	// affichez le premier nombre a l'ecran
	afficheComplexe(&user1);

	printf("\n\nEntrez le 2eme nombre complexe\n");
	// saisissez de l'utilisateur le deuxieme nombre
	user2 = saisitComplexe();
	// affichez le deuxieme nombre a l'ecran
	afficheComplexe(&user2);

	printf("\n\nMultiplication de 2 complexes\n");
	// multipliez les 2 nombres complexes
	mul = multiComplexe(user1, user2);
	// affichez le resultat a l'ecran
	afficheComplexe(&mul);
	// affichez a l'ecran le module du nombre complexe resultant de la multiplication
	printf("\n");
	printf("|z| = %.2lf\n", moduleComplexe(&mul));

	
	printf("\n-------- Tableau des structures --------\n");
	
	// definissez un tableau de nombres complexes de N elements
	struct complexe tab[N];

	// remplissez le tableau avec des nombres complexes alleatoire
	remplitTableau(tab);
	
	// affichez les elements de tableau et leur module
	
	for (int i = 0; i<N; i++) {
		printf("tab[%d] :  ", i);
		afficheComplexe(&tab[i]); 
		t =  moduleComplexe(&tab[i]); 
		printf("  |z| = %.2lf\n", t);
		if (t > max) {
			max = t;
			iMax = i;
		}
	}
	

	printf("\nLe nombre complexe avec le max module:\n");
	// trouvez et affichez le nombre complexe qui a le module max, son module et son indice
	afficheComplexe(&tab[iMax]);
	printf("\n|z| = %.2lf", moduleComplexe(&tab[iMax]));
	printf("\nindex : %d\n", iMax);

	return 0;
}
