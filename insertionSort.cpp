#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoesAuxiliares.h"

void insertionSort(int valores[], int qtd) {
	int i, chave, j;
	for (i = 1; i < qtd; i++) {
	    chave = valores[i];
	    j = i - 1;
	
	    while (j >= 0 && valores[j] > chave) {
	        troca(&valores[j + 1], &valores[j]);
	        j = j - 1;
	    }
		troca(&valores[j + 1], &chave);
	}
}

void executaInsertionSort(int valores[], int qtd, int mostrarSequencia) {
	clock_t inicio = clock();
	insertionSort(valores, qtd);
	clock_t fim = clock();
	double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
	printf("\nMetodo Insertion Sort: %fs", tempo_gasto);
	
	if (mostrarSequencia == 1) {
		mostraSequencia(valores, qtd);
	}

}
