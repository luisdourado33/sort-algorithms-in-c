#include <stdio.h>
#include <stdlib.h>
#include "funcoesAuxiliares.h"

void troca(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void mostraSequencia(int valores[], int qtd) {
	printf("\nQuantidade: %d\n", qtd);
	for (int i = 0; i < qtd; i++) {
		printf("%d ", valores[i]);
	}
	printf("\n");
}
