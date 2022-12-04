#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoesAuxiliares.h"

void mergeIterativo(int arr[], int l, int m, int r);
 
void mergeSortIt(int arr[], int l, int r)
{
   if (l < r)
   {
      int m = l+(r-l)/2;
      mergeSortIt(arr, l, m);
      mergeSortIt(arr, m+1, r);
      mergeIterativo(arr, l, m, r);
   }
}
 
void mergeIterativo(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
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

void executaMergeSortIterativo(int valores[], int qtd, int mostrarSequencia) {
	clock_t inicio = clock();
	mergeSortIt(valores, 0, qtd - 1);
	clock_t fim = clock();
	double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
	printf("\nMetodo Merge Sort Iterativo: %fs", tempo_gasto);
	
    if (mostrarSequencia == 1) {
        mostraSequencia(valores, qtd);
    }
}
