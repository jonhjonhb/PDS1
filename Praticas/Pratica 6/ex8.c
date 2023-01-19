#include <stdio.h>

int str(){

	char c;
	printf("Digite seu nome(coloque o '.' no fim):\n");
	do{
		c = getc(stdin);
		if (c > 64 && c < 91){
			printf("%c.", c);
		}
	} while ( c != '.');
	printf("\n");

	return 0;
}

void main(){

	//Teste
	str();
}