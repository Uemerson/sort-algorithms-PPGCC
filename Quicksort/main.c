#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
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
    quickSort(array, 0, n - 1);               // Ordena o array usando o algoritmo quick sort
  }

  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

  printf("\nprogram took %f seconds to execute \n", time_taken);

  return 0;
}