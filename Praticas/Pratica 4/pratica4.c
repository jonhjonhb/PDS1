#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pratica4f.h"

void main(){

	int x, y;
	
	printf("Digite o x:\n");
	scanf("%d", &x);
		if (x<=0){ 
			do {
			printf("Valor digitado invalido\n");
			printf("Digite o x:\n");
			scanf("%d", &x);	
			}while(x<=0);
		}
	printf("Digite o y:\n");
	scanf("%d", &y);
		if (y<=0){
			do {
			printf("Valor digitado invalido\n");
			printf("Digite o y:\n");
			scanf("%d", &y);	
			} while (y<=0);
		}
	printf("MMC eh: %d\n", mmc(x, y));
	printf("MDC eh: %d", mdc(x, y));
}
