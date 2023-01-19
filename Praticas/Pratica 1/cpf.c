#include "cpf.h"

void main(){

	int c1, c2, c3, c4, c5, c6, c7, c8, c9;
	
	//c1 = 0;
	//c2 = 8;
	//c3 = 6;
	//c4 = 3;
	//c5 = 2;
	//c6 = 8;
	//c7 = 1;
	//c8 = 3;
	//c9 = 6;

	printf("Digite seu CPF:");

	scanf("%d %d %d %d %d %d %d %d %d", &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9);

	printf("%i%i%i.%i%i%i.%i%i%i-XX\n", c1, c2, c3, c4, c5, c6, c7, c8, c9);

	system("PAUSE");

	int cpf = CPF(c1, c2, c3, c4, c5, c6, c7, c8, c9);

	//printf("1. Soma dos produtos eh %i\n", cpf);

	int d1 = cpf % 11;

		if (d1 < 2 && d1 >= 0){
			d1 = 0;
		} else{
			d1 = 11 - d1;
		}

	printf("O digito 1 verificador eh %i\n", d1);

	int cpf11 = CPF11(c1, c2, c3, c4, c5, c6, c7, c8, c9, d1);

	//printf("3. Soma dos produtos eh %i\n", cpf11);

	int d2 = cpf11 % 11;

		if (d2 >= 0 && d2 < 2){
			d2 = 0;
		} else {
			d2 = 11 - d2;
		}

	printf("O digito 2 verificador eh %i\n", d2);

	printf("%i%i%i.%i%i%i.%i%i%i-%i%i\n", c1, c2, c3, c4, c5, c6, c7, c8, c9, d1, d2);

}