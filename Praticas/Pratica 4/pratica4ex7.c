#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pratica4f.h"

void main(){

	float h = 1.73;
	char s = 'M';
	float p;

	printf("Digite o char M ou F: \n");
	scanf("%c", &s);

	printf("Digite sua altura: \n");
	scanf("%f", &h);

	printf("Digite seu peso: \n");
	scanf("%f", &p);

	system("PAUSE");

	printf("\nPeso ideal: %.2f Kg\n", peso(h, s));

	if (peso(h, s) > p){
		float x = peso(h, s) - p;
		return printf("Voce precisa engordar %.2f Kg\n", x);
	} else (peso(h, s) < p);{
		float x = p - peso(h, s);
		return printf("Voce precisa emagrecer %.2f Kg\n", x);
}