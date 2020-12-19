int bubblesort(int list[], int n)
{
  int c, d, t;
  int comparacoes = 0;

  for (c = 0; c < n - 1; c++)
  {
    for (d = 0; d < n - c - 1; d++)
    {
      if (list[d] > list[d + 1])
      {
        t = list[d];
        list[d] = list[d + 1];
        list[d + 1] = t;
        comparacoes++;
      }
    }
  }

  return comparacoes;
}