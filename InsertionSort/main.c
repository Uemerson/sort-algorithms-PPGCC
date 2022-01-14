#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int array[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > key)
    {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
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
    insertionSort(array, n);                  // Ordena o array usando o algoritmo insertion sort

    printArray(array, n);
  }

  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

  printf("\nprogram took %f seconds to execute \n", time_taken);

  return 0;
}