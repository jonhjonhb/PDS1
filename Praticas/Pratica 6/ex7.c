#include <stdio.h>

int str(){
	char digitado[100];
	char inverso[100];
	int i=0, x;
	char c;
	printf("Digite seu texto(coloque o '.' no fim do texto):\n");
	do{
		c = getc(stdin);
		digitado[i]= c;
		i++;
	} while ( c != '.');
	x = i-1;
	inverso[i] = '\0';
	i=0;
	while (x>=0){
		inverso[x] = digitado[i];
		x--;
		i++;
	}
	printf("Inverso: %s\n", inverso);

	return 0;
}

void main(){

	//Teste
	str();
}