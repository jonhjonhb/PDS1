#include <stdio.h>
#include "p8.h"

void pegavalor(int *m, int *n, int *k)
{
	do{
	printf("\nDigite o m e n: ");
	scanf("%d %d", &(*m), &(*n));
	} while(*m < 0 || *m > TAM_MAX || *n < 0 || *n > TAM_MAX);	
	do{
	printf("\nDigite o k: ");
	scanf("%d", &(*k));
	} while( *k < 2 );	
}

void main()
{
	int matriz[TAM_MAX][TAM_MAX];
	int m=0, n=0, k=0;

	pegavalor(&m, &n, &k);
	criamatriz(matriz, m, n, k);
	zeraseq(matriz, m, n);

}