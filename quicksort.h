#include <stdio.h>
#include <stdlib.h>

int comp=0;
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
	comp++;
	}

	A[r] = A[i + 1];
	A[i + 1] = x;
	
	return i + 1;
}

int quicksort(int *A, int p, int r){
	while(p < r){
		int q = partition(A,p,r);
		if(q - p < r - q){		
		quicksort(A,p, q - 1);
		p=q+1;
		} else {
		quicksort(A,q + 1,r);
	        r=q-1;
		}
	}
	return comp;
}
