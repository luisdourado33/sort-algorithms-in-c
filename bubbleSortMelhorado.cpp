#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoesAuxiliares.h"

void bubbleSortMelhorado(int valores[], int qtd) {
	int houveTroca;
	houveTroca = 1;
	
	for(int i = 0; (i < qtd - 1); i++) {
		houveTroca = 0;
		for(int j = 0; j < qtd - i - 1; j++) {
			if(valores[j] > valores[j + 1]) {
				troca(&valores[j], &valores[j + 1]);
				houveTroca = 1;
			}
		}
	}
}

void executaBubbleSortMelhorado(int valores[], int qtd, int mostrarSequencia) {
	clock_t inicio = clock();
	bubbleSortMelhorado(valores, qtd);
	clock_t fim = clock();
	double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
	printf("\nMetodo Bolha Melhorado: %fs", tempo_gasto);
	
	if (mostrarSequencia == 1) {
		mostraSequencia(valores, qtd);
	}
}
