#include <stdio.h>
#include "estatistica.h"

void main(){

	float x, mi, beta, b;

	x = -2;

	printf("\nO resultado de cauchy eh: %f\n", cauchy(x));

	x = 0, mi = 0.5, beta = 2;
	
	printf("\nO resultado de gumbel eh: %f\n", gumbel (beta, x, mi));
	
	x = -6, mi = -5, b = 4;

	printf("\nO resultado de laplace eh: %f\n", laplace(x, mi, b));

}