#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/*
 * Parametre olarak verilen yigit
 *   elemanini bellekten siler.
 * Yigit zaten bos ise herhangi bir 
 *   islem yapmaz.
 */
void stack_free(struct stackNode** top) {
    /* Alistirma 1.a1 */

    // 1. "top" pointer'imizi kaybetmemek icin, while 
    //    icinde donecek olan yeni bir pointer tanimliyoruz.
    //    Bu yeni pointer (cursor), top pointer'in gosterdigi
    //    adresteki degere isaret etmeli. (dereference)
    if(*top == NULL){
        return;
    }
    struct stackNode* cursor = *top;
    
    // 2. Her bir eleman NULL olmadigi 
    //   surece silme islemi yapan donguyu yazin
    //dongu (kosul)
    while(cursor != NULL){

        // 3. "cursor"i hareket ettirecegiz, orijinali kaybetmemek 
        //    adina, orphan adinda bir pointer tanimlayin.
        //    orphan, cursor ile ayni yere isaret etmeli.
        struct stackNode* orphan = cursor;

        // 4. "cursor"i bir sonraki node'a kaydirin.
        cursor = cursor-> next;

        // 5. "orphan"in kullandigi bellegi serbest birakin.
        free(orphan);
    }

    // 6. "top" pointer'ini NULL yapin, bellegi tamamen
    //    serbest biraktik.
    *top = NULL;
}


/*
 * Parametre olarak verilen yigit yapisinin
 * bos olup olmadini kontrol eder.
 * yigit bos ise 1, degilse 0 dondurur.
 */
int is_empty(struct stackNode *top){
    int result = 0;
    /* Alistirma 1.a2 */
    if(top == NULL){
        printf("Stack is already empty!\n");
        return 1;
    }
    return result;
}


/*
 * Parametre olarak verilen yigit yapisinda
 * yeni veri data yapisini ekler.
 * (LIFO prensibi ile)
 */
void stack_push(struct stackNode **top, double data) {
	/* Alistirma  1.b */

    // Adim 1
    //1. Yeni dugum icin gosterici olusturun
    //ve bellekte yer acin.
    struct stackNode* new = malloc(sizeof(struct stackNode));

    // Adim 2
    //Bellek icin kontrol yaptiktan sonra
    //yeni veri atamasini yapin.
    if(new == NULL){
        return;
    }
    new->data = data;

    // Adim 3
    //3. Son olarak, yigittaki ilk degeri guncelleyin.
    new->next = *top;
    *top = new;
}


/*
 * Parametre olarak verilen yigit yapisindan
 *   ilk elemani siler.
 * Eger yigit bos ise -1 degerini dondurur.
 */
double stack_pop(struct stackNode **top) {
	double retval = -1;
	/* Alistirma 1.c */

    //Bos degilse ilk elemani al, sonraki 
    //elemani ilk eleman olarak ata.
    if(*top == NULL){
        return retval;
    }
    struct stackNode* temp = *top;
    retval = temp->data;
    *top = (*top)->next;

    //Ilk eleman icin ayrilan bellegi sil.
    free(temp);

    //Ilk eleman verisini dondur.
    return retval;
}


/*
* Alistirma 1.d 
* Parametre olarak verilen number degiskeninin 
*   degeri kadar elemani pop ile stackten cikaran
*   stack_multi_pop fonksiyonunu tanimlayiniz.
* Dikkat! 
* Bu fonksiyonu stack.h dosyasina eklemeyi unutmayin!
*/
// stack_multi_pop()
void stack_multi_pop(struct stackNode **top, int number, double* multiReturn){
    for(int i = 0; i < number; i++){
        multiReturn[i] = stack_pop(top);
    }
    return;
}


/*
 * Parametre olarak verilen yigit yapisini
 * ekrana basar.
 * yigit bos ise "yigit bos" mesajini gosterir.
 */
void stack_print(struct stackNode *top) {
    /* Alistirma 1.e */
    /*
     * Tip: Yigit yapisi bagli liste olarak tanimlandigindan, 
     *   ekrana basma islemi de bagli listeler ile 
     *   benzer olacaktır.
    */

	//Yigit bos mu kontrol edip, bos ise 
    //ekrana mesaj basip fonksiyondan cikmali
    if(top == NULL){
        printf("Empty stack!\n");
        return;
    }

    //Yigit bos degilse ilk elemandan 
    //baslayarak son elemana kadar tum 
    //degerler ekrana yazilsin.
    struct stackNode* temp = top;
    printf("Here is your list: ");
    while(temp != NULL){
        printf("%.2lf -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


