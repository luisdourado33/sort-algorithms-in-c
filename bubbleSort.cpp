#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoesAuxiliares.h"

void bubbleSort(int valores[], int qtd) {
	for(int i = 0; i < qtd - 1; i++) {
		for(int j = 0; j < qtd - i - 1; j++) {
			if(valores[j] > valores[j + 1]) {
				troca(&valores[j], &valores[j + 1]);
			}
		}
	}
}

void executaBubbleSort(int valores[], int qtd, int mostrarSequencia) {
	clock_t inicio = clock();
	bubbleSort(valores, qtd);
	clock_t fim = clock();
	double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
	printf("\nMetodo Bolha: %fs", tempo_gasto);
	
	if (mostrarSequencia == 1) {
		mostraSequencia(valores, qtd);
	}
	
}
