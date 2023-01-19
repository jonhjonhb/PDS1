#include <stdio.h>

#define inf 1000000

char conceitoAluno (){

	int x;
	do{
	
	printf("Digite sua nota:\n");
	scanf("%d", &x);
	
		switch (x){
			case 0 ... 4:
			return 'F';
			break;
			case 5:
			return 'E';
			break;
			case 6:
			return 'D';
			break;
			case 7:
			return 'C';
			break;
			case 8:
			return 'B';
			break;
			case 9 ... inf:
			return 'A';
			break;
			default:
			printf("Numero invalido.\n");
			continue;
			break;
		}
	} while (x<0);
}

void main(){

	//Teste
	printf("\nTeste 2!\n");
	char c = conceitoAluno();
	printf("Conceito: %c\n", c);

}