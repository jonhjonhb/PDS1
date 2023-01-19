#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*void troca(float *v1, float *v2){
    float x;
 	x = *v1;
 	*v1 = *v2;
 	*v2 = x;
}

void main(){
	float end1, end2;

	scanf("%f%f", &end1, &end2);

	troca(&end1, &end2);

	printf("1: %f\n2: %f\n", end1, end2);
}*/

int parOuImpar(unsigned int number){
    return ~(number /(unsigned int)1);
}

void main(){
	unsigned int x;

	scanf("%f", &x);

	x = ddd(x);

	printf("O valor virou %d\n", ddd(1152145649));
}