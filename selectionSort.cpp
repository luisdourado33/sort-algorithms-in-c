#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoesAuxiliares.h"

void selectionSort(int valores[], int qtd)
{
    int i, j, min_idx;
 
    for (i = 0; i < qtd-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < qtd; j++)
          if (valores[j] < valores[min_idx])
            min_idx = j;
 
           if(min_idx != i)
            troca(&valores[min_idx], &valores[i]);
    }
}

void executaSelectionSort(int valores[], int qtd, int mostrarSequencia) {
	clock_t inicio = clock();
	selectionSort(valores, qtd);
	clock_t fim = clock();
	double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
	printf("\nMetodo Selection Sort: %fs", tempo_gasto);
	
  if (mostrarSequencia) {
    mostraSequencia(valores, qtd);
  }
}
