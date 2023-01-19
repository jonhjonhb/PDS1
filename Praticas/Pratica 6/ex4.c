#include <stdio.h>

int numero(char str[]){
	int i = 1;
	for (i=1; str[i] != 0; i++);
	return i-1;
}

void main(){

	char str[128];
	printf("Digite uma linha:\n");
	fgets(str, 128, stdin);
	printf("\nQuantidade de caracteres digitados: %d\n", numero(str));
}