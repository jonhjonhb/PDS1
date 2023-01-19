#include <stdio.h>
#define MAX 10

void monta_vetor(int vetorx[], char x){
	int i = 0; 
	printf("Digite o vetor %c: ", x);
	for (i=0; i<MAX; i++){
	scanf("%d", &vetorx[i]);
	}
}

void intcal(){
	
	int vetorU[MAX], vetorV[MAX];
	monta_vetor(vetorU, 'U');
	monta_vetor(vetorV, 'V');

	int i = 0, intercal[MAX];
	int u=0, v=0;

	for (i=0; i<20; i++){
		if (i%2==0){
		intercal[i] = vetorU[u];
		u++;
		}
		if (i%2==1){
		intercal[i] = vetorV[v];
		v++;
		}
	}

	printf("Vetor Z: ");
	
	for (i=0; i<20; i++){
	printf("%d ", intercal[i]);
	}
}