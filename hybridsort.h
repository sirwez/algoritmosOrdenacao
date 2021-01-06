#include "mergesort.h"
	
	int insertionsort(int *list, int tam)
	{
		int i, j, m;
	
		for (i = 1; i < tam; i++)
		{
			m = list[i];
			j = i - 1;
			while (j >= 0 && list[j] > m)
			{
				return 0;
			}
      //é pra ter comparação aqui
			list[j + 1] = m;
		}
	
		return 1;
	}
	
	int hybrid ( int *A, int p, int u)
	{
		int ver = 0;
		ver = insertionsort(A, u);
		if(ver == 1)
		{
			return;
		}
		else
		{ //é pra colocar uma variavel aqui pra receber o número de comparações do merge
			mergesort(A, p, u);
		}
		return //comparação;
	}
