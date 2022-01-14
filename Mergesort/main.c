#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main()
{
  clock_t t;
  t = clock();

  // 15 mil elementos
  // FILE *file = fopen("../Listas/15ThousandNumbersRandomOrder.txt", "r");
  // FILE *file = fopen("../Listas/15ThousandNumbersAscOrder.txt", "r");
  // FILE *file = fopen("../Listas/15ThousandNumbersDescOrder.txt", "r");
  // int array[15000];

  // 35 mill elementos
  // FILE *file = fopen("../Listas/35ThousandNumbersRandomOrder.txt", "r");
  // FILE *file = fopen("../Listas/35ThousandNumbersAscOrder.txt", "r");
  // FILE *file = fopen("../Listas/35ThousandNumbersDescOrder.txt", "r");
  // int array[35000];

  // 65 mil elementos
  // FILE *file = fopen("../Listas/65ThousandNumbersRandomOrder.txt", "r");
  // FILE *file = fopen("../Listas/65ThousandNumbersAscOrder.txt", "r");
  // FILE *file = fopen("../Listas/65ThousandNumbersDescOrder.txt", "r");
  // int array[65000];

  // 105 mil elementos
  // FILE *file = fopen("../Listas/105ThousandNumbersRandomOrder.txt", "r");
  // FILE *file = fopen("../Listas/105ThousandNumbersAscOrder.txt", "r");
  // FILE *file = fopen("../Listas/105ThousandNumbersDescOrder.txt", "r");
  // int array[105000];

  // 155 mil elementos
  // FILE *file = fopen("../Listas/155ThousandNumbersRandomOrder.txt", "r");
  // FILE *file = fopen("../Listas/155ThousandNumbersAscOrder.txt", "r");
  FILE *file = fopen("../Listas/155ThousandNumbersDescOrder.txt", "r");
  int array[155000];

  if (file == NULL)
  {
    printf("error reading file\n");
    return -1;
  }
  else
  {
    int i;
    // Carrega o array de numeros do arquivo selecionado
    while (fscanf(file, "%d", &array[i]) != EOF)
    {
      i++;
    }
    fclose(file);

    int n = sizeof(array) / sizeof(array[0]); // Obtem o tamanho do vetor da array
    mergeSort(array, 0, n - 1);               // Ordena o array usando o algoritmo mergesort
  }

  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

  printf("\nprogram took %f seconds to execute \n", time_taken);

  return 0;
}