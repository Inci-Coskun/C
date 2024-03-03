#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "stack.h"
#include "rpn.h"

#define LINE_MAX 20

int main(int argc, char *argv[]) {
	
	/*
	// Alistirma 1.f
	// stack.c dosyasina yazdiginiz fonksiyonlari test edin.
	double multiReturn[4];
	struct stackNode *test = NULL;

	// Stack bos mu testi
	is_empty(test);
	
	// Stack push testi
	stack_push(&test, 5);
	stack_push(&test, 10);

	// Stack print testi
	stack_print(test);

	// Stack pop ve multi-pop testi
	stack_multi_pop(&test, 2, multiReturn);
	printf("\nPop: %.2lf\n", multiReturn[1]);
	printf("Pop: %.2lf\n", multiReturn[0]);

	// Stack free testi
	stack_free(&test);
	*/

    // Alistirma 2.b yi tamamladiktan sonra alttaki 
	//   satiri yorumdan cikarip test yapabilirsiniz.
	// Bu fonksiyon herhangi bir ek isleme gerek duymaz,
	//   oldugu gibi calisir.
	//rpn_test_evaluate_RPN();


	/* Alistirma 3
	 * Komut satiri arayuzunden (CLI), kullanicinin
	 *   girdigi islemi alip, hesaplayan donguyu yazin.
	 * Kullanici sistemden cikis yapmak icin 
	 *   exit yazip Enter'a basmalidir.
	 * Programdan cikmadan once bellekte stack icin 
	 *   kullandiginiz yeri serbest birakmayi unutmayin!
	 * Kullanicinin komutunu asagida tanimlanan 
	 *   <line> degiskeni icine okuyabilirsiniz.
	 * Stack baslangici icin asagida tanimlanmis <stack>
	 *   degiskenini kullanabilirsiniz.
	 */

	char line[LINE_MAX];
	struct stackNode *stack = NULL;

	printf("\nWelcome to RPN Calculator!\n");
	printf("To exit, write exit then press ENTER.\n");
	while(1){
		printf("\nEnter the equation: ");
		fgets(line, LINE_MAX, stdin);
        line[strcspn(line, "\n")] = '\0';
		//scanfte kullanici bosluk girerse sikinti yasayabilirdim
		//gets de test asamasinda linuxta warning verdi
		//mecburen ek islemler yaptim
		if(strcmp(line, "exit") == 0){
			break;
		}
		double result = evaluate_RPN(line, &stack);
		printf("The result of the equation: %.2lf\n", result);
	}
	stack_free(&stack);
	return 0;
}
