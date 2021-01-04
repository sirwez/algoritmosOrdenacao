long bubblesort(int a[], int n)
{
  int i, j, aux;
  long comparacoes = 0;

  for (i = 0; i < n - 1; i++)
  {
    for (j = n - 1; j >= i + 1; j--)
    {
      comparacoes++;

      if (a[j] < a[j - 1])
      {
        aux = a[j];
        a[j] = a[j - 1];
        a[j - 1] = aux;
      }
    }
  }

  return comparacoes;
}
