#include <stdio.h>

int merge(int *A, int p, int q, int r)
{
  int tam1 = q - p + 1;
  int tam2 = r - q;

  int subvetor1[tam1];
  int subvetor2[tam2];

  int i;
  for (i=0; i<tam1; ++i)
  {
    subvetor1[i] = A[p + i];
  }
  for (i=0; i<tam2; ++i)
  {
    subvetor2[i] = A[q + 1 + i];
  }
  subvetor1[tam1] = 100;
  subvetor2[tam2] = 100;

  int j,k, cont;
  j = 0;
  i = 0;
  cont = 0;

  for (k=p; k<=r; ++k)
  {
    if (subvetor1[i] <= subvetor2[j])
    {
      A[k] = subvetor1[i];
      ++i;
    }
    else if (subvetor1[i] > subvetor2[j])
    {
      A[k] = subvetor2[j];
      ++j;
    }
    cont++;
  }

  return cont;
}
int mergesort(int *A, int p, int r)
{
  int compara=0;
  if (p < r)
  {
    int q = (p + r ) / 2;
    mergesort(A, p, q);
    mergesort(A, q+1, r);
    compara=merge(A, p, q, r);
  }

  return compara;
}
