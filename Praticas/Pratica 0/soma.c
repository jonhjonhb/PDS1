#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int soma(unsigned int N){

	unsigned int soma = 0, k = 1;
	while (k<=N){
		soma += k;
		k++;
	}
	return soma;
}

void main (){

	int N;

	do {
		printf("Digite N:\n");
		scanf("%d", &N);
	} while (N<=0);{
		printf("Soma: %d\n", soma(N));
	}

}