#include <stdio.h>
#include "func.h"

void main(){

	int M[MAX_TAM][MAX_TAM];

	zeraMatriz(M, MAX_TAM);
	printf("\n");
	//imprimeMatriz(M, MAX_TAM);
	//printf("\n");
	criaBloco(M, 2, 2, 3);
	//imprimeMatriz(M, MAX_TAM);
	//printf("\n");

	Bloco b1;
	b1.linha = 0;
	b1.coluna = 0;
	b1.tam = 2;
	
	if(insereBloco(M, MAX_TAM, b1))
	{
		printf("Existe.\n\n");
		//imprimeMatriz(M, MAX_TAM);
	}else
		printf("Inexistente.\n\n");	

	printf("\nTamanho do bloco: %d\n", tamBloco(M, MAX_TAM, 2, 2));

	char str[MAX_TAM];

	fgets(str ,MAX_TAM, stdin);

	printf("\nNumero de chars dif.: %d", numCharsDiferentes(str));
	
}