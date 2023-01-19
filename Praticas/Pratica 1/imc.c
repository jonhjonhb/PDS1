#include <stdio.h>

float IMC (float altura, float peso){
	return peso / (altura*altura);
}

float IMCB (float altura, float maximo){
	return altura * altura * maximo;
}

float IMCO (float altura, float minimo){
	return altura * altura * minimo;
}

void main(){
 	
	float altura, peso, imc, imco, imcb, minimo, maximo;

	minimo = 18.5;
	maximo = 25;

	//Brutus

	altura = 1.84;
	peso = 122;

	imc = IMC(altura, peso);
	imcb = peso-IMCB(altura, maximo);

	printf("O IMC de brutos eh %.2f\nPara chegar ao peso ideal eh nessecario perder no minimo %.0f Kg\n", imc, imcb);
	
	//Olívia

	system("PAUSE");

	altura = 1.59;
	peso = 50;

	imc = IMC(altura, peso);
	imco = IMCO(altura, minimo)-peso;

	printf("O IMC de Hadassa eh %.2f\nPara chegar ao peso ideal eh nessecario ganhar no minimo %.0fKg", imc, imco);

/*if (IMCO(altura, minimo)>peso){
	(printf("\nO IMC de Olivia eh %.2f\nPara chegar ao peso ideal eh nessecario ganhar no minimo %.0fKg", imc, imco));
	(printf("O IMC de Olivia eh %.2f\nPara chegar ao peso ideal eh nessecario perder no minimo %.0f Kg\n", imc, imco));
	}
*/
}