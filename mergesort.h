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

  int j,k;
  j = 0;
  i = 0;

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
  }

  return 0;
}
int merge_sort(int *A, int p, int r)
{
  if (p < r)
  {
    int q = (p + r ) / 2;
    merge_sort(A, p, q);
    merge_sort(A, q+1, r);
    merge(A, p, q, r);
  }

  return 0;
}
