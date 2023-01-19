#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define enesimo pow(10,-6)

double fatorial (int a){

	int x = 0, i = a-1;

	for (x=0; i>=1; i--){
		a *= i;
	}
	return a;
}

double aprox_fatorial (){

	int x, i = 1;
	double e = 1.0;

	for(i = 1; 1.0/fatorial(i) > enesimo ; i++){
		e += 1.0/fatorial(i);
	}

	return e;
}

void main(){

	//Teste
	printf("O numero euler eh: %lf\n", aprox_fatorial());

}