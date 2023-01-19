#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"

int M[NUM_PESSOAS][NUM_PESSOAS];

void inicializar_rede()
{
	for(int i = 0; i<NUM_PESSOAS; i++)
		for (int j = 0; j<NUM_PESSOAS; j++)
			M[i][j] = 0;
}

void adicionar_amizade(int i, int j)
{
	M[j][i] = 1;
	M[i][j] = 1;
}

float random_float()
{
	return (float)rand() / RAND_MAX;
}

void popularRedeSocialAleatoriamente(float P)
{
	int j;
	float r;
	inicializar_rede();
	for(int i = 0; i<NUM_PESSOAS; i++)
		for (j = i+1; j<NUM_PESSOAS; j++){
			r = random_float();
			if (r<P)
				adicionar_amizade(i, j);
		}
}

void imprimirRedeSocial()
{
	printf("\n");

	for (int i = 0; i < NUM_PESSOAS; i++)
	{
		for (int j = 0; j < NUM_PESSOAS; j++)
			printf("%2d ", M[i][j]);	
		printf("\n");
	}	
	printf("\n");
}

int numAmigosEmComum(int v, int u)
{
	int comum = 0;
	for (int j = 0; j < NUM_PESSOAS; j++)
		if (M[v][j] ==1 && M[u][j] == 1){
			comum++;
			printf("%d ", j);
		}
	printf("\n");
	return comum;
}