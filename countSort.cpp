#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoesAuxiliares.h"

void countingSort(int arr[], int n) {
	int saida[10];
	int max = arr[0];
	
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	
	int count[10]; // O ideal seria max+1 porem nao eh possivel alocar memoria dinamica
	
	for (int i = 0; i < n; i++) {
		count[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		count[arr[i]]++; 
	}
	
	for (int i = 0; i <= max; i++) {
		count[i] += count[i - 1];
	}
	
	for (int i = n - 1; i >= 0; i--) {
		saida[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	
	for (int i = 0; i < n; i++) {
		arr[i] = saida[i];
	}
}

void executaCountSort(int valores[], int qtd, int mostrarSequencia) {
	clock_t inicio = clock();
	countingSort(valores, qtd);
	clock_t fim = clock();
	double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
	printf("\nMetodo Contagem: %fs", tempo_gasto);
	
  if (mostrarSequencia == 1) {
    mostraSequencia(valores, qtd);
  }

}
