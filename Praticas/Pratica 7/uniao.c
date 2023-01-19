#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
#include "random.h"

#define TAM 60
#define ALT 366

void cria(int vetor[]){

	int i=0;
	for (i=0; i<TAM; i++){
		vetor[i] = random(ALT);
		printf("%d ", vetor[i]);
	}
}

void une(int vetor[], int vetorx[]){

	for (int i = 0; i < TAM; i++) {
        vetor[i] = vetorx[i];
    }

}

void une1(int vetorU[], int vetorY[]){
    
    int i = 0;
    for (i = 0; i < TAM; i++) {
        vetorU[TAM + i] = vetorY[i]; 
    }

}

void uniao(){
	
	int vetorX[TAM], vetorY[TAM], vetorU[TAM*2];

    printf("\nVetor X\n");
	
	srand(time(NULL)*2);
	cria(vetorX);
	printf("\n");
    
    printf("\nVetor Y\n");

	srand(time(NULL)*5);
	cria(vetorY);

	une(vetorU, vetorX);
	une1(vetorU, vetorY);
    
    printf("\n\nVetor uniao\n");
    for (int x = 0; x<TAM*2; x++){
		printf("%d ", vetorU[x]);
	}

}