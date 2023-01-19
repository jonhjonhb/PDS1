#include <stdio.h>
#include <math.h>

void main(){

	float juros, conta, poupanca, r;

	poupanca = 789.54;

	juros = 1.0056;

	r = juros;

	conta = poupanca;

 	printf("O saldo atual eh de %.2f no primeiro mes\n", conta);

 	conta = conta*r+303.20;

 	system("PAUSE");
	
 	printf("O saldo atual eh de %.2f no segundo mes\n", conta);

 	conta = conta*r-58.25;

 	system("PAUSE");

 	printf("O saldo atual eh de %.2f no terceiro mes\n", conta);

 	conta = conta*r;

 	system("PAUSE");

 	printf("O saldo atual eh de %.2f no quarto mes\n", conta);
}