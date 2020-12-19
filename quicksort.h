#include <stdio.h>
#include <stdlib.h>

int partition(int *A, int p, int r){
	int i, j;
	i = p - 1;
	int x = A[r];
	
	for(j = p; j < r; j++){
		if(A[j] <= x){
			i++;
			int aux = A[i];
			A[i] = A[j];
			A[j] = aux;
		}
	}

	A[r] = A[i + 1];
	A[i + 1] = x;
	
	return i + 1;
}

void quick_sort(int *A, int p, int r){
	if(p < r){
		int q = partition(A,p,r);
		quick_sort(A,p, q - 1);
		quick_sort(A,q + 1,r);
	}	
}
