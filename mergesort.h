void merge(int *array_of_integers, int p, int q, int r) {
     int n1 = q - p + 1;
     int n2 = r - q; 
     int i, j, k;
     int left_array[n1 + 1];
     int right_array[n2 + 1];

     left_array[n1] = 123456798;
     right_array[n2] = 123456798;

     for (i = 0; i < n1; i++)
         left_array[i] = array_of_integers[p + i];
     for (j = 0; j < n2; j++)
         right_array[j] = array_of_integers[q + j + 1];

     i = 0;
     j = 0;

     for (k = p; k <= r; k++) {
         if (left_array[i] <= right_array[j]) {
             array_of_integers[k] = left_array[i];
             i++;
         } else {
             array_of_integers[k] = right_array[j];
             j++;
         }
     }
 }

 void merge_sort(int *array_of_integers, int p, int r) {
     if(p < r) {
         int q = (p + r) / 2;
         merge_sort(array_of_integers, p, q);
         merge_sort(array_of_integers, q + 1, r);
         merge(array_of_integers, p, q, r);
     }
 }
