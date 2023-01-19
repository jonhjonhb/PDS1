#include <stdio.h>
#include <math.h>

float cauchy (float x){
	return pow(x,2);
}


void main(){

	float x;
	printf("Digite a base:");
	scanf("%f", &x);
	x = cauchy(x);
	
	printf("O resultado eh: %.2f\n", x);

	system("PAUSE");

	//módulo

	int y;
	printf("Digite o valor absoluto:");
	scanf("%d", &y);
	y = abs(y);
	printf("O resultado eh: %d", y);
}
