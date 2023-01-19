#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int element(int n){
	do {
		scanf("%d", &n);
	}while (n>MAX);
	return n;
}

void monta_vetor(int vetorx[], int n){
	int i=0;
	for (i=0; i<n; i++){
		vetorx[i] = rand();
		printf("%d ", vetorx[i]);
	}
}

void monta_vetorI(int vetorI[], int n, int vetor[]){
	int i=0, j=0;
	int x = 0;
	x = n;
	for (i=0; i<x; i++){
		vetorI[i] = vetor[x-1-i];
	}
}

void inverte(){

	int n = MAX+1;
	n = element(n);
	int vetorV[n];
	int i=0;
	srand(time(NULL));
	monta_vetor(vetorV, n);

	int vetorI[n];
	monta_vetorI(vetorI, n, vetorV);
	
	printf("\nVetor Z: ");
	for (i=0; i<n; i++){
		printf("%d ", vetorI[i]);
	}
}