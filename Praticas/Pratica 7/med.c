#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

double calcula(int vetor[],int n){
	double soma = 0, med = 0;
	int i = 0;
	for (i=0; i<n; i++){
		soma += vetor[i];
	}
	med = soma/n;
	return med;
}

void media(){
	int tamanho = 0;
	srand(time(NULL));
	do{
	tamanho = rand();
	} while (tamanho>MAX || tamanho<=0);
	printf("%d\n", tamanho);
	
	int vetor[tamanho];
	int i=0;
	
	for (i=0; i<tamanho; i++){
		vetor[i] = rand();
		printf("%d ", vetor[i]);
	}

	printf("\nMedia do vetor: %.2lf\n", calcula(vetor, tamanho));
} 


