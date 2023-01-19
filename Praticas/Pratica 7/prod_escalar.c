#include <stdio.h>
#define MAX 100

int element(int n){
	do {
		scanf("%d", &n);
	}while (n>MAX);
	return n;
}

void monta_vetor(int vetorx[], char x, int n){
	
	int i = 0; 
	printf("Digite o vetor %c: ", x);
	for (i=0; i<n; i++){
	scanf("%d", &vetorx[i]);
	}
}

void produtoescalar(){
	
	int vetorU[MAX], vetorV[MAX];
	int n = MAX+1;
	n = element(n);

	monta_vetor(vetorU, 'U', n);
	monta_vetor(vetorV, 'V', n);

	int i = 0, produto = 0;
	for (i=0; i<n; i++){
		produto += vetorU[i]*vetorV[i];
	}
	printf("Produto escalar: %d\n", produto);
}