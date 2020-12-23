int insertionsort(int lista[], int tamanho)  
{  
    int i, j, m, comparacoes=0;
	  
    for (i = 1; i < tamanho; i++) 
    {  
        m = lista[i];  
        j = i - 1;  
        
	comparacoes++;
        while (j >= 0 && lista[j] > m) 
        {  
            lista[j + 1] = lista[j];  
            j = j - 1;
	comparacoes++;  
        }  
        lista[j + 1] = m;  
    } 

	return comparacoes;	 
}  
