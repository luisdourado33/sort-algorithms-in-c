#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoesAuxiliares.h"

int particao(int arr[], int menor, int maior)
{
    int pivot = arr[maior]; // pivot
    int i
        = (menor
           - 1); 
  
    for (int j = menor; j <= maior - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[maior]);
    return (i + 1);
}

void quickSort(int arr[], int menor, int maior)
{
    if (menor < maior) {
        int pi = particao(arr, menor, maior);
  
        quickSort(arr, menor, pi - 1);
        quickSort(arr, pi + 1, maior);
    }
}

void executaQuickSort(int valores[], int qtd, int mostrarSequencia) {
	clock_t inicio = clock();
	quickSort(valores, 0, qtd - 1);
	clock_t fim = clock();
	double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
	printf("\nMetodo Quick Sort: %fs", tempo_gasto);
	
    if (mostrarSequencia == 1) {
        mostraSequencia(valores, qtd);
    }
}
