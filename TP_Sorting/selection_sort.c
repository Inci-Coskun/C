/*************************************
 * Selection Sort
 ************************************/

void swap_function(int *var1, int *var2) {
    int temp;
    temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

void selection_sort(int *arritem,int size){
    // i, j: Dongu indexlerimiz
    // min: Listedeki minimum deger
    // cursor: sort olmayan kisimda gezen index
    int i, j, min, cursor;

    // Ana dongu
    for (i = 0; i < size; i++) {
        min = arritem[i];
        cursor = i;

        // Minimumu bulan dongu
        for (j = i; j < size; j++) {
            if (arritem[j] < min) {
                min = arritem[j];
                cursor = j;
            }
        }

        // Minimumu i indexine koyalim (swap_function kullanin)
        swap_function(&arritem[i], &arritem[cursor]);
    }
}