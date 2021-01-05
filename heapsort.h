int compar =0;

void rearrange(int A[], int i, int tam){
	int esq = i * 2 + 1;
	int dir = i * 2 + 2;
	int maior = i;
	int aux;
	
	compar++;
	if (esq < tam && A[esq] > A[maior]){
		maior = esq;
		
	}
	compar++;	   
	if (dir < tam && A[dir] > A[maior]) {
		maior = dir;
		
	}
	compar++;
	if (maior != i ){
		aux = A[i];
		A[i] = A[maior];
		A[maior] = aux;   
		rearrange(A,maior, tam);
	}
}

int buildHeap (int *val, int tam) {
	int i;
	
	int aux;
	
	while(tam > 0){
		for ( i = (tam -1)/2; i >= 0; i= i-1) {
	  		rearrange(val, i, tam);
		}
		aux = val[tam-1];
		val[tam-1] = val[0];
		val[0] = aux;	
		tam--;
		compar++;
	}
	compar++;
 
 return compar;
}
