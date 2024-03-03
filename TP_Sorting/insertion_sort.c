/*************************************
 * Insertion Sort
 ************************************/

void insertion_sort(int *array, int size) {
  // Ana dongu
  // Tip: Ikinci elemandan basla
  for (int i = 1; i < size; i++) {
    // Bu iterasyonda ilgilenilen eleman: pivot
    int pivot = array[i];
    int j;

    // Dogru yeri bulana kadar kaydirma yaptigimiz dongu
    for (j = i; j > 0; j--) {
      if (pivot < array[j - 1]) {
        array[j] = array[j - 1];
      } else break;
    }

    // Dogru yere gelindi, pivot'u buraya koyalim
    array[j] = pivot;    
  }
}
