#include <stdio.h>

int main(){

	int idade;

	printf("Favor informar idade:\n");
	scanf("%i", &idade);

	if (idade < 18){
		printf("Bebidas alcolicas nao estao liberadas\n");
	} else {
		printf("Bebidas alcolicas estao liberadas\n");
	}

	return 0;
}