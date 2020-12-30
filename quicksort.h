#include <stdio.h>
#include <stdlib.h>

int comp=0;
int partition(int *A, int p, int r){
	int i, j;
	i = p;
	int x = A[r];
	
	for(j = p; j < r; j++){
		if(A[j] <= x){
			int aux = A[i];
			A[i] = A[j];
			A[j] = aux;
			i++;
		}
	comp++;
	}

	A[r] = A[i];
	A[i] = x;
	
	return i;
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
