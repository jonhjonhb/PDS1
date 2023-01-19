#include <stdio.h>
#include <math.h>

void main(){

	float juros, conta, poupanca;

	poupanca = 500;

	juros = 1.01;

	conta = poupanca * juros;

	poupanca = conta;
 	
 	printf("O saldo atual eh de %f no primeiro mes\n", poupanca);

 	conta = (poupanca+200)*juros;

 	system("PAUSE");

	poupanca = conta;
 	
 	printf("O saldo atual eh de %f no segundo mes\n", poupanca);

 	conta = (poupanca-50)*juros;

 	poupanca = conta;

 	system("PAUSE");

 	printf("O saldo atual eh de %f no terceiro mes\n", poupanca);

}