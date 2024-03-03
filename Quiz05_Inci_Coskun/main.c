#include "data.h"
#include <stdlib.h>
#include <stdio.h>
#define SIZE 100

/* Alistirma 6
 * Bir dosyadan veri okuyup, uzerinde lineer regresyon
 *  uygulayan programi yazin.
 * Adim 1: Veriyi read_data fonksiyonu ile okuyup mainData 
 *         degiskenine yazin. read_data fonksiyonuna vereceginiz
 *         dosya adini argv kullanarak komut satirindan almalisiniz.
 * Adim 2: Veriyle ilgili bilgileri get_information 
 *         fonksiyonunu kullanarak ekrana basin.
 * Adim 3: Veriyi sort_values fonksiyonunu kullanarak
 *         siralayin.
 * Adim 4: sorted_data.txt isimli bir dosya olusturup,
 *         icine siralanmis X ve Y degerlerini yazin.
 *         (data.txt ile ayni formatta yazilmali!)
 * Adim 5: find_line fonksiyonunu kullanarak veri uzerinde
 *         lineer regresyon uygulayin. Elde ettiginiz 
 *         sonuclari a ve b degiskenlerine yazin. Ardindan
 *         bu sonuclari ekrana basin.
 * 
 * Basarilar
 */
int main(int argc, char *argv[]){
  data mainData;
  int tmpX[SIZE];
  int tmpY[SIZE];
  mainData.dataX=tmpX;
  mainData.dataY=tmpY;

  // Adim 1
  // TODO
  read_data(argv[1], &mainData);

  // Adim 2
  // TODO
  printf("Informations about X values:\n");
  get_information(tmpX);

  printf("\nInformations about Y values:\n");
  get_information(tmpY);

  // Adim 3
  // TODO
  sort_values(&mainData);

  // Adim 4
  // TODO
  FILE *myF = fopen("sorted_data.txt", "w");
  if(myF == NULL){
    perror("Error: ");
    return -1;
  }
  for(int i = 0; i < SIZE; i++){
    fprintf(myF, "%d , %d\n", tmpX[i], tmpY[i]);
  }
  
  fclose(myF);

  // Adim 5
  double a; 
  double b;
  // TODO
  find_line(&mainData, &a, &b);
  printf("\na : %lf\n", a);
  printf("b : %lf\n", b);

  return 0;
}
