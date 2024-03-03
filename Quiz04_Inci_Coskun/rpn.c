#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include"rpn.h"
#include"stack.h"

/*
 * Verilen iki sayi uzerinde, verilen islemi uygular.
 * Ex: op1 = 1 op2 = 3 operation= +
 *        sonuc: 1+3 = 4
 * Ex: op1 = 8 op2 = -3 operation = *
 *        sonuc: 8 * -3 = -24
 * Verilen operation eger istenen 4 islem(*,+,/,-) karakterinde degilse
 *   hata mesaji gosterip fonksiyondan cikar.
 */
double compute_operation(double op1, double op2, char operation) {
    /* Alistirma 2.a: op1 ve op2'yi operation ile verilen '+', '-', '*', '/'
     *   islemlerini uygulayip geri donduren fonksiyonu yazin. 
     */
    double result = 0;
    /*
     * Tip: switch-case kullanabilirsiniz.
     */
     switch (operation) {
        case '+':
            result = op1 + op2;
            break;

        case '-':
            result = op1 - op2;
            break;

        case '*':
            result = op1 * op2;
            break;

        case '/':
            if (op2 != 0) {
                result = op1 / op2;
            } 
            else {
                printf("Impossible to divide a number by zero!\n");
                // etkisi olmaması icin 0 donduruyorum.
                return result;
            }
            break;
            
        default:
            printf("Error: Operation you have provided is not a valid operation!\n");
            // etkisi olmaması icin 0 donduruyorum.
            return result;            
    }
    return result;
}

/*
 * Verilen expr parametresindeki sayilari, yine
 *   expr icindeki islemler ile hesaplayip,
 *   yigit icerisine kaydedecek.
 */
double evaluate_RPN(char *expr, struct stackNode **top) {
    double retval = 0.;
    // Alistirma 2.b
    
	// Kullanilacak degisken atamalarini yapin
    double multiReturn [8];
    int i = 0;

    // Donguyu kurun
    //Ifadenin sonuna kadar elemanlari gezecek bir dongu kurunuz.
    //Ifadenin sonuna gelip gelmedigini ('\0') ile kontrol edebilirsiniz.
    //Tip: Kontrol icin her dongu sirasinda yigit icerigini ekrana basabilirsiniz
    //boylece yigitdaki degisimleri gorebilirsiniz. 
    while(expr[i] != '\0'){

        //Eger eleman islenen (operand) ise yigita ekleyiniz (push).
        if(isdigit(expr[i])){
            double charToDouble = expr[i]-'0';
            stack_push(top, charToDouble);
        }

        //Eger eleman bir islem ise yigittan iki deger cekiniz (pop).
        //Tip: isdigit fonksiyonunu kontrol icin kullanabilirsiniz. 
        //Bu iki deger ile istenen islemi compute_operation()
        //fonksiyonuna verip donus degeri yigita ekleyin (push).
        else{    
            //operand degilse sembolun ise yarayip yaramadigini compute_operation
            //icinde test ettigim icin direkt else kisminda fonksiyona yolluyorum 
            //condition koymuyorum 
            stack_multi_pop(top, 2, multiReturn);
            double result = compute_operation(multiReturn[1], multiReturn[0], expr[i]);
            stack_push(top, result);
        }
        i++;
        stack_print(*top);
    }

    // Yigitta kalan eleman sonuc degeridir.
    // retval degiskenini sonuc degerini pop ile alarak guncelleyin.
    retval = stack_pop(top);

	// Yigit bos degilse kontrol edin, bu durumda 
    // compute_operation fonksiyonu hatali olabilir.
	// Bununla ilgili mesaj ekrana yazilsin.
    if(*top != NULL){
        printf("Better to check to result!");
    }

    return retval;
} 


void rpn_test_evaluate_RPN(){
	/* Test */
    struct stackNode *stack = NULL;
    printf("Testing equation 13+2-\n");
	assert(evaluate_RPN("13+2-", &stack) == 2.0);
    printf("\nTesting equation 62+5*84/-\n");
	assert(evaluate_RPN("62+5*84/-", &stack) == 38.0);
    stack_free(&stack);
	printf("\nThe tests are successful.\n");
}
