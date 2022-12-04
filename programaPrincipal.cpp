#include <stdio.h>
#include <time.h>

#include "bubbleSort.cpp"
#include "bubbleSortMelhorado.cpp"
#include "insertionSort.cpp"
#include "selectionSort.cpp"
#include "mergeSort.cpp"
#include "mergeSortIterativo.cpp"
#include "quickSort.cpp"
#include "countSort.cpp"

#include "funcoesAuxiliares.cpp"

int * geraAleatorio(int qtd) {
	int seq[qtd];
	
	srand((unsigned)time(NULL));
	for(int i = 0; i < qtd; i++) {
		seq[i] = rand() % 999;
	}
	
	int *seq_ptr = seq;
	
	return seq_ptr;
}

int * geraCrescente(int qtd) {
	int seq[qtd];
	for(int i = 0; i < qtd; i++) {
		seq[i] = i;
	}
	
	int *seq_ptr = seq;
	
	return seq_ptr;
}

int * geraDecrescente(int qtd) {
	int seq[qtd];
	for(int i = qtd - 1; i >= 0; i--) {
		seq[i] = i;
	}
	
	int *seq_ptr = seq;
	
	return seq_ptr;
}

int * geraQuaseOrdenado(int qtd) {
	int seq[qtd];
	srand((unsigned)time(NULL));
	for(int i = 0; i < qtd; i++) {
		if (i % 10 == 0) {
			seq[i] = rand() % 999;
		} else {
			seq[i] = i;
		}
	}
	
	int *seq_ptr = seq;
	
	return seq_ptr;
}

int main(void) {
	int tamanhoConjunto;
	int opcao;
	
	printf("Digite o tamanho do vetor que deve ser ordenado [1-100000]: ");
	scanf("%d", &tamanhoConjunto);
	
	if (tamanhoConjunto > 0) {
		int *valores;
		int gerado[tamanhoConjunto];
		
		printf("Digite o tipo de conjunto de dados a ser ordenado:\n");
		printf("1 - Aleatorio\n");
		printf("2 - Ordenado Crescentemente\n");
		printf("3 - Ordenado Descrescentemente\n");
		printf("4 - Quase Ordenado\n");
		printf("Opcao: ");
		scanf("%d", &opcao);
		
		if (opcao < 1 || opcao > 4) {
			printf("Opcao invalida!\n");
			return 0;
		}
		
		printf("Inicializando os vetores!\n\n");
		
		// Opcao 1 - Aleatorio
		if (opcao == 1) {
			valores = geraAleatorio(tamanhoConjunto);
		}
		
		// Opcao 2 - Crescente
		if (opcao == 2) {
			valores = geraCrescente(tamanhoConjunto);
		}
		
		// Opcao 3 - Decrescente
		if (opcao == 3) {
			valores = geraDecrescente(tamanhoConjunto);
		}
		
		// Opcao 4 - Quase ordenado
		if (opcao == 4) {
			valores = geraQuaseOrdenado(tamanhoConjunto);
		}
		
		// Criando sequencia sem ponteiros
		for (int i = 0; i < tamanhoConjunto; i++) {
			gerado[i] = *(valores + i);
		}
				
		printf("\nComparando ordenacao de valores aleatorios\n");
		
		int mostrarSequencia = 0;
		
		executaBubbleSort(gerado, tamanhoConjunto, mostrarSequencia);
		executaBubbleSortMelhorado(gerado, tamanhoConjunto, mostrarSequencia);
		executaInsertionSort(gerado, tamanhoConjunto, mostrarSequencia);
		executaSelectionSort(gerado, tamanhoConjunto, mostrarSequencia);
		executaMergeSort(gerado, tamanhoConjunto, mostrarSequencia);
		executaMergeSortIterativo(gerado, tamanhoConjunto, mostrarSequencia);
		executaQuickSort(gerado, tamanhoConjunto, mostrarSequencia);
		executaCountSort(gerado, tamanhoConjunto, mostrarSequencia);
	} else {
		printf("Tamanho do vetor eh invalido!\n");
	}
}
