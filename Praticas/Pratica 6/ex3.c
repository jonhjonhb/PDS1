#include <stdio.h>

int linhas (int x){
	
	int i=1;
	int count=1;
	int qtdlinha = 1;
	printf("\n");
	for(i=1 ; qtdlinha<=x ; qtdlinha++){
		if(x==0)
			break;

		printf("%d ", i);
		i++;
		if (count < qtdlinha)
			do{
				printf("%d ", i);
				i++;
				count++;
			} while (count < qtdlinha);
		count = 1;
		printf("\n");
	}
	printf("\n");
	return 0;
}

void triangulo(){

	int x = 0;
	do {
		printf("\nDigite o numero de linhas:\n");
		scanf("%d", &x);
		if (x<=0)
		printf("\nNumero invalido.\n");
	} while (x<=0);

	linhas(x);
}

void main(){

	//Teste
	triangulo();
}