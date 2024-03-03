#include "data.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
/* ONEMLI BILGI
 * Asagida kullanilan tum listelerin uzunluklari
 * yukaridaki SIZE'a esit olacaktir.
 * Fonksiyonlarinizda (read_data haric) gonlunuzce kullanin.
 */


/* Alistirma 1
 * Istediginiz bir sort algoritmasini yazin
 * Bu algoritmayi data.h dosyasinda tanimlamayi unutmayin!
 * Dogru calistigi surece onceki calismalardan kopyalabilirsiniz.
 * Tip: Kolay bir tane secin, asagida bunu tekrar yazacaksiniz
 *      (Performans cok onemli degil, 100 eleman olacak zaten)
 */
// TODO: SORT FONKSIYONU

void insertionSort(int array[]) {
  for (int step = 1; step < SIZE; step++) {
    int key = array[step];
    int j = step - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}



/* Alistirma 2
 * Dosyayi satir satir okuyup, dt degiskeninin
 *  dataX ve dataY arraylerine yazan fonksiyonu yazin.
 * Dosyadaki sayilar virgul (,) ile ayrilmistir. Virgulden
 *  onceki deger x, sonraki deger y degeridir.
 * Dosyayi okuyamazsa error versin ki bilelim :)
 * Tip 1: feof() komutu dosya okurken cok kullanislidir.
 * Tip 2: Isiniz bitince dosyayi kapatmayi unutmayin.
 */
void read_data(char* filename, data* dt){
  // TODO
  FILE *f = fopen(filename, "r");

  if(f == NULL){
    perror("Error: ");
    return;
  }

  int i = 0;

  while(!feof(f)){
    fscanf(f, "%d , %d", &dt->dataX[i], &dt->dataY[i]);
    i++;
  }

  fclose(f);
}


/* Alistirma 3
 * Aldigi param_list degiskeninde asagidaki bilgileri 
 *  sirasiyla bulup ekrana basan fonksiyon:
 * - Eleman sayisi
 * - Ortalama
 * - Minimum
 * - Maximum
 * Tip: Min ve max bulmadan once sort ederseniz 
 *      isiniz cok daha kolay olur.
 */
void get_information(int* param_list){
  // TODO
  int sum = 0;
  insertionSort(param_list);
  for(int i = 0; i < SIZE; i++){
    sum += param_list[i];
  }
  printf("Number of elements : %d\n", SIZE);
  printf("Average : %d\n", sum / SIZE);
  printf("Minimum : %d\n", param_list[0]);
  printf("Maximum : %d\n", param_list[SIZE - 1]);
}


/* Alistirma 4
 * Yukarida yazdiginiz sorting fonksiyonunu dt 
 *  degiskenine uygulayan sorting fonksiyonunu yazin.
 * Bu fonksiyonu yazarken onceki yazdiginiz sort
 *  fonksiyonunu kullanamazsiniz. Yani bu fonksiyon
 *  kendi basina calismali.
 */
void sort_values(data* dt){
  // TODO
  for (int i = 1; i < SIZE; i++) {
    int key = dt->dataX[i];
    int j = i - 1; 

    while (key < dt->dataX[j] && j >= 0) {
      dt->dataX[j + 1] = dt->dataX[j];
      --j;
    }
    dt->dataX[j + 1] = key;
  }

  for (int i = 1; i < SIZE; i++) {
    int key = dt->dataY[i];
    int j = i - 1; 

    while (key < dt->dataY[j] && j >= 0) {
      dt->dataY[j + 1] = dt->dataY[j];
      --j;
    }
    dt->dataY[j + 1] = key;
  }
}



/* Alistirma 5
 * dt degiskenindeki X ve Y degerlerini kullanarak
 *  lineer regresyon hesabi yapan fonksiyonu yazin.
 * Yani, Y = a + bX seklindeki formulun a ve b 
 *  parametreleri bulunacak.
 * Fonksiyon sonucu ekrana basmamali ve deger 
 *  geri dondurmemeli, b ve a uzerinden sonuca erisilmeli.
 * Tip: Gerekli formullerin hepsi PDF'te verilmistir.
 */
void find_line(data* dt, double* a, double* b){
  // TODO
  int x = 0;
  int y = 0;
  int xy = 0;
  int x2 = 0;

  for(int i = 0; i < SIZE; i++){
    x += dt->dataX[i];
    y += dt->dataY[i];
    x2 += dt->dataX[i] * dt->dataX[i];
    xy += dt->dataX[i] * dt->dataY[i];
  }
    
  *a = ((y * x2) - (x * xy)) / ((SIZE * x2) - (x*x));
  *b = ((SIZE * xy) - (x * y)) / ((SIZE * x2) - (x*x));
}

